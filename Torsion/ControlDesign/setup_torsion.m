%% Quanser 1 DOF Rotary Torsion
%
% Sets the necessary parameters to run the SRV02 1-DOF Torsion experiment.
% 
% Copyright (C) 2012 Quanser Consulting Inc.
%
clear all;
%
%% System Configuration
% External Gear Configuration: set to 'HIGH' or 'LOW'
EXT_GEAR_CONFIG = 'HIGH';
% Encoder Type: set to 'E' or 'EHR'
ENCODER_TYPE = 'E';
% Is SRV02 equipped with Tachometer? (i.e. option T): set to 'YES' or 'NO'
TACH_OPTION = 'YES';
% Type of Load: set to 'NONE', 'DISC', or 'BAR'
LOAD_TYPE = 'TORSION_1DOF';
% Amplifier Gain used: 
% VoltPAQ-X1 users: set to K_AMP to 1 and Gain switch on amplifier to 1
% VoltPAQ-X2 users: set to K_AMP 3
K_AMP = 1;
% Position of Mass Anchor on Support Bar: set to 'A', or 'B'
DISC_POSITION = 'A'; % maximum spacing
% Amplifier Type: set to 'VoltPAQ'
AMP_TYPE = 'VoltPAQ';
% Digital-to-Analog Maximum Voltage (V)
VMAX_DAC = 10;
%
%% Lab Configuration
% Type of controller: set it to 'INSTRUCTOR', 'STUDENT'
 % CONTROL_TYPE = 'INSTRUCTOR';   
CONTROL_TYPE = 'STUDENT';
%
%% Model Parameters
% Set Model Variables Accordingly to the USER-DEFINED SRV02 System Configuration
% Also Calculate the SRV02 Model Parameters and 
% Write them to the MATLAB Workspace (to be used in Simulink diagrams)
[ Rm, kt, km, Kg, eta_g, B1, Jm, J1, eta_m, K_POT, K_TACH, K_ENC, VMAX_AMP, IMAX_AMP ] = config_srv02( EXT_GEAR_CONFIG, ENCODER_TYPE, TACH_OPTION, AMP_TYPE, LOAD_TYPE );
% Load 1-DOF Torsion parameters
[ J2, B2 ] = config_torsion_1d( DISC_POSITION );
% Stiffness
if strcmp ( CONTROL_TYPE , 'STUDENT')
    disp ('');
    Ks = 0.5;
elseif strcmp (CONTROL_TYPE , 'INSTRUCTOR')
    Ks = d_torsion_Ks;   
end


%% Overwrite Values
J1 = 2.18e-3;
J2 = 5.45e-4;
Ks = 0.63;
B1 = 0.5*B1;
B2 = 0.55*B2;


%% Create State Space
% Load 1-DOF Torsion Linear State-Space Model
if strcmp ( CONTROL_TYPE , 'STUDENT' )
    Torsion_1D_ABCD_eqns_student;
elseif strcmp ( CONTROL_TYPE , 'INSTRUCTOR' )    
    Torsion_1D_ABCD_eqns;
end
%



%% Filter Parameters
% High-pass filter in PD control used to compute velocity
% Cutoff frequency (rad/s)
wcf = 2 * pi * 50.0;
% Damping ratio
zetaf = 0.9;
%
%% Calculate Control Gain
if strcmp ( CONTROL_TYPE , 'STUDENT' )
    Q = diag ( [ 1 1 1 1 ] );
    R = 1;
    K = lqr(A, B, Q, R);
elseif strcmp ( CONTROL_TYPE , 'INSTRUCTOR' )    
    K =  d_torsion_1d_lqr(A,B);   
end
%
%% Display
K