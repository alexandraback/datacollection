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

string bstr;
string str[102];
int cc[102];
int ptrs[102];
int main()
{
	ios_base::sync_with_stdio(false);
	int n,t;
	cin >> t;
	bool found;
	bool noAns;
	int med;
	int ans;
	vector<int>medVect;
	for(int tt = 1; tt <= t; tt++){
		bstr = "";
		cin >> n;
		ans = 0;
		for(int i = 0;i<n;i++)
			cin >> str[i];
		bstr = str[0][0];
		memset(cc, 0, sizeof(bstr));
		memset(ptrs, 0, sizeof(ptrs));
		for(int i = 1;i< str[0].length(); i++){
			if( str[0][i] == str[0][i-1])
				continue;
			bstr += str[0][i];
		}
		noAns = false;
		for(int i = 0; i < bstr.length() && !noAns; i++){
			for(int j = 0; j < n && !noAns;j++){
				cc[j] = 0;
				found = false;
				while( str[j][ptrs[j]] == bstr[i] && ptrs[j] < str[j].length()){
					found = true;
					cc[j]++;
					ptrs[j]++;
				}
				if(!found)
					noAns = true;
			}
			sort(cc, cc+n);
			med = cc[ int(n/2) ];
			for(int j = 0;j<n;j++)
				ans += mabs(med-cc[j]);
		}
		for(int j = 0; j < n && !noAns;j++)
			if(ptrs[j] != str[j].length())
				noAns = true;
		
		cout << "Case #" << tt << ": ";
		if(noAns)
			cout << "Fegla Won" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}