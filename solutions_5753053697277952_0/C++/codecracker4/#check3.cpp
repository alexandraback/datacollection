//Author : Jatin Goyal
//codecracker4

#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007  //NA
#define N 111111
#define ll long long int
#define dt int
#define all(c) c.begin(), c.end()
#define dcl(a) memset(a,0,sizeof(a))
#define rep(i,a,b) for(dt i=a;i<=(dt)(b);i++)
#define tr(container, it) for(vector<dt> ::iterator it= container.begin(); it!=container.end(); it++)
#define trp(container, it) for(vector<pair<dt,dt> >::iterator it = container.begin(); it!=container.end(); it++)
#define cc1(a)cout<<#a<<": "<<a<<endl;
#define tra(container, it) for(typeof(container.begin()) it = container.begin(); it!=container.end(); it++)
#define cc2(a,b)cout<<#a<<": "<<a<<" , "<<#b<<": "<<b<< endl;
#define cc3(a,b,c)cout<<#a<<": "<<a<<" , "<<#b<<": "<<b<<" , "<<#c<<": "<<c<<endl;
#define cc4(a,b,c,d)cout<<#a<<": "<<a<<" , "<<#b<<": "<<b<<" , "<<#c<<": "<<c<<" , "<<#d<<": "<<d<<endl;
#define pr pair<dt,dt>  //NA
#define mp(a,b) make_pair(a,b)
#define pb push_back  //NA
#define gc getchar  //NA
#define F first
#define S second

int main()
{
	freopen("##inp.cpp","r",stdin);
    freopen("##out.cpp","w",stdout);
	//ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	rep(tes,1,t)
	{
	    int n;
	    vector<pr>vec;
	    cout<<"Case #"<<tes<<": ";
	    int cur=MOD;

	    cin>>n;
	    rep(i,0,n-1)
	    {
	        int x;
	        cin>>x;
	        vec.pb(mp(x,i));
        }
        sort(all(vec));
        reverse(all(vec));

        cur=abs(vec[0].F-vec[1].F);

        while(cur--)
        {
            printf("%c ",vec[0].S+'A');
        }
        vec[0].F=vec[1].F;

        rep(i,2,vec.size()-1)
        {
            while(vec[i].F--) printf("%c ",vec[i].S+'A');
        }

        cur=vec[0].F;
        while(cur--)
        {
            printf("%c%c ",vec[0].S+'A',vec[1].S+'A');
        }
        vec.clear();
        cout<<endl;
	}
}

