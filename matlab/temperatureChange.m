% Hot drink in cold fridge: When will it reach an enjoyable drinking temperature?
% Assumptions: Small temperature difference, constant surroundings, even cooling
% Ethan Greenhouse
% 3/11/25

%% Initialize
clear all; 
clc;

% Declare variables
T0 = 120;       % Initial temperature [degF]
Ts = 38;        % Fridge temperature [degF]
k = 0.45;       % Heat transfer constant [1/hr]
time = 1:24;    % Time vector [hr]
e = exp(1);     % Euler's constant

%% Calculations
figure; 
hold on;

% Calculate temperature using Newton's Law of Cooling
temp = Ts + (T0 - Ts) * exp(1).^(-k * time); % Temperature over time
fprintf('The temperature at %.1f hours is %.2f degrees F.\n', time, temp);

% Plot temperature vs. time
plot(time, temp);               % Plot data
title('Temperature vs. Time');  % Plot title
xlabel('Time');                 % X-axis label
ylabel('Temperature');          % Y-axis label