load('fp_lin_matrices_fit3.mat')

Qr = diag([10,0,1,0,0]); %Weight Matrix for x in the integral
Rr = 1; %Weight for the input variable
K = lqr(A, B, Qr, Rr); %Calculate feedback gain
%----------------------------------------------------------------------
% Simulate controller
x_0=[0.1 0 0 0 0]';% insert here the inital conditions -> id all 0 nothing should happen 
%D=[0 0 0 0 0]';
%%

% C = eye(5);
T=2; % Time duration of the simulation

% nom;e = sim('basic.slx',T)
% 
% gg=plot(t,x(:,3));% only plot the 3rd coordinate corresponding to beta
% set(gg,'LineWidth',1.5)
% gg=xlabel('Time (s)');
% set(gg,'Fontsize',14);
% gg=ylabel('\beta (rad)');
% set(gg,'Fontsize',14);




%%


G = eye(size(A)); %Gain of the process noise
Qe = eye(size(A))*10; %Variance of process errors
Re = eye(2); %Variance of measurement errors
L = lqe(A, G, C, Qe, Re); %Calculate estimator gains

D2 =D';

nome = sim('two.slx',T);

gg=plot(t,y);% only plot the 3rd coordinate corresponding to beta
set(gg,'LineWidth',1.5);
gg=xlabel('Time (s)');
set(gg,'Fontsize',14);
gg=ylabel('angles (rad)');
set(gg,'Fontsize',14);
gg = legend('alfa','beta');
set(gg,'Fontsize',14);



