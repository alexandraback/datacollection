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

int s[1000];
int t,a,b,c;
int solve1(){
    int ret;
    for(int i=1;i<a;i++){
        if(s[i]<s[i-1]){
            ret+=s[i-1]-s[i];
        }
    }
    return ret;
}
int solve2(){
    int max=0;
    for(int i=1;i<a;i++){
        int trial=s[i-1]-s[i];
        max=max>trial?max:trial;
    }
    int ret=0;
    for(int i=0;i<a-1;i++){
        ret+=s[i]>max?max:s[i];
    }
    return ret;
}

int main(int argc, char* argv[]){
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a;
        for(int j=0;j<a;j++){
            cin>>s[j];
        }
        int m1=solve1();
        int m2=solve2();
        cout<<"Case #"<<i+1<<": "<<m1<<" "<<m2<<endl;
    }
    return 0;
}
