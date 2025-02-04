%% D_PI_GYRO
%
% Designs a proportional-integral (PI) position controller for the SRV02 
% Gyroscope plant based on the desired damping ratio and natural frequency
% specifications.
%
% ************************************************************************
% Input paramters:
% K         Model steady-state gain                             (rad/s/V)
% tau       Model time constant                                 (s)
% Gg        Gyroscope sensitivity                               (Hz) 
% zeta      Damping ratio 
% wn        Natural frequency                                   (rad/s)
%
% ************************************************************************
% Output parameters:
% kp        Proportional gain                       (V/rad)
% kd        Derivative gain                         (V-s/rad)
%
% Copyright (C) 2012 Quanser Consulting Inc.
% Quanser Consulting Inc.
%%
function [kp,kd] = d_gyro_pd(K, tau, Gg, zeta, wn)
    % Proportional gain (V/rad)
    kp = wn^2/K*Gg*tau;
    % Derivative gain (V-s/rad)
    kd = Gg*(2*zeta*wn*tau -1)/K;
end
