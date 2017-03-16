//IN THE NAME OF ALLAH
//

#include <bits/stdc++.h>
#include <fstream>
#define mp make_pair
#define pb push_back
using namespace std;
ifstream fin("1.in");
ofstream fout("1.out");
typedef long long int ll;
typedef long double ld;
typedef pair < ll, ll > pii;
typedef vector < ll > vi;
typedef set < ll > si;
const ld pi=3.1415926535897932384626433832795028841971693993751;
const ll maxn=26,inf=1e9+1;
int t,n,p[maxn];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    fin>>t;
    for(int i=1;i<=t;i++){
        fout<<"Case #"<<i<<": ";
        vector < pair < int, char > >v;
        fin>>n;
        for(int j=0;j<n;j++){
            fin>>p[j];
            v.pb(mp(p[j],j+'A'));
        }
        sort(v.begin(),v.end());
        int x=v[0].first;
        while(v.back().first>x){
            for(int j=v.size()-1;j>-1;j--){
                if(v[j].first>x){
                    v[j].first--;
                    fout<<v[j].second<<" ";
                }
            }
        }
        int po=0;
        if(x%2 && n%2){
            fout<<v[0].second<<" ";
            po++;
            v[0].first--;
        }
        while(v.back().first){
            fout<<v[po].second;
            v[po].first--;
            po++;
            po%=n;
            fout<<v[po].second<<" ";
            v[po].first--;
            po++;
            po%=n;
        }
        fout<<endl;
    }
    return 0;
}
