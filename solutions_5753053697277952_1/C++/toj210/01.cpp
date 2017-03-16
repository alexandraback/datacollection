#include<iostream>
#include<sstream>
#include<iomanip>
#include<stdlib.h>
#include<string>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<map>
#include<utility>
#include<algorithm>
#include<complex>
using namespace std;
#define loop(i,l,r) for(int (i)=(int)(l);(i)<(int)(r);(i)++)
#define rloop(i,l,r) for(int (i)=(int)(l);(i)>(int)(r);(i)--)
#define rep(i,n) loop(i,0,n)
#define rrep(i,n) rloop(i,n-1,-1)
#define INF 0x3f3f3f3f
#define mod 1000000007LL
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef complex<double> C;

vector<string> split(stringstream& ss){
	string str;
	vector<string> res;
	while(ss>>str)res.push_back(str);
	return res;
}

int main(){
		int n,m;
		cin>>n;
		rep(i,n){
				cin>>m;
				int mx=0;
				vector<int> d(m),v;
				cout<<"Case #"<<i+1<<": ";
				rep(j,m){
						cin>>d[j];
						mx=max(mx,d[j]);
				}
				do{
					int cnt=0;
					v.clear();
					rep(j,m)if(mx==d[j])cnt++,v.push_back(j);
					if(cnt>=2&&cnt!=3)rep(k,2)d[v[k]]--,cout<<(char)(v[k]+'A');
					else if(cnt==1||cnt==3)d[v[0]]--,cout<<(char)(v[0]+'A');
					if(cnt==1||cnt==2)mx=d[v[0]];
					cout<<" ";
				}while(mx>0);
				cout<<endl;
		}
}
