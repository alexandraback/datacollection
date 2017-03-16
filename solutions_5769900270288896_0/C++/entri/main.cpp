#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <string.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

typedef     long long       LL;
typedef     pair<int, int>  pii;
typedef     pair<LL, LL>    pll;
typedef     pair<pii,pii>   ppi;
typedef     vector<int>     vi;
typedef     vector<vi>      vvi;
typedef     vector<LL>      vl;
typedef     vector<vl>      vvl;
typedef     vector<string>  vs;
typedef     vector<pii>     vii;

double      EPS = 1e-9;
int         INF = 2000000000;
long long   INFF = 8000000000000000000LL;
double      PI = acos(-1);
int         dx[8] = {-1,0,0,1,-1,-1,1,1};
int         dy[8] = {0,1,-1,0,-1,1,-1,1};
int         hx[4] = {-1, 0, 1, 0};
int         hy[4] = {0, -1, 0, 1};

#define     fi      first
#define     se      second
#define     mp      make_pair
#define     pb      push_back
#define     SIZE(v)         (int)v.size()
#define     ALL(v)          v.begin(),v.end()
#define     ALLA(arr,sz)    arr,arr+sz
#define     SORT(v)         sort(ALL(v))
#define     SORTA(arr,sz)   sort(ALLA(arr,sz))
#define     SQR(x)          ((x) * (x))
#define     FOR(i,s,e)      for(int (i) = (s); (i) <  (e); ++(i))
#define     FORE(i,s,e)     for(int (i) = (s); (i) <= (e); ++(i))
#define     FORD(i,e,s)     for(int (i) = (e); (i) >= (s); --(i))
#define     REP(i,n)        FOR(i,0,n)
#define     REPE(i,n)       FORE(i,1,n)
#define     REPD(i,n)       FORD(i,n,1)

inline string IntToString(int a){
    char x[100];
    sprintf(x,"%d",a); string s = x;
    return s;
}

inline int StringToInt(string a){
    char x[100]; int res;
    strcpy(x,a.c_str()); sscanf(x,"%d",&res);
    return res;
}
//== End of NNN template===
int T;
int N, R, C, RC;
const int NRCMax = 10005;

vector<int> nnList[NRCMax];
int nnBusyOf[NRCMax];

set<pair<int, pii>> MySet;

int idOf(int row, int col){
    return (row * C + col);
};

void init(){
    MySet.clear();
    RC = R* C;
    int id, rx, cy, idx;
    int cnn;
    REP(r, R)
    REP(c, C){
        id = idOf(r,c);

        //cout <<r<<" "<<c<<" "<<id<<endl;

        nnList[id].clear();
        nnBusyOf[id] = 0;
        REP(i,4){
            rx = r + hx[i];
            cy = c + hy[i];
            if ( (0<=rx) and (rx<R) and (0<=cy) and (cy<C)){
                idx = idOf(rx, cy);
                nnList[id].pb(idx);
            }
        }// for 4 dir
        MySet.insert(mp( nnList[id].size(),  mp(nnBusyOf[id], id)));
    }; // for each cell
};

int solve(){

    int ans = 0;

    pair<int, pii> FirstChoice;
    pair<int, pii> myNB;
    int id, nid;

    REP(i,N){
        FirstChoice = *MySet.begin();
        MySet.erase(MySet.begin());
        id = FirstChoice.second.second;

        //cout <<"id is: "<<id<<endl;

        //recalculate busy nn:

        REP(k, nnList[id].size()){
            nid = nnList[id][k];
            myNB = mp(nnList[nid].size(), mp(nnBusyOf[nid], nid));
            if (MySet.count(myNB)<1){
                ans++;
                continue;
            }
            MySet.erase(myNB);
            nnBusyOf[nid]++;
            myNB = mp(nnList[nid].size(), mp(nnBusyOf[nid], nid));
            MySet.insert(myNB);
        }
    };

    return ans;
};

int main()
{
    cin >>T;
    int t = 0;
    while(T--){
        cin >>R>>C>>N;

        init();

        t++;
        cout << "Case #"<<t<<": "<<solve()<<endl;
    }


    return 0;
}
