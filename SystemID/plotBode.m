function plotBode(uFFT, yFFT)
%PLOTBODE Given a uFFT and yFFT plot a Bode plot

% Define the transfer function
H = yFFT ./ uFFT;

% Bode Plot
figure();
semilogx(frequencyVec, db(abs(H)))
grid on
xlabel('Frequency (rad/s)')
ylabel('Amplitude (dB)');
title('Bode Plot')


end

