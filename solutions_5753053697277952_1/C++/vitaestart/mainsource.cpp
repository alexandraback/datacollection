#pragma warning(disable:4996)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

int caseNum, totalCaseNum;
int n;
pair<int,char> p[26], pp, qq;

class Comp
{
public:
	bool operator()(pair<int,char> a, pair<int,char> b)
	{
		return a.first < b.first;
	}
};

int main()
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int i, j, m;

	scanf("%d", &totalCaseNum);
	for(caseNum=1; caseNum<=totalCaseNum; caseNum++)
	{
		printf("Case #%d: ", caseNum);
		scanf("%d", &n); m=n;
		priority_queue<pair<int,char>, vector<pair<int,char>>, Comp> q;
		for(i=0; i<n; i++)
		{
			scanf("%d", &p[i].first);
			p[i].second = i+'A';
			q.push(p[i]);
		}
		while(!q.empty())
		{
			if(m==2)
			{
				pp = q.top(); q.pop();
				qq = q.top(); q.pop();
				for(j=0; j<abs(pp.first-qq.first); j++) printf("%c ", pp.first>qq.first?pp.second:qq.second);
				for(j=0; j<min(pp.first,qq.first); j++) printf("%c%c ", pp.second, qq.second);
				break;
			}
			pp = q.top(); q.pop();
			printf("%c ", pp.second);
			if(--pp.first) q.push(pp);
			else m--;
		}
		printf("\n");
	}

	return 0;
}