%
%% CONFIG_GYRO
%
% Sets up and returns the SRV02 Gyroscope model variables.
%
% Copyright (C) 2010 Quanser Consulting Inc.
% Quanser Consulting Inc.
%
%%
function [ G_g ] = config_gyro( )
    % nominal gyroscope motor voltage (V)
    Vgm = 12; 
    % gyro motor resistance (ohms)
    Rgm = 5.3; 
    % nominal current (A)
    Igm = 0.23;
    % back-emf constant (V.s/rad)
    Kgm = 0.0235;
    % speed of disk at steady-state
    wg = (Vgm - Igm*Rgm)/Kgm; 
    % mass of disk (kg)
    mf = 0.8; 
    % radius of disk (m)
    rf = 2*0.0254;          
    % flywheel moment of inertia about spin axis (kg.m^2)
    Jf = mf*rf^2/2; 
    % flywheel moment of inertia about spin axis (kg.m^2)
%     Jt = 0.002; 
    % momentum of disk (kg.m^2/s)
    Lf = Jf*wg; 
    % distance between axis and spring (m)
    R = 1*0.0254; 
    % spring stiffness (N/m)
    Ks = 1.9089e3; 
    % rotational stiffness (N.m/rad)
    Kr = 2*R^2*Ks; 
    % gyroscope sensitivity (deg/s/deg);
    G_g = Kr / Lf;
end
