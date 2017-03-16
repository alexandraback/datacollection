#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t,r,c,n;
	cin >> t;
	for(int test=1;test<=t;++test)
	{
		cin >> r >> c >> n;
		bool flag[r][c];
		int b = r*c;
		int res = INT_MAX;
		for(int i=0;i<(1<<b);++i)
		{
			if(__builtin_popcount(i)!=n)
				continue;
			for(int j=0;j<b;++j)
				if(i&(1<<j))
					flag[j/c][j%c] = true;
				else
					flag[j/c][j%c] = false;
//			cout << i << "================\n";
//			for(int i=0;i<r;++i)
//				for(int j=0;j<c;++j)
//					cout << flag[i][j] << " \n"[j==c-1];
//			cout << "============\n";
			int value = 0;
			for(int i=0;i<r;++i)
				for(int j=0;j<c;++j)
					if(flag[i][j])
					{
						if(i!=0)	
							if(flag[i-1][j])
								++value;
						if(j!=0)
							if(flag[i][j-1])
								++value;
						if(i!=r-1)
							if(flag[i+1][j])
								++value;
						if(j!=c-1)
							if(flag[i][j+1])
								++value;
					}
			value /= 2;
			res = min(res,value);
		}
		cout << "Case #" << test << ": " << res << endl;
	}
	return 0;
}
