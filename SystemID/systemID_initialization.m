%% Initialization
close all; clear; clc;

%% Input Signal
T = 15;
Ts = 0.002;
Ttrans = 60;
K = 5;
N = 100; % Number of frequencies we want to excite in the system
omega0 = 50;

% Experiment parameters
w1e = 2;
w2e = 10;
Q1e = 10;
Ke = 5;

