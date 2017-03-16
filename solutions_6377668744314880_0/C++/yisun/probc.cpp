#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;

fstream in, out;

int T;
int N;

vector<long long> X;
vector<long long> Y;

vector<int> ans;
long long temp_X;
long long temp_Y;

vector<long long> angle;

long long cX;
long long cY;

/*
bool compare(pair<long long, long long> a, pair<long long, long long> b) {
  return (a.second < b.second);
}

bool check_base() {
  for (int j = 0; j < N; ++j) {
    if (X[j] == cX && Y[j] == cY) {
      return false;
    }
    for (int k = 0; k < N; ++k) {
      if (k != j && get_cross(j, k, cX, cY) == 0) {
	return false;
      }
    }
  }
  return true;
}

void find_base_point() {
  cX = 0;
  cY = 0;
  while (!check_base()) {
    ++cX;
    cY = (long long)sqrt(cX);
  }
  cout << "base " << cX << " " << cY << endl;
}
*/ 

// angle A C B
long long get_cross(int a, int b, long long cX, long long cY) {
  return (X[a] - cX) * (Y[b] - cY) - (Y[a] - cY) * (X[b] - cX);
}

int find_ans(int i) {
  if (N == 1) {
    return 0;
  }
  int best = N;
  for (int j = 0; j < N; ++j) {
    if (j != i) {
      angle.clear();
      //      cout << "searching i " << i << " " << X[i] << " " << Y[i] << " j " << j << " " << X[j] << " " << Y[j] << endl;
      for (int k = 0; k < N; ++k) {
	if (k != i) {
	  //	  cout << "pt " << X[k] << " " << Y[k] << " " << get_cross(k, i, X[j], Y[j]) << endl;
	  angle.push_back(get_cross(k, i, X[j], Y[j]));
	}
      }
      //      sort(angle.begin(), angle.end());

      int num_pos = 0;
      int num_neg = 0;
      int num_zero = 0;
      for (long long ang : angle) {
	if (ang > 0) {
	  ++num_pos;
	} else if (ang < 0) {
	  ++num_neg;
	} else {
	  ++num_zero;
	}
      }
      if (num_pos < best) {
	best = num_pos;
      }
      if (num_neg < best) {
	best = num_neg;
      }
    }
  }
  return best;
}

int main() {
  in.open("C-small-attempt1.in", fstream::in);
  out.open("probc-small1.out", fstream::out);

  in >> T;
  for (int i = 0; i < T; i++) {
    in >> N;
    X.clear();
    Y.clear();
    ans.clear();
    for (int j = 0; j < N; ++j) {
      in >> temp_X >> temp_Y;
      X.push_back(temp_X);
      Y.push_back(temp_Y);
      ans.push_back(0);
    }

    for (int j = 0; j < N; ++j) {
      ans[j] = find_ans(j);
    }

    out << "Case #" << i + 1 << ":" << endl;
    for (int j = 0; j < N; ++j) {
      out << ans[j] << endl;
    }
  }
    
  in.close();
  out.close();
  return 0;
}
