#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctype.h>
#include <stack>
#include <queue>
#include <limits.h>
#include <fstream>
#include <map>
#include <set>

#define rep(i, a) for(long long int i = 0; i < a; i++)
#define rep1(i, a) for(long long int i = 1; i <= a; i++)
#define fo(i, a, b) for(long long int i = a; i < b; i++)
#define defo(i, a, b) for(long long int i = a; i >= b; i--)
#define ll long long
#define Int long long int
#define pr(i) printf("Case #%lld: ",i)
#define pb push_back
#define sz(a) ((long long int)(a.size()))
#define x first
#define y second
#define fin(e) freopen("e.txt","r",stdin)
#define fout(e) freopen("e.txt","w",stdout)
#define mp make_pair
#define SET(x, a) memset(x, a, sizeof(x));
#define pi  3.1415926535897
#define mod 1000000007
#define retunr return
using namespace std;

typedef vector<long long int> vi;
typedef vector<ll> vll;
typedef pair<long long int, long long int> pii;
typedef pair<ll, ll> pll;
int po(int a,int b){
    int p = 1;
    int i;
    for(i=0;i<b;i++){
        p*=a;
    }
    return p;
}
int main(){
    freopen("b.in", "r", stdin);
    freopen("out1.txt", "w", stdout);
    int test;
    cin>>test;
    Int l11 = 0;
    while(test--){
        l11++;
        vector<int> primes;
        primes.push_back(2);
        primes.push_back(3);
        primes.push_back(5);
        primes.push_back(7);
        primes.push_back(11);
        primes.push_back(13);
        primes.push_back(17);
        primes.push_back(19);
        primes.push_back(23);
        int arr[26]={0};
        int n,i,j,no;
        scanf("%d%d",&n,&no);
        pair<int,int> b[10];
        for(i=0;i<n;i++){
            scanf("%d",&b[i].first);
            b[i].second = i+1;
        }
        //sort(b,b+n);
        for(j=0;j<n;j++){
            int temp = b[j].first;
            for(i=0;i<primes.size();i++){
                int t = 0;
                while(temp%primes[i]==0){
                    temp/=primes[i];
                    t++;
                }
                arr[primes[i]] = max(arr[primes[i]],t);
            }
        }
        int l = 1,t=0;
        for(i=1;i<25;i++){
            l = l*po(i,arr[i]);
        }
        for(i=0;i<n;i++){
            t = t+(l/b[i].first);
        }
        //cout<<t<<"\n";
        no = (no-1+t)%t;
        no++;
        //cout<<"no = "<<no<<"\n";
        int ti[10]={0},in;
        for(j=1;j<=no;j++){
            in = 0;
            for(i=0;i<n;i++){
                if(ti[i]<ti[in]){
                    in = i;
                }
            }
            ti[in]+=b[in].first;
        }
        pr(l11);
        cout<<in+1<<"\n";
        /*int prev = 0,khali;
        for(i=0;i<=l;i++){
            int cu = 0;
            for(j=0;j<n;j++){
                cu+=(i/b[j].first);
            }
            cout<<i<<" "<<cu<<"\n";
            if(cu>=no){
                khali = cu-prev;
                break;
            }
            prev = cu;
        }
        cout<<"Khali = "<<khali<<"\n";
        vector<int> v;
        for(j=0;j<n;j++){
            if(i%b[j].first==0){
                cout<<b[j].second<<"\n";
                v.push_back(b[j].second);
            }
        }
        int abhi = 0;
        for(j=0;j<n;j++){
            abhi+=((i-1)/b[j].first);
        }
        cout<<"abhi = "<<abhi<<"\n";
        no-=abhi;
        cout<<"no = "<<no<<"\n";
        no--;
        vector<pair<int,int> > vec;
        for(j=0;j<v.size();j++){
            vec.push_back(mp(i-b[v[j]-1].first,b[v[j]-1].second));
        }
        sort(vec.begin(),vec.end());
        pr(l11);
        cout<<vec[no].second<<"\n";*/
    }
    return 0;
}
