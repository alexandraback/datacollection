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
int t,a,b,c;
int m[1000];
long tar;

long search(long time){
    long sum=0;
    for(int i=0;i<a;i++){
        sum+=(time)/m[i]+1;
    }
    //cerr<<time<<" "<<sum<<endl;
    return sum;
    
}
int find(long time){
    long sum=0;
    for(int i=0;i<a;i++){
        sum+=(time+m[i]-1)/m[i];
    }
    long wait=tar-sum;
    for(int i=0;i<a;i++){
        if(time%m[i]==0){
            wait--;
            if(wait==0) return i+1;
        }
    }
    return -1;
}

long binsearch(long lcan){
   long small=0,large=lcan; 
   while(small<large-1){
   //cout<<small<<" "<<large<<endl;
        long mid=(small+large)/2; 
        long ans=search(mid);
        //cerr<<ans<<endl;
        if(ans>=tar){
            large=mid;
        }else{
            small=mid;
        }
   }
   //cerr<<small<<" "<<large<<endl;
   return find(large);
}

int main(int argc, char* argv[]){
    cin>>t;
    for(int i=0;i<t;i++){
        cerr<<"read "<<i<<endl;
        cin>>a>>tar;
        cerr<<"head "<<i<<" "<<a<<" "<<tar<<endl;
        long max=0;
        for(int i=0;i<a;i++){
            cin>>m[i];
            max=max>m[i]?max:m[i];
        }
        int num;
        cerr<<"suc "<<i<<endl;
        if(tar<=a){
            num=tar; 
        }else{
            num=binsearch((max/a+1)*tar);
        }
        cout<<"Case #"<<i+1<<": "<<num<<endl;
    }
    return 0;
}
