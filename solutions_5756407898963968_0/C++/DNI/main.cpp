#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<bitset>


using namespace std;

int ar[4][4];
int tr[4];


int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int t;
	cin >> t;
	for(int tt = 0; tt < t; tt++)
	{
		int n;
		cin >> n;
		n--;
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++)
				cin >> ar[i][j];

		for(int i = 0; i < 4; i++)
			tr[i] = ar[n][i];

		cin >> n;
		n--;
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++)
				cin >> ar[i][j];

		int res = 0;
		int ans = 0;
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++)
				if(tr[i] == ar[n][j])
				{
					ans = tr[i];
					res++;
				}
		if(res == 1)
		{
			printf("Case #%d: %d\n", tt+1, ans);
		}
		else if(res == 0)
		{
			printf("Case #%d: Volunteer cheated!\n", tt+1);
		}
		else
		{
			printf("Case #%d: Bad magician!\n", tt+1);
		}
	}
	return 0;
}

