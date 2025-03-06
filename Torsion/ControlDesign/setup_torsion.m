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
    % Q = 800.*[150, 0, 0, 0;
    % 0, 700, 0, 0;
    % 0, 0, 1, 0;
    % 0, 0, 0, 1];
    % 
    % R = 100;
    Q = 100.*[100, 0, 0, 0;
    0, 100, 0, 0;
    0, 0, 1, 0;
    0, 0, 0, 1];

    R = 100;

    K = lqr(A, B, Q, R);
elseif strcmp ( CONTROL_TYPE , 'INSTRUCTOR' )    
    K =  d_torsion_1d_lqr(A,B);   
end
%
%% Load Calculated gains
load('Data\lqr_k_matrix.mat')


%% PID Gains

% Kp = 3.37;
% Kd = -0.24;
% Ki = 2.5;

Kp = 3.37;
Kd = -0.24;
Ki = 3;




%% Plot the simulation results
RUN_SIM = false;

if RUN_SIM
    close all;
    sim('s_torsion.mdl')

    % Truncate data to be between 3 and 4 seconds
    data_theta2 = data_theta2(data_theta2(:,1) <= 4 & data_theta2(:,1) >= 3, :);

    % Plot the results
    figure();
    plot(data_theta2(:,1), data_theta2(:,2), 'color', 'r')
    hold on
    plot(data_theta2(:,1), data_theta2(:,3), 'color', 'b')
    xline(3.4)
    yline(10.5, 'color', 'r')
    yline(10.2, 'linestyle', ':', 'LineWidth', 2)
    yline(9.8, 'linestyle', ':', 'LineWidth', 2)
    yline(10, 'color', 'g', 'LineStyle', '--')

    xlabel('Time (seconds)');
    ylabel('Theta 2 [deg]');
    ylim([8 12])
    grid on;
    title('Closed-Loop Step Response');

    % Control effort
    figure();
    plot(data_vm(:,1), data_vm(:,2))
    hold on
    yline(10, 'color', 'r')
    
    xlabel('Time (s)')
    ylabel('Voltage (V)')
    title('Control Effort')


end