#include <bits/stdc++.h>
using namespace std;
long long int T,N,L;
long long int barberos[1010];
long long int colas[1010];
bool desocupado(){
    for(int i=0;i<N;i++){
        if(colas[i]==0){
            return true;
        }
    }
    return false;
}
long long int EuclidesMCD(long long int a, long long int b) {
   int iaux;
   a =abs(a);
   b = abs(b);
   int i1=max(a,b);
   int i2=min(a,b);
   do
   {
      iaux = i2;
      i2 = i1 % i2;
      i1 = iaux;
   } while (i2 != 0);
   return i1;
}
long long int EuclidesMCM(long long int a,long long int b)
{
    return (a / EuclidesMCD(a, b)) * b;
}
int main()
{
    ofstream cout("respuestas2.txt");
    ifstream cin;cin.open ("B-small-attempt1.in");
    while (cin>>T){
        for(int a=0;a<T;a++){
            for(int i=0;i<1010;i++){
                colas[i]= 0;
            }
            cin>>N>>L;
            for(int b=0;b<N;b++){
                cin>>barberos[b];
            }
            long long int mcm = barberos[0];
            for(int i=0;i<N;i++){
                mcm= EuclidesMCM(mcm,barberos[i]);
            }
            long long int modulo=0;
            for(int i=0;i<N;i++){
                modulo+= (mcm/barberos[i]);
            }
            if(L%modulo!=0){
                L= L%modulo;
            }
            else{
                L= modulo;
            }
            int i=1;
            bool bandera2 = false;
            while(true){
                if(desocupado()){
                    bool bandera = false;
                    for(int j=0;j<N;j++)
                    {
                        if(colas[j]==0){
                            colas[j]= barberos[j];
                            if(i==L){
                                cout<<"Case #"<<a+1<<": "<<j+1<<endl;
                                bandera2= true;
                            }
                            i++;
                            break;
                        }
                    }
                }
                else{
                    for(int j=0;j<N;j++){
                        colas[j]--;
                    }
                }
                if(bandera2){
                    break;
                }
            }
        }
    }
    cin.close();
    cout.close();
}
