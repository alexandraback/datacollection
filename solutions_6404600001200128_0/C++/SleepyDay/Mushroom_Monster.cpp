#include <vector>
#include <algorithm>
#include <fstream>
#include <stdlib.h> 
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stack>
#include <string.h>
#include <iomanip>
#include <sstream>
#include <map>
#include <set>

using namespace std;

#define ll long long
#define ull unsigned long long

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
	ll i, numCase, n;
	cin>>numCase;
	for(i=0; i<numCase; i++){
		ll m[10001], ans1=0, ans2=0;
		cin>>n;
		for(int j=1; j<=n; j++){
			cin>>m[j];
		}
		int maxdiff=0;
		for(int j=2; j<=n; j++){
			if(m[j] < m[j-1]){
				ans1=ans1+m[j-1]-m[j];
				if(maxdiff < m[j-1]-m[j]){
					maxdiff=m[j-1]-m[j];
				}
			}
		}
		for(int j=1; j<=n-1; j++){
			if(maxdiff > m[j]){
				ans2=ans2+m[j];
			}
			else{
				ans2=ans2+maxdiff;
			}
		}
		cout << "Case #" << (i+1) << ": "<<ans1<<" "<<ans2<<endl;
	}	
	return 0;
}
