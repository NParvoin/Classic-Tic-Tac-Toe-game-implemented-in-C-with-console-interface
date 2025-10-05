#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

char board[SIZE][SIZE];
char currentPlayer;

// Инициализация игрового поля
void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
    currentPlayer = 'X';
}

// Отображение игрового поля
void displayBoard() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i < SIZE - 1) {
            printf("\n-----------\n");
        }
    }
    printf("\n\n");
}

// Проверка валидности хода
int isValidMove(int row, int col) {
    return (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ');
}

// Проверка победы
int checkWin() {
    // Проверка строк и столбцов
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return 1;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return 1;
        }
    }
    
    // Проверка диагоналей
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return 1;
    }
    
    return 0;
}

// Проверка на ничью
int checkDraw() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

// Смена игрока
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Основная игровая логика
void playGame() {
    int row, col;
    int gameOver = 0;
    
    printf("Добро пожаловать в крестики-нолики!\n");
    printf("Игроки по очереди вводят координаты (ряд и столбец от 1 до 3)\n");
    
    while (!gameOver) {
        displayBoard();
        printf("Ход игрока %c\n", currentPlayer);
        
        // Ввод координат
        while (1) {
            printf("Введите ряд и столбец (например, 1 2): ");
            if (scanf("%d %d", &row, &col) != 2) {
                printf("Некорректный ввод. Попробуйте снова.\n");
                while (getchar() != '\n'); // Очистка буфера ввода
                continue;
            }
            
            // Преобразование в индексы массива (от 1-based к 0-based)
            row--;
            col--;
            
            if (isValidMove(row, col)) {
                break;
            } else {
                printf("Неверный ход! Попробуйте снова.\n");
            }
        }
        
        // Выполнение хода
        board[row][col] = currentPlayer;
        
        // Проверка условий окончания игры
        if (checkWin()) {
            displayBoard();
            printf("Игрок %c победил! Поздравляем!\n", currentPlayer);
            gameOver = 1;
        } else if (checkDraw()) {
            displayBoard();
            printf("Ничья! Игра окончена.\n");
            gameOver = 1;
        } else {
            switchPlayer();
        }
    }
}

// Главная функция
int main() {
    char playAgain;
    
    do {
        initializeBoard();
        playGame();
        
        printf("Хотите сыграть еще раз? (y/n): ");
        scanf(" %c", &playAgain);
        
    } while (playAgain == 'y' || playAgain == 'Y');
    
    printf("Спасибо за игру!\n");
    return 0;
}