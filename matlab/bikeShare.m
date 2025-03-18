% Bike Share Rounding Comparison 
% Compares round, ceil, and floor on the number of bikes in each location from one day to the next
% Ethan Greenhouse
% 3/10/25

%% Initialize
clear;
clc; 

% Initial number of bikes
bostonBikes = [100, 100, 100]; % [round, ceil, floor]
cambridgeBikes = [100, 100, 100]; % [round, ceil, floor]

% Number of days to simulate
days = 30;

% Matrices to store results for plotting
bostonBikes_history = zeros(3, days); % Rows: round, ceil, floor
cambridgeBikes_history = zeros(3, days); % Rows: round, ceil, floor

%% Simulate
for day = 1:days
    % Calculate bike transfers for each rounding method
    bostonToCambridge = [round(bostonBikes(1) * 0.05), ceil(bostonBikes(2) * 0.05), floor(bostonBikes(3) * 0.05)];
    cambridgeToBoston = [round(cambridgeBikes(1) * 0.03), ceil(cambridgeBikes(2) * 0.03), floor(cambridgeBikes(3) * 0.03)];
    
    % Update bike counts
    bostonBikes = bostonBikes - bostonToCambridge + cambridgeToBoston;
    cambridgeBikes = cambridgeBikes + bostonToCambridge - cambridgeToBoston;
    
    % Store results for plotting
    bostonBikes_history(:, day) = bostonBikes;
    cambridgeBikes_history(:, day) = cambridgeBikes;
end

%% Plot
% Plots bikes in Boston vs. Days
figure;
plot(1:days, bostonBikes_history(1, :), 'b'); % Round
hold on;
plot(1:days, bostonBikes_history(2, :), 'r'); % Ceil
plot(1:days, bostonBikes_history(3, :), 'g'); % Floor
title('Number of Bikes in Boston Over Time');
xlabel('Day');
ylabel('Number of Bikes');
legend('Round', 'Ceil', 'Floor');

% Plots bikes in Cambridge vs. Days
figure;
plot(1:days, cambridgeBikes_history(1, :), 'b'); % Round
hold on;
plot(1:days, cambridgeBikes_history(2, :), 'r'); % Ceil
plot(1:days, cambridgeBikes_history(3, :), 'g'); % Floor
title('Number of Bikes in Cambridge Over Time');
xlabel('Day');
ylabel('Number of Bikes');
legend('Round', 'Ceil', 'Floor');