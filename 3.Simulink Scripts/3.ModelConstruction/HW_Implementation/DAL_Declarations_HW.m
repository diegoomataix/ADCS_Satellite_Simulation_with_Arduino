clear all; clc
%% Sensor Normal Vectors
N_B = [1 0; -1 0;        % Normales sensores xp,xn
       0 1; 0 -1]';      % Normales sensores yp,yn

%% Phototransistors determination
Beam_Threshold = 100*5/1023;

%% Control
Theta_target = 0;              % Relative Angle with respect to Incident Light Angle in rad 
Theta_limit = 4*pi/180;
V_wmax = 255;
