#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fornn(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vi_it;
typedef vector<vi> vvi;

typedef long long i64;
typedef pair<i64, i64> pi64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
int t,a,b,c;

int num(){
    int ret=0;
    int sl[4];
    if(c<=(a*b+1)/2) return 0;
    int tot=a*b/2;
    int extra=c-(a*b+1)/2;
    sl[0]=sl[1]=sl[2]=sl[3]=0;
    if(a==1||b==1){
        sl[0]=(a+b)%2;
        sl[1]=tot-sl[1];
    }else if(a%2==0){
        sl[2]=(a-2)+(b-2);
        sl[1]=2;
        sl[3]=tot-sl[1]-sl[2];
    }else{
        sl[2]=a/2*2+b/2*2;
        sl[3]=tot-sl[2];
    }
    for(int i=0;i<4;i++){
        if(extra>sl[i]){
            ret+=sl[i]*(i+1);
            extra-=sl[i];
        }else{
            ret+=extra*(i+1);
            break;
        }
    }
    return ret;
}
int num2(){
    int ret=0;
    int sl[4];
    if(c<=(a*b)/2) return 0;
    int tot=(a*b+1)/2;
    int extra=c-(a*b)/2;
    sl[0]=sl[1]=sl[2]=sl[3]=0;
    if(a==1){
        sl[0]=(b+1)%2;
        sl[1]=tot-sl[1];
    }else if(a%2==0){
        sl[2]=(a-2)+(b-2);
        sl[1]=2;
        sl[3]=tot-sl[1]-sl[2];
    }else{
        sl[1]=4;
        sl[2]=a-3+b-3;
        sl[3]=tot-sl[2]-sl[1];
    }
    for(int i=0;i<4;i++){
        if(extra>sl[i]){
            ret+=sl[i]*(i+1);
            extra-=sl[i];
        }else{
            ret+=extra*(i+1);
            break;
        }
    }
    return ret;
}

int main(int argc, char* argv[]){
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a>>b>>c;
        if(a%2==1){
            int tmp=a;a=b;b=tmp;
        }
        int x=num(),y=num2();
        cout<<"Case #"<<i+1<<": "<<min(x,y)<<endl;
    }
    return 0;
}
