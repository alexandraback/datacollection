#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <functional>

using namespace std;

void solveCase()
{
	int N;
	cin >> N;
	vector<int> P(N);
	typedef pair<int, int> PII;
	priority_queue<PII, vector<PII>, less<PII> > pq;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		pq.push(make_pair(temp, 'A' + i));
	}
	
	while (!pq.empty())
	{
		if (pq.size() == 2) {
			char a = pq.top().second;
			pq.pop();
			char b = pq.top().second;
			int length = pq.top().first;
			pq.pop();

			for (int i = 0; i < length; i++) {
				cout << a << b << " ";
			}
		}
		else {
			PII p = pq.top();
			cout << (char)p.second << " ";
			if (p.first > 1) {
				pq.push(make_pair(p.first - 1, p.second));
			}
			pq.pop();
		}
	}

	cout << endl;
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("C:\Users\ZeroPage\Downloads\A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		printf("Case #%d: ", i);
		solveCase();
	}
	return 0;
}