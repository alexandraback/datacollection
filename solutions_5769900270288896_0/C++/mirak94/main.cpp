#include <iostream>
#include <cstdio>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <string>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <list>
#define MOD 1000000007
#define MAXN 25

using namespace std;
int t;
int dist[10000100];
int n,m,r,c;
typedef pair<int, int>  ii;
int get_len(long long num){
    int ret =0;
    while (num) {
        ret++;
        num/=10;
    }
    return ret;
}
long long rev_num(long long num){
    long long pw=1;
    for (int i =0; i<get_len(num)-1; i++) {
        pw*=10;
    }
    int ret=0;
    while (num) {
        ret+=(pw*(num%10));
        num/=10;
        pw/=10;
    }
    return ret;
}
int bin_search(int key){
    
    return 0;
}
int count_one(int num){
    int res=0;
    while(num){
        if(num&(1<<0)){
            res++;
        }
        num>>=1;
    }
    return res;
}
int check(int num){
    int ret=0;
    int grid[r][c];
    int k =0;
    for(int i=0;i<r;i++){
        for (int j =0; j<c; j++) {
            grid[i][j]= (num&(1<<k))?1:0;
            k++;
        }
    }
    for (int i =0; i<r; i++) {
        for (int j =0; j<c; j++) {
            if(grid[i][j]){
                if(i-1>=0&&grid[i-1][j]){
                    ret++;
                }
                if(i+1<r&&grid[i+1][j]){
                    ret++;
                }
                if(j-1>=0&&grid[i][j-1]){
                    ret++;
                }
                if(j+1<c&&grid[i][j+1]){
                    ret++;
                }
                grid[i][j]=0;
            }
            
        }
    }
    return ret;
}
int main (){
    freopen("/Users/Masoud/Desktop/in.txt", "r", stdin);
    freopen("/Users/Masoud/Desktop/out.txt", "w", stdout);
    scanf("%d",&t);
    int ca =1;
    while(t--){
        scanf("%d %d %d",&r,&c,&n);
        int res = 1000000000;
        for(int i =0;i<(1<<(r*c));i++){
            if(count_one(i)==n){
                res = min(res,check(i));
            }
        }
        printf("Case #%d: %d\n",ca++,res);
    }
    
    return 0;
}