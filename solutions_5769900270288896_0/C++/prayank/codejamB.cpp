#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("B-small-attempt3.in" , "r" , stdin);
	freopen("outputB.out" , "w" , stdout);
	int t , test;
	cin >> t;
	for(test = 1;test <= t;test++)
	{
		int r , c , n ,i , j , ans1 = 0 , ans2 = 0 , n1 , n2 , ans = 0;
		cin >> r >> c >> n;
		if(n <= (r*c+1)/2)
		{
			cout << "Case #" << test << ": 0" << endl;
			continue;
		}
		bool a[r][c];
		memset(a , 0 , r*c);
		if(r == 1 || c == 1)
		{
			for(i = 0;i < r ; i++)
			{
				for(j = 0;j < c;j++)
				{
					if((i+j)%2 == 0)
					{
						n--;
						a[i][j] = 1;
					}
				}
			}
			if(r == 1)
			{
				if(!a[0][c-1] && n)
				{
					a[0][c-1] == 1;
					ans += 1;
					n--;
				}
			}
			else
			{
				if(!a[r-1][0] && n)
				{
					n--;
					ans++;
					a[r-1][0] = 1;
				}
			}
			for(i = 0;i < r ; i++)
			{
				for(j = 0;j < c;j++)
				{
					if(!a[i][j] && n)
					{
						n--;
						a[i][j] = 1;
						ans += 2;
					}
				}
			}
			cout << "Case #" << test << ": " << ans << endl;
			continue;
		}
		n1 = n2 = n;
		for(i = 0;i < r ; i++)
		{
			for(j = 0;j < c;j++)
			{
				if((i+j)%2 == 0)
				{
					n1--;
					a[i][j] = 1;
				}
			}
		}
		if(!a[0][c-1] && n1)
		{
			n1--;
			a[0][c-1] = 1;
			ans1 += 2;
		}
		if(!a[r-1][0] && n1)
		{
			a[r-1][0] = 1;
			n1--;
			ans1 += 2;
		}
		if(!a[r-1][c-1] && n1)
		{
			a[r-1][c-1] = 1;
			n1--;
			ans1 += 2;
		}
		for(i = 0;i < c;i++)
		{
			if(!a[0][i] && n1)
			{
				ans1 += 3;
				n1--;
				a[0][i] = 1;
			}
			if(!a[r-1][i] && n1)
			{
				ans1 += 3;
				n1--;
				a[r-1][i] = 1;
			}
		}
		for(i = 0;i < r;i++)
		{
			if(!a[i][0] && n1)
			{
				ans1 += 3;
				n1--;
				a[i][0] = 1;
			}
			if(!a[i][c-1] && n1)
			{
				a[i][c-1] = 1;
				n1--;
				ans1 += 3;
			}
		}
		for(i = 0;i < r;i++)
		{
			for(j = 0;j < c;j++)
			{
				if(!a[i][j] && n1)
				{
					n1--;
					ans1 += 4;
					a[i][j] = 1;
				}
			}
		}


		memset(a , 0 , r*c);
		for(i = 0;i < r ; i++)
		{
			for(j = 0;j < c;j++)
			{
				if((i+j)%2 == 1)
				{
					n2--;
					a[i][j] = 1;
				}
			}
		}
		if(!a[0][0] && n2)
		{
			n2--;
			a[0][0] = 1;
			ans2 += 2;
		}
		if(!a[0][c-1] && n2)
		{
			n2--;
			a[0][c-1] = 1;
			ans2 += 2;
		}
		if(!a[r-1][0] && n2)
		{
			a[r-1][0] = 1;
			n2--;
			ans2 += 2;
		}
		if(!a[r-1][c-1] && n2)
		{
			a[r-1][c-1] = 1;
			n2--;
			ans2 += 2;
		}
		for(i = 0;i < c;i++)
		{
			if(!a[0][i] && n2)
			{
				ans2 += 3;
				n2--;
				a[0][i] = 1;
			}
			if(!a[r-1][i] && n2)
			{
				ans2 += 3;
				n2--;
				a[r-1][i] = 1;
			}
		}
		for(i = 0;i < r;i++)
		{
			if(!a[i][0] && n2)
			{
				ans2 += 3;
				n2--;
				a[i][0] = 1;
			}
			if(!a[i][c-1] && n2)
			{
				a[i][c-1] = 1;
				n2--;
				ans2 += 3;
			}
		}
		for(i = 0;i < r;i++)
		{
			for(j = 0;j < c;j++)
			{
				if(!a[i][j] && n2)
				{
					n2--;
					ans2 += 4;
					a[i][j] = 1;
				}
			}
		}

		ans = min(ans1 , ans2);

		cout << "Case #" << test << ": " << ans << endl;
	}
	return 0;
}