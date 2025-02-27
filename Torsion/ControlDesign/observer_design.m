%% Design a Luenberg Observer to estimate the angular rates
close all; clear; clc;

%% Load Data
load('Data\dynamic_model.mat')
load('Data\lqr_k_matrix.mat')


%% Observer Design
% Calculate poles of the closed loop system
[vec_cl, poles_cl] = eig(A - B*K);
poles_cl = diag(poles_cl);

% We can place the two poles associated with the measured states of the
% system
poles_obsv = 5 .* real(poles_cl);
% poles_obsv(2:3) = poles_obsv(2:3) .* 10; % Make 10 times faster
% poles_obsv(4) = poles_obsv(4) .* 10;
% poles_obsv(1) = poles_obsv(1) .* 10;

% Determine L matrix
L = place(A', C', poles_obsv)';


% Simulink
sim('lqr_design_model.slx')
t_out = t;
y = y_sim;
x = x_sim;
xhat = xhat_sim;
yhat = yhat_sim;

% Plot step response
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




