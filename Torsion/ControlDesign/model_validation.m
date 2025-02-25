%% Post process for model validation q_torsion_val


% Plot model and experimental results
% Plot 1: Theta 1
figure;
hold on;

% Plot data with different line styles and colors
plot(t, theta1(:,1), 'color', [30 167 217] ./ 255, 'LineWidth', 2); % Model (blue, solid line)
plot(t, theta1(:,2), 'linestyle', '-.', 'color', [189 4 115] ./ 255, 'LineWidth', 2); % Experimental (red, dashed line)

% Add labels and title
xlabel('Time (s)', 'FontSize', 12);
ylabel('$\theta_1$ [rad]', 'Interpreter','latex', 'FontSize', 12);
title('$\theta_1$ Model and Experimental Response', 'Interpreter','latex', 'FontSize', 14);

% Add a legend
legend('Model', 'Experimental', 'Location', 'best');

% Add grid
grid on;

% Plot 2: Theta 2
figure;
hold on;

% Plot data with different line styles and colors
plot(t, theta2(:,1), 'color', [30 167 217] ./ 255, 'LineWidth', 2); % Model (blue, solid line)
plot(t, theta2(:,2), 'linestyle', '-.', 'color', [189 4 115] ./ 255, 'LineWidth', 2); % Experimental (red, dashed line)

% Add labels and title
xlabel('Time (s)', 'FontSize', 12);
ylabel('$\theta_2$ [rad]', 'Interpreter','latex', 'FontSize', 12);
title('$\theta_2$ Model and Experimental Response', 'Interpreter','latex', 'FontSize', 14);

% Add a legend
legend('Model', 'Experimental', 'Location', 'best');

% Add grid
grid on;
