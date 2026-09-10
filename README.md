# Tic-Tac-Toe Game in C++

A console-based Tic-Tac-Toe game developed in C++ featuring both **Player vs Player** and **Player vs Computer** gameplay. The computer opponent uses the **Minimax algorithm** to make optimal moves.

## Features

* Player vs Player mode
* Player vs Computer mode
* Minimax-based AI opponent
* Win and draw detection
* Invalid move validation
* Prevention of occupied-cell selection
* Score tracking
* Simple console-based interface
* Replay support through the main menu

## Technologies Used

* **C++**
* **Minimax Algorithm**
* **Recursion**
* **Arrays**
* **Functions**
* **Conditional Statements and Loops**

## How the Game Works

The game uses a 3 × 3 board where players take turns placing `X` or `O`.

A player wins by placing three of their symbols in:

* A row
* A column
* A diagonal

If all cells are occupied without a winner, the game ends in a draw.

### Computer AI

In Player vs Computer mode, the computer uses the **Minimax algorithm** to evaluate possible future game states and select the best available move.

The scoring system is:

* `+10` → Computer wins
* `-10` → Player wins
* `0` → Draw

This allows the computer to play optimally in Tic-Tac-Toe.

## How to Run

### Prerequisites

A C++ compiler such as **G++** is required.

### Compile

Open a terminal in the project directory and run:

```bash
g++ Tic_Tac_Toe.cpp -o Tic_Tac_Toe
```

### Run

On Windows:

```bash
Tic_Tac_Toe
```

On Linux/macOS:

```bash
./Tic_Tac_Toe
```

## Game Menu

```text
========== MAIN MENU ==========
1. Player vs Player
2. Player vs Computer
3. View Score
4. Exit
===============================
```

## Learning Objectives

This project demonstrates practical use of:

* C++ programming fundamentals
* Functions and modular programming
* Two-dimensional arrays
* Recursion
* Game-state evaluation
* The Minimax decision-making algorithm

## Future Improvements

Possible improvements include:

* Difficulty levels
* Improved console UI
* Move history
* Player name customization
* Alpha-Beta pruning for Minimax optimization
* Graphical user interface

---

If you found this project useful, feel free to explore the code and try improving the AI.
