#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
 
using namespace std;
 
#define ll long long
#define pi pair<int,int>
#define pll pair<ll,ll>
#define pii pair<int,pi>
#define X first
#define Y second
#define pb push_back
#define ab(x) ((x)<0?(-(x)):(x))
#define xx(x) ((x)*(x))
#define mp make_pair
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define vpi vector<pi>
#define vpll vector<pll>
#define ALL(x) (x).begin(),(x).end()
#define Max (1<<30)
#define LLMax (1ll<<60)
template<class T>string ToString(T t){stringstream s;s<<t;return s.str();}
template<class T>void ToOther(T&t,string a){stringstream s(a);s>>t;}
 
int cnt[20];

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int CC=0;
	int Test; cin>>Test; while(Test--){
		CC++;
		memset(cnt,0,sizeof(cnt));
		int n=4;
		int num;

		for(int C=0;C<2;C++){
			cin>>num;
			int t;
			for(int i=0;i<n;i++)for(int j=0;j<n;j++){
				cin>>t;
				if(i==num-1)cnt[t]++;
			}
		}
		int r=0,idx=-1;
		for(int i=1;i<=16;i++)if(cnt[i]==2)r++,idx=i;


		cout<<"Case #"<<CC<<": ";
		if(r==0)cout<<"Volunteer cheated!";
		else if(r==1)cout<<idx;
		else cout<<"Bad magician!";
		puts("");
	}
}