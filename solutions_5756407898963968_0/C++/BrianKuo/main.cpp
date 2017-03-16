#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("A-small-attempt0.in");
    ofstream fout("A-small-attempt0.out");
    int n;
    fin>>n;
    for(int t=1;t<=n;t++){
        int a,b,ans=0;
        fin>>a;
        int m[4],x;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(i+1==a)
                    fin>>m[j];
                else fin>>x;
            }
        }
        fin>>b;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(i+1==b){
                    fin>>x;
                    for(int k=0;k<4;k++){
                        if(x==m[k]){
                            if(ans==0)
                                ans=x;
                            else if(ans>0)
                                ans=-1;
                        }
                    }
                }
                else fin>>x;
            }
        }
        if(ans>0)
            fout<<"Case #"<<t<<": "<<ans<<endl;
        else if(ans==0)
            fout<<"Case #"<<t<<": "<<"Volunteer cheated!"<<endl;
        else
            fout<<"Case #"<<t<<": "<<"Bad magician!"<<endl;
    }
    return 0;
}
