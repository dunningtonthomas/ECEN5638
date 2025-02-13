%% GYRO HEADING PD POST



% Plot response
figure();
plot(data_theta(:,1), data_theta(:,2), 'color', [30 167 217] ./ 255, 'LineWidth', 1.5);  % Plot thetaL with blue solid line

title('PD Response of \theta_L', 'FontSize', 14);
xlabel('Time (seconds)', 'FontSize', 12);
ylabel('Angle (radians)', 'FontSize', 12);
grid on;

figure();
plot(data_alpha(:,1), data_alpha(:,2), 'color', [30 167 217] ./ 255, 'LineWidth', 1.5);  % Plot thetaL with blue solid line

title('PD Response of \alpha', 'FontSize', 14);
xlabel('Time (seconds)', 'FontSize', 12);
ylabel('Angle (radians)', 'FontSize', 12);
grid on;


figure();
plot(data_vm(:,1), data_vm(:,2), 'color', [30 167 217] ./ 255, 'LineWidth', 1.5);  % Plot thetaL with blue solid line

title('PD Response of Vm', 'FontSize', 14);
xlabel('Time (seconds)', 'FontSize', 12);
ylabel('Vm (V)', 'FontSize', 12);
grid on;


data_theta_control = data_theta;
data_alpha_control = data_alpha;
data_vm_control = data_vm;
save('Data\pd_control_exp.mat')