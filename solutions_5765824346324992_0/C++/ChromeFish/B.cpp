#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
ifstream in("B.in");
ofstream out("B.out");

int ans, b, n;
int m[1010];

int main()
{
	int T, n, headNum;
	in>>T;
	for (int i=1; i<=T; i++)
	{
		in>>b>>n;
		for (int j=0; j<b; j++)
			in>>m[j];
		if (n<=b)
			ans = n;
		else
		{
			long long x=0, y=100000000000000, mid, cnt; 
			while (x < y)
			{
				mid = (x+y)/2;
				cnt=0;
				for (int j=0; j<b; j++)
					cnt+=mid/m[j];
				if (cnt>=n-b)
					y=mid;
				else
					x=mid+1;
			}
			cnt = b;
			for (int j=0; j<b; j++)
				cnt += (x-1)/m[j];
			for (int j=0; j<b; j++)
				if (!(x % m[j]))
				{
					cnt ++;
					if (cnt == n)
					{
						ans = j+1;
						break;
					}
				}
		}
		out<<"Case #"<<i <<": "<<ans<<endl;
	}
}