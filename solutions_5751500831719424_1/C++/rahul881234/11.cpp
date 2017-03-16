#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int main(){
long long int t,c,i,j,k,l,m=0,s=0,n;
cin>>t;
while(t--)
{
    m++;
    cin>>n;
    string a[n];
    string b[n];
    for(i=0;i<n;i++){
        cin>>a[i];
        b[i]+=a[i]+'=';
    }
    cout<<"Case #"<<m<<": ";
    int pp=0;
    string z;
    for(j=0;j<b[0].size();j++){
            if(b[0][j]!=b[0][j+1]){
                z+=b[0][j];
            }
        }
    for(i=1;i<n;i++){
            string x;
            for(j=0;j<b[i].size();j++){
                if(b[i][j]!=b[i][j+1]){
                x+=b[i][j];
                }
            }
        if(x.size()!=z.size()){
            pp=1;
            break;
        }
        else{
            for(j=0;j<z.size();j++){
                if(z[j]!=x[j]){
                    pp=1;
                    break;
                }
            }
            if(pp==1){
                break;
            }
        }
    }
    if(pp==1){
        cout<<"Fegla Won\n";
    }
    else{
        long long  int m1=0,m2=100000000;
        long int aa[n][100];
        for(i=0;i<n;i++){
            for(j=0;j<100;j++){
                aa[i][j]=0;
            }
        }
        for(i=0;i<n;i++){
                int k=0;
                string qw=a[i]+'=';
            for(j=0;j<qw.size();j++){
                if(a[i][j]==a[i][j+1]){
                    aa[i][k]++;
                }
                else
                {aa[i][k]++;k++;}
            }
        }
        for(i=0;i<n;i++){
            m1=0;
            for(j=0;j<n;j++){
                for(k=0;k<a[i].size();k++){
                    m1+=abs(aa[i][k]-aa[j][k]);
                }
            }
            m2=min(m1,m2);
        }

    cout<<m2<<"\n";m2=100000000;
    }

}
return 0;}
