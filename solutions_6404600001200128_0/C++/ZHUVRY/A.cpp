#include <bits/stdc++.h>
using namespace std;
long long int T,N;
long long int platos[1010];
int main()
{
//    ofstream cout("respuestas.txt");
//    ifstream cin;cin.open ("A-small-attempt1.in");

    while (cin>>T){
        for(int i=0;i<T;i++){
            long long int r1=0;
            long long int mayor = 0;
            long long int r2=0;
            cin>>N;
            for(int i=0;i<N;i++){
                cin>>platos[i];
            }
            for(int i=1;i<N;i++){
                if(platos[i]<platos[i-1]){
                    r1+= (platos[i-1]-platos[i]);
                    mayor = max(mayor,platos[i-1]-platos[i]);
                }
            }
            for(int i=0;i<N-1;i++){
                if(platos[i]>=mayor){
                    r2+=mayor;
                }
                else{
                    r2+=platos[i];
                }
            }
            cout<<"Case #"<<i+1<<": "<<r1<<" "<<r2<<endl;
        }
    }
//    cin.close();
//    cout.close();
}
