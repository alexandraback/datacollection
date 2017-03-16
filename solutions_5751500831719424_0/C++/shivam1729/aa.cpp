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
int main(void){
    ifstream f1("input.txt");
    ofstream f2("output.txt");
    int t,tt=1;
    f1>>t;
    while(t--){
        int n;
        f1>>n;
        string a1,b1;
        f1>>a1>>b1;
        ss aa[105];
        ss bb[105];
        int index1=0,index2=0;
        aa[index1].a=a1[0];
        aa[index1].freq=1;
        for(int i=1;i<a1.length();i++){
            if(a1[i]==aa[index1].a){
                aa[index1].freq++;
            }
            else{
                index1++;
                aa[index1].a=a1[i];
                aa[index1].freq=1;
            }
        }
        for(int i=0;i<=index1;i++){
            //cout<<aa[i].a<<" "<<aa[i].freq<<endl;
        }
        bb[index2].a=b1[0];
        bb[index2].freq=1;
        for(int i=1;i<b1.length();i++){
            if(b1[i]==bb[index2].a){
                bb[index2].freq++;
            }
            else{
                index2++;
                bb[index2].a=b1[i];
                bb[index2].freq=1;
            }
        }
        for(int i=0;i<=index2;i++){
            //cout<<bb[i].a<<" "<<bb[i].freq<<endl;
        }
        int canconvert=1;
        int j=0;
        int i=0;
        int steps=0;
        for(;i<=index1&&j<=index2;){
            if(aa[i].a!=bb[i].a){
                canconvert=0;
                break;
            }
            else{
                steps+=abs(aa[i].freq-bb[i].freq);
            }
            j++;
            i++;
        }
        if(i<=index1||j<=index2)
            canconvert=0;
        if(canconvert){
            f2<<"Case #"<<tt<<": "<<steps<<"\n";
            cout<<"Case #"<<tt<<": "<<steps<<"\n";
        }
        else{
            cout<<"Case #"<<tt<<": "<<"Fegla Won"<<"\n";
            f2<<"Case #"<<tt<<": "<<"Fegla Won"<<"\n";
        }
        tt++;
    }
    return 0;
}
