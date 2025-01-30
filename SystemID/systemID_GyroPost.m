%% Post Processing

%% FFT
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

%% Servo Base Unit 
K = 1.53;
tau = 0.0486;
s = tf('s');
H_base = K / (s * (tau*s + 1));
Hm = H_base;
model_sb = sim('sysID_model.slx');
model_sb_uFFT = fft(model_sb.u)/length(model_sb.t);
model_sb_yFFT = fft(model_sb.y)/length(model_sb.t);

Hmsb_experiment = model_sb_yFFT ./ model_sb_uFFT;
Hmsb_experiment = Hmsb_experiment(belowNyquist);


%% Model 1
% K1 = db2mag(-6.567);
% omega_0 = 1.657;
K1 = db2mag(-0.6132);
omega_0 = 0.8377;
s = tf('s');
Hm1 = K1 * (omega_0 / s);

% Call the simulink file for the model
Hm = Hm1;
model_1 = sim('sysID_model.slx');
model_1_uFFT = fft(model_1.u)/length(model_1.t);
model_1_yFFT = fft(model_1.y)/length(model_1.t);

Hm1_experiment = model_1_yFFT ./ model_1_uFFT;
Hm1_experiment = Hm1_experiment(belowNyquist);

%% Model 2
omega_1 = 1.972;
Hm2 = K1 * (omega_0 * omega_1 / (s * (s + omega_1)));
Hm = Hm2;
model_2 = sim('sysID_model.slx');
model_2_uFFT = fft(model_2.u)/length(model_2.t);
model_2_yFFT = fft(model_2.y)/length(model_2.t);

Hm2_experiment = model_2_yFFT ./ model_2_uFFT;
Hm2_experiment = Hm2_experiment(belowNyquist);


%% Model 2
% Calculate Q
% Qm2 = db2mag(31 - 14);
% wm1 = 2.09;
% 
% % Create a more refined transfer function
% Hm2 = Hm1 * 1 / (s^2 / wm1^2 + s / (Qm2*wm1) + 1);
% 
% % Call simulink
% Hm = Hm2;
% model_2 = sim('sysID_model.slx');
% model_2_uFFT = fft(model_2.u)/length(model_2.t);
% model_2_yFFT = fft(model_2.y)/length(model_2.t);
% Hm2_experiment = model_2_yFFT ./ model_2_uFFT;
% Hm2_experiment = Hm2_experiment(belowNyquist);

%% Save Data
% save('SysID_Data\goodData2.mat')
% 


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
% semilogx(frequencyVec, db(abs(Hm1_experiment)))
% semilogx(frequencyVec, db(abs(Hmsb_experiment)))
% semilogx(frequencyVec, db(abs(Hm2_experiment)))
xlabel('Frequency (rad/s)')
ylabel('Amplitude (dB)');
title('Bode Plot')
legend('Experiment', 'First Order Fit', 'Second Order Fit')

figure();
semilogx(frequencyVec, rad2deg(angle(H)))


