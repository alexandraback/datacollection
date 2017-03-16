#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("A-large.in","r",stdin);
        freopen("A-large.out","w",stdout);
    int t;
    cin>>t;
    for(int f=1; f<=t; f++){
        int num;
        cin>>num;
        long long arr[num];
        for(int i=0; i<num; i++)cin>>arr[i];
        long long res1=0,mx = 0 , res2=0;

        for(int i=1; i<num; i++)
            if(arr[i-1] > arr[i])
                res1 += arr[i-1]-arr[i];

        for(int i=1; i<num; i++)
            if(arr[i-1] > arr[i])
                mx = max(mx,arr[i-1]-arr[i]);
        for(int i=0;i<num-1;i++)
            res2+=min(arr[i],mx);

        cout<<"Case #"<<f<<": "<<res1<<" "<<res2<<endl;

    }
    return 0;
}
