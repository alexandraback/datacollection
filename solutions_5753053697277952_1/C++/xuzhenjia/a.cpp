#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<ctime>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<cassert>
#include<bitset>

using namespace std;
typedef long long LL;
int a[100000];
priority_queue<pair<int,int> >q;
int main() {
	freopen("aa.in","r",stdin);
	freopen("aa.out","w",stdout);
	int numcase;
	cin>>numcase;
	int n;
	for(int ii=1;ii<=numcase;ii++){
		scanf("%d",&n);
		while (!q.empty())q.pop();
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			q.push(make_pair(a[i],i));	
		}
		printf("Case #%d:",ii);
		while (!q.empty()){
			if(q.size()==2){
				pair<int,int> r=q.top();
				q.pop();
				pair<int,int> t=q.top();
				q.pop();
				printf(" %c%c",(char)(r.second + 'A'-1),(char)(t.second + 'A'-1));	
				r.first--;
				t.first--;
				if(r.first){
					q.push(r);
					q.push(t);	
				}
			}else
			{
				pair<int,int> r=q.top();
				q.pop();
				printf(" %c",(char)(r.second + 'A'-1));
				r.first--;
				if(r.first) q.push(r);
			}
		}
		puts("");
	}
	return 0;
}
