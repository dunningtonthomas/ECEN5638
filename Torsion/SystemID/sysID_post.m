%% Post Processing
% Load Data
% load('SysID_Data\goodData.mat');

%% Process Experimental Data
% Compute the FFT
uFFT = fft(u)/length(t);
yFFT = fft(y)/length(t);

% Frequency vector
frequencyVec = 0:2*pi/T:2*pi*(1/Ts - 1/T);

% Truncate everything to be below the nyquist frequency
belowNyquist = frequencyVec <= N*2*pi/T;
uFFT = uFFT(belowNyquist);
yFFT = yFFT(belowNyquist);
frequencyVec = frequencyVec(belowNyquist);

% Define the transfer function
H = yFFT ./ uFFT;

%% First Order Fit
K = db2mag(15);
omega0 = 0.419;
s = tf('s');
H_base = K * omega0 / s;
Hm = H_base;
model_sb = sim('sysID_model.slx');
model_sb_uFFT = fft(model_sb.u)/length(model_sb.t);
model_sb_yFFT = fft(model_sb.y)/length(model_sb.t);

Hm_first = model_sb_yFFT ./ model_sb_uFFT;
Hm_first = Hm_first(belowNyquist);


%% Plotting
figure();
plot(t, u, 'linewidth', 2, 'color', 'b')
grid on;
grid minor;
hold on;
plot(t, y, 'linewidth', 2, 'color', 'r')
xlabel('Time (s)')
ylabel('Signal (V)')
title('Signals')
legend('Input', 'Output')

% FFT Plot
figure();
stem(frequencyVec, abs(uFFT), 'filled')
hold on;
stem(frequencyVec, abs(yFFT), 'filled')
xlabel('Frequency (rad/s)')
ylabel('Amplitude');
title('FFT')

% Bode Plot
figure();
semilogx(frequencyVec, db(abs(H)))
grid on
hold on
semilogx(frequencyVec, db(abs(Hm_first)))

xlabel('Frequency (rad/s)')
ylabel('Amplitude (dB)');
title('Bode Plot')
legend('Experiment')

figure();
semilogx(frequencyVec, rad2deg(angle(H)))

