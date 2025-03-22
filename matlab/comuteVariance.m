% Simulate variance in time between 3 different ways to travel
% Ethan Greenhouse
% 3/19/2025

%% Initialize
clear;
clc;
close all;

% Number of simulations
numSimulations = 1000;

% Arrays to store trip times
busTimes = [1, numSimulations];
subwayTimes = [1, numSimulations];
carTimes = [1, numSimulations];

% Parameters (mean, standard deviation)
% Bus trip parameters
busWait = [6, 3];
bus96 = [20, 3];
busTransfer = [5, 2];
bus1 = [28, 5];

% Subway trip parameters
subwayWalk = [5, 2];
subwayWait = [10, 2];
subwayRide = [35, 5];

% Car trip parameters
carWalk = [3, 1];
carDrive = [25, 8];
carPark = [5, 2];

%% Simulate 
for i = 1:numSimulations
    % Calculate bus trip time
    busMeans = [busWait(1), bus96(1), busTransfer(1), bus1(1)];
    busStds = [busWait(2), bus1(2), busTransfer(2), bus96(2)];
    busTimes(i) = sum(busMeans + busStds .* randn(1,4)); 
    
    % Calculate subway trip time
    subwayMeans = [subwayWalk(1), subwayWait(1), subwayRide(1), subwayWalk(1)];
    subwayStds = [subwayWalk(2), subwayWait(2), subwayRide(2), subwayWalk(2)];
    subwayTimes(i) = sum(subwayMeans + subwayStds .* randn(1,4));
    
    % Calculate car trip time
    carMeans = [carWalk(1), carDrive(1), carPark(1), carWalk(1)];
    carStds = [carWalk(2), carDrive(2), carPark(2), carWalk(2)];
    carTimes(i) = sum(carMeans + carStds .* randn(1,4));
end

%% Plot 
figure();

% Bus histogram
subplot(3, 1, 1)
histogram(busTimes);
title('Bus Trip Times');
xlabel('Time (min)');
ylabel('Frequency');

% Subway histogram
subplot(3, 1, 2);
histogram(subwayTimes);
title('Subway Trip Times');
xlabel('Time (min)');
ylabel('Frequency');

% Car histogram
subplot(3, 1, 3);
histogram(carTimes);
title('Car Trip Times');
xlabel('Time (min)');
ylabel('Frequency');

%% Display
fprintf('Bus Average = %.2f min, Standard Deviation = %.2f min\n', mean(busTimes), std(busTimes));
fprintf('Subway Average = %.2f min, Standard Deviation = %.2f min\n', mean(subwayTimes), std(subwayTimes));
fprintf('Car Average = %.2f min, Standard Deviation = %.2f min\n', mean(carTimes), std(carTimes));