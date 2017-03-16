#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>
#define MOD 1000000007
using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define PB(X) push_back(X)
#define fill(x,v) memset(x,v,sizeof(x))

#define Fill(x,y) memset(x,y,sizeof(x))
int NumberOfSetBits(int i)
{
     i = i - ((i >> 1) & 0x55555555);
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}
int getAns(int index,int r,int c,int n){
    if(NumberOfSetBits(index)!=n)
        return MOD;
    bool Grid[r*c+100];
    int ind=0;
    Fill(Grid,false);
    while(index){
        if(index&1){
            Grid[ind]=true;
        }
        index=index>>1;
        ind++;
    }
    int score=0;
    for(int i=0 ; i<r ; i++){
        for(int j=0 ; j<c ; j++){
            if(Grid[i*c+j]==false)
                continue;
            if(j+1<c && Grid[i*c + j+1])
                score++;
            if(i+1<r && Grid[(i+1)*c+ j])
                score++;
        }
    }
    return score;
}
int main()
{
	int testCases;
	freopen("Bsmall.in","r",stdin);
	freopen("OutputSmallB.out","w",stdout);
	cin>>testCases;
	int r,c,n;
	for(int k=1 ; k<=testCases ; k++){
	    cout<<"Case #"<<k<<": ";
        cin>>r>>c>>n;
        if(n==0 || n==1){
            cout<<0<<endl;
            continue;
        }
        int current=MOD;
        int ans;
        for(int i=1 ; i<=(1<<(r*c)) ; i++){
            ans=getAns(i,r,c,n);
            if(ans<current)
                current=ans;
            if(current==0)
                break;
        }
        cout<<current<<endl;
	}
	return 0;
}
