#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <cassert>
#include <iomanip>
using namespace std;
static const double EPS = 1e-9;
static const int mod = 100000007;
typedef long long ll;

int t,n,l;
string str[101];

int main() {
	// freopen ("input.txt", "r", stdin);
	// freopen ("output.txt", "w", stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cout<<"Case #"<<(i+1)<<": ";
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>str[j];
		}

		vector<int> vi[101];
		vector<char> ci[101];
		for(int j=0;j<n;j++){
			for(int k=0;k<str[j].size();k++){
				int index=k+1;
				ci[j].push_back(str[j][k]);
				for(;index<str[j].size() && str[j][index-1]==str[j][index];index++){
				}
				vi[j].push_back(index-k);
				k=index-1;
			}
		}
		bool ok=true;
		for(int j=1;j<n;j++){
			if(ci[0].size()!=ci[j].size())ok=false;
			for(int k=0;ok && k<ci[0].size();k++){
				if(ci[0][k]!=ci[j][k])ok=false;
			}
		}
		if(!ok){
			cout<<"Fegla Won"<<endl;
			continue;
		}
		int res=0;

		for(int j=0;j<vi[0].size();j++){
			int tmp=0xffffff;
			int minLen=0xffffff,maxLen=0;
			for(int k=0;k<n;k++){
				minLen=min(minLen,vi[k][j]);
				maxLen=max(maxLen,vi[k][j]);
			}
			for(int len=minLen;len<=maxLen;len++){
				int tmptmp=0;
				for(int k=0;k<n;k++){
					tmptmp+=abs(vi[k][j]-len);
				}
				tmp=min(tmp,tmptmp);
			}
			res+=tmp;
		}

		cout<<res<<endl;
	}
}