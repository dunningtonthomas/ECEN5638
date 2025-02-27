%% Post process running the controller on the hardware
% Run this script after running q_torsion to plot experimental results and
% compare to the model results
data_theta2_exp = data_theta2;
data_vm_exp = data_vm;

%% Simulate the model
sim('s_torsion.mdl')

%% Plot Results
% Plot the results
figure();
h1 = plot(data_theta2_exp(:,1), data_theta2_exp(:,3), 'color', 'r');
hold on
h2 = plot(data_theta2(:,1), data_theta2(:,3), 'color', 'b');
h3 = plot(data_theta2_exp(:,1), data_theta2_exp(:,2), 'color', 'g');

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
h1 = plot(data_vm_exp(:,1), data_vm_exp(:,2), 'color', 'r');
hold on
grid on
h2 = plot(data_vm(:,1), data_vm(:,2), 'color', 'b');
yline(10, 'color', 'k', 'label', 'Voltage Limit')
yline(-10, 'color', 'k')

xlabel('Time (s)')
ylabel('Voltage (V)')
title('Control Effort')
legend([h1, h2], 'Experiment', 'Model')