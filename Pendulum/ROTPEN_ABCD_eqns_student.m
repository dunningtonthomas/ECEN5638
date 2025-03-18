% State Space Representation
load('Data\constants.mat');
load('Data\stateSpace.mat');

% Add actuator dynamics
% A(3,3) = A(3,3) - Kg^2*kt*km/Rm*B(3);
% A(4,3) = A(4,3) - Kg^2*kt*km/Rm*B(4);
% B = Kg * kt * B / Rm;
%%%%%%% ALREADY ADDED IN stateSpace.mat

system = ss(A,B,C,D);

% Poles
[vec, val] = eig(A);