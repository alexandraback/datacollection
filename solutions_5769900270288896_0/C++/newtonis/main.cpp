#include <iostream>

using namespace std;

int best;

void solve(int x);

int main() {
    freopen("input.in","r",stdin);
    freopen("output.out","w+",stdout);
    int T; cin>>T;
    for (int x = 1;x <= T;x++){
        solve(x);
    }
}
void Colocar(int actual,int colocados,int *mapa,int R,int C);
void solve(int x){
    int R,C,N; cin>>R>>C>>N;
    best = 1000000;

    int mapa[R*C];
    for (int x = 0;x < R*C;x++){
        mapa[x] = 0;
    }
    Colocar(0,N,mapa,R,C);
    cout<<"Case #"<<x<<": "<<best<<endl;
}

void Colocar(int actual,int colocados,int *mapa,int R,int C){

    if (colocados == 0){
        int c = 0;

        for (int v = 0;v < R*C;v++){
            /*if (v%C == 0){
                cout<<endl;
            }
            cout<<mapa[v];*/

            if (mapa[v]){
                if (v+1 < R*C and mapa[v+1] and not(v%C == C-1)){
                    c ++;
                }
                if (v + C < R*C and mapa[v + C]){
                    c ++;
                }
            }
        }
        //cout<<endl;
        best = min(best,c);

        return;
    }

    for (int x = actual;x < R*C;x++) {
        mapa[x] = 1;
        Colocar(x+1, colocados-1, mapa, R, C);
        mapa[x] = 0;
    }

}