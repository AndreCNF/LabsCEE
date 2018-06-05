function fp_anim( t, ang1, ang2, options )
%
% Show animation of the Pendulum

% April2018, J. Gaspar

if nargin<1 || isempty(t)
    % get current data
    [t, ang1, ang2, ~]= fp_plot;
end
if nargin<4
    options= [];
end
if ~isfield( options, 'op' )
    options.op= 'anim';
    %options.op= 'snapshots';
    %options.op= 'snapshots2';
end

iRange= calc_range( t, ang1, ang2, options );
figure(201); clf

for ind= 1:length(iRange)
    i= iRange(ind);
    if strcmp(options.op, 'snapshots2')
        subplot(2,4,mod(ind-1,8)+1)
    end
    plot_one_pose( t(i), ang1(i), ang2(i), options )
    if max(get(0,'PointerLocation'))<100, break; end
    drawnow
end

return; % end of main function


function iRange= calc_range( t, ang1, ang2, options )
switch options.op
    case 'anim'
        % iRange= 1:100:length( ang1 );
        % calc step given the range of t
        % k*dt= k*(t2-t1)/N, k*dt=0.1 => k= 0.1/dt= 0.1*N/(t2-t1)
        try
            ks= round(0.1*length(t)/(max(t)-min(t)));
        catch
            ks= 100;
        end
        iRange= 1:ks:length( t );
        
    case {'snapshots', 'snapshots2'}
        iRange= [];
        iRange= add_max_min_indexes( iRange, ang1 );
        iRange= add_max_min_indexes( iRange, ang2 );
        iRange= add_max_min_indexes( iRange, abs(ang1)+abs(ang2) ); % norm1
        iRange= add_max_min_indexes( iRange, sqrt(ang1.*ang1+ang2.*ang2) ); % norm2
        
    otherwise
        error('inv options.op')
end


function iRange= add_max_min_indexes( iRange, ang1 )
[~,ind]= max(ang1); iRange= [iRange ind];
[~,ind]= min(ang1); iRange= [iRange ind];


function plot_one_pose( t, ang1, ang2, options )
Le1 = 227e-3;
Lcm2= 404e-3;

ca= cos(ang1);
sa= sin(ang1);
cb= cos(ang2);
sb= sin(ang2);

% calc wA, wB from ang1, ang2
wA = Le1*[ca sa 0]';

wRa= [ca -sa 0; sa ca 0; 0 0 1];
wTa= wA;
wB = wRa*[0 sb cb]'*Lcm2 + wTa;

M= [zeros(3,1) wA wB];

% start drawing, plot origin to do clear all
plot3(0,0,0,'.');
draw_frame( 0.15, struct('color','c') ); % 15cm XYZ frame

% plot 000->wA->wB
washold= ishold;
hold on
h= plot3( M(1,:), M(2,:), M(3,:), 'b.-' );
set(h, 'LineWidth', 3, 'MarkerSize', 20)
if ~washold
    hold off
end

axis equal
axis([0 1 -1 1 0 1]*.5)
view([40 15])
box on

tStr= sprintf('t= %.1f sec', t);

switch options.op
    case 'anim'
        % nothing
    case 'snapshots'
        hold on
        axis tight
        tStr= '';
    case 'snapshots2'
        axis tight
    otherwise
        error('err inv options.op')
end

title( tStr );

return


function draw_frame(rotTransl, options)
%
% Draw the coordinate system frame {Ox,Oy,Oz} localized by the argument
% "rotTransl", or at the origin if no arguments i.e. rotTransl= eye(4)
%
% Usage:
%    draw_frame
%    draw_frame(scale)
%    draw_frame(rotTransl)
%    draw_frame(scale, options)
%    draw_frame(rotTransl, scale)
%    draw_frame(rotTransl, color)
%    draw_frame(rotTransl, options)
%
% input args:
%    rotTransl: 3x4 or 4x4 : [rot3x3 transl3x1]
%                 if rotTransl 4x4, than the last line is assumed [0 0 0 1]
%    scale: see options
%    color: see options
%
% options input arg is a struct with (optional) fields:
%    scale: 1x1 : scalar to resize the coordinate frame
%    color: str 1x1 or 1x3 : color names for the axis e.g. 'r' or 'rgb'
%    xyztag: 1x1 : (flag) write 'x', 'y', 'z' close to the axis
%    offset: 3x1 or 4x4 : use [eye3 offset]*rotTransl
%

% 15.2.08, JGaspar

% argument #2
if nargin<2
    options= [];
end
if ischar(options)
    options.color= options;
end
if isnumeric(options) && numel(options)==1
    options.scale= options;
end
if ~isfield(options, 'scale')
    options.scale= 1.0;
end

% argument #1
if nargin<1
    rotTransl= eye(4);
end
if numel(rotTransl)==1, % rotTransl is a scalar
    options.scale= rotTransl;
    rotTransl= eye(4);
end

% finaly the drawing
for i=1:size(rotTransl, 3)
    % accept one frame as 4x4
    % or multiple frames as 4x4xn or 3x4xn
    draw_frame_main(rotTransl(:,:,i), options)
end

return; % end of main function


function draw_frame_main(rotTransl, options)
% enforce line 4 (if existing) to be 0001
if size(rotTransl,1)<3 || size(rotTransl,2)<4
    error('rotTransl lines<3 or columns<4')
end
if size(rotTransl,1)>3 && norm(rotTransl(4,1:4)-[0 0 0 1])>eps
    warning('rotTransl 4th line is not [0 0 0 1] - ignoring this line')
end

% apply offset if desired
if isfield(options, 'offset')
    if numel(options.offset)==3
        % offset is 3x1 or 1x3
        rotTransl(1:3,4)= options.offset(:)+rotTransl(1:3,4);
    else
        % offset is 4x4
        rotTransl= options.offset * [rotTransl(1:3,1:4); 0 0 0 1];
    end
end

% the frame extremes
%
z= zeros(3,1);
P= eye(3);
P= options.scale * [z P(:,1) z P(:,2) z P(:,3)];

% reposition of the coordinate frames
%
P= rotTransl(1:3,1:3)*P +repmat(rotTransl(1:3,4),1,size(P,2));

% the drawing commands
%
%plot3(P(1,:),P(2,:),P(3,:))

washold= ishold;
hold on

cstr= {'r', 'g', 'b'};
lstr= {'x', 'y', 'z'};
h= [];
for i=1:length(cstr)
    R= 2*i+[-1 0];
    if ~isfield(options, 'color')
        % use default colors (RGB for XYZ respectively)
        h= [h plot3(P(1,R),P(2,R),P(3,R), cstr{i})];
    else
        % use the color indicated in the options
        cc= options.color;
        if length(cc)==3
            cc= cc(i);
        end
        h= [h plot3(P(1,R),P(2,R),P(3,R), cc)];
    end
    if isfield(options, 'xyztag') && ...
            (isempty(options.xyztag) || options.xyztag==1)
        k= 1.1;
        text(P(1,R(2))*k, P(2,R(2))*k, P(3,R(2))*k, lstr{i})
    end
end

% enlarge the linewidth
%
set(h, 'linewidth', 2)

if ~washold
    hold off
end
