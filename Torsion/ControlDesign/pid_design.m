%% PID Design
% This script includes model code to develop a PID controller that uses a
% transfer function from Vm to theta2
clear; close all; clc;

%% Sys ID transfer function from sys ID
% Second order
K = db2mag(12.15);
omega0 = 0.41888;
omega1 = 27;
s = tf('s');
H_second = K * omega0 * omega1/ (s*(s+omega1));

% Anti resonance
n1 = 33.5 + 3;
n2 = 35.6 + 3;
omega_n = 34.5;
zeta_p = (n2 - n1) / (2*omega_n);
zeta_z = 0.09*zeta_p;
H_anti = (s^2 + 2*zeta_z*omega_n*s + omega_n^2) / (s^2 + 2*zeta_p*omega_n*s + omega_n^2);
H_high = H_second * H_anti;

%% Try state space conversion
load('Data\dynamic_model.mat')
C = [0, 1, 0, 0];
D = [0];
[num, den] = ss2tf(A,B,C,D);
H_ss = tf(num, den);


%% Design PID controller
Kp = 4;
Kd = -0.2;
Ki = 2.5;

% Create closed loop transfer function
C = pid(Kp, Ki, Kd);
T = feedback(C*H_high, 1);  % Unity feedback


% Simulate the step response of the PID controller
H = H_ss;
sim('pid_model.slx')


% Plot the result
figure();
plot(t, y, 'linewidth', 2)

grid on
xlabel('Time (s)')
ylabel('Amplitude (deg)')
title('Theta 2 Response')

figure();
plot(t, u, 'linewidth', 2)

grid on
xlabel('Time (s)')
ylabel('Amplitude (V)')
title('Input Voltage (V)')
