#include <bits/stdc++.h>
using namespace std;
int a[1000001];
int main()
{
    int t;
    ifstream cin("B-small-attempt1.in");
    ofstream cout("oputo.txt");
    cin >>  t;
    for(int tt=1;tt<=t;tt++){
        int n,r,c;
        cin >>  r >> c >> n;
        string a="";

        for(int i=n+1;i<=(r*c);i++)a+="0";
        for(int i=1;i<=n;i++){
            a+="1";
        }
        int mi=INT_MAX;
        string s;
        do{
            int un=0;
            for(int i=1;i<r;i++){
                for(int j=0;j<c;j++){
                    if(a[(i*c)+j]=='1'&&a[(i-1)*(c)+j]=='1')
                       un+=1;
                }
            }
            for(int i=0;i<r;i++){
                for(int j=1;j<c;j++){
                    if(a[(i*c)+j]=='1'&&a[(i*c)+j-1]=='1')
                       un+=1;
                }
            }
            if(un<mi){
                mi=un;
                s=a;
            }
            //cout<<un << " " << a<<endl;


        }while(next_permutation(a.begin(),a.end()));
        cout<<"Case #"<<tt<<": "<<mi<<endl;
    }
    return 0;
}
