% Calculates the factorial of a number less than or equal to 21
% Ethan Greenhouse
% 3/10/25

%% Initialize
clc; 
clear all; 

largest = 21; % Largest number for which factorial can be calculated
input = 10; % Change value to calculate the factorial

%% Calculate
for n = 1:input
    result = 1; % Result for current number
    % Calculate factorial
    for k = 1:n
        result = result * k; % Multiply to compute factorial
    end
    actualResult = factorial(n); % Compute factorial using built-in function
    error = (actualResult - result) / actualResult; % Calculate relative error
end