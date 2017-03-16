#include<bits/stdc++.h>
using namespace std;
long long d,t,n,b,m[2000];

long long funcion(long long tim){
    //cout<<"FUNCION "<<tim<<endl;
    long long sum=0;
    for(int i=0;i<b;i++){
        sum+=(tim/m[i]);
    }
    return sum;
}

int main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    int cases,c1;
    cin>>cases;
    for(c1=1;c1<=cases;c1++){
        int i;
        cin>>b>>n;
        for(i=0;i<b;i++){
            cin>>m[i];
        }
        cout<<"Case #"<<c1<<": ";
        if(n<b){
            cout<<n<<endl;
        }
        else{
            n=n-b;
            t=2000000000000;
            d=1000000000000;
            while(d>1){
                if(funcion(t-1)>n){
                    t=t-d;
                }
                if(funcion(t)<n){
                    t=t+d;
                }
                d=d/2;
            }
            while(funcion(t)<n){
                t++;
            }
            while(funcion(t)>=n){
                t--;
            }
            long long coso = funcion(t);
            t++;
            for(i=0;i<b;i++){
                if(t%m[i]==0){
                    coso++;
                }
                if(coso==n){
                    cout<<(i+1)<<endl;
                    break;
                }
            }
        }
    }
}

