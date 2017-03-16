#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <list>
#include <set>
#include <map>
#include <ctime>
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define ms0(x) memset((x),0,sizeof(x))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define rep(i,m,n) for(int i=(m),_end=(n);i < _end;++i)
#define repe(i,m,n) for(int i=(m), _end =(n);i <= _end;++i)
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;
using namespace std;

int main(){
    freopen("/Users/hao/Dropbox/chmffwn1/gcj/Qualification2014/A/A/A-small-attempt0.in", "r", stdin);
    freopen("/Users/hao/Dropbox/chmffwn1/gcj/Qualification2014/A/A/A.out", "w", stdout);
    //ios_base::sync_with_stdio(false);
    int T;
    cin>>T;
    repe(c,1,T){
        int ln;
        int mat[4][4];
        map<int,int> st;
        cin>>ln;
        rep(i,0,4){
            rep(j,0,4){
                cin>>mat[i][j];
            }
        }
        rep(i,0,4){
            st.insert(mp(mat[ln-1][i],1));
        }
        cin>>ln;
        rep(i,0,4){
            rep(j,0,4){
                cin>>mat[i][j];
            }
        }
        int jud=0;
        int re=0;
        rep(i,0,4){
            if(st.count(mat[ln-1][i])){
                re=mat[ln-1][i];
                jud++;
            }
        }
        cout<<"Case #"<<c<<": ";
        if(jud==0) cout<<"Volunteer cheated!"<<endl;
        else if(jud==1) cout<<re<<endl;
        else cout<<"Bad magician!"<<endl;
    }
	return 0;
}