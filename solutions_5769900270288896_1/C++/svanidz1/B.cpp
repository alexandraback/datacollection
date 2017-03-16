#include <bits/stdc++.h>
#define MA(a,b) ((a)>(b)?(a):(b))
#define MI(a,b) ((a)<(b)?(a):(b))
#define AB(a) (-(a)<(a)?(a):-(a))
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pob pop_back
#define ep 0.00000001
#define pi 3.1415926535897932384626433832795
#define na(x) ((x)<P?(x):(x)-P)
using namespace std;

int main() {
    freopen("B5.in","r",stdin);
    freopen("textB5.txt","w",stdout);
    int R,C,N;

    int t;
    cin>>t;
    for (int tt=1;tt<=t;tt++){
        int A=0;
        cin>>R>>C>>N;
        if (R<C) swap(R,C);
        if (C<3){
            if(C==1) {
                if (N<=(R+1)/2) A=0;
                else {
                    A=0;
                    N-=(R+1)/2;
                    if (R%2==0)
                        if (N) N--,A++;
                    A+=N*2;
                }
            } else {
                if (N<=R) A=0;
                 else {
                    N-=R;
                    A=0;
                    if (N) A+=2,N--;
                    if (N) A+=2,N--;
                    while (N) A+=3,N--;
                 }
            }
        } else {
        A=R*(C-1)+(R-1)*C;
        N=R*C-N;
        int NN=N;
        int A1=0;
        if (max(((R-2)*(C-2)+1)/2,0)<NN) A1+=max(((R-2)*(C-2)+1)/2,0)*4,NN-=max(((R-2)*(C-2)+1)/2,0);
        else A1=NN*4,NN=0;
        for (int i=1;i<=2*(R+C-2);i+=2){
            if (i!=1 && i!=R && i!=R+C-1 && i!=R+C+R-2)
                if (NN )NN--,A1+=3;
        }
        A1+=NN*2;

        int A2=0;
        NN=N;
        if (max(((R-2)*(C-2))/2,0)<NN) A2+=max(((R-2)*(C-2))/2,0)*4,NN-=max(((R-2)*(C-2))/2,0);
        else A2=NN*4,NN=0;

        for (int i=2;i<=2*(R+C-2);i+=2){
            if (i!=1 && i!=R && i!=R+C-1 && i!=R+C+R-2)
                if (NN )NN--,A2+=3;
        }
        A2+=NN*2;


        A=max(0,A-max(A1,A2));
        }
        printf("Case #%d: %d\n",tt,A);
    }
    return 0;
}
