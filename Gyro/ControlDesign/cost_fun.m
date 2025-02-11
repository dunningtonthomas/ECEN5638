function J = cost_fun(gain)
% Extract Gains
global Kp Ki Kd;
Ki = gain(1);
Kd = gain(2);
Kp = gain(3);

% Define Weights
w_rt = 2;
w_st = 5;
w_os = 3; 
w_ess = 5;
% Initialize Cost
J = 0;

% Define Transfer Function
% K = 0.7112;
% tau = 0.4348;
% s = tf('s');
% H_base = K / (s * (tau*s + 1));
% controller_tf = @(Kp, Ki, Kd) Kp + Ki / s + Kd*s;
% thetaR_thetaL_tf = H_base * controller_tf(Kp, Ki, Kd) / (1 + H_base * controller_tf(Kp, Ki, Kd));
% 
% % Step info
% stepInfo = stepinfo(thetaR_thetaL_tf);

% Simualte gains
optimal_step_response = sim('pid_model.slx');
stepInfo = stepinfo(thetaL,t);
% Step Info
rt = stepInfo.RiseTime;
st = stepInfo.SettlingTime;
os = stepInfo.Overshoot;
e_ss = abs(1 - thetaL(end));  % Final value error

% Calculate Cost
J = w_rt * rt^2 + w_st * st^2 + w_os * os^2 + w_ess * e_ss^2;
end

