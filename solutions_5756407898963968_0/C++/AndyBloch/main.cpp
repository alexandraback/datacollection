// code jam a
int verbose = 0 ;

#include <iostream>
using namespace std ;

int runTest() {
  int r1;
  int r2;
  cin >> r1 ;
  if (verbose)
    cout << endl << "Row picked: " << r1 << ": " ;
  int possible[17];
  int i;
  int row;
  for (i = 0 ; i <= 15 ; i++) {
    row = i/4 + 1;
    int x;
    cin >> x;
    if (row == r1) {
      if (verbose)
        cout << x << " ";
      possible[x] = 1;
    }
    else
      possible[x] = 0;
  }
  cin >> r2 ;
  if (verbose)
    cout << endl;
  if (verbose)
    cout << "Row picked: " << r2 << ": " ;
  int answer = 0;
  int twoAnswers = 0 ;
  for (i = 0 ; i <= 15 ; i++) {
    row = i/4 + 1;
    int x;
    cin >> x;
    if (row == r2) {
      if (verbose)
        cout << x << " ";
      if (possible[x]) {
        if (verbose)
          cout << "* ";
        if (answer) {
          if (verbose)
            cout << " two answers" << endl;
          twoAnswers = 1;
        }
        else
          answer = x;
      }
    }
  }
  if (verbose)
    cout << endl;
  if (twoAnswers)
    return -1;
  return answer ;
}

int main (int argc, const char * argv[])
{
  int testCases ;
  cin >> testCases ;
  if (verbose) {
    cerr << "Verbose is on!" << endl ;
    cout << "// Test cases: " << testCases << endl ;
  }
  int i;
  for (i=0 ; i < testCases ; i++) {
    if (verbose)
      cout << "// Running case #" << i+1 << endl ;
    cout << "Case #" << i + 1 << ": " ;
    int r = runTest();
    if (r==0)
      cout << "Volunteer cheated!";
    else if (r<0)
      cout << "Bad magician!";
    else
      cout << r;
    cout << endl;
  }
  
  return 0;
}

