%% CONFIG_TORSION_1D
%
% Returns the configuration-dependent model parameters of the Quanser
% One-Degree-Of-Freedom (DOF) Torsion module.
%
% Input Parameters:
% DISC_POSITION     Position of disc.
%
% Output Parameters:
% J2        Equivalent Moment of Inertia, 
%               as seen at the Torsion Module Load shaft    (kg.m^2)
% B2        Equivalent Viscous Damping Coefficient 
%               as seen at the Torsion module load shaft    (N.m.s/rad)
%
% Copyright (C) 2009 Quanser Consulting Inc.
% Quanser Consulting Inc.
%%
%
function [ J2, B2 ] = config_torsion_1d( DISC_POSITION )
    % load support bar length (m)
    Lb = 0.102;
    % load support bar mass (kg)
    Mb = 0.021;
    % load support bar inertia (kg.m^2)
    Jb = Mb * Lb^2 / 12; % = 1.8207e-005
    % disc weight mass (kg)
    Mw = 0.123;
    % disc weight diameter (m)
    Dw = 0.038; % = 1.5"
    % disc weight inertia about its cog (kg.m^2)
    Jw_cog = Mw * ( Dw / 2 )^2 / 2; % = 2.2202e-005
    % inertial disc position on support arm
    % distance from the pivot axis to disc cog (m)
    % position symmetry of the 2 discs is assumed
    if strcmp ( DISC_POSITION, 'A' )
        dpw = 44.3e-3;
    elseif strcmp ( DISC_POSITION, 'B' )
        dpw = 31.7e-3;
    else
        error( 'Error: Set the positions of the inertial load discs.' )
    end
    % disc weight inertia about pivot (kg.m^2)
    Jw_piv = Jw_cog + Mw * dpw^2; % = 2.6359e-004
    % total load inertia (kg.m^2)
    J2 = Jb + 2 * Jw_piv; % = 5.4538e-004
    % Flexible Coupling Equivalent Viscous Damping Coefficient
    % as seen at the Torsion module load shaft (N.m.s/rad)
    % -- found experimentally
    B2 = 0.0015;
end
