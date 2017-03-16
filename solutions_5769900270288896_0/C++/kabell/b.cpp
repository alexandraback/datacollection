/*
 * This is my code,
 * my code is amazing...
 */
//Template v2.0
//iostream is too mainstream
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<iomanip>
//clibraries
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<ctime>
//defines
#define ll long long
#define lld long double
#define pll pair<ll,ll>
#define pld pair<lld,lld>
#define vll vector<ll>
#define vvll vector<vll>
#define INF 1000000000000000047
const char en='\n';
#define debug(x){cerr<<x<<en;}
#define prime 47
#define lprime 1000000000000000009
#define lldmin LDBL_MIN
#define MP make_pair
#define PB push_back
using namespace std;


int main(){
	ios::sync_with_stdio(false);

        int T;
        cin>>T;

        for(int t=1; t<=T; t++){
            ll r,c,n;
            cin>>r>>c>>n;

            int rc=r*c;
            int naj=1000;
            for(int i=0; i<(1<<rc); i++){
                int p[r+1][c+1];
                for(int j=0; j<r+1; j++)
                    for(int k=0; k<c+1; k++)
                        p[j][k]=0;
                int ii=i;
                for(int j=0; j<rc; j++){
                    p[j/c][j%c]=ii%2;
                    ii/=2;
                }
                int pocet=0;
                for(int j=0; j<rc; j++){
                    pocet+=p[j/c][j%c];
                }
                
                int sum=0;
                if(pocet==n){
                     
                    for(int j=0; j<rc; j++){
                            int x=j/c,y=j%c;
                        //    cout<<x<<y<<en;
                            //cout<<p[j/r][j%c]<<"("<<sum<<")"<<" \n"[j%c==c-1];
                            sum+=(p[x][y]+ p[x][y+1]==2);
                            sum+=(p[x][y]+ p[x+1][y]==2);
                            

                    }
                    //cout<<sum<<en;
                    

                naj=min(naj,sum);
                }

            }
        
            




            cout<<"Case #"<<t<<": "<<naj<<en;
        }





}
