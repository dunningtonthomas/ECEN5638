%% Post Analysis File

%% Simulate model
K = 0.7112;
tau = 0.4348;
s = tf('s');
H_base = K / (s * (tau*s + 1));
Kp = 20;
Kd = 3;
Ki = 2;

% Simulate 
step_response = sim('pid_model.slx');

% Plot response
figure();
plot(t, thetaL, 'color', [30 167 217] ./ 255, 'LineWidth', 1.5);  % Plot thetaL with blue solid line
hold on
plot(t, thetaR, 'r--', 'LineWidth', 1.5); % Plot thetaR with red dashed line
plot(t_exp, thetaL_exp, 'color', [129 9 227] ./ 255, 'LineWidth', 1.5)

title('Step Response of \theta_L and \theta_R', 'FontSize', 14);
xlabel('Time (seconds)', 'FontSize', 12);
ylabel('Angle (radians)', 'FontSize', 12);
legend({'\theta_L', '\theta_R', '\theta_L EXP'}, 'Location', 'Best', 'FontSize', 12);
grid on;