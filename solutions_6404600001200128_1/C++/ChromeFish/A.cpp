#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
ifstream in("A.in");
ofstream out("A.out");

int ans1, ans2;
int m[1010];
int main()
{
	int T, n, headNum;
	in>>T;
	for (int i=1; i<=T; i++)
	{
		in>>n;
		ans1=ans2=0;
		for (int i=0; i<n; i++)
			in>>m[i];
		for (int i=1; i<n; i++)
			if (m[i]<m[i-1])
				ans1+=m[i-1]-m[i];
		int maxd = 0;
		for (int i=1; i<n; i++)
			if (m[i]<m[i-1])
				maxd = max(maxd, m[i-1]-m[i]);
		if (maxd == 0) ans2 = 0;
		else
		{
			for (int i=0; i<n-1; i++)
				ans2+=min(m[i], maxd);
		}
		out<<"Case #"<<i <<": "<<ans1<<' '<<ans2<<endl;
	}
}