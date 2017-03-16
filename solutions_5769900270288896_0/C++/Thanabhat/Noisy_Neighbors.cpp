/*
AUTHOR: THANABHAT KOOMSUBHA
LANG: C++
*/

#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<list>
#include<set>
#include<queue>
#include<map>
#include<cctype>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<ctime>

using namespace std;

int solve(int cc){
    int R,C,N;
    scanf("%d %d %d",&R,&C,&N);
    int RC=R*C;
    int perm[16];
    int mp[16][16];
    int sol=1000000;
    for(int i=0;i<RC;i++){perm[i]=0;}
    for(int i=RC-1;i>RC-1-N;i--){perm[i]=1;}
    do{
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                mp[i][j]=0;
            }
        }
        for(int i=0;i<RC;i++){
            if(perm[i]==1){
                mp[i/C][i%C]=1;
            }
        }
        int cnt=0;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(mp[i][j]==0){
                    continue;
                }
                if(i<R-1&&mp[i+1][j]==1){
                    cnt++;
                }
                if(j<C-1&&mp[i][j+1]==1){
                    cnt++;
                }
            }
        }
        sol=min(sol,cnt);
    }while(next_permutation(perm,perm+RC));
    printf("Case #%d: %d\n",cc,sol);
    return 1;
}

int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        solve(i);
    }

	return 0;
}
