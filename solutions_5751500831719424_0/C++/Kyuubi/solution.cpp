#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

#define MOD 1000000007
#define SWAP(a,b) {a=(a)^(b);b = (a)^(b);a= (a)^(b);}

using namespace std;
inline long long minOf(long long x, long long y){return (x<y?x:y);}
inline long long maxOf(long long x, long long y){return (x>y?x:y);}
inline long long mabs(long long x){return (x<0?-x:x);}

int main()
{
	ios_base::sync_with_stdio(false);
	int n,t;
	cin >> t;
	string s1,s2;
	bool noAns;
	int ans;
	for(int tt = 1; tt <= t; tt++){
		cin >> n;
		cin >> s1 >> s2;
		ans = 0;
		noAns = false;
		int ii = 0, jj = 0;
		char ch;
		int c1,c2;
		while( ii < s1.length() && jj < s2.length()){
			ch = s1[ii];
			c1 = c2 = 0;
			while(s1[ii] == ch){
				c1++;
				ii++;
			}
			while(s2[jj] == ch){
				c2++;
				jj++;
			}
			if(!c1 || !c2)
				noAns = true;
			ans += mabs(c1-c2);
		}
		if(ii != s1.length() || jj != s2.length())
			noAns = true;
		cout << "Case #" << tt << ": ";
		
		if(noAns)
			cout << "Fegla Won" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}