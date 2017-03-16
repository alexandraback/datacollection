#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#define N 101
using namespace std;

char buff[N];
string s[N];
int p[N];
int cnt[N], med[N];

int main()
{
	int t;scanf("%d",&t);
	for(int cs=1;cs<=t;++cs)
	{
		printf("Case #%d: ", cs);
		int n;scanf("%d",&n);

		for(int i=0;i<n;++i)
			scanf("%s", buff), s[i] = buff;

		string t1, t2;
		t1 = s[0];
		t1.resize(unique(t1.begin(), t1.end())-t1.begin());
		bool ok = 1;
		for(int i = 1;i<n && ok;++i)
		{
			t2 = s[i];
			t2.resize(unique(t2.begin(), t2.end())-t2.begin());
			ok &= t1 == t2;
		}

		if(!ok)
		{
			printf("Fegla Won\n");
			continue;
		}
		memset(p, 0, sizeof p);
		int ans = 0;
		for(int i=0;i<t1.size();++i)
		{
			for(int j=0;j<n;++j)
			{
				int k = p[j];
				while(k < s[j].size() && s[j][k] == t1[i]) ++k;
				med[j] = cnt[j] = k-p[j];
				p[j] = k;
			}
			sort(med, med+n);
			for(int i=0;i<n;++i)
				ans += abs(med[n/2]-cnt[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
