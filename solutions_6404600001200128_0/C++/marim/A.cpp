#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#define sz size()
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define fu(i,n) for(int i=0; i<(n); i++)
#define ALL(a) (a).begin(),(a).end()
#define cl(a,co) memset(a,co,sizeof a)
#define un(a) sort(ALL(a)),a.erase( unique(ALL(a)), a.end() )
typedef long long ll;
//istringstream is(s); is >> a;

using namespace std;

int ileTestow;

int main(){

	scanf("%d",&ileTestow);

	for(int q=1; q<=ileTestow; q++){
		printf("Case #%d: ",q);
		
		int n, t[1000];
		int first=0,mx=0;
			
		cin >> n;

		for(int i=0; i<n; i++){
			cin >> t[i];	
			if( i > 0 && t[i] < t[i-1] ){ 
				first += t[i-1] - t[i];
				mx = max(mx, t[i-1] - t[i]);
			}
		}
		
		int second = 0;
		for(int i=0; i<n-1; i++){
			second += min(mx, t[i]);
		}
		
		printf("%d %d\n", first, second);
			
	}

	return 0;
}
