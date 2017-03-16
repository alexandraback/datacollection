#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

int data[1005];
int main(){
    freopen("A-large (1).in","r",stdin);
    freopen("outputA1.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int co=1;co<=t;co++){
        int n;
        scanf("%d",&n);
        for(int g=0;g<n;g++) scanf("%d",&data[g]);
        int ans1=0,ans2=0;
        int temp2=-1;
        for(int g=1;g<n;g++){
            if(data[g]<data[g-1]) ans1+=(data[g-1]-data[g]);
            temp2 = max(temp2,data[g-1]-data[g]);
        }
        for(int g=1;g<n;g++){
            ans2+=(min(data[g-1],temp2));
        }
        printf("Case #%d: %d %d\n",co,ans1,ans2);

    }


}
