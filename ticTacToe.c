// This is a really simple tic tac toe game that you can play 
// on the terminal

#include <stdio.h>
#include <string.h>

#define ROWS 3
#define COLS 3
#define FIRST_ROW 0
#define SECOND_ROW 1
#define FIRST_COLUMN 0
#define SECOND_COLUMN 1

enum board {
  NONE = ' ',
  X = 'X',
  O = 'O'
};

// this is a single tile of the board
// value should only contain a value if there is an x or o there
// true (1)
// false (0)
struct tile {
  enum board mark;
  
};

//the player coordinates
struct gameState {
  struct tile box[ROWS][COLS];
  enum board currentPlayer;
};

//function prototypes
void initBoard(struct gameState *game);
void printLine(void);
void printBoard(struct gameState *game);

int main(void) {
  struct gameState game;
  initBoard(&game);
  playGame(&game);
  return 0;
}
// initialises the board to default values.
void initBoard(struct gameState *game) {
  for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
          game->box[i][j].board = NONE;
          game->box[i][j].value = 0;
      }
  }
  game->currentPlayer = X;
}

void printBoard (struct gameState *game) {
  for (int i = 0; i < ROWS; i++ ) {
    printf("|");
    for (int j = 0; j < COLS; j++) {
      printf(" %c |", game->box[i][j].board);
    }
    printf("\n");
    print_line();
  }
}

void print_line(void) {
  for (int i = 0; i < COLS * 4 + 1; i++) {
      printf("-");
  }
  printf("\n");
}