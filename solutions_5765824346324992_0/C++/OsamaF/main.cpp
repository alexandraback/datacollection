#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
    int t;
    cin>>t;
    for(int f=1; f<=t; f++){
        long long b,pos,lcm=1,numperLcm=0;
        cin>>b>>pos;
        int arr[b];
        for(int i=0; i<b; i++)
            cin>>arr[i];
        for(int i=0; i<b; i++)
            lcm = lcm*arr[i]/__gcd((long long)arr[i],lcm);
        for(int i=0; i<b; i++)
            numperLcm += lcm/arr[i];

        vector<int> arr2[lcm+1];
        memset(arr2,0,sizeof(arr2));
        for(int i=0;i<b;i++){
            for(int j=0;j<=lcm;j+=arr[i])
                arr2[j].push_back(i);
        }

        pos = (pos-1)%(numperLcm);
        int pl;

        for(int i=0;i<=lcm;i++){
            pos-=arr2[i].size();

            if(pos<0){
                pos+=arr2[i].size();
                for(int j=0; j<=pos;j++){
                    pl = arr2[i][j];
                }

                break;
            }

        }

        cout<<"Case #"<<f<<": "<<pl+1<<endl;
    }
    return 0;
}
