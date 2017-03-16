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

int be[10][10];
int af[10][10];
int co[100];

string IntToString(int number){
	stringstream ss;
	ss << number;
	return ss.str();
}

int main() {
	// freopen ("input.txt", "r", stdin);
	// freopen ("output.txt", "w", stdout);
	int t;
	int q1,q2;
	cin>>t;
	for(int i=0;i<t;i++){
		string res="Case #"+IntToString(i+1)+": ";
		cin>>q1;
		q1--;
		for(int x=0;x<4;x++){
			for(int y=0;y<4;y++){
				cin>>be[x][y];
			}
		}
		cin>>q2;
		q2--;
		for(int x=0;x<4;x++){
			for(int y=0;y<4;y++){
				cin>>af[x][y];
			}
		}
		memset(co,0,sizeof(co));
		for(int y=0;y<4;y++)co[be[q1][y]]++;
		for(int y=0;y<4;y++)co[af[q2][y]]++;
		int ans,c=0;
		for(int i=0;i<100;i++){
			if(co[i]==2){
				ans=i;
				c++;
			}
		}
		if(c==1){
			res+=IntToString(ans);
		}else if(c>1){
			res+="Bad magician!";
		}else{
			res+="Volunteer cheated!";
		}
		cout<<res<<endl;
	}
}