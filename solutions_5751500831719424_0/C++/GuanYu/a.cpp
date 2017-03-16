#include <cstdio>
#define abs(a,b) ((a)>(b)?((a)-(b)):((b)-(a)))
#define MAXN 102
using namespace std;

// Node
typedef struct{
	int cnt[102];
}NODE;
NODE node[MAXN];

// Pattern
int len;
char pat[120],pat2[120];

// String
char str[120];

// Main
int main(void)
{
	int tc,cs,i,j,k,cnt,n,len2,mm,MM,tmp,plus,ans;
	char prev;
	bool ok;

	// Read Input
	scanf("%d",&tc);
	for(cs=1;cs<=tc;cs++)
	{
		scanf("%d",&n);
		scanf("%s",str);

		// First string
		len=0;
		prev=0;
		for(i=cnt=0;str[i]!='\0';i++)
		{
			if(str[i]!=prev)
			{
				if(cnt)
				{
					pat[len]=prev;
					node[0].cnt[len]=cnt;
					len++;
				}
				prev=str[i];
				cnt=1;
			}
			else cnt++;
		}
		if(cnt)
		{
			pat[len]=prev;
			node[0].cnt[len]=cnt;
			len++;
			cnt=1;
		}

		// Rest of strings
		ok=true;
		for(j=1;j<n;j++)
		{
			scanf("%s",str);
			if(!ok) continue;
			len2=0;
			prev=0;
			for(i=cnt=0;str[i]!='\0';i++)
			{
				if(str[i]!=prev)
				{
					if(cnt)
					{
						pat2[len2]=prev;
						node[j].cnt[len2]=cnt;
						len2++;
					}
					prev=str[i];
					cnt=1;
				}
				else cnt++;
			}
			if(cnt)
			{
				pat2[len2]=prev;
				node[j].cnt[len2]=cnt;
				len2++;
				cnt=1;
			}

			// Impossible
			if(len2!=len) ok=false;
			else
			{
				for(i=0;i<len;i++)
					if(pat[i]!=pat2[i]) break;
				if(i<len) ok=false;
			}
		}

		// Output
		printf("Case #%d: ",cs);

		// Impossible
		if(!ok) puts("Fegla Won");
		else
		{
			ans=0;
			mm=1000,MM=0;
			for(i=0;i<len;i++)
			{
				for(j=0;j<n;j++)
				{
					if(node[j].cnt[i]>MM) MM=node[j].cnt[i];
					if(node[j].cnt[i]<mm) mm=node[j].cnt[i];
				}

				// Try
				plus=1000000;
				for(k=mm;k<=MM;k++)
				{
					tmp=0;
					for(j=0;j<n;j++)
						tmp+=abs(node[j].cnt[i],k);
					if(tmp<plus) plus=tmp;
				}
				ans+=plus;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}