#include <bits/stdc++.h>

#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define SIZE(a) ((int)a.size())
#define pb push_back

using namespace std;

int n, m;
char buff[113];
vector<char> repr;
vector<int> rs[113];
bool works;

bool parse(){
	int i = 0, j = 0;
	while(j < SIZE(repr)){
		int c = 0;
		while(buff[i] == repr[j]) ++c, ++i;
		if(c == 0)
			return false;
		rs[j].push_back(c);
		++j;
	}
	return i == m;
}

int calc(vector<int> &V){
	sort(V.begin(), V.end());
	int s = V[SIZE(V)/2];
	int c = 0;
	for(int v : V)
		c += abs(s - v);
	return c;
}

int main(){
	int Z; scanf("%d", &Z); FWD(z,1,Z+1){
		repr.clear();
		scanf("%d", &n);
		scanf("%s", buff);
		repr.pb(buff[0]);
		m = strlen(buff);
		FWD(i,0,m)
			rs[i].clear();
		FWD(i,1,m)
			if(repr.back() != buff[i])
				repr.push_back(buff[i]);
		works = true;
		if(!parse()) works = false;
		FWD(i,1,n){
			scanf("%s", buff);
			m = strlen(buff);
			if(!parse()) works = false;
		}
		if(!works)
			printf("Case #%d: Fegla Won\n", z);
		else{
			int c = 0;
			FWD(i,0,SIZE(repr))
				c += calc(rs[i]);
			printf("Case #%d: %d\n", z, c);
		}
	}
	return 0;
}
