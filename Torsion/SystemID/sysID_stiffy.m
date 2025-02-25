%% Process Stiffness data for natural frequency
load('Data\stiffness_damping.mat')

%% Calculate Natural Frequency
% Truncate data
t_cut = 1.1;
t_cut_2 = 3.5;
% t_cut_2 = 10;
u_data = u(t > t_cut & t < t_cut_2);
y_data = y(t > t_cut & t < t_cut_2);
t_data = t(t > t_cut & t < t_cut_2);

% FFT
u_fft = fft(u_data)/length(t_data);
y_fft = fft(y_data)/length(t_data);

% Sampling time
Ts = 0.002;
Fs = 1 / Ts;
L = length(t_data);
f = Fs * (0:(L/2)) / L;
y_mag = abs(y_fft(1:L/2+1));
u_mag = abs(u_fft(1:L/2+1));

% Plot data
figure();
plot(t_data, y_data, 'linewidth', 2, 'color', 'r')

xlabel('Time (s)')
ylabel('Response (rad)')
title('Impulse Response')
grid on


% FFT Plot
figure();
stem(f, y_mag, 'filled')
xlabel('Frequency (rad/s)')
ylabel('Amplitude');
title('FFT')


% Final value
omega_n = 5.4;      % Hz
omega_n = omega_n*2*pi; % rad/s

% Calculate stiffness
J1 = 2.18e-3;
J2 = 5.45e-4;
K = (J2)*omega_n^2;

% Calculate damping
delta = 1 / 2 * log(1.05691 / 1.00322);
delta_1 = 1 / 3 * log(1.05691 / 0.957204);
delta_2 = 1 / 4 * log(1.05691 / 0.926524);
delta_3 = 1 / 5 * log(1.05691 / 0.908117);
delta = 0.033;

% Damping ratio
damp_ratio = 1 / sqrt(1 + (2*pi^2/delta));

% Damping
B2 = 2*damp_ratio*omega_n*J2;
B1 = 0.015;

% Simulate second order system with calculated frequency and damping
H_num =  omega_n^2;
H_den = [1 2*damp_ratio*omega_n  omega_n^2];
sys = tf(H_num, H_den);
impulse(sys, 2.4);

% Save data
%save('Data\stiffness_damping.mat');

% Create state space model
A = [0, 0, 1, 0; 
    0, 0, 0, 1;
    -K/J1, K/J1, -B1/J1, 0;
    K/J2, -K/J2, 0, -B2/J2];

B = [0; 0; 1/J1; 0];


C = [1, 0, 0, 0;
    0, 1, 0, 0];

D = [0; 0];


% Convert to tf
% [num, den] = ss2tf(A, B, C, D);
% sys_sstf = tf(num, den);
% 
% figure();
% impulse(sys_sstf, 2.5)