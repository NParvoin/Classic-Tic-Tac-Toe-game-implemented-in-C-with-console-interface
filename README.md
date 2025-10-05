# Classic-Tic-Tac-Toe-game-implemented-in-C-with-console-interface

🏗️ Core Structure
Data Layer

char board[3][3] - Game grid

char currentPlayer - 'X' or 'O'

Modules

initializeBoard() - Reset game

displayBoard() - Show grid

isValidMove() - Check input

checkWin() - 8 win conditions

checkDraw() - Full board check

switchPlayer() - X/O toggle

🔄 Game Flow
Initialize → Display → Input → Validate

Update → Check Win/Draw → Switch Player

Repeat until game end

🎯 Win Detection
3 rows, 3 columns, 2 diagonals

All same symbol ≠ ' '

💻 Tech
Pure C

Console I/O

2D array logic

Input validation

Simple, modular, functional.
