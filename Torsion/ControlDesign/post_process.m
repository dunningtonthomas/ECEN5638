%% Post process running the controller on the hardware
% Run this script after running q_torsion to plot experimental results and
% compare to the model results

%% Simulate the model
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

H = H_high;
sim('pid_model.slx')

%% Plot Results
% Plot the results
figure();
h1 = plot(t_exp, y_exp, 'color', 'r');
hold on
h2 = plot(t, y, 'color', 'b');
h3 = yline(10, 'linestyle', ':', 'color', 'k');

% xline(3.4)
yline(10.5, 'color', 'r')
yline(10.2, 'linestyle', ':', 'LineWidth', 2)
yline(9.8, 'linestyle', ':', 'LineWidth', 2)
yline(10, 'color', 'g', 'LineStyle', '--')

xlabel('Time (seconds)');
ylabel('Theta 2 [deg]');
% ylim([8 12])
grid on;
legend([h1, h2, h3], 'Experiment', 'Model', 'Reference')
title('Closed-Loop Step Response');

% Control effort
figure();
h1 = plot(t_exp, u_exp, 'color', 'r');
hold on
grid on
h2 = plot(t, u, 'color', 'b');
yline(10, 'color', 'k', 'label', 'Voltage Limit')
yline(-10, 'color', 'k')

xlabel('Time (s)')
ylabel('Voltage (V)')
title('Control Effort')
legend([h1, h2], 'Experiment', 'Model')