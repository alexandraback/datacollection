#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<sstream>
#include<set>
#include<vector>
#include<map>
#include<cassert>
#include<queue>
using namespace std;
int c[1001];

int main(){
   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);

    int tc;
    cin>>tc;
    for(int caso=1;caso<=tc;caso++){
        cout<<"Case #"<<caso<<":";
        int n;
        cin>>n;
        for(int i=0;i<n;i++)cin>>c[i];
        
        if(n==2){
            for(int i=0;i<c[0];i++)
                cout<<" AB";
            cout<<endl;
            continue;
        }
        
        while(true){
            int sum=0;int maxi2=0;
            for(int i=0;i<n;i++)sum+=c[i];
            for(int i=0;i<n;i++)maxi2=max(maxi2,c[i]);
            if(sum<maxi2*2){
                cout<<"xuxa "<<maxi2<<endl;
            }


            string dev="";
            int dos=0;
            for(int i=0;i<n;i++){
                if(c[i]==0)continue;
                if(c[i]==2){
                    dev+=('A'+i);
                    dos++;
                    continue;
                }
                dos=10000;
            }

            if(dos==2){
                cout<<" "<<dev<<" "<<dev;
                break;
            }
            
            int uno=0;
            dev="";
            for(int i=0;i<n;i++){
                if(c[i]==0)continue;
                if(c[i]==1){
                    dev+=('A'+i);
                    uno++;
                    continue;
                }
                uno=10000;
            }

            if(uno==0)break;

            if(uno==2){
                cout<<" "<<dev;
                break;
            }

            int maxi=-1;
            int id=-1;
            
            for(int i=0;i<n;i++){
                if(c[i]==0)continue;
                if(c[i]>maxi){
                    maxi=c[i];
                    id=i;
                }
            }

            char ch='A'+id;
            c[id]--;
            cout<<" "<<ch;
        }
        
        cout<<endl;
        
    }

    return 0;
}





