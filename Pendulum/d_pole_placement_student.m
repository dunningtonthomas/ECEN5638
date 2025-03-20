% IMPORTANT: Make sure you run setup_rotpen.m first. You need the (A,B)
% state-space matrices.
%
% close all; clear; clc;
%% Load state space
load('Data\stateSpace.mat');

%% Find desired poles
% zeta = 0.7;
% wn = 4;
zeta = 0.7;
wn = 4;
p1 = -zeta*wn + 1j*wn*sqrt(1-zeta^2);
p2 = -zeta*wn - 1j*wn*sqrt(1-zeta^2);
p3 = -30;
p4 = -40;
desired_poles = [p1; p2; p3; p4];

%% Find Tranformation Matrix W
% Characteristic equation: s^4 + a_4*s^3 + a_3*s^2 + a_2*s + a_1
a = poly(A);
% 
% Companion matrices (Ac, Bc)
Ac = [  0 1 0 0;
        0 0 1 0;
        0 0 0 1;
        -a(5) -a(4) -a(3) -a(2)];
%
Bc = [0; 0; 0; 1];
%
% Controllability
T = ctrb(A, B);
% Controllability of companion matrices
Tc = ctrb(Ac, Bc);
% Transformation matrices
W = T*inv(Tc);
%

% Desired characteristic equation
syms s;
des_char = (s - p3)*(s - p4)*(s - (p1))*(s - (p2));
des_char = simplify(des_char);
[coeffs_vector, powers] = coeffs(des_char, s);
coeffs_vector = double(coeffs_vector);

% Companion state-feedback control gain
Kc = flip(coeffs_vector(2:end)) + Ac(4,:);

% Test closed loop poles
A_closed_test = Ac - Bc*Kc;
[~, cls_poles_test] = eig(A_closed_test);


% Convert back from companion form
K_other = Kc*inv(W);
%

% Test closed loop poles
A_closed_test_2 = A - B*K_other;
[~, cls_poles_test_2] = eig(A_closed_test_2);


%% Find Gain Using Place

% Use Place to find the K matrix
K = place(A, B, desired_poles);

%% Closed-loop System Poles
% Find poles of closed-loop system. 
A_closed = A - B*K;


% Verify that they are the same as the desired poles.
[~, cls_poles] = eig(A_closed);
