#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int i,c1,cases,n;
    long m1,m2,m3;
    cin>>cases;
    for(c1=1;c1<=cases;c1++){
        cin>>n;
        long m[n];
        m1=0;
        m2=0;
        m3=0;
        cin>>m[0];
        for(i=1;i<n;i++){
            cin>>m[i];
            if(m[i]<m[i-1]){
                m1+=m[i-1]-m[i];
                if(m[i-1]-m[i]>m2){
                    m2=m[i-1]-m[i];
                }
            }
        }
        m3=0;
        for(i=0;i<n-1;i++){
            if(m2>m[i]){
                m3+=m[i];
            }
            else{
                m3+=m2;
            }
        }
        cout<<"Case #"<<c1<<": "<<m1<<" "<<m3<<endl;
    }
}
