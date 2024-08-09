# Farkle Game Project

## Project Overview

This project implements the Farkle dice game using a combination of C++ classes and data structures. The game involves rolling dice, keeping certain dice, and scoring based on predefined rules. The project features a circular linked list to manage players and handle game rotations.

## Data Structures Implemented

1. **Circular Linked List:**
   - **Class:** `CircularLinkedList`
   - **Description:** Manages a list of players in a circular fashion, allowing seamless rotation through the list. It supports operations such as adding players, moving to the next player, and checking if the list is empty.

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
   - Compile the project and run.

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
   - The game continues until a player reaches or exceeds 10,000 points.

5. **View Results:**
   - After a player wins, final scores for all players are displayed.

## Project Features

- **Circular Linked List:** Efficiently manages player rotation.
- **Dice Rolling:** Simulates dice rolls with random results.
- **Scoring:** Implements Farkle game rules for scoring.
- **Player Management:** Tracks player scores and wins.

## Contact

For any questions or feedback, please reach out to [colinmichael89@example.com](mailto:colinmichael89@gmail.com).

