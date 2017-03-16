#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <ctime>
#include <cmath>

using namespace std;

#define forn(I,N) for (int I=0; I<N; I++)
#define fornd(I,N) for (int I=N-1; I>=0; I--)
#define forab(I,A,B) for (int I=A; I<=B; I++)
#define forabd(I,A,B) for (int I=B; I>=A; I--)
#define FOREACH(I,A) for (__typeof__(A)::iterator I=A.begin(); I<A.end(); I++)
#define pb push_back
#define mp make_pair

typedef long long int ll;

int getVal(vector<vector<bool> > & room) {
  int R = room.size();
  int C = room[0].size();

  int val = 0;
  forn(i, R) {
    forn(j, C) {
      if(room[i][j]) {
        if(i > 0 && room[i-1][j]) {
          val++;
        }
        if(j > 0 && room[i][j-1]) {
          val++;
        }
      }
    }
  }
  return val;
}

int getMin(vector<vector<bool> > & room, int row, int col, int N) {
  int R = room.size();
  int C = room[0].size();

  if(N == 0) {
    return getVal(room);
  }
  else if(row < R) {
    int nextRow, nextCol;
    if(col == C - 1) {
      nextRow = row + 1;
      nextCol = 0;
    }
    else {
      nextRow = row;
      nextCol = col + 1;
    }
    int val1 = 1000000;
    if(N > 0) {
      room[row][col] = true;
      val1 = getMin(room, nextRow, nextCol, N - 1);
      room[row][col] = false;
    }
    int val2 = getMin(room, nextRow, nextCol, N);

    return val1 <= val2 ? val1 : val2;
  }
  else {
    return 1000000;
  }
}


int main() {
  int T;
  cin >> T;

  forn(i, T) {
    int R, C, N;
    cin >> R >> C >> N;
    
    vector<vector<bool> > room(R, vector<bool>(C));
    cout << "Case #" << i + 1 << ": " << getMin(room, 0, 0, N) << endl;
  }

  return 0;
}
