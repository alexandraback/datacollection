// Code Jam 2015 Round 1A
// Haircut
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


int solveCase(const int B, const int N, const vector<int>& M) {
  if (N < B) {
    return N;
  }

  vector<double> M_inv;
  M_inv.resize(M.size());
  double rate = 0;
  for (int i=0; i<M.size(); i++) {
    M_inv[i] = 1.0 / (double) M[i];
    rate += M_inv[i];
  }
  //cout << "N: " << (double)N-B-1 << endl;

  long long start = floor((double)(N - B - 1) / rate);
  //cout << "S: " << start << endl;

  vector<int> remain;
  remain.resize(B);
  long long served = B;
  for (int i=0; i<B; i++) {
    served += start / M[i];
    remain[i] = M[i] - (start % M[i]);
  }
  int next_barber = 0;
  while (served < N) {
    //cout << "served: " << served << endl;
    //cout << "reamin: ";
    //for (auto r: remain) {
    //  cout << r << " ";
    //}
    //cout << endl;
    int min_r = 99999999;
    int b = 0;
    for (int i=0; i<B; i++) {
      if (remain[i] < min_r) {
        min_r = remain[i];
        b = i;
      }
    }
    next_barber = b;

    for (int i=0; i<B; i++) {
      remain[i] -= min_r;
      if (i == b) {
        remain[i] = M[i];
      }
    }
    served += 1;
  }

  return next_barber+1;
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
  int B = 0;
  int N = 0;
  *fs >> B;
  *fs >> N;

  vector<int> M = readVals(fs, B);
  if (M.size() != B) {
    cerr << "Error\n";
    return;
  }

  int b = solveCase(B, N, M);

  cout << "Case #" << case_num << ": " << b << endl;
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
