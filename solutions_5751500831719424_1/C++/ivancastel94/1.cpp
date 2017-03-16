#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<utility>
#include<set>
using namespace std;
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int min,con,max,i,j,k,n,t,tam,cases;
    bool b;
    char co;
    string s;
    cin>>cases;
    for(t=1;t<=cases;t++){
        tam=-1;
        cin>>n;
        vector< pair<char, int> > stri[n];
        vector< int > liminf, limsup;
        for(i=0;i<n;i++){
            cin>>s;
            stri[i].push_back(make_pair(s[0],1));
            for(j=1;j<s.length();j++){
                if(stri[i][stri[i].size()-1].first == s[j])
                    stri[i][stri[i].size()-1].second++;
                else{
                    stri[i].push_back(make_pair(s[j],1));
                }
            }
            if(tam!=-1 && tam!=stri[i].size())
                tam=-2;
            if(tam!=-2)
                tam=stri[i].size();
        }
        cout<<"Case #"<<t<<": ";
        if(tam==-2){
            cout<<"Fegla Won"<<endl;
            continue;
        }
        b=true;
        for(i=0;i<tam;i++){
            co=stri[0][i].first;
            min=max=stri[0][i].second;
            for(j=1;j<n;j++){
                if(co!=stri[j][i].first)
                    b=false;
                if(min>stri[j][i].second)
                    min=stri[j][i].second;
                if(max<stri[j][i].second)
                    max=stri[j][i].second;
            }
            liminf.push_back(min);
            limsup.push_back(max);
        }
        if(!b){
            cout<<"Fegla Won"<<endl;
            continue;
        }
        max=0;
        for(i=0;i<tam;i++){
            min=limsup[i]*n;
            for(j=liminf[i];j<=limsup[i];j++){
                con=0;
                for(k=0;k<n;k++){
                    con+=abs(j-stri[k][i].second);
                }
                if(con<min)
                    min=con;
            }
            max+=min;
        }
        cout<<max<<endl;
    }
}
