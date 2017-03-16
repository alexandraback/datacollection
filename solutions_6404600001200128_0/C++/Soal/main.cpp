#include <iostream>
#include <string>
#include <cstdio>
#include <climits>
using namespace std;

int a[1100];

int main(){
    //getResult("jijiji");
    //getResult("");
    freopen("/Users/jiangzefan/code/C/C/input.txt","r",stdin);
    freopen("/Users/jiangzefan/code/C/C/output.txt","w",stdout);
    int _,__;
    scanf("%d",&_);
    for (__=1;__<=_;__++){
        int n;
        scanf("%d",&n);
        for (int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        int ans1=0;
        for (int i=0;i<n;i++){
            if (a[i]<a[i-1]){
                ans1+=a[i-1]-a[i];
            }
        }
        int ans2=0,Max=0;
        for (int i=1;i<n;i++){
            if (a[i]<a[i-1]){
                Max=max(Max,a[i-1]-a[i]);
            }
        }
        for (int i=0;i<n-1;i++){
            if (a[i]>=Max){
                ans2+=Max;
            }else{
                ans2+=a[i];
            }
        }
        printf("Case #%d: %d %d\n",__,ans1,ans2);
    }
    
}