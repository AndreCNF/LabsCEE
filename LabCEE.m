%% Laboratorios de CEE
%
% Andre Ferreira 81715
% Jose Miragaia 81567
% Jo?o Ornelas 79681
% 
%load('fp_lin_matrices_fit3.mat');

%% Q1

eig_lbd = eig(A);

%%
% One of the eigenvalues has a positive real part, which makes the system
% unstable.

%% Q2

Ctr_M = ctrb(A, B);
rank_C = rank(Ctr_M);

%%
% As rank(Controllability matrix) = #(row of A), the system is controllable.

%% Q3

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

%% Q4

% Get numerator and denominator of the transfer function
[NUM,DEN] = ss2tf(A, B, C, D);

% Create the transfer function's system object
sys_alpha = tf(NUM(1, :), DEN);
sys_beta = tf(NUM(2, :), DEN);

% Minimum and maximum frequencies for the bode plot
Wmin = 0.1;
Wmax = 100000;

figure;
bode(sys_alpha, {Wmin, Wmax});
% title('Alpha transfer function bode');
title('Diagrama de Bode Referente a Alpha');

figure;
bode(sys_beta, {Wmin, Wmax});
% title('Beta transfer function bode');
title('Diagrama de Bode Referente a Beta');

%% Q6

figA = figure;
hold on

figB = figure;
hold on

for i=1:9:10
    for j=1:9:10
        T =10;
        Qr = diag([100*i,1,100*j,1,1]); %Weight Matrix for x in the integral
        Rr = 1; %Weight for the input variable
        K = lqr(A, B, Qr, Rr); %Calculate feedback gain
        %----------------------------------------------------------------------
        % Simulate controller
        x_0=[0.1 0 0 0 0]';% insert here the inital conditions -> id all 0 nothing should happen 
        D1=[0 0 0 0 0]';
        %

        C1 = eye(5);
        T=2; % Time duration of the simulation

        sim('Q6.slx',T);

        figure(figA);
        hold on;
        gg=plot(t,x(:,1));% only plot the 3rd coordinate corresponding to alpha
        set(gg,'LineWidth',1.5)
        gg=xlabel('Time (s)');
        set(gg,'Fontsize',14);
        gg=ylabel('\alpha (rad)');
        set(gg,'Fontsize',14);
        
        figure(figB);
        hold on;
        gg=plot(t,x(:,3));% only plot the 3rd coordinate corresponding to beta
        set(gg,'LineWidth',1.5)
        gg=xlabel('Time (s)');
        set(gg,'Fontsize',14);
        gg=ylabel('\beta (rad)');
        set(gg,'Fontsize',14);
    end
end

figure(figA);
legend('100; 100', '100; 1000', '1000; 100', '1000; 1000');

figure(figB);
legend('100; 100', '100; 1000', '1000; 100', '1000; 1000');

%% Q8

figure
T =10;
ganho = 2;
Qr = diag([100*ganho,1,100*ganho,1,1]); %Weight Matrix for x in the integral
Rr = 1; %Weight for the input variable
K = lqr(A, B, Qr, Rr);

G = eye(size(A)); %Gain of the process noise
Qe = eye(size(A))*300; %Variance of process errors
Re = eye(2); %Variance of measurement errors
L = lqe(A, G, C, Qe, Re); %Calculate estimator gains


D1=[0 0 0 0 0;0 0 0 0 0]';
D2 =D';
A2 = A-B*K-L*C;
C2 = -K;
B2 = L;
D3 = [D D];

% The observer.slx is essentially the same as the block diagram asked for
% in question 8, with the difference that it's also outputing to matlab the
% estimations of the angles alpha and beta from the observer.
nome = sim('observer.slx',T); 

gg=plot(t,y); % only plot the 3rd coordinate corresponding to beta
set(gg,'LineWidth',1.5);
gg=xlabel('Time (s)');
set(gg,'Fontsize',14);
gg=ylabel('angles (rad)');
set(gg,'Fontsize',14);
gg = legend('alfa','beta');
set(gg,'Fontsize',14);

figure
hold on

plot(t,y-y2)
legend('alfa','beta')

y_ref = 0;
mean(i,:) = sum((y-y_ref).^2);

eig(A-L*C)
eig(A-B*K)
track_error=y(end)-y_ref;


%% Q9

x_0=[0.1 0 0 0 0]';

for i= 1:50
    for j= 1:20
        T =10;
        Qr = diag([100*i,1,100*j,1,1]); %Weight Matrix for x in the integral
        Rr = 1; %Weight for the input variable
        K = lqr(A, B, Qr, Rr);
        
        G = eye(size(A)); %Gain of the process noise
        Qe = eye(size(A))*300; %Variance of process errors
        Re = eye(2); %Variance of measurement errors
        L = lqe(A, G, C, Qe, Re); %Calculate estimator gains
        
        D1=[0 0 0 0 0;0 0 0 0 0]';
        D2 =D';
        A2 = A-B*K-L*C;
        C2 = -K;
        B2 = L;
        D3 = [D D];
        D_obs = 0;
        sim('observer.slx',T);
        mean = sum(y.^2);
        mean_array(i, j) = mean(1)+mean(2);
    end
end

surf(mean_array);
xlabel('0.01*Q_{r_{11}}');
ylabel('0.01*Q_{r_{33}}');