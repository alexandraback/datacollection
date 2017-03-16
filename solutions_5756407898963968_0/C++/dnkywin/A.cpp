#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream in("A.in"); ofstream out("A.out");
    int T;
    in>>T;
    for (int t=0;t<T;t++){
        out<<"Case #"<<t+1<<": ";
        int row;
        in>>row;
        int dontwork = 0;
        for (int i=0;i<4;i++){
            for (int j=0;j<4;j++){
                int c;
                in>>c;
                c--;
                if (i+1!=row){
                    dontwork |= (1<<c);
                }
            }
        }
        in>>row;
        for (int i=0;i<4;i++){
            for (int j=0;j<4;j++){
                int c;
                in>>c;
                c--;
                if (i+1!=row){
                    dontwork |= (1<<c);
                }
            }
        }
        dontwork ^= 65535;
        cout<<dontwork<<"\n";
        if (dontwork == 0) out<<"Volunteer cheated!\n";
        else if (dontwork != (dontwork & -dontwork)) out<<"Bad magician!\n";
        else{
            int ans = 1;
            while(dontwork > 1) {dontwork/=2; ans++;}
            out<<ans<<"\n";
        }
    }
}
