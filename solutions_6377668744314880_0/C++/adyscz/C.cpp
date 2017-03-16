#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef std::pair<int,int> point;

bool above(point &A, point &B, point &C)
{
  return (B.first-A.first)*(C.second-A.second)-(B.second-A.second)*(C.first-A.first) > 0;
}

bool below(point &A, point &B, point &C)
{
  return (B.first-A.first)*(C.second-A.second)-(B.second-A.second)*(C.first-A.first) < 0;
}

int above(int i, int j, vector<point> &trees)
{
	int cnt = 0;
	for (int k = 0; k < trees.size(); ++k) {
		if (k == i || k == j) continue;
		cnt += above(trees[i], trees[j], trees[k]);
	}
	return cnt;
}

int below(int i, int j, vector<point> &trees)
{
	int cnt = 0;
	for (int k = 0; k < trees.size(); ++k) {
		if (k == i || k == j) continue;
		cnt += below(trees[i], trees[j], trees[k]);
	}
	return cnt;
}

void solve(vector<point> &trees)
{
	if (trees.size() == 1) {
		cout << 0 << endl;
		return;
	}
	for (int i = 0; i < trees.size(); ++i) {

		int mm = 100;
		for (int j = 0; j < trees.size(); ++j) {
			if (i == j) continue;
			int a = above(i,j,trees);
			int b = below(i,j,trees);
			int m = min(a,b);
			mm = min(mm,m);
		}

		cout << mm << endl;
	}
}

int main()
{
	int T; cin >> T;
	for (int t = 1; t <= T; ++t) {
		int N; cin >> N;
		vector<point> trees;
		for (int i = 0; i < N; ++i) {
			int X,Y; cin >> X >> Y;
			trees.push_back(make_pair(X,Y));
		}
		cout << "Case #" << t << ":" << endl;
		solve(trees);
	}
	return 0;
}
