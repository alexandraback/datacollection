/*
ID: Plagapong
LANG: C++
TASK: A
*/

#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#define INF 999999999
#define MULTI_MATCH "Bad magician!"
#define NO_MATCH "Volunteer cheated!"

using namespace std;

int r, a[4][4];
bool possible[17];

void preprocess() {
  // Preprocess
  
}

void clearVars() {
  // Clear variables
  for (int i = 0; i < 17; i++)
    possible[i] = false;
}

void process() {
  // Code here!
  int i, j;
  cin >> r;
  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
      cin >> a[i][j];
  i = r - 1;
  for (j = 0; j < 4; j++)
    possible[a[i][j]] = true;
  cin >> r;
  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
      cin >> a[i][j];
  i = r - 1;
  int answer = 0;
  for (j = 0; j < 4; j++)
    if (possible[a[i][j]])
      answer = (answer == 0) ? a[i][j] : INF;
  if (answer == 0)
    cout << NO_MATCH;
  else if (answer == INF)
    cout << MULTI_MATCH;
  else
    cout << answer;
}

int main() {
  preprocess();
  int times;
  cin >> times;
  for (int i = 1; i <= times; i++) {
	cout << "Case #" << i << ": ";
	clearVars();
	process();
	cout << endl;
  }
  return 0;
}
