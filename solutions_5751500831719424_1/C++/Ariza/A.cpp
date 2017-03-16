#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define EPS (1e-10)
#define lef(x) (x<<1)
#define rig(x) (x<<1)+1
#define PI (2*acos(0.0))

string inp[100];
string uni[100];
int memo[100][100];
int N;

void init(){
     for (int i=0;i<100;++i){
         inp[i]=uni[i]="";
         for (int j=0;j<100;++j){
             memo[i][j]=0;
         }
     }
}
string noDouble(int y){
       string x = inp[y];
       string ret="";
       char last = '\0';
       for (int i=0;i<x.size();++i){
           if (last == '\0'){
              ret += x[i];
              last = x[i];
           }
           else{
                if (last!=x[i]){
                   ret+=x[i];
                   last=x[i];
                }
           }
       }
       return ret;
}
void fillMemo(int y){
     string x=inp[y];
     int idx=0,tmp=0;
     char last='\0';
     for (int i=0;i<x.size();++i){
         if (last=='\0'){
            tmp=1;
            last=x[i];
         }
         else{
              if (last!=x[i]){
                 memo[y][idx]=tmp;
                 idx++;
                 tmp=1;
                 last=x[i];
              }
              else tmp++;
         }
     }
     memo[y][idx]=tmp;
}
int getMin(int idx){
    int ret=1000000000,ctr;
    for (int i=0;i<N;++i){
        //pivot = i
        ctr=0;
        for (int j=0;j<N;++j){
            if (i!=j){
               ctr+=abs(memo[i][idx]-memo[j][idx]);
            }
        }
        ret=min(ret,ctr);
    }
    return ret;
}
void solve(){
     init();
     printf(" ");
     scanf("%d",&N);
     for (int i=0;i<N;++i) cin >> inp[i];
     for (int i=0;i<N;++i){
         uni[i] = noDouble(i);
     }
     bool safe=1;
     for (int i=1;i<N;++i){
         if (uni[i]!=uni[0]){
            safe=0;
            break;
         }
     }
     if (!safe){
        printf("Fegla Won\n");
        return;
     }
     for (int i=0;i<N;++i){
         fillMemo(i);
     }
     int ret=0;
     for (int idx=0;idx<100;++idx){
         ret+=getMin(idx);
     }
     printf("%d\n",ret);
}
int main(){
    int ntest;
    scanf("%d",&ntest);
    for (int test=1;test<=ntest;++test){
        printf("Case #%d:",test);
        solve();
    }
    return 0;
}
