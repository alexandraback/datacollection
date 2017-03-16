#include <iostream>
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
long x[3000];
long y[3000];
int t,a,b,c;
void print(int k){
    int min=a;
    for(int i=0;i<a;i++){
        if(i==k) continue;
        int up=0,down=0;
        for(int j=0;j<a;j++){
            if(j==i||j==k) continue;
            if((y[i]-y[k])*(x[j]-x[k])+y[k]*(x[i]-x[k])>y[j]*(x[i]-x[k]))up++;
            if((y[i]-y[k])*(x[j]-x[k])+y[k]*(x[i]-x[k])<y[j]*(x[i]-x[k]))down++;
        }
        min=min<up?min:up;
        min=min<down?min:down;
    }
    cout<<min<<endl;
}


int main(int argc, char* argv[]){
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a;
        for(int j=0;j<a;j++){
            cin>>x[j]>>y[j];
        }
        cout<<"Case #"<<i+1<<":"<<endl;
        for(int j=0;j<a;j++){
            print(j);
        }
    }
    return 0;
}
