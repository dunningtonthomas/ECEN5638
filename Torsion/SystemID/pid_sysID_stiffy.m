%% Process Stiffness data for natural frequency
%load('Data\pid_sys_id_exp.mat')

%% Calculate Natural Frequency
% Truncate data
t_cut = 0;
t_cut_2 = 4;
% t_cut_2 = 10;
u_data = u(t > t_cut & t < t_cut_2);
y_data = y(t > t_cut & t < t_cut_2);
t_data = t(t > t_cut & t < t_cut_2);


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

% Simulate higher order impulse response
Hm = H_high;
sim('pid_sys_id_model.slx');

% Plot data
figure();
plot(t_data, y_data, 'linewidth', 2, 'color', 'r')
hold on
plot(t_model, y_model, 'linewidth', 2, 'color', 'b')
ylim([0.8 0.9]);

xlabel('Time (s)')
ylabel('Response (rad)')
title('Impulse Response')
legend('Experiment', 'Model')
grid on



