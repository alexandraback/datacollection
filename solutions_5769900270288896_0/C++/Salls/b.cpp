#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int **board;
int R,C,N;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int count_bad(int r, int c) {
  int num_bad = 0;
  for(int k = 0; k < 4; k++) {
    int y = r + dy[k];
    int x = c + dx[k];
    if (x >= 0 && y >= 0 && x < C && y < R) {
      if(board[y][x] > 0) {
        num_bad++;
      }
    }
  }
  return num_bad;
}

int find_best(int &best_r, int &best_c) {
  int best = 10000000;
  for(int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
      if (board[i][j] > 0) {
        continue;
      }
      int num_bad = 0;
      for(int k = 0; k < 4; k++) {
        int y = i + dy[k];
        int x = j + dx[k];
        if (x >= 0 && y >= 0 && x < C && y < R) {
          if(board[y][x] > 0) {
            num_bad++;
          }
        }
      }
      if (num_bad < best) {
        best = num_bad;
        best_r = i;
        best_c = j;
      }
      
    }
  }
  
  return best;
}



int main() {
  int T;
  cin >> T;

  for(int tt = 1; tt <= T; tt++) {
    cin >> R >> C >> N;

    board = new int*[R];
    for(int i = 0; i < R; i++) {
      board[i] = new int[C];
      for (int j = 0; j < C; j++) {
        board[i][j] = 0;
      }
    }

    // first add all alternating
    int num_added = 0;
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if ((i+j) % 2 == 0) {
          board[i][j] = 1;
          num_added++;
        } 
      }
    }

    int ni, nj;
    int result = 0;
    while(num_added < N) {
      //cout << "adding"<<endl;
      int num_bad = find_best(ni,nj);
      //cout << "ni: " << ni << " nj: " << nj << endl;
      //cout << "num_bad: " << num_bad << endl;
      result += find_best(ni,nj);
      board[ni][nj] = 1;
      num_added++;
    }


    // try to improve
    int old_best = result;
    while(1) {
      for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
          if(board[i][j] == 1) {
            int old_bad = count_bad(i,j);
            board[i][j] = 0;
            int new_bad = find_best(ni,nj);
            if (new_bad < old_bad) {
              board[ni][nj] = 1;
              result = result-old_bad+new_bad;
            } else {
              board[i][j] = 1;
            }
          }
        } 
      }
      
      if(result==old_best) {
        break;
      }
      old_best = result;
    }


    cout << "Case #" << tt << ": " << result << endl;

    // free
    for(int i = 0; i < R; i++) {
      delete[] board[i];
    }
    delete[] board;

  }

  return 0;
}
