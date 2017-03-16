#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;

int m[10000],N;

int main()
{
	int NumberOfTestcases;
	scanf("%d",&NumberOfTestcases);
	for(int CaseNumber=1;CaseNumber<=NumberOfTestcases;CaseNumber++)
	{
		printf("Case #%d: ",CaseNumber);
		scanf("%d",&N);
		for(int i=0;i<N;i++)
			scanf("%d",m+i);
		int ans1=0,ans2=0,big=0;
		for(int i=1;i<N;i++)
			ans1+=max(0,m[i-1]-m[i]);
		for(int i=1;i<N;i++)
			big=max(big,m[i-1]-m[i]);
		for(int i=0;i<N-1;i++)
			ans2+=min(big,m[i]);
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}
