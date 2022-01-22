clear all; clc
%% Sensor Normal Vectors
N_B = [1 0; -1 0;        % Normales sensores xp,xn
       0 1; 0 -1]';      % Normales sensores yp,yn

%% Phototransistors determination
Beam_Threshold = 40*5/1023;

%% Control
Theta_target = 0;              % Relative Angle with respect to Incident Light Angle in rad 
Theta_limit = 4*pi/180;
V_wmax = 255;

%% Plot servo stuff
% theta_range = linspace(0, 180, 100);
% PWM_tramo1 = 0; %0<=PWM<60;
% PWM_tramo2 = 97/90 * theta_range + 60; %60<=PWM<=254;
% PWM_tramo3 = 254; %254<PWM<=255
% 
% figure()
% hold on
% plot(theta_range,PWM_tramo2, LineWidth=1.5, Color='k')
% box("on")
% axis([0, 180, 0, 255])
% grid("minor")
% xlabel("Ángulo de giro del servo, \theta [\circ]", "FontSize", 16)
% ylabel("PWM normalized Arduino value",  "FontSize", 16)
% hold off