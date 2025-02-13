%% GYRO HEADING PD POST

% Load data
% load('Data\pd_control_exp.mat')
load('Data\pd_control_exp_refined.mat')
load('Data\pd_no_control_exp.mat')


% Plot response
figure();
plot(data_theta_control(:,1), data_theta_control(:,2), 'color', [30 167 217] ./ 255, 'LineWidth', 1.5);  % Plot thetaL with blue solid line
hold on
plot(data_theta_no_control(:,1), data_theta_no_control(:,2), 'color', 'r', 'LineWidth', 1.5);  % Plot thetaL with blue solid line
yline(-42.5, 'label', 'External Deflection', 'color', 'k', 'LineStyle', '--')

title('PD Response of \theta_L', 'FontSize', 14);
xlabel('Time (seconds)', 'FontSize', 12);
ylabel('Angle (degrees)', 'FontSize', 12);
legend('Control On', 'Control Off', 'External Deflection')
grid on;

figure();
plot(data_alpha_control(:,1), data_alpha_control(:,2), 'color', [30 167 217] ./ 255, 'LineWidth', 1.5);  % Plot thetaL with blue solid line
hold on
plot(data_alpha_no_control(:,1), data_alpha_no_control(:,2), 'color', 'r', 'LineWidth', 1.5);  % Plot thetaL with blue solid line

title('PD Response of \alpha', 'FontSize', 14);
xlabel('Time (seconds)', 'FontSize', 12);
ylabel('Angle (degrees)', 'FontSize', 12);
legend('Control On', 'Control Off')
grid on;


figure();
plot(data_vm_control(:,1), data_vm_control(:,2), 'color', [30 167 217] ./ 255, 'LineWidth', 1.5);  % Plot thetaL with blue solid line
hold on
plot(data_vm_no_control(:,1), data_vm_no_control(:,2), 'color', 'r', 'LineWidth', 1.5);  % Plot thetaL with blue solid line

title('PD Response of Vm', 'FontSize', 14);
xlabel('Time (seconds)', 'FontSize', 12);
ylabel('Vm (V)', 'FontSize', 12);
legend('Control On', 'Control Off')
grid on;


%% Compare Different Gains
% Load and truncate
load('Data\pd_control_exp_refined.mat')
data_theta_control_refined = data_theta_control;
data_alpha_control_refined = data_alpha_control;
data_vm_control_refined = data_vm_control;
load('Data\pd_control_exp.mat')

% Truncate data
t_orig = 1.382;
t_refined = 3.194;
data_theta_control_refined = data_theta_control_refined(data_theta_control_refined(:,1) >= t_refined, :);
data_alpha_control_refined = data_alpha_control_refined(data_alpha_control_refined(:,1) >= t_refined, :);
data_vm_control_refined = data_vm_control_refined(data_theta_control_refined(:,1) >= t_refined, :);
data_theta_control = data_theta_control(data_theta_control(:,1) >= t_orig, :);
data_alpha_control = data_alpha_control(data_alpha_control(:,1) >= t_orig, :);
data_vm_control = data_vm_control(data_vm_control(:,1) >= t_orig, :);

% Zero time
data_theta_control_refined(:,1) = data_theta_control_refined(:,1) - data_theta_control_refined(1,1);
data_alpha_control_refined(:,1) = data_alpha_control_refined(:,1) - data_alpha_control_refined(1,1);
data_vm_control_refined(:,1) = data_vm_control_refined(:,1) - data_vm_control_refined(1,1);
data_theta_control(:,1) = data_theta_control(:,1) - data_theta_control(1,1);
data_alpha_control(:,1) = data_alpha_control(:,1) - data_alpha_control(1,1);
data_vm_control(:,1) = data_vm_control(:,1) - data_vm_control(1,1);


% Plot response
figure();
plot(data_theta_control(:,1), data_theta_control(:,2), 'color', [30 167 217] ./ 255, 'LineWidth', 1.5);  % Plot thetaL with blue solid line
hold on
plot(data_theta_control_refined(:,1), data_theta_control_refined(:,2), 'color', 'r', 'LineWidth', 1.5);  % Plot thetaL with blue solid line
% yline(-42.5, 'label', 'External Deflection', 'color', 'k', 'LineStyle', '--')

title('PD Response of \theta_L', 'FontSize', 14);
xlabel('Time (seconds)', 'FontSize', 12);
ylabel('Angle (degrees)', 'FontSize', 12);
legend('Original Gains', 'Refined Gains', 'External Deflection')
grid on;

figure();
plot(data_alpha_control(:,1), data_alpha_control(:,2), 'color', [30 167 217] ./ 255, 'LineWidth', 1.5);  % Plot thetaL with blue solid line
hold on
plot(data_alpha_control_refined(:,1), data_alpha_control_refined(:,2), 'color', 'r', 'LineWidth', 1.5);  % Plot thetaL with blue solid line

title('PD Response of \alpha', 'FontSize', 14);
xlabel('Time (seconds)', 'FontSize', 12);
ylabel('Angle (degrees)', 'FontSize', 12);
legend('Original Gains', 'Refined Gains')
grid on;


figure();
plot(data_vm_control(:,1), data_vm_control(:,2), 'color', [30 167 217] ./ 255, 'LineWidth', 1.5);  % Plot thetaL with blue solid line
hold on
plot(data_vm_control_refined(:,1), data_vm_control_refined(:,2), 'color', 'r', 'LineWidth', 1.5);  % Plot thetaL with blue solid line

title('PD Response of Vm', 'FontSize', 14);
xlabel('Time (seconds)', 'FontSize', 12);
ylabel('Vm (V)', 'FontSize', 12);
legend('Original Gains', 'Refined Gains')
grid on;


%% Save Data
% data_theta_control = data_theta;
% data_alpha_control = data_alpha;
% data_vm_control = data_vm;
% save('Data\pd_control_exp.mat')