% Simulates and generates a bracket for March Madness
% Ethan Greenhouse
% 3/20/2025

clear all;
clc;

%% Load teams
south = {'Auburn', 'Michigan St', 'Iowa St', 'Texas AM', 'Michigan', 'Mississippi', 'Marquette', 'Louisville', 'Creighton', 'New Mexico', 'North Carolina', 'San Diego', 'Yale', 'Lipscomb', 'Bryant', 'Alabama St'};
west = {'Florida', "St Johns", 'Texas Tech', 'Maryland', 'Memphis', 'Missouri', 'Kansas', 'UConn', 'Oklahoma', 'Arkansas', 'Drake', 'Colorado St', 'Grand Canyon', 'NC Wilmington', 'Omaha', 'Norfolk St'};
east = {'Duke', 'Alabama', 'Wisconsin', 'Arizona', 'Oregon', 'BYU', "Saint Marys", 'Mississippi St', 'Baylor', 'Vanderbilt', 'VCU', 'Liberty', 'Akron', 'Montana', 'Robert Morris', 'Mt St Marys'};
midwest = {'Houston', 'Tennessee', 'Kentucky', 'Purdue', 'Clemson', 'Illinois', 'UCLA', 'Gonzaga', 'Georgia', 'Utah St', 'Xavier', 'McNeese', 'High Point', 'Troy', 'Wofford', 'SIU Edward'};
allTeams = [south, west, east, midwest];

%% Load stats
offensiveEfficiency = readtable('offensiveEfficiency.csv');
offensiveEfficiency.Properties.VariableNames = {'Team', 'oEff'};

defensiveEfficiency = readtable('defensiveEfficiency.csv');
defensiveEfficiency.Properties.VariableNames = {'Team', 'dEff'};

possessionsPerGame = readtable('possessionsPerGame.csv');
possessionsPerGame.Properties.VariableNames = {'Team', 'poss'};

winPercentCloseGames = readtable('winPercentCloseGames.csv');
winPercentCloseGames.Properties.VariableNames = {'Team', 'winPct'};

%% Match team with stat
teamStats = struct();

function stats = findTeamStats(teamName, csvData)
    row = find(strcmpi(csvData.Team, teamName));
    if ~isempty(row)
        stats = csvData.(csvData.Properties.VariableNames{2})(row);
    else
        stats = NaN;
        warning('Team "%s" not found in CSV data.', teamName);
    end
end

% Loop through all teams and stores their stats
for i = 1:length(allTeams)
    teamName = allTeams{i};
    seed = mod(i-1, 16) + 1; % Calculate seed (1-16) based on position
    offEff = findTeamStats(teamName, offensiveEfficiency);
    defEff = findTeamStats(teamName, defensiveEfficiency);
    poss = findTeamStats(teamName, possessionsPerGame);
    winPct = findTeamStats(teamName, winPercentCloseGames);
    
    % Store stats in structure
    teamStats.(matlab.lang.makeValidName(teamName)) = struct('OffensiveEfficiency', offEff, 'DefensiveEfficiency', defEff, 'PossessionsPerGame', poss, 'WinPctCloseGames', winPct, 'Seed', seed);
end

%% Simulation functions
function winner = simulateGame(team1, team2, teamStats)
    % Calculate win probability based on team stats
    team1Strength = teamStats.(matlab.lang.makeValidName(team1)).OffensiveEfficiency - teamStats.(matlab.lang.makeValidName(team2)).DefensiveEfficiency;
    team2Strength = teamStats.(matlab.lang.makeValidName(team2)).OffensiveEfficiency - teamStats.(matlab.lang.makeValidName(team1)).DefensiveEfficiency;
    
    % Adjust for possessions and close game performance
    team1Strength = 0.05 * (team1Strength + (teamStats.(matlab.lang.makeValidName(team1)).PossessionsPerGame - teamStats.(matlab.lang.makeValidName(team2)).PossessionsPerGame));
    team1Strength = 2 * (team1Strength + (teamStats.(matlab.lang.makeValidName(team1)).WinPctCloseGames - teamStats.(matlab.lang.makeValidName(team2)).WinPctCloseGames));
    
    % Add upset factor based on seed difference
    seedDifference = teamStats.(matlab.lang.makeValidName(team1)).Seed - teamStats.(matlab.lang.makeValidName(team2)).Seed;
    upsetFactor = seedDifference * 0.05; % Adjust this multiplier as needed
    
    team1Strength = team1Strength - upsetFactor;
    
    team1ExpectedStrength = exp(team1Strength);
    winProb1 = team1ExpectedStrength / (team1ExpectedStrength + exp(team2Strength));
    
    % Simulate game outcome
    if rand() < winProb1
        winner = team1;
    else
        winner = team2;
    end
end

function winners = simulateRound(teams, matchups, teamStats)
    winners = cell(1, size(matchups, 1));
    for i = 1:size(matchups, 1)
        seed1Index = matchups(i, 1);
        seed2Index = matchups(i, 2);
        
        winners{i} = simulateGame(teams{seed1Index}, teams{seed2Index}, teamStats);
    end
end

function dynamicMatchups = generateMatchups(numTeams)
    % Dynamically generate matchups for the next round
    dynamicMatchups = reshape(1:numTeams, [], 2);
end

function simulateTournament(south, west, east, midwest, teamStats)
    regions = {south, west, east, midwest};
    regionNames = {'South', 'West', 'East', 'Midwest'};
    
    % Define first-round matchups based on seeding
    firstRoundMatchups = [1, 16; 8, 9; 5, 12; 4, 13; 6, 11; 3, 14; 7, 10; 2, 15];
    
    % Simulate first four rounds (regional rounds)
    for round = 1:4
        fprintf('Round %d:\n', round);
        for r = 1:length(regions)
            fprintf('%s Region:\n', regionNames{r});
            
            if round == 1
                % Use predefined first-round matchups
                regions{r} = simulateRound(regions{r}, firstRoundMatchups, teamStats);
            else
                % Dynamically generate matchups for subsequent rounds
                dynamicMatchups = generateMatchups(length(regions{r}));
                regions{r} = simulateRound(regions{r}, dynamicMatchups, teamStats);
            end
            
            disp(regions{r});
        end
        fprintf('\n');
    end
    
    % Simulate Final Four
    finalFour = {regions{1}{1}, regions{2}{1}, regions{3}{1}, regions{4}{1}};
    fprintf('Final Four:\n');
    finalists = simulateRound(finalFour, [1, 2; 3, 4], teamStats); % Final Four matchups
    disp(finalists);
    
    % Simulate Championship
    fprintf('\nChampionship:\n');
    champion = simulateRound(finalists, [1, 2], teamStats); % Championship matchup
    fprintf('NCAA Champion: %s\n', champion{1});
end

%% Run simulation
simulateTournament(south, west, east, midwest, teamStats);