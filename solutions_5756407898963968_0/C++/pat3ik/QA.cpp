#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <climits>
#include <cassert>

#define FOR(i,n) for(int i=0,_n=n;i<_n;i++)
#define FORD(i,n) for(int i=n;i>=0;i--)
#define FORR(i,s,n) for(int i=s,_n=n;i<_n;i++)
#define FORRD(i,n,s) for(int i=n,_s=s;i>=_s;i--)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pli pair<ll,int>
#define vi vector<int>
#define fs first
#define sec second

#define maxn 100000
using namespace std;
typedef long long ll;

int row[2][4];
int main(){
	int t,a,tmp;
	cin>>t;
	FORR(tt,1,t + 1){
		FOR(i,2)
		{
			cin>>a; a--;
			FOR(j,4)
				FOR(k,4)
				{
					cin>>tmp;
					if(j == a) row[i][k] = tmp;
				}
		}
		int cnt = 0,p = -1;
		FOR(i,4)
			FOR(j,4)
				if(row[0][i] == row[1][j]){ cnt++; p = row[0][i]; }
		cout<<"Case #"<<tt<<": ";
		if(cnt > 1)
			cout<<"Bad magician!\n";
		else if(cnt == 0)
			cout<<"Volunteer cheated!\n";
		else cout<<p<<"\n";
	}
	return 0;
}
