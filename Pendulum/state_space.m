%% Derivation of the state space equations
close all; clear; clc;

%% Constant values
load("Data\constants.mat");

% Create symbolic variables
syms alpha alphaDot theta thetaDot tau;

% Create nonlinear matrix equations
D = [Mp*Lr^2 + Jr, -1/2*Mp*Lp*Lr;
    -1/2*Mp*Lp*Lr, Jp + 1/4*Mp*Lp^2];

C = [Br, 0; 0, Bp];

G = [0; -1/2*Mp*Lp*g*alpha];

T = [tau; 0];


% Solve for second order derivatives
qDoubleDot = inv(D) * (T - C*[thetaDot; alphaDot] - G);

qDoubleDot = vpa(qDoubleDot, 4);


% State space with jacobians
A = [0, 0, 1, 0; 0, 0, 0, 1; double(jacobian(qDoubleDot, [theta, alpha, thetaDot, alphaDot]))];
B = [0; 0; double(jacobian(qDoubleDot, tau))];
C = [1, 0, 0, 0; 0, 1, 0, 0];
D = [0; 0];



%save('Data\stateSpace.mat', 'A', 'B', 'C', 'D');
