%% Run after an experiment with q_rotpen_swingup_student.slx

%% 

% Tracking
% Tracking
figure;
sgtitle('Full State Response')

% Color for all plots
plotColor = [0, 0.4470, 0.7410]; % Default blue color in MATLAB

% Plot Theta (deg)
subplot(4,1,1)
plot(t_final, 180/pi.*x_final(:,1), 'LineWidth', 2, 'Color', plotColor); % Same color for all plots
grid on;
ylabel('$\theta$ (deg)', 'Interpreter', 'latex', 'FontSize', 12);
set(gca, 'FontSize', 12);

% Plot Alpha (deg)
subplot(4,1,2)
plot(t_final, 180/pi.*x_final(:,2), 'LineWidth', 2, 'Color', plotColor); % Same color for all plots
grid on;
ylabel('$\alpha$ (deg)', 'Interpreter', 'latex', 'FontSize', 12);
set(gca, 'FontSize', 12);

% Plot ThetaDot (rad/s)
subplot(4,1,3)
plot(t_final, x_final(:,3), 'LineWidth', 2, 'Color', plotColor); % Same color for all plots
grid on;
ylabel('$\dot{\theta}$ (rad/s)', 'Interpreter', 'latex', 'FontSize', 12);
set(gca, 'FontSize', 12);

% Plot AlphaDot (rad/s)
subplot(4,1,4)
plot(t_final, x_final(:,4), 'LineWidth', 2, 'Color', plotColor); % Same color for all plots
grid on;
ylabel('$\dot{\alpha}$ (rad/s)', 'Interpreter', 'latex', 'FontSize', 12);
xlabel('Time (s)', 'FontSize', 12);
set(gca, 'FontSize', 12);
