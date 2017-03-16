#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;

int a[30];

int main()
{
    freopen("gcj_16_r1_c_a_in.txt","r",stdin);
    freopen("gcj_16_r1_c_a_out.txt","w",stdout);
    int t;
    cin>>t;
    for(int qq=1;qq<=t;qq++) {
        cout<<"Case #"<<qq<<": ";
        int i,j,n,m,temp,cnt;
        cin>>n;
        for(i=0;i<n;i++) cin>>a[i];
        a[n]=0;
        while(1) {
            for(i=0;i<n;i++) if(a[i]>0) break;
            if(i>=n) break;
            cnt=0;
            temp=n;
            for(i=0;i<n;i++) {
                if(a[i]>a[temp]) temp=i;
            }
            cnt=0;
            for(i=0;i<n;i++) {
                if(i!=temp && a[i]==a[temp]) j=i,cnt++;
            }
            if(cnt==1) cout<<char(temp+'A'),cout<<char(j+'A')<<" ",a[temp]--,a[j]--;
            else cout<<char(temp+'A')<<" ",a[temp]--;
        }
        cout<<"\n";
    }
    return 0;
}
