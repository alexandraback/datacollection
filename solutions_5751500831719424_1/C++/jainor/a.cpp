#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdio.h>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;
string f(string s){
    string dev="";
    dev+=s[0];
    for(int i=1;i<s.size();i++){
        if(s[i]!=s[i-1])
            dev+=s[i];    
    }
    return dev;    
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    int tc;
    cin>>tc;
    for(int caso=1;caso<=tc;caso++){
        cout<<"Case #"<<caso<<": ";
        int n;
        cin>>n;
        string s[n];
        string ham="";
        bool ok=1;
        
        for(int i=0;i<n;i++){
            cin>>s[i];
            if(ham!="" && ham!=f(s[i]))ok=0;
            ham=f(s[i]);
        }
        
        if(ok==0){
            cout<<"Fegla Won"<<endl;
        }else{
            int c[n][100];
            memset(c,0,sizeof(c));
            int tam=0;
            for(int i=0;i<n;i++){
                int cont=0;
                c[i][0]=1;
                for(int j=1;j<s[i].size();j++){
                    if(s[i][j]==s[i][j-1]){
                        c[i][cont]++;    
                    }else{
                        cont++;
                        c[i][cont]++;    
                    }    
                }
                cont++;
                tam=cont;
            }
            
            
            int dev=0;
            for(int j=0;j<tam;j++){
                
                int mini1=1<<30;
                for(int k=1;k<=100;k++){
                    int sum=0;
                    for(int i=0;i<n;i++){
                        sum+=abs(c[i][j]-k);
                    }
                    
                    mini1=min(mini1,sum);
                }
                dev+=mini1;
            }
            
            cout<<dev<<endl;
        }
        
    }
    
    return 0;
}
