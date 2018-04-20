load('fp_lin_matrices_fit3.mat'); %%Load Matrices A, B, C, D

MOTOR_SAT = 5;
TH1_BOUND = 120*pi/180;
TH2_BOUND = 30*pi/180;
TIME_DELAY = 6;

Qr = diag([10,0,1,0,0]); % Weight Matrix for x in the integral
Rr = 1e0;                % Weight for the input variable

K = lqr(A, B, Qr, Rr);   % Compute the feedback gain

G = eye(size(A));         % Weight of the process noise
Qe = eye(size(A))*1e3;    % Variance of process errors
Re = eye(2);              % Variance of measurement errors

L = lqe(A, G, C, Qe, Re); % Compute the estimator gains
