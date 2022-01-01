clear all; clc
%% 2-D or 3-D Determination
dim = '2D';
if dim == '2D'
    n_sensors = 4;
    N_B = [1 0; -1 0;       %Normales sensores xp,xn
           0 1; 0 -1];      %Normales sensores yp,yn
elseif dim == '3D'
    n_sensors = 6;
    N_B = [1 0 0; -1 0 0;   %Normales sensores xp,xn
          0 1 0; 0 -1 0;    %Normales sensores yp,yn
          0 0 1; 0 0 -1];   %Normales sensores zp,zn
end

%% Phototransistors determination
Beam_Mod = 1013.21*5/1023*ones(n_sensors,1);           %[V]
Beam_Threshold = 97*5/1023;%*ones(n_sensors,1);

%% Control
Theta_rel = 0;              %Relative Angle with respect to Incident Light Angle in rad 

%% Prueba en ordenador
theta = 40*pi/180;
Vxp = Beam_Mod(1)*cos(theta);
Vxn = Beam_Threshold;
Vyp = Beam_Mod(3)*sin(theta);
Vyn = Beam_Threshold;

V_test = [Vxp,Vxn,Vyp,Vyn];