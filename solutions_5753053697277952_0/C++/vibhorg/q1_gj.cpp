#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define X first
#define Y second
#define rep(i,a) for(ll i=0;i<a;++i)
#define repp(i,a,b) for(ll i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
#define    foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define	mp make_pair
#define	pb push_back
#define fastScan ios_base::sync_with_stdio(0); cin.tie(NULL);
ll M=1e9+7;



ll mpe(ll base, ll exponent, ll modulus)
{  
    ll result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = result*base%modulus ;
        exponent = exponent >> 1;
        base =  base*base%modulus ;
    }
    return result;
}
 
int main()
{
    fastScan;
    ll cas,t;
    cin>>t;
    repp(cas,1,t+1){
        ll n,tot=0;
        cin>>n;
        ll arr[n];
        rep(i,n){cin>>arr[i];tot+=arr[i];}
        set<pll > st;
        set<pll >::reverse_iterator it;
        rep(i,n){
            st.insert(mp(arr[i],i));
        }
        cout<<"Case #"<<cas<<": ";
        while(!st.empty()){
            it=st.rbegin();
            int fir,sec=-1;
            pll tm1,tm2;
            tm1=(*it);
            fir=tm1.Y;
            st.erase(tm1);
            tm1.X--;
            tot--;
            if(tm1.X!=0)st.insert(tm1);
            if(!st.empty()){
                it=st.rbegin();
                tm2=(*it);
                if(tm2.X<=(tot/2 +1) && tot!=2){
                    
                    sec=tm2.Y;
                    st.erase(tm2);
                    tm2.X--;
                    tot--;
                    if(tm2.X!=0)st.insert(tm2);
                    
                }
            }
            if(sec!=-1){
                char a='A'+fir,b='A'+sec;
                cout<<a<<b<<" ";
            }
            else{
                char a='A'+fir;
                cout<<a<<" ";
            }
           // cout<<fir<<"  "<<sec<<endl;
        }
        cout<<endl;
        
    }
    
    return 0;
}