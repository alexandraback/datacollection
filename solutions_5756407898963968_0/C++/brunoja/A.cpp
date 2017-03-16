#include <iostream>
#include <cstring>
using namespace std;

const int N = 4;
const int M = 17;
int set[M];

void read()
{
	int a, b;
	cin >> a;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> b;
			if (i == a-1) ++set[b];
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	
	int t;
	cin >> t;
	
	for (int q = 1; q <= t; ++q)
	{
		cout << "Case #" << q << ": ";
		memset(set, 0, sizeof set);
		read();
		read();
		int r = 0, l;
		for (int i = 1; i < M; ++i)
		{
			r += set[i] == 2;
			if (set[i] == 2) l = i;
		}
		if (r == 0) cout << "Volunteer cheated!" << endl;
		else if (r != 1) cout << "Bad magician!" << endl;
		else cout << l << endl;
	}
}

