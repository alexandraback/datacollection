#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t,tc=0,i,j,k,n,m;
    cin>>t;
    while(t--){
        int arr[30]={0};
        cin>>n;
        int sum=0,p=0;
        for(i=0;i<n;i++){
            scanf("%d",&arr[i]);
            sum+=arr[i];
        }
        p=sum;
        printf("Case #%d:",++tc);
        for(i=0;i<p;i++){
            int ss=0;
            for(j=0;j<n;j++)ss+=arr[j];
            if(ss==0)break;
            bool ok=false;
            for(j=0;j<n && !ok;j++){
                for(k=j;k<n && !ok;k++){
                    if(arr[j] + arr[k]-2 >=0){
                        arr[j]--;
                        arr[k]--;
                        bool ok2=true;
                        for(int l=0;l<n;l++){
                            if(arr[l] > (ss-2)/2)ok2=false;
                        }
                        if(ok2){
                            cout<<" ";
                            cout<<char('A'+j);
                            cout<<char('A'+k);
                            ok=true;
                            break;
                        }
                        else {
                            arr[j]++;
                            arr[k]++;
                        }
                    }
                }
            }
            if(!ok){
                for(j=0;j<n && !ok;j++){
                    if(arr[j]>0 ){
                        arr[j]--;
                        bool ok2=true;
                        for(int l=0;l<n;l++){
                            if(arr[l]> (ss-1)/2)ok2=false;
                        }
                        if(ok2){
                            cout<<" ";
                            cout<<char('A'+j);
                            ok=true;
                            break;
                        }
                        else {
                            arr[j]++;
                        }
                    }
                }
            }
        }
        cout<<"\n";
    }
    return 0;
}
