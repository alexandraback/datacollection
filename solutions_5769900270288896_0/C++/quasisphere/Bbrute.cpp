#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<utility>

using namespace std;

int64_t penalty(vector<vector<int64_t>> &board) {
  int64_t p=0;
  for(int64_t r=0;r<board.size();r++) {
    for(int64_t c=1;c<board[r].size();c++) {
      if(board[r][c-1] && board[r][c]) p++;
    }
  }
  for(int64_t c=0;c<board[0].size();c++) {
    for(int64_t r=1;r<board.size();r++) {
      if(board[r-1][c] && board[r][c]) p++;
    }
  }
  return p;
}

int64_t calc(vector<vector<int64_t>> &board, int64_t r, int64_t c, int64_t R, int64_t C, int64_t n) {
  if(r == R) {
    if(n == 0) return penalty(board);
    else return 10000000;
  }
  if(c < C-1) {
    int64_t res1,res2;
    res1=calc(board, r, c+1, R, C, n);
    board[r][c]=1;
    res2=calc(board, r, c+1, R, C, n-1);
    board[r][c]=0;
    return min(res1,res2);
  } else {
    int64_t res1,res2;
    res1=calc(board, r+1, 0, R, C, n);
    board[r][c]=1;
    res2=calc(board, r+1, 0, R, C, n-1);
    board[r][c]=0;
    return min(res1,res2);
  }
}

int main(void) {
  int64_t T;
  cin >> T;
  for(int64_t t=1;t<=T;t++) {
    int64_t r,c,n;
    cin >> r >> c >> n;
    vector<vector<int64_t>> board(r, vector<int64_t>(c,0));
    int64_t res=calc(board, 0, 0, r, c, n);
    cout << "Case #" << t << ": " << res << "\n";
  }
  return 0;
}

