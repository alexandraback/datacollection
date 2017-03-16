#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define FORR(i,a,b) for (int i=a; i>=b; i--)
#define pi M_PI

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef pair<int,int> PII;

int n;
VI e;
VVI e2;
int d[50][50];

int dfs(int now, int past){
	int res = -1;
	REP(i,e2[now].size()){
		int next = e2[now][i];
		if (next == past) continue;
		res = max(res,dfs(next,now));
	}
	if (res>=0)
		return res+1;
	else
		return 0;

}

int main(void) {
	ifstream ifs("input.txt");
	FILE *fp;
	fp = fopen("out.txt","w");
	int t;
	ifs >> t;
	REP(cas,t){		
		fprintf(fp,"Case #%d: ",cas+1);
		int n, s = 0;
		ifs >> n;
		priority_queue<pair<int, char> > pq;
		REP(i,n){
			int x;
			ifs >> x;
			s += x;
			char c = 'A'+i;
			pq.push(make_pair(x, c));
		}
		if (s%2){
			pair<int, char> p = pq.top();
			pq.pop();
			fprintf(fp,"%c ",p.second);
			cout << p.second << " ";
			p.first--;
			if (p.first>0)
				pq.push(p);
		}
		while (!pq.empty()){
			pair<int, char> p;
			p = pq.top();
			pq.pop();
			fprintf(fp,"%c",p.second);
			cout << p.second;
			p.first--;
			if (p.first>0)
				pq.push(p);
			p = pq.top();
			pq.pop();
			fprintf(fp,"%c ",p.second);
			cout << p.second << " ";
			p.first--;
			if (p.first>0)
				pq.push(p);
		}
		cout << endl;
		fprintf(fp,"\n");


	}

	return 0;
}