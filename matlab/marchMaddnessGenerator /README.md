# March Madness Bracket Generator

Simulates March Madness Tournament and generates a predicted bracket based on team statistics. The script loads team data, including offensive and defensive efficiency, possessions per game, and win percentage in close games, to simulate game outcomes.

## Features

- Loads team names and statistics from CSV files.
- Simulates game outcomes based on offensive and defensive efficiency, possessions per game, win percentage in close games, and seed number.
- Simulates the entire tournament and generates matchups for each round of the tournament.
- Prints the results of each round, including the Final Four and the predicted National Champion.

## Requirements 

- MATLAB
- CSV files containing team statistics:
        *   `offensiveEfficiency.csv`: Team name and offensive efficiency rating.
        *   `defensiveEfficiency.csv`: Team name and defensive efficiency rating.
        *   `possessionsPerGame.csv`: Team name and possessions per game.
        *   `winPercentCloseGames.csv`: Team name and win percentage in close games.

  ## Usage
  
- Data Preparation:** Ensure the CSV files are in the same directory as the MATLAB script. The CSV files should have headers, with the team names in the first column and the stat in the second column. Ensure that team names are consistent across all CSV files.
- Running the Script:** Open the `marchMaddnessBracketGenerator.m` file in MATLAB and run the script.
    ```matlab
    marchMaddnessBracketGenerator
    ```

## Important Notes

- The simulation uses a degree of randomness, so each run will produce a different bracket.
- The relative influence of each statistic on the outcome is determined by the weights assigned in the code. Specifically, the impact of possessions per game and win percentage in close games can be directly adjusted within the simulateGame function, allowing for fine-tuning of their influence. Additionally, the upsetFactor within the simulateGame function can be adjusted to control the degree to which lower-seeded teams can potentially win.

## Technology

- MATLAB

## Acknowledgements

- teamrankings.com for providing data.
- Generative AI tools for assisting with parts of the code and debugging.
- This project was created by Ethan Greenhouse.
