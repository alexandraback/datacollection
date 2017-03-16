#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	int TESTS;
	cin >> TESTS;
	for (int test = 0; test < TESTS; ++test)
	{
		int n;
		cin >> n;
		vector<int> A(n);
		for (int i = 0; i < n; ++i)
			cin >> A[i];
		int answer1 = 0;
		for (int i = 0; i < n - 1; ++i)
			answer1 += max(0, A[i] - A[i + 1]);
		int speed = 0;
		for (int i = 0; i < n - 1; ++i)
			speed = max(speed, max(0, A[i] - A[i + 1]));
		int answer2 = 0;
		for (int i = 0; i < n - 1; ++i)
			answer2 += min(speed, A[i]);
		cout << "Case #" << test + 1 << ": " << answer1 << " " << answer2 << endl;
	}	
}