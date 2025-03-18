% Ball Drop Experiment: Compare Experimental and Theoretical Data
% Ethan Greenhouse
% 3/17/25

clear all;
clc;

% Experimental Data
time_exp = [0.0300, 0.0633, 0.0967, 0.1300, 0.1633, 0.1967, 0.2300, 0.2633, 0.2967]; % Experimental time points [s]
height_exp = [22.0, 21.5, 20.5, 18.8, 17.0, 14.5, 12.0, 8.0, 3.0]; % Experimental height measurements [in]

% Theoretical Values
g = 386.4; % Acceleration due to gravity [in/s^2]
time_theo = linspace(0, 0.3, 100); % Time vector for theoretical calculation
height_theo = 22 - 0.5 * g * time_theo.^2; % Theoretical height using free-fall equation

% Plotting
figure; 
plot(time_exp, height_exp, 'ro', 'DisplayName', 'Experimental Data'); % Plot experimental data
hold on;
plot(time_theo, height_theo, 'b', 'DisplayName', 'Theoretical Values'); % Plot theoretical curve

% Title and Labels
title('Experimental vs. Theoretical Height'); % Plot title
xlabel('Time [s]'); % X-axis label
ylabel('Height [in]'); % Y-axis label
legend('Location', 'best'); % Add legend

% Axis Limits
xlim([0, 0.3]); % Set x-axis limits
ylim([0, 23]); % Set y-axis limits