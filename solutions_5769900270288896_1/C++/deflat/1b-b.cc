#include<iostream>
#include<sstream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<functional>
#include<climits>
#include<utility>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define FORB(i,s,e,st) for (int i = int(s); i < int(e); i+=(int(st)))
#define FOR(i,s,e) FORB(i,s,e,1)
#define REP(i,x) FOR(i,0,x)
#define CLR(a) memset((a), 0 ,sizeof(a))


const int MOD = 1000000007;
const double PI  = acos(-1.0);



int main(){

    int T;
    cin>>T;
    REP(t,T){
        cout<<"Case #"<<(t+1)<<": ";
        int r,c,n;
        cin>>r>>c>>n;
        
        if(((r*c)+1)/2>= n){
            cout<<"0\n";
        }else if(r==1||c==1){
            cout<<(r*c-1)-(2*(r*c-n))<<"\n";
        }else if(r*c%2==0){
            ll ret=(r-1)*c + r*(c-1);
            ll fcnt=(r-2)*(c-2);
            int emp=r*c-n;
            if(emp <= fcnt/2){
                cout<<ret-emp*4<<"\n";
                continue;
            }
            ret-=fcnt*2;
            emp-=fcnt/2;
            fcnt=(r*c-fcnt)/2 -2;
            if(emp<=fcnt){
                cout<<ret-emp*3<<"\n";
            }else{
                cout<<"2\n";
            }
        }else{
            ll ret=(r-1)*c + r*(c-1);
            ll fcnt=(r-2)*(c-2);
            int emp=r*c-n;
            if(emp <= (fcnt+1)/2){
                cout<<ret-emp*4<<"\n";
                continue;
            }
            ll pf =fcnt;
            emp-=(fcnt+1)/2;
            fcnt=(r*c-fcnt)/2 -4;
            if(fcnt>=emp){
                cout<<ret-(pf+1)*2 - emp*3<<"\n";
            }else{
            cout<<ret-(pf-1)*2-(++emp)*3<<"\n";
            }
        }
        
    }
}
