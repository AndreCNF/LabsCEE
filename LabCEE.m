%% Laboratorios de CEE
%
% Andre Ferreira 81715
% Jose Miragaia 81567
% 

clear all;
load('fp_lin_matrices_fit3.mat');

%% 1

eig_lbd = eig(A);

%%
% One of the eigenvalues has a positive real part, which makes the system
% unstable.

%% 2

Ctr_M = ctrb(A, B);
rank_C = rank(Ctr_M);

%%
% As rank(Controllability matrix) = #(row of A), the system is controllable.

%% 3

% Measure only x3
C1 = [0 0 1 0 0];

% Measure x1 and x3
C2 = [1 0 0 0 0;
      0 0 1 0 0];
  
% Check observability matrix and its rank for case 1
Obsr_M1 = obsv(A, C1);
rank_O1 = rank(Obsr_M1);

% Check observability matrix and its rank for case 2
Obsr_M2 = obsv(A, C2);
rank_O2 = rank(Obsr_M2);

%%
% rank(Observability matrix of case 1) < #(row of A) which means that the
% system isn't observable if the only output is x3.
% rank(Observability matrix of case 2) = #(row of A) which means that the
% system is observable if the output is x1 and x3.

%% 4

% Get numerator and denominator of the transfer function
[NUM,DEN] = ss2tf(A, B, C, D);

% Create the transfer function's system object
sys_alpha = tf(NUM(1, :), DEN);
sys_beta = tf(NUM(2, :), DEN);

% Minimum and maximum frequencies for the bode plot
Wmin = 0;
Wmax = 50;

figure;
bode(sys_alpha);
title('Alpha transfer function bode');

figure;
bode(sys_beta);
title('Beta transfer function bode');
% bode(SYS,{Wmin,WMmax});