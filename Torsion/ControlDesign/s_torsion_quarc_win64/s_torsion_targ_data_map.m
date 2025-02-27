    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 2;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (s_torsion_P)
        ;%
            section.nData     = 24;
            section.data(24)  = dumData; %prealloc

                    ;% s_torsion_P.A
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% s_torsion_P.B
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 16;

                    ;% s_torsion_P.C
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 20;

                    ;% s_torsion_P.K
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 28;

                    ;% s_torsion_P.FullStateFeedback_Value
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 32;

                    ;% s_torsion_P.PartialStateFeedback_Value
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 36;

                    ;% s_torsion_P.SignalGenerator_Amplitude
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 40;

                    ;% s_torsion_P.SignalGenerator_Frequency
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 41;

                    ;% s_torsion_P.Amplitudedeg_Gain
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 42;

                    ;% s_torsion_P.RateLimiter_RisingLim
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 43;

                    ;% s_torsion_P.RateLimiter_FallingLim
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 44;

                    ;% s_torsion_P.Gain1_Gain
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 45;

                    ;% s_torsion_P.ConverttoVectorState_Gain
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 46;

                    ;% s_torsion_P.Gain_Gain
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 50;

                    ;% s_torsion_P.StateSpace_InitialCondition
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 51;

                    ;% s_torsion_P.DiscreteTransferFcn_NumCoef
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 52;

                    ;% s_torsion_P.DiscreteTransferFcn_DenCoef
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 55;

                    ;% s_torsion_P.DiscreteTransferFcn_InitialStat
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 58;

                    ;% s_torsion_P.DiscreteTransferFcn_NumCoef_l
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 59;

                    ;% s_torsion_P.DiscreteTransferFcn_DenCoef_c
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 62;

                    ;% s_torsion_P.DiscreteTransferFcn_InitialSt_b
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 65;

                    ;% s_torsion_P.Gain_Gain_i
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 66;

                    ;% s_torsion_P.SaturationV_UpperSat
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 67;

                    ;% s_torsion_P.SaturationV_LowerSat
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 68;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% s_torsion_P.ManualSwitch_CurrentSetting
                    section.data(1).logicalSrcIdx = 24;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 1;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (s_torsion_B)
        ;%
            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% s_torsion_B.RateLimiter
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% s_torsion_B.Gain
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 1;

                    ;% s_torsion_B.StateSpace
                    section.data(3).logicalSrcIdx = 3;
                    section.data(3).dtTransOffset = 5;

                    ;% s_torsion_B.DiscreteTransferFcn
                    section.data(4).logicalSrcIdx = 4;
                    section.data(4).dtTransOffset = 7;

                    ;% s_torsion_B.DiscreteTransferFcn_n
                    section.data(5).logicalSrcIdx = 5;
                    section.data(5).dtTransOffset = 8;

                    ;% s_torsion_B.Gain_o
                    section.data(6).logicalSrcIdx = 6;
                    section.data(6).dtTransOffset = 9;

                    ;% s_torsion_B.ManualSwitch
                    section.data(7).logicalSrcIdx = 7;
                    section.data(7).dtTransOffset = 13;

                    ;% s_torsion_B.SaturationV
                    section.data(8).logicalSrcIdx = 8;
                    section.data(8).dtTransOffset = 17;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 3;
        sectIdxOffset = 1;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (s_torsion_DW)
        ;%
            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% s_torsion_DW.DiscreteTransferFcn_states
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% s_torsion_DW.DiscreteTransferFcn_states_k
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 2;

                    ;% s_torsion_DW.PrevY
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 4;

                    ;% s_torsion_DW.LastMajorTime
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 5;

                    ;% s_torsion_DW.DiscreteTransferFcn_tmp
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 6;

                    ;% s_torsion_DW.DiscreteTransferFcn_tmp_k
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% s_torsion_DW.theta1deg_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

                    ;% s_torsion_DW.theta2deg_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 7;
                    section.data(2).dtTransOffset = 1;

                    ;% s_torsion_DW.VmV_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 8;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% s_torsion_DW.PrevLimited
                    section.data(1).logicalSrcIdx = 9;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 210498291;
    targMap.checksum1 = 481767036;
    targMap.checksum2 = 207521249;
    targMap.checksum3 = 450995880;

