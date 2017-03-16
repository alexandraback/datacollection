#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N=1010;
int d[N];

int main(){
   freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout);
   int T,n;
   cin >> T;
   for(int t=1;t<=T;t++){
        int y=0,z=0,w=0;
        cin >> n;
        memset(d,0,sizeof(d));
        for(int i=0;i<n;i++){
            cin >> d[i];
        }
        for(int i=1;i<n;i++){
            y+=max(0,d[i-1]-d[i]);
            w=max(d[i-1]-d[i],w);
        }
        for(int i=1;i<n;i++){
            z+=min(d[i-1],w);
        }
        printf("Case #%d: %d %d\n",t,y,z);
   }
    return 0;
}
