%% initialize breach. Every breach driver script will typically start with
%  this command.
InitBreach;
clc;
clear S;
close all;

%% Initialization 

init_x_pos = init.posNED(1);
init_y_pos = init.posNED(2);
init_z_pos = init.posNED(3);

%%

S = BreachSimulinkSystem('flightControlSystem');


%%

STL_ReadFile('specifications.stl');
fprintf('Checking safe following ..');
robs1 = S.CheckSpec(safeFollowing);