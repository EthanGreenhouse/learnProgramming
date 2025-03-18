% Beach Profile Evolution Over Time Calculation
% Ethan Greenhouse
% 3/17/25

clear all; 
clc; 

% Given variables for South Padre Island, Texas
Hb = 0.71;      % Breaking wave height [m]
g = 9.81;       % Gravity [m/s^2]
k = 0.78;       % Breaking ratio
s = 2.65;       % Specific gravity of sediment
p = 0.4;        % Porosity
B = 1.22;       % Berm height [m]
dc = 7.62;      % Closure depth [m]
L = 2000;       % Total length of beach fill [m]

% Calculate G (sediment transport parameter)
G = (k * Hb^(5/2) * sqrt(g / k)) / (8 * (s - 1) * (1 - p) * (dc + B));

%% Part A: Find initial width W for maximum y at x = 0 after 1 year
secondsInYear = 365 * 24 * 3600; % Convert 1 year to seconds
x = 0; % Center location

W = 60; % Initial guess for W [m]

% Calculate width at x = 0 after 1 year
t1A = L / (4 * sqrt(G * secondsInYear)); % Time scaling factor
widthTest = (W / 2) * (erf(t1A * (2 * x / L + 1)) - erf(t1A * (2 * x / L - 1))); % Width calculation

disp(['Guess W: ', num2str(W), ' meters']);
disp(['Calculated width at x = 0 after 1 year: ', num2str(widthTest), ' meters']);

%% Part B: Maximum beach width after 10 years at x = 0
t = 10 * secondsInYear; % Time for 10 years in seconds
t1B = L / (4 * sqrt(G * t)); % Time scaling factor
y10Years = (W / 2) * (erf(t1B * (2 * x / L + 1)) - erf(t1B * (2 * x / L - 1))); % Width calculation

disp(['Maximum width at x = 0 after 10 years: ', num2str(y10Years), ' meters']);

%% Part C: Beach width at the edge of the fill (x = L/2) after 1 year
x_edge = L / 2; % Edge location
t = secondsInYear; % Time for 1 year in seconds
t1C = L / (4 * sqrt(G * t)); % Time scaling factor
yEdge1Year = (W / 2) * (erf(t1C * (2 * x_edge / L + 1)) - erf(t1C * (2 * x_edge / L - 1))); % Width calculation

disp(['Width at x = L/2 after 1 year: ', num2str(yEdge1Year), ' meters']);

%% Part D: Time to fill sand to 4000 m from the centerline
x_4000 = 4000; % Location 4000 m from center

years = 0.661; % Initial guess for time [years]
t_seconds = secondsInYear * years; % Convert years to seconds

% Calculate y at x = 4000
t1D = L / (4 * sqrt(G * t_seconds)); % Time scaling factor
y_at_4000 = (W / 2) * (erf(t1D * (2 * x_4000 / L + 1)) - erf(t1D * (2 * x_4000 / L - 1))); % Width calculation

disp(['Calculated width at x = 4000 after ',num2str(years),' years: ', num2str(y_at_4000), ' meters']);