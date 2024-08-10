# Farkle Game Project

## Project Overview

This project implements the Farkle dice game using C++ classes and data structures. The game involves rolling dice, keeping certain dice, and scoring based on predefined rules. The project features a circular linked list to manage players and handle game rotations, with enhanced gameplay features for a more interactive experience.

## Data Structures Implemented

1. **Circular Linked List:**
   - **Class:** `CircularLinkedList`
   - **Description:** Manages a list of players in a circular fashion, allowing seamless rotation through the list. Supports operations such as adding players, moving to the next player, and checking if the list is empty.

2. **Node:**
   - **Class:** `Node`
   - **Description:** Represents an element in the circular linked list, holding a pointer to a `Player` object and the next node in the list.

3. **Dice:**
   - **Class:** `Dice`
   - **Description:** Simulates the rolling of dice and calculates scores based on the dice results. Provides methods to roll multiple dice and a single die, as well as to calculate scores.

4. **Player:**
   - **Class:** `Player`
   - **Description:** Represents a player in the game, tracking their name, total score, current turn score, and number of wins. Provides methods for score management and win tracking.

5. **Farkle Game:**
   - **Class:** `Farkle`
   - **Description:** Manages the game flow, including taking turns, rolling dice, selecting dice to keep, calculating scores, and determining the winner. Handles game rules and player interactions.

## How to Run

1. **Build the Project:**
   - Ensure you have a C++ compiler installed.
   - Compile the project using a command such as `g++ -o farkle main.cpp`.
	- If you are using a different compiler, adjust the command accordingly.
	- If you are using an IDE, follow the instructions for building a C++ project. (I built this in VS)
   
2. **Execute the Program:**
   - Run the compiled executable: `./farkle`.
   - Follow the on-screen prompts to select the game, input player names, and start playing.

## Usage

1. **Select a Game:**
   - Choose the Farkle game from the list of available games.

2. **Input Players:**
   - Enter the number of players and their names.

3. **Start the Game:**
   - Begin playing by following the prompts to roll dice and select dice to keep.

4. **Gameplay:**
   - Roll dice, select which dice to keep, and score based on the game rules.
   - If all dice are kept during a turn, the player’s score for that turn is added to their final score, and the turn restarts with a new roll.
   - If not all dice are kept, the game rolls the remaining dice and calculates the score with all dice.

5. **End of Turn:**
   - The turn ends when not all dice are kept after a roll. The total score for the turn is added to the player's final score, and the next player begins their turn.

6. **View Results:**
   - After a player wins (reaches or exceeds 10,000 points), final scores for all players are displayed.

## Project Features

- **Circular Linked List:** Efficiently manages player rotation.
- **Dice Rolling:** Simulates dice rolls with random results.
- **Scoring:** Implements Farkle game rules for scoring.
- **Player Management:** Tracks player scores, wins, and handles turn-based gameplay.

## Contact

For any questions or feedback, please reach out to [colinmichael89@example.com](mailto:colinmichael89@gmail.com).
