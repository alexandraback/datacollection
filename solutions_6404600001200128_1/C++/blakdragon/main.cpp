#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie
using namespace std;

int numeros[1002];

int T;
int N;
int mayor;
int res1,res2;

int main(){
    optimizar_io(0);
    cin>>T;
    for(int caso=1;caso<=T;caso++){
        cin>>N;
        res1=res2=mayor=0;
        for(int i=1;i<=N;i++)
            cin>>numeros[i];
        for(int i=2;i<=N;i++){
            if(numeros[i]<numeros[i-1])
                res1+=numeros[i-1]-numeros[i];
            if(numeros[i-1]-numeros[i]>mayor)
                mayor=numeros[i-1]-numeros[i];
        }
        for(int i=1;i<N;i++)
            res2+=min(numeros[i],mayor);
        cout<<"Case #"<<caso<<": "<<res1<<" "<<res2<<"\n";
    }
    return 0;
}
