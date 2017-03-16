#include<bits/stdc++.h>
#define ll long long
#define pn() printf("\n")
#define si(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define sll(x) scanf("%I64d",&x)
#define pll(x) printf("%I64d",x)
#define sc(x) scanf("%c",&x)
#define pc(x) printf("%c",x)
#define sf(x) scanf("%f",&x)
#define pf(x) printf("%f",x)
#define sd(x) scanf("%lf",&x)
#define pd(x) printf("%lf",x)
#define sld(x) scanf("%Lf",&x)
#define pld(x) printf("%Lf",x)
#define MOD 1000000007LL
using namespace std;
struct ss{
    char a;
    int freq;
};
string a1[105];
ss aa[105][105];
int main(void){
    ifstream f1("input.txt");
    ofstream f2("output.txt");
    int t,tt=1;
    f1>>t;
    while(t--){
        int n;
        f1>>n;
        for(int i=0;i<n;i++)
            f1>>a1[i];
        int indexx[n];
        memset(indexx,0,sizeof(indexx));
        //cout<<"hello";
        for(int i=0;i<n;i++){
            aa[i][indexx[i]].a=a1[i][0];
            aa[i][indexx[i]].freq=1;
        }
        //cout<<"hello3";
        for(int i=0;i<n;i++){
            for(int j=1;j<a1[i].length();j++){
                if(a1[i][j]==aa[i][indexx[i]].a){
                    aa[i][indexx[i]].freq++;
                }
                else{
                    indexx[i]++;
                    aa[i][indexx[i]].a=a1[i][j];
                    aa[i][indexx[i]].freq=1;
                }
            }
        }
        //cout<<"hello2";
        int canconvert=1;
        int temp=indexx[0];
        for(int i=1;i<n;i++){
            if(temp!=indexx[i]){
                canconvert=0;
                break;
            }
        }
        for(int i=0;i<=indexx[0];i++){
            char tt=aa[0][i].a;
            for(int j=1;j<n;j++){
                if(tt!=aa[j][i].a){
                    canconvert=0;
                    break;
                }
            }
        }
        //cout<<"hello3";
        int finalans=0;
        for(int i=0;i<=indexx[0];i++){
            int mindif=INT_MAX;
            int at=0;
            for(int trying=1;trying<=100;trying++){
                int tttt=0;
                for(int k=0;k<n;k++){
                    tttt+=abs(aa[k][i].freq-trying);
                }
                if(tttt<mindif){
                    mindif=tttt;
                    at=trying;
                }
            }
            finalans+=mindif;
        }
        if(canconvert){
            f2<<"Case #"<<tt<<": "<<finalans<<"\n";
            cout<<"Case #"<<tt<<": "<<finalans<<"\n";
        }
        else{
            cout<<"Case #"<<tt<<": "<<"Fegla Won"<<"\n";
            f2<<"Case #"<<tt<<": "<<"Fegla Won"<<"\n";
        }
        tt++;
    }
    return 0;
}
