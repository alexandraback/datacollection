#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
  // Basic Case Information
  int casenumber;
  char *result;

  // Custom Data
  int rows, cols, n;

} Case;

typedef struct {
  int full;
  int noise;
} Cell;

// Basic custom functions
void readCase(FILE *, int, Case *);
void printCase(Case *);
void freeCase(Case *);
void processCase(Case *);

// Custom functions
int isPalindrome(int);

// Basic static I/O functions
void readFile(const char *, Case **, int *);
void freeCases(Case *, int);
void writeResults(const char *, Case *, int);

int main(int argc, char const *argv[]) {
  Case *cases = NULL;
  int n;
  const char *filename;
  if (argc < 2) {
    filename = "min-sample.in";
    printf("Warning: No File specified. Using %s\n", filename);
    // exit(EXIT_FAILURE);
  } else {
    filename = argv[1];
  }
  readFile(filename, &cases, &n);
  for (int i = 0; i < n; i++) {
    printCase(cases + i);
    processCase(cases + i);
  }
  writeResults(filename, cases, n);
  freeCases(cases, n);
  return 0;
}

// #############################################################################
// #                          Basic custom functions                           #
// #############################################################################

void readCase(FILE *file, int casenumber, Case *c) {
  c->casenumber = casenumber;

  fscanf(file, "%d", &(c->rows));
  fscanf(file, "%d", &(c->cols));
  fscanf(file, "%d", &(c->n));
}
void printCase(Case *c) {
  printf("Case %d rows: %d cols: %d n: %d\n", c->casenumber, c->rows, c->cols,
         c->n);
}
void freeCase(Case *c) { free(c->result); }

void processCase(Case *c) {
  c->result = (char *)malloc(10 * sizeof(char));
  Cell **grid = (Cell **)malloc(c->rows * sizeof(Cell *));
  for (int i = 0; i < c->rows; ++i) {
    grid[i] = (Cell *)malloc(c->cols * sizeof(Cell));
    for (int j = 0; j < c->cols; j++) {
      grid[i][j].full = 1;
      grid[i][j].noise = 4;
      if (i == 0) {
        grid[i][j].noise--;
      }
      if (i == c->rows - 1) {
        grid[i][j].noise--;
      }
      if (j == 0) {
        grid[i][j].noise--;
      }
      if (j == c->cols - 1) {
        grid[i][j].noise--;
      }
    }
  }
  int filled = c->rows * c->cols;
  while (filled > c->n) {
    int max_i = 0, max_j = 0;
    int max = 0;
    for (int i = 0; i < c->rows; ++i) {
      for (int j = 0; j < c->cols; j++) {
        if (grid[i][j].full) {
          if (max == 0) {
            max_i = i;
            max_j = j;
          }
          if (grid[i][j].noise > max) {
            max_i = i;
            max_j = j;
            max = grid[i][j].noise;
          }
        }
      }
    }
    grid[max_i][max_j].full = 0;
    grid[max_i][max_j].noise = 0;
    if (max_i - 1 >= 0) {
      if (grid[max_i - 1][max_j].noise > 0)
        grid[max_i - 1][max_j].noise--;
    }
    if (max_i + 1 <= c->rows - 1) {
      if (grid[max_i + 1][max_j].noise > 0)
        grid[max_i + 1][max_j].noise--;
    }
    if (max_j - 1 >= 0) {
      if (grid[max_i][max_j - 1].noise > 0)
        grid[max_i][max_j - 1].noise--;
    }
    if (max_j + 1 <= c->cols - 1) {
      if (grid[max_i][max_j + 1].noise > 0)
        grid[max_i][max_j + 1].noise--;
    }
    filled--;
  }
  int noise = 0;
  for (int i = 0; i < c->rows; ++i) {
    for (int j = 0; j < c->cols; j++) {
      printf("%d ", grid[i][j].full);
      noise += grid[i][j].noise * grid[i][j].full;
    }
    printf("\n");
  }
  int count = noise / 2;

  sprintf(c->result, "%d", count);
}

// #############################################################################
// #                          Custom functions                                 #
// #############################################################################

// #############################################################################
// #                          Basic I/O functions                              #
// #############################################################################

void readFile(const char *filename, Case **result, int *n) {
  FILE *file;
  file = fopen(filename, "r");
  if (file) {
    fscanf(file, "%d", n);
    Case *cases = (Case *)malloc(*n * sizeof(Case));
    for (int i = 0; i < *n; i++) {
      readCase(file, i + 1, cases + i);
    }
    fclose(file);
    *result = cases;
  } else {
    printf("Error opening file\n");
    exit(EXIT_FAILURE);
  }
}
void freeCases(Case *cases, int n) {
  for (int i = 0; i < n; i++) {
    freeCase(cases + i);
  }
  free(cases);
}
void writeResults(const char *filename, Case *cases, int n) {
  FILE *file;
  char outfilename[200];
  sprintf(outfilename, "%s.out", filename);
  file = fopen(outfilename, "w");
  if (file) {
    for (int i = 0; i < n; i++) {
      fprintf(file, "Case #%d: %s\n", cases[i].casenumber, cases[i].result);
    }
    fclose(file);
  } else {
    printf("Error writing file\n");
    exit(EXIT_FAILURE);
  }
}
