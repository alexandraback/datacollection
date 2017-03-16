#include <iostream>
#include <vector>
using namespace std;



vector <int> readF()
{
	vector <int> ans;
	int r;
	scanf("%d", &r);
	r--;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int x;
			scanf("%d", &x);
			if (i == r)
				ans.push_back(x);
		}
	}
	return ans;
}


void solve()
{
	vector <int> p1 = readF();
	vector <int> p2 = readF();
	
	int eq = 0;
	int ans = 0;
	for (int i = 0; i < p1.size(); i++)
		for (int j = 0; j < p2.size(); j++)
			if (p1[i] == p2[j] )
			{
				ans = p1[i];
				eq++;
			}
	if (eq == 0)
		printf("Volunteer cheated!");
	else if (eq == 1)
		printf("%d", ans);
	else
		printf("Bad magician!");
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		printf("Case #%d: ", i);
		solve();
		printf("\n");
	}



	return 0;
}