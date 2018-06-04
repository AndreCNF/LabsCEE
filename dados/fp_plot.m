function [t, ang1, ang2, ctrl_u]= fp_plot( op, a1 )
% Run this after fp_ini.m and one of fp_*.slx
% to obtain plots, or simply the signals

% March2017, April2018 (both in/out args), J. Gaspar

% tipical behaviour is ploting or getting signals
if nargin<1 && nargout<1
    fp_plot_signals;
    % work done, terminate function
    return;
end

if nargin<1
    op= '';
end
if nargin<2
    a1= '';
end

% more operations asked via arg 'op'
switch op
    case 'save'
        fp_plot_data_save
    case 'load'
        fp_plot_data_load( a1 )
    case {'anim', 'snapshots', 'snapshots2'}
        fp_anim( [],[],[], struct('op',op) );
    otherwise
        %error('invalid op')
        % do nothing
end

if nargout>1
    % return signals
    [t, ang1, ang2, ctrl_u]= fp_get_signals;
end

return; % end of main function


% -----------------------------------------------------
function [t, ang1, ang2, ctrl_u]= fp_get_signals
if ~evalin('base','exist(''pendulum'',''var'')')
    error('No data found: please *run* simulation or *load* simulation result')
end
pendulum= evalin('base', 'pendulum');
t= pendulum.time;
ang1= pendulum.signals(1).values(:,1);
ang2= pendulum.signals(1).values(:,2);
ctrl_u= pendulum.signals(2).values;


function fp_plot_signals
[t, ang1, ang2, ctrl_u]= fp_get_signals;
figure(gcf);

washold= ishold; hold on
subplot(211); plot(t,ang1,'b', t,ang2,'m')
xlabel('t [sec]'); ylabel('ang [rad]')
if ~washold, hold off; end

washold= ishold; hold on
subplot(212); plot(t,ctrl_u,'b')
xlabel('t [sec]'); ylabel('u [V]')
if ~washold, hold off; end


% -----------------------------------------------------
function fname= mk_fname
[y,m,d,h,mi,s]= datevec(now);
fname= sprintf('z_fp_data_%02d%02d%02d__%02d%02d%02d.mat', ...
    rem(y,100), m, d, ...
    h, mi, round(s) );


function fp_plot_data_save
% create filename to save data
fname= mk_fname;
if exist(fname, 'file')
    str= questdlg(['Save file "' fname '" exists. Overwrite?'], ...
        'overwrite', 'Yes','No','No');
    if strcmp(str, 'No')
        disp('-- Canceled overwrite output file.')
        return
    end
end
% finally save data to z_fp_data_*.mat
pendulum= evalin('base', 'pendulum');
save(fname, 'pendulum')
fprintf(1, '-- Pendulum data saved to "%s"\n', fname);


function fp_plot_data_load( fname )
if nargin<1
    fname= '';
end
if isempty(fname)
    % find all z_fp_data_*.mat
    fname= uigetfile('z_fp_data_*.mat', 'Load file "z_fp_data_*.mat"');
end
load( fname, 'pendulum' );
assignin( 'base', 'pendulum', pendulum );
fprintf(1, '-- Pendulum data loaded from "%s"\n', fname);
