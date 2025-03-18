    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
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
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (s_rotpen_bal_P)
        ;%
            section.nData     = 18;
            section.data(18)  = dumData; %prealloc

                    ;% s_rotpen_bal_P.A
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% s_rotpen_bal_P.B
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 16;

                    ;% s_rotpen_bal_P.C
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 20;

                    ;% s_rotpen_bal_P.K
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 28;

                    ;% s_rotpen_bal_P.InvertedPendulumModel_InitialCo
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 32;

                    ;% s_rotpen_bal_P.Gain_Gain
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 33;

                    ;% s_rotpen_bal_P.SignalGenerator_Amplitude
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 34;

                    ;% s_rotpen_bal_P.SignalGenerator_Frequency
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 35;

                    ;% s_rotpen_bal_P.Amplitudedeg_Gain
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 36;

                    ;% s_rotpen_bal_P.Gain1_Gain
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 37;

                    ;% s_rotpen_bal_P.ConverttoVectorState_Gain
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 38;

                    ;% s_rotpen_bal_P.Gain_Gain_g
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 42;

                    ;% s_rotpen_bal_P.HPFtheta_dotrads_A
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 43;

                    ;% s_rotpen_bal_P.HPFtheta_dotrads_C
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 44;

                    ;% s_rotpen_bal_P.HPFtheta_dotrads_D
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 45;

                    ;% s_rotpen_bal_P.HPFalpha_dotrads_A
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 46;

                    ;% s_rotpen_bal_P.HPFalpha_dotrads_C
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 47;

                    ;% s_rotpen_bal_P.HPFalpha_dotrads_D
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 48;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
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
        ;% Auto data (s_rotpen_bal_B)
        ;%
            section.nData     = 11;
            section.data(11)  = dumData; %prealloc

                    ;% s_rotpen_bal_B.InvertedPendulumModel
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% s_rotpen_bal_B.Gain
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 2;

                    ;% s_rotpen_bal_B.SignalGenerator
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 3;

                    ;% s_rotpen_bal_B.Amplitudedeg
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 4;

                    ;% s_rotpen_bal_B.Gain1
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 5;

                    ;% s_rotpen_bal_B.ConverttoVectorState
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 6;

                    ;% s_rotpen_bal_B.Gain_j
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 10;

                    ;% s_rotpen_bal_B.HPFtheta_dotrads
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 12;

                    ;% s_rotpen_bal_B.HPFalpha_dotrads
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 13;

                    ;% s_rotpen_bal_B.Sum
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 14;

                    ;% s_rotpen_bal_B.ControlGain
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 18;

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
        nTotSects     = 1;
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
        ;% Auto data (s_rotpen_bal_DW)
        ;%
            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% s_rotpen_bal_DW.alphadeg_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% s_rotpen_bal_DW.thetadeg_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% s_rotpen_bal_DW.VmV_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
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


    targMap.checksum0 = 4093483053;
    targMap.checksum1 = 1869852445;
    targMap.checksum2 = 235411782;
    targMap.checksum3 = 2578978309;

