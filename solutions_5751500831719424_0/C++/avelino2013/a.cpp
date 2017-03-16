#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

int main()
{
	int T, t=1, n, i, j, sz, k, ans;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		ans=0;
		vector<pair<char, int> > v[111];
		for(i=0; i<n; i++)
		{
			char s[111];
			scanf("%s", s);
			sz=strlen(s);
			for(j=0; j<sz; j++)
			{
				for(k=j; k<sz && s[k]==s[j]; k++);
				v[i].push_back(make_pair(s[j], k-j+1));
				j=k-1;
			}
		}
		int ok=1;
		printf("Case #%d: ", t++);
		for(i=1; i<n && ok; i++)
		{
			if((int)v[i].size()!=(int)v[i-1].size()) ok=0;
			else
			{
				for(j=0; j<v[i].size(); j++) if(v[i][j].first!=v[i-1][j].first) ok=0;
			}
		}
		if(!ok) printf("Fegla Won\n");
		else
		{
			for(i=0; i<v[0].size(); i++)
			{
				vector<int> med;;
				for(j=0; j<n; j++) med.push_back(v[j][i].second);
				sort(med.begin(), med.end());
				int s=med[((int)med.size())/2];
				for(j=0; j<med.size(); j++)
				{
					if(med[j]>s) ans+=med[j]-s;
					else ans+=s-med[j];
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
