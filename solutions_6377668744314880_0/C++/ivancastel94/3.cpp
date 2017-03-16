#include<bits/stdc++.h>
#define PI 3.14159265358979323846
#define epsilon 0.0000000000001
using namespace std;

long double angulo(long double x1, long double y1, long double x2, long double y2){
    long double h,h2,a;
    h2=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    h=sqrt(h2);
    a=(y2-y1);
    if(x2>=x1)
        return asin(a/h);
    if(y2>=y1)
        return PI - asin(a/h);
    return - (PI + asin(a/h));
}

bool derecha(long double a1, long double a2){
    long double lim1,lim2;
    if(a1>0){
        lim1=a1-PI;
        lim2=a1;
    }
    else{
        lim1=a1;
        lim2=a1+PI;
    }
    if((a2>lim1+epsilon)&&(a2<lim2-epsilon)) return true;
    return false;
}

bool izquierda(long double a1, long double a2){
    long double lim1,lim2;
    if(a1>0){
        lim1=a1-PI;
        lim2=a1;
    }
    else{
        lim1=a1;
        lim2=a1+PI;
    }
    if((a2<lim1-epsilon)||(a2>lim2+epsilon)) return true;
    return false;
}

int main(){
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    int cases,c1;
    cin>>cases;
    for(c1=1;c1<=cases;c1++){
        int i,j,k,n,der,izq,res;
        long double x[5000],y[5000];
        cin>>n;
        for(i=0;i<n;i++){
            cin>>x[i]>>y[i];
        }
        cout<<"Case #"<<c1<<":"<<endl;
        for(i=0;i<n;i++){
            res=n;
            vector<long double> angles;
            //cout<<i<<" ";
            for(j=0;j<n;j++){
                if(i==j)continue;
                angles.push_back(angulo(x[i],y[i],x[j],y[j]));
                //cout<<angles.back()<<" ";
            }
            for(j=0;j<angles.size();j++){
                der=0;
                izq=0;
                for(k=0;k<angles.size();k++){
                    if(derecha(angles[j],angles[k])){
                        der++;
                    }
                    if(izquierda(angles[j],angles[k])){
                        izq++;
                    }
                }
                if(res>der)res=der;
                if(res>izq)res=izq;
            }
            if(res==n){
                res=0;
            }
            cout<<res<<endl;
        }
    }
}

