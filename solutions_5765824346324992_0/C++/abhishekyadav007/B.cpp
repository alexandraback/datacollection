#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <climits>
#include <cassert>
 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
 
#define pb push_back
#define mp make_pair
#define sz size()
#define ln length()
#define forr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) forr(i,0,n)
#define all(v) v.begin(),v.end()
#define uniq(v) sort(all(v));v.erase(unique(all(v)),v.end())
#define clr(a) memset(a,0,sizeof a)
#define debug if(1)
#define debugoff if(0)
 
#define print(x) cerr << x << " ";
#define pn() cerr << endl;
#define trace1(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
 
#define MAX 2000010
#define MOD 1000000007
#define endl '\n'

int arr[20];
int m[MAX][6];
int flg[6];
int fun_lcm(int a , int b){

	return (a*b)/__gcd(a,b);


}
int main(){
	int t,cases,n,b;
	string str ;

	cin>>cases;
	rep(t,cases){
		//clr(m);
		int lcm = 1;
		cin>>b>>n;
		rep(i,b){
			cin>>arr[i];
			lcm = fun_lcm(lcm,arr[i]);
		}
		//trace1(lcm);
		int diff = 0;
		rep(i,b)
			diff += (lcm/arr[i]);
		int N = (int)((n-1+diff)/diff);
		int cnt = (N-1)*diff + 1 ;
		int  ans = 0;
		//trace1(cnt);
		for(int i=1;i<=b;i++){
			m[1][i] = cnt++;
			flg[i] = arr[i-1];
			flg[i]--;
			if(m[1][i] == n){
				ans = i;
				break;
			}
		}
		if(!ans){
			for(int i=2;i<=lcm;i++){
				for(int j=1;j<=b;j++){
					if(flg[j]){
						m[i][j] = m[i-1][j];
						flg[j]--;
					}
					else{
						flg[j]=arr[j-1]-1;
						m[i][j] = cnt++;
						if(m[i][j] == n){
							ans = j;
							break;
						}
					}
				}
			}
		}

		cout<<"Case #"<<(t+1)<<": "<<ans<<endl;
	}
	return 0;
}

