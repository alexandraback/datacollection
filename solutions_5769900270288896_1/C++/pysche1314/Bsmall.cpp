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
    freopen("C:\\Users\\chmffwn1\\Downloads\\B-large.in", "r", stdin);
    freopen("C:\\Users\\chmffwn1\\Downloads\\B-large.out", "w", stdout);
    int T;
    cin >> T;
    int R, C, N;
    rep(tc, 0, T) {
        cin >> R >> C >> N;
        std::priority_queue<int, std::vector<int>, std::greater<int> > A,B;
        int re=0;
        if(R>C){
          int tmp;
          tmp=R;
          R = C;
          C = tmp;
        }
        int total=R*(C-1)+(R-1)*C;
        int half=(R/2)*C +(R%2)*(C/2);
        if(N <= half){
            re=0;
        }
        else{
            rep (i,0,R){
              rep(j,0,C){
                int tmp=4;
                if(i==0||i==R-1){
                  tmp--;
                  if(R==1)
                    tmp--;
                }
                if(j==0||j==C-1){
                  tmp--;
                  if(C==1)
                    tmp--;
                }
                if((i+j)%2){
                  A.push(tmp);
                  B.push(0);
                }
                else{
                  B.push(tmp);
                  A.push(0);
                }
              }
            }
            vector<int> a,b;
            a.push_back(A.top());
            A.pop();
            b.push_back(B.top());
            B.pop();
            rep(i,1,R*C){
              a.push_back(a[i-1]+A.top());
              A.pop();
              b.push_back(b[i-1]+B.top());
              B.pop();
            }
            re=min(a[N-1],b[N-1]);
            re=min(total,re);


        }

        cout << "Case #" << (tc+1) << ": " <<  re << endl;

    }
	return 0;
}
