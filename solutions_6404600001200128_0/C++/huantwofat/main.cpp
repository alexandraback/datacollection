#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int a[10005];
int main()
{
    int i,j,n,t,N=0;
    cin>>t;
    while(t--){
        cin>>n;
        for(i=1;i<=n;i++) scanf("%d",&a[i]);
        int x,y,s=1000000000;
        x=0;
        for(i=2;i<=n;i++){
            if(a[i]<a[i-1]) x+=a[i-1]-a[i];
        }
        for(i=0;i<=10000;i++){
            y=0;
            int f=0;
            for(j=1;j<n;j++){
                if(a[j]-i>a[j+1]){
                    f=1;
                    break;
                }
                if(i>=a[j]) y+=a[j];
                else y+=i;
            }
            if(!f) s=min(s,y);
        }
        printf("Case #%d: ",++N);
        cout<<x<<" "<<s<<endl;
    }
}