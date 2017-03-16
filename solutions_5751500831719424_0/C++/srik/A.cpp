#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <climits>

using namespace std;

typedef int ttyp;
#define fors(bg,en) for(int i=bg;i<en;i++)
#define forso(j,bg,en) for(int j=bg;j<en;j++)
#define forz(n) for(int i=0;i<n;i++)
#define forzo(j,n) for(int j=0;j<n;j++)
#define forsz(v) for(int i=0;i<v.size();i++)
#define forszo(j,v) for(int j=0;j<v.size();j++)
#define MP make_pair
#define sz(v) v.size()


void doit(){
    int a[105], ix[105], n, cix, ret=0, tret, tadd;
    vector <string> vs;
    memset(ix,0,sizeof(ix));
    cin>>n;
    vs.resize(n);
    forz(n){
        cin>>vs[i];
    }
    while(ix[0]<vs[0].size()){
        cix = ix[0];
        forz(n){
            a[i]=ix[i];
            while(ix[i]<vs[i].size() && vs[i][ix[i]]==vs[0][cix]){
                ix[i]++;
            }
            a[i] = ix[i]-a[i];
            if(a[i]==0){
                cout<<"Fegla Won"<<endl;
                return;
            }
        }
        tret = 10000005;
        fors(1,101){
            tadd = 0;
            forzo(j,n){
                tadd += abs(i-a[j]);
            }
            tret = min(tret, tadd);
        }
        ret += tret;
    }
    forz(n){
        if(ix[i]<vs[i].size()){
            cout<<"Fegla Won"<<endl;
            return;
        }
    }
    cout<<ret<<endl;
  return;
}
int main(){
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++){
      cout<<"Case #"<<i<<": ";
      doit();
    }
    return 0;
}
