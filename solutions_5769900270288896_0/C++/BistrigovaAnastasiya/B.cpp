#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <complex>
#include <ctime>
#include <iomanip>
#include <cassert>
#include <sstream>
#include <iterator>

using namespace std;

#define file "file"
#define mp make_pair
#define pb push_back
#define xx real()
#define yy imag()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef complex<double> point;

int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

void solve(){
    int r,c,n;
    scanf("%d%d%d",&r,&c,&n);
    int b = 1 << (r * c);
    int rc = r * c;
    int mn = 4 * r * c * r * c;
    for(int mask = 0;mask < b;mask++){
        int cnt = 0;
        for(int j = 0;j < rc;j++){
            if(mask & (1 << j)) cnt++;
            if(cnt > n) break;
        }
        if(cnt != n) continue;
        int cur = 0;
        for(int i = 0;i < r;i++){
            for(int j = 0;j < c;j++){
                if(!(mask & (1 << (i * c + j)))) continue;
                for(int k = 0;k < 4;k++){
                    int i2 = i + dx[k],j2 = j + dy[k];
                    if(i2 >= 0 && i2 < r && j2 >= 0 && j2 < c){
                        if((mask & (1 << (i2 * c + j2)))){
                           cur++;
                        }
                    }
                }
            }
        }
        cur /= 2;
        mn = min(mn, cur);
    }
    printf("%d\n",mn);
}

int main()
{
//	#ifndef ONLINE_JUDGE
//    assert(freopen("input.txt","r",stdin));
//    assert(freopen("output.txt","w",stdout));
//    #else
//    assert(freopen(file".in","r",stdin)); assert(freopen(file".out","w",stdout));
//    #endif
	int t = 1;
	scanf("%d",&t);
	int cs = 1;
	while(t--){
        printf("Case #%d: ",cs++);
		solve();
	}
	return 0;
}
