%
%% SETUP_SRV02_EXP10_GYRO
%
% Sets the necessary parameters to run the SRV02 Experiment #10: Gyroscope
% laboratory using the "q_gyro" Simulink diagram.
% 
% Copyright (C) 2010 Quanser Consulting Inc.
%
clear all;
%
%% SRV02 Configuration
% External Gear Configuration: set to 'HIGH' or 'LOW'
EXT_GEAR_CONFIG = 'HIGH';
% Encoder Type: set to 'E' or 'EHR'
ENCODER_TYPE = 'E';
% Is SRV02 equipped with Tachometer? (i.e. option T): set to 'YES' or 'NO'
TACH_OPTION = 'YES'; %CHANGED FROM YES
% Type of Load: set to 'NONE', 'DISC', or 'BAR'
LOAD_TYPE = 'GYRO';
% Amplifier Gain used: 
% VoltPAQ-X1 users: set to K_AMP to 1 and Gain switch on amplifier to 1
% VoltPAQ-X2 users: set to K_AMP 3
K_AMP = 1;
% Amplifier type: set to 'UPM_1503', 'UPM_2405', or 'Q3', or 'VoltPaq'
AMP_TYPE = 'VoltPAQ';
% Digital-to-Analog Maximum Voltage (V)
VMAX_DAC = 10;
%
%% Lab Configuration
% Type of Controller: set it to 'AUTO', 'MANUAL'
CONTROL_TYPE = 'AUTO';   
%CONTROL_TYPE = 'MANUAL';
%
%% Control Specifications
% Damping ratio
zeta = 0.7;
% Natural frequency (rad/s)
wn = 2*pi*3;
%    
%% SRV02 System Parameters
% Set Model Variables Accordingly to the USER-DEFINED SRV02 System Configuration
% Also Calculate the SRV02 Model Parameters and 
% Write them to the MATLAB Workspace (to be used in Simulink diagrams)
[ Rm, kt, km, Kg, eta_g, Beq, Jm, Jeq, eta_m, K_POT, K_TACH, K_ENC, VMAX_AMP, IMAX_AMP ] = config_srv02( EXT_GEAR_CONFIG, ENCODER_TYPE, TACH_OPTION, AMP_TYPE, LOAD_TYPE );
% Load model parameters based on SRV02 configuration.
[ K, tau ] = d_model_param(Rm, kt, km, Kg, eta_g, Beq, Jeq, eta_m, AMP_TYPE);
% Load Gyroscope parameters
[ Gg ] = config_gyro();
%
%% Calculate PD Control Gains

%Change design specifications
wn = 8*pi;
zeta = 0.9;


if strcmp ( CONTROL_TYPE, 'STUDENT' )     
    % Proportional gain (V/rad)
    kp = 0;
    % Integral gain (V/(rad-s))
    ki = 0;
else
    % Find gyro PD gains
    [kp,kd] = d_gyro_pd(K, tau, Gg, zeta, wn);    
end
%


%% PID Control Gains
% Hand tuned gains
Kp = 20;
Kd = 3;
Ki = 2;

% Optimal gains
% Kp = 13.6402;
% Ki = 0.2055;
% Kd = 3.159;


%% Display
disp( ' ' );
disp( 'Specifications: ' );
disp( [ '   wn   = ' num2str( wn, 3 ) ' rad/s' ] );
disp( [ '   zeta = ' num2str( zeta, 3 ) ] );
disp( 'Calculated PI control gains: ' );
disp( [ '   kp = ' num2str( kp, 3 ) ' V/rad' ] );
disp( [ '   kd = ' num2str( kd, 3 ) ' V-s/(rad)' ] );
