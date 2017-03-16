#include<iostream>
#include <stdlib.h>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
#include<queue>

using namespace std;

#define INF (1<<29)
#define SET(a) memset(a,-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define CLR(a) memset(a,0,sizeof(a))
#define FILL(a,v) memset(a,v,sizeof(a))
#define PB push_back
#define FOR(i,n) for(int i = 0;i<n;i++)
#define PI acos(-1.0)
#define EPS 1e-9
#define MP(a,b) make_pair(a,b)
#define min3(a,b,c) min(a,min(b,c))
#define mai3(a,b,c) mai(a,mai(b,c))
#define READ freopen("input.tit", "r", stdin)
#define WRITE freopen("output.tit", "w", stdout)
#define LL long long
#define Mi 1000000005

#define F first
#define S second
#define pii pair<int,int>
#define pic pair<int,char>
#define p(i) printf("%d",i)
#define inp(i) scanf("%d",&i)
#define inpll(i) scanf("%lld",&i)
#define getci getchar_unlocked
/*inline void inp( int &n )
 {
 n=0;
 int ch=getci();int sign=1;
 while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getci();}
 
 while(  ch >= '0' && ch <= '9' )
 n = (n<<3)+(n<<1) + ch-'0', ch=getci();
 n=n*sign;
 }*/

using namespace std;
int n,total = 0;
vector<pic> v;
int rem[30];
void print() {
    for (int j=0;j<n;j++){
        cout<<v[j].first<<" "<<v[j].second<<endl;
    }
}

string getExitGuys() {
    string result = "";
    
    if (total > 3) {
        if (v[0].first==v[1].first) {
            v[0].first--;
            v[1].first--;
            total -= 2;
            result += v[0].second;
            result += v[1].second;
        }
        else{
            v[0].first -= 2;
            total -= 2;
            result += v[0].second;
            result += v[0].second;
        }
    }
    else if (total == 3) {
        v[0].first--;
        total--;
        result += v[0].second;
    }
    else {
        v[0].first--;
        v[1].first--;
        total -= 2;
        result += v[0].second;
        result += v[1].second;
    }
    sort(v.begin(), v.end(), greater<pic>());
    return result;
}

int main(){
    int t;
    inp(t);
    for(int i=0;i<t;i++){
        total = 0;
        v.clear();
        cout<<"Case #"<<i+1<<":";
        inp(n);
        for (int j=0;j<n;j++) {
            inp(rem[j]);
            total += rem[j];
        }
        for (int j=0;j<n;j++){
            v.PB(MP(rem[j], char(j+65)));
        }
        sort(v.begin(), v.end(), greater<pic>());
        while (v[0].first!=0) {
            string exitSenetor = getExitGuys();
            cout<<" "<<exitSenetor;
        }
        cout<<endl;
    }
    return 0;
}