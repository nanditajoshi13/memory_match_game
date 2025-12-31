# Memory Match Game
A console-based **Memory Match Game** implemented in **C++** as part of my Data Structure Lab coursework.  
This project demonstrates practical use of **structures, functions, and stacks** to build an interactive
game where players flip cards to find matching pairs.
## Project Overview
The Memory Match Game challenges players to test their memory and logic skills:
- A set of cards is laid face down.
- Players flip two cards at a time.
- If the cards match, they remain revealed; otherwise, they are flipped back.
- The goal is to match all pairs with the fewest moves.  

This project is not just a game, it's a demonstrationo of how **core data structures** can be applied to solve real-world
problems in an engaging way.
## Key Concepts Used
- **Structures**:  
  Used to define the card entity, storing attributes like alphabets, state (hidden/revealed), and position.
- **Functions**:  
  Modular design with functions for initialization, card flipping, match checking, and game logic.  
  This improves readability, reusability, and debugging
- **Stacks**:  
  Implemented to manage moves and backtracking.
  Each move is pushed onto a stack, allowing the game to track history and demonstrate stack operations in practice.
## Features
- Console-based interactive gameplay.
- Clear instructions and prompts for the player.
- Stack-based move tracking for educational demonstration.
- Modular C++ code with well-defined functions.
- Easy to extend (e.g. add scoring system, timer).
- Dynamically choose the number of pairs.
## How to Run
1.  Clone the repository:  
git clone https://github.com/nanditajoshi13/memory_match_game.git
2. Navigate to the project folder:  
   cd memory_match_game
3. Run the game:  
   g++ memory_match.cpp -o memory_match
4. Run the executable:  
   ./memory_match
## Learning Outcomes
- Practical application of **abstract data types** in C++.
- Hands-on experience with stack operations in a real scenario.
- Improved understanding of **modular programming** using functions.
- Reinforcement of **structure-based design** for organizing data.
## Future Enhancements
- Add a scoring system based on number of moves.
- Implement difficulty levels (time limits, reshuffling).
- Create a graphical interface using libraries
- Save and load game states using file handling.
