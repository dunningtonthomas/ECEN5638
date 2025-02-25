% State-space matrices relative to applied torque
A = [0, 0, 1, 0; 
    0, 0, 0, 1;
    -Ks/J1, Ks/J1, -B1/J1, 0;
    Ks/J2, -Ks/J2, 0, -B2/J2];

B = [0; 0; 1/J1; 0];


C = [1, 0, 0, 0;
    0, 1, 0, 0];

D = [0; 0];

% Add actuator dynamics
B = Kg * eta_g * kt * eta_m * B / Rm;
A(3,3) = A(3,3) - Kg*km*B(3);
A(4,3) = A(4,3) - Kg*km*B(4);

% Output eigenvalues
eig(A)

% Save the dynamic model matrices
save('Data\dynamic_model.mat', 'A', 'B', 'C', 'D');


