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

%% Model 1
% K1 = db2mag(14);
% s = tf('s');
% Hm1 = K1 + (1 + 0*s);
% 
% % Call the simulink file for the model
% Hm = Hm1;
% model_1 = sim('sysID_model.slx');
% model_1_uFFT = fft(model_1.u)/length(model_1.t);
% model_1_yFFT = fft(model_1.y)/length(model_1.t);
% 
% Hm1_experiment = model_1_yFFT ./ model_1_uFFT;
% Hm1_experiment = Hm1_experiment(belowNyquist);
% 
% 
% %% Model 2
% % Calculate Q
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
% semilogx(frequencyVec, db(abs(Hm2_experiment)))
xlabel('Frequency (rad/s)')
ylabel('Amplitude (dB)');
title('Bode Plot')


