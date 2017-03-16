#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
    int T;
    freopen("D:\\in.txt","r",stdin);
    freopen("D:\\out.txt","w",stdout);
    cin>>T;
    for (int t=1;t<=T;t++){
        int n;
        cin>>n;
        string pre;
        pre="?";
        vector<int> a[200];
        int ok=1;
        for (int i=0;i<n;i++){
            string s;
            cin>>s;
            //cout<<"s="<<s<<endl;
            string t;
            t=""+s[0];
            for (int i=1;i<(int)s.size();i++)
                if (s[i]!=s[i-1]) t+=s[i];
            if (pre=="?") pre=t;
            if (t!=pre) ok = 0;
            int last=0;
            int cnt=0;
            for (int i=1;i<(int)s.size();i++)
                if (s[i]!=s[i-1]){
                    cnt++;
                    a[cnt].push_back(i-last);
                    last=i;
                }
            cnt++;
            a[cnt].push_back(s.size()-last);
       }
        cout<<"Case #"<<t<<": ";
        if (!ok){
            cout<<"Fegla Won"<<endl;
        }else{
            int ans=0;
            /*for (int i=0;i<200;i++){
                for (int j=0;j<(int)a[i].size();j++) cout<<a[i][j]<<" ";
                cout<<endl;
            }*/
            for (int i=0;i<200;i++){
                int mm=99999;
                for (int j=0;j<(int)a[i].size();j++){
                    int now=0;
                    for (int k=0;k<(int)a[i].size();k++){
                       now+=abs(a[i][j]-a[i][k]);
                    }
                    mm=min(mm,now);
                }
                if (mm==99999) mm=0;
                ans+=mm;
            }
            cout<<ans<<endl;
        }


    }
}

