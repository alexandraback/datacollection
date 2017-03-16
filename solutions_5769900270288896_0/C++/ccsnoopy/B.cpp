#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long long LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#ifdef DEBUG
    #define cek(x) cout<<x
#else
    #define cek(x) if(false){}
#endif // DEBUG

#define fi first
#define se second
#define INF 1000000000
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define PI acos(-1.0)
#define pb push_back
#define TC() while(tc--)
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORN(i,n) for(int i=0;i<=n;i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define REPN(i,a,b) for(int i=a;i<=b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define sc(x) scanf("%d",&x)

int main(void){
    #ifdef ccsnoopy
        freopen("C:/Users/SONY/Desktop/B-small-attempt1.in", "r", stdin);
        freopen("C:/Users/SONY/Desktop/out.txt","w",stdout);
    #endif
    //to compile: g++ -o foo filename.cpp -lm -Dccsnoopy for debug.
    int tc,casecounter = 1;
    sc(tc);
    int r,c,n;

    while(tc--){
        sc(r);sc(c);sc(n);
        int happy;
        if((r*c + 1)/2 >= n)happy = 0;
        else{
            int lebih = n - (r*c+1)/2;
            if(c < r){
                int temp = r;
                r = c;
                c = temp;
            }
            if(r == 1){
                happy = lebih*2;
                if(c%2 == 0)happy--;
            }else if(r == 2){
                happy = min(lebih,2)*2 + max(lebih-2,0)*3;
            }else if(r == 3){
                if(c == 3){
                    int arr[] = {0,3,6,8,12};
                    happy = arr[lebih];
                }else if(c == 4){
                    int arr[] = {0,2,4,7,10,13,17};
                    happy = arr[lebih];
                }else{
                    int arr[] = {0,3,6,9,12,14,18,22};
                    happy = arr[lebih];
                }
            }else{
                happy = min(lebih,2)*2 + max(min(4,lebih-2),0)*3 + max(lebih-6,0)*4;
            }
        }
        printf("Case #%d: %d\n",casecounter++,happy);
    }

    return 0;
}



