#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 101;

char str[N][105],tmp[105];
int n,cnt[N][105],len[N];

int isimpossible()
{
	int i;
	for(i=1;i<n;++i)
		if(strcmp(str[0],str[i])!=0)
			return 1;
	return 0;
}

int main()
{
	freopen("F:\\A-small-attempt0.in","r",stdin);
	freopen("F:\\A_small-out.txt","w",stdout);
	int b,k,i,j,t,tt,sum,ans;
	scanf("%d",&t);
	for(tt=1;tt<=t;++tt)
	{
		scanf("%d",&n);
		memset(str,0,sizeof(str));
		memset(cnt,0,sizeof(cnt));
		memset(len,0,sizeof(len));
		for(i=0;i<n;++i)
		{
			scanf("%s",tmp);
			for(j=0;tmp[j]!='\0';++j)
			{
				if(j==0||tmp[j]!=tmp[j-1])
				{
					str[i][len[i]++]=tmp[j];
				}
				++cnt[i][len[i]-1];
			}
			str[i][len[i]]='\0';
		}

		if(isimpossible())
			printf("Case #%d: Fegla Won\n",tt);
		else
		{
			ans=0;
			for(i=0;i<len[0];++i)
			{
				sum=0;
				vector<int> vec;
				for(j=0;j<n;++j)
					vec.push_back(cnt[j][i]);
				sort(vec.begin(),vec.end());
				for(j=0;j<n;++j)
					sum+=abs(cnt[j][i]-vec[n/2]);
				ans+=sum;
			}
			printf("Case #%d: %d\n",tt,ans);
		}
	}
	return 0;
}