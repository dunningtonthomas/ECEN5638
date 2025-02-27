%% LQR Design using the A, B, C, D matrices
clear; close all; clc;

%% Load Data
load('Data\dynamic_model.mat')

%% Simulate the natural response
natural_sys = ss(A, B, C, D);

% Natural response
% figure();
% impulse(natural_sys)


%% Control Design
% Observability and controlability
o_mat = obsv(A, C);
c_mat = ctrb(A, B);

% Open loop poles
OLP = eig(A);

% Torsion angle 2% settling time 0.4 s
% Overshoot < 5%
% Torsion angle steady-state error < 0.5 degrees
% Max control effort Vm < 10 V
% These specifications are to be satisfied when the servo is tracking a ±10 degree angle square wave.

% LQR Design
Q = 500.*[300, 0, 0, 0;
    0, 300, 0, 0;
    0, 0, 1, 0;
    0, 0, 0, 1];

R = 100;

[K, S, CLP] = lqr(natural_sys, Q, R);

%% Simulate closed loop system
A_cl = A - B*K;
B_cl = B*K;
C_cl = C;
D_cl = zeros(2,4);

% Create system
sys_cl = ss(A_cl, B_cl, C_cl, D_cl);

% Create input signal
t = 0:0.001:3;       % Time vector for simulation
xd = zeros(length(t), 4);   % Input vector
xd(:,1) = 10*pi/180*ones(length(t), 1);
xd(:,2) = 10*pi/180*ones(length(t), 1);

% Reference signal
% xd_temp = 10*pi/180*ones(length(t), 1);

% Simulate the system response to the step input
[y, t_out, x] = lsim(sys_cl, xd, t);

% Calculate control effort
u = zeros(length(t), 1);
for i = 1:length(t)
    u(i, :) = K*(xd(i,:)' - x(i,:)');
end


% Simulink
% sim('lqr_design_model.slx')
% t_out = t;
% y = y_sim;
% x = x_sim;


% Plot the step response
figure;
plot(t_out, y(:,2).*180/pi, 'LineWidth', 2);
hold on
xline(0.4)
yline(10.5, 'color', 'r')
yline(10.2, 'linestyle', ':', 'LineWidth', 2)
yline(9.8, 'linestyle', ':', 'LineWidth', 2)
yline(10, 'color', 'g', 'LineStyle', '--')

xlabel('Time (seconds)');
ylabel('Theta 2 [deg]');
ylim([8 12])
grid on;
title('Closed-Loop Step Response');


% Plot control effort
figure();
plot(t_out, u)
hold on
yline(10, 'color', 'r')

xlabel('Time (s)')
ylabel('Voltage (V)')
title('Control Effort')
