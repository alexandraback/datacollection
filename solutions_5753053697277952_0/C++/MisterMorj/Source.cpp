#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <map>
#include <limits>
#include <set>

using namespace std;

string new_str;

int arr[100001];
bool used[100001];
vector <int> pos_list, ans;
int ans_sz;
priority_queue <pair<int, char>> q;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int N;
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cout << "Case #" << i + 1 << ": ";
		int N;
		cin >> N;
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			int val;
			cin >> val;
			sum += val;
			q.push(make_pair(val, 'A' + i));
		}
		while (!q.empty())
		{
			sum--;
			pair<int, char> to_pr = q.top();
			cout << to_pr.second;
			to_pr.first--;
			q.pop();
			if (to_pr.first > 0)
				q.push(to_pr);

			to_pr = q.top();
			if ((to_pr.first + 0.0) <= (sum + 0.0) / 2.0)
				cout << ' ';
		}
		cout << endl;
	}

}