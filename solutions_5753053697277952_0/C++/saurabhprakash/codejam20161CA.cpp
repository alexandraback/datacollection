#include<bits/stdc++.h>

using namespace std;

int main() {

    freopen("C:\\Users\\Saurabh\\Desktop\\in.txt","r",stdin);
    freopen("C:\\Users\\Saurabh\\Desktop\\out.txt","w",stdout);

    int t,cas=1;
    cin>>t;
    while(t--) {
        int n,i;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        cout<<"Case #"<<cas++<<": ";
        string ans;
        while(true) {
            int ind=0;
            for(i=0;i<n;i++) {
                if(a[i]>a[ind])
                    ind=i;
            }
            if(!a[ind])
                break;
            a[ind]--;
            ans+=char(ind+'A');
            int ind1=0;
            for(i=0;i<n;i++) {
                if(a[i]>a[ind1])
                    ind1=i;
            }
            if(!a[ind1])
                break;
            if(a[ind1]==a[ind]+1)
                ans+=char(ind1+'A'),a[ind1]--;
            ans+=" ";
        }
        if(ans[ans.size()-2]==' ') {
            string temp=ans.substr(ans.size()-4,4);
            reverse(temp.begin(),temp.end());
            ans=ans.substr(0,ans.size()-4)+temp;
        }
        cout<<ans<<endl;
    }

    return 0;
}
