#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int t,n;
int a[1000],b[1000];
vector<int> num[110];
vector<char> v[110];
string s[110];

int main(){
    freopen("A-small-attempt0 (2).in","r",stdin);
    freopen("1.out","w",stdout);
    cin >> t;
    for (int ti=1;ti<=t;ti++){
        scanf("%d",&n);
        for (int i=1;i<=n;i++) cin>>s[i];
        int ans=0;
        //if (s[1]==s[2]) ans=0;
        //   else{
           string ss="";
           for (int i=1;i<=n;i++){
               v[i].clear();
               num[i].clear();
               v[i].push_back(s[i][0]);
               num[i].push_back(1);
               for (int j=1;j<s[i].length();j++)
                   if (s[i][j]!=s[i][j-1]){
                      v[i].push_back(s[i][j]);
                      num[i].push_back(1);
                   }else
                   num[i].back()++;
               if (i==1) ss="";
               string st="";
               for (int j=0;j<v[i].size();j++){
                   st+=v[i][j];
                   if (i==1) ss+=v[i][j];
               }
               //cout<<st<<endl;
               if (ss!=st){ ans=-1;break;}
               //if (i==1)cout<<"!"<<ss<<endl;
           }
          if (ans!=-1){
             ans=0;
             for (int i=0;i<num[1].size();i++){
                 int cnt=1000000000;
                 for (int avg=1;avg<=100;avg++){
                     int now=0;
                     for (int j=1;j<=n;j++)
                         if (avg>num[j][i]) now+=avg-num[j][i];
                            else now+=num[j][i]-avg;
                     if (now<cnt) cnt=now;
                 }
                 ans+=cnt;
             }
          }
           
        //}
        
        cout << "Case #"<<ti<<": ";
        if (ans==-1) cout<<"Fegla Won"<<endl;
           else cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}
