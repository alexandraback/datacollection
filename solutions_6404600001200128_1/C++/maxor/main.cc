// Code Jam 2015 Round 1A
// Mushroom Monster
// Author: Max Pflueger

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <math.h>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


void solveCase(const vector<int>& M, int& y, int& z) {
  int N = M.size();

  // Method 1
  y = 0;
  int max_rate = 0;
  int prev = M[0];
  for (int i=1; i < M.size(); i++) {
    if (M[i] < prev) {
      y += prev - M[i];
      if (prev-M[i] > max_rate) {
        max_rate = prev-M[i];
      }
    }
    prev = M[i];
  }

  // Method 2
  z = 0;
  prev = M[0];
  for (int i=1; i < M.size(); i++) {
    if (prev > max_rate) {
      z += max_rate;
    } else {
      z += prev;
    }
    prev = M[i];
  }
}

// Read n int values out of the file
vector<int> readVals(fstream* fs, int n) {
  vector<int> vals;
  int x;

  vals.resize(n);
  for (int i=0; i < n; i++) {
    *fs >> x;
    vals[i] = x;
  }
  return vals;
}

void readCase(fstream* fs, int case_num) {
  int N = 0;
  *fs >> N;

  vector<int> m = readVals(fs, N);
  if (m.size() != N) {
    cerr << "Error\n";
    return;
  }

  int y = 0;
  int z = 0;
  solveCase(m, y, z);

  cout << "Case #" << case_num << ": " << y << " " << z << endl;
}

int main(int argc, char** argv) {
  // Check number of args
  if (argc < 2) {
    cout << "Please supply an input file.\n";
    return -1;
  }

  // Open the input file (read only)
  fstream fs;
  fs.open(argv[1], fstream::in);

  int cases;
  fs >> cases;
  for (int i=0; i<cases; i++) {
    readCase(&fs, i+1);
  }
}
