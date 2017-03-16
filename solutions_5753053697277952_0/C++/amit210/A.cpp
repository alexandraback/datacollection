#include<bits/stdc++.h>
using namespace std;

#define     ll             long long
#define     si(x) 	scanf("%d",&x)
#define 	sc(ch)	 scanf(" %c",&ch);
#define 	sl(x) 	scanf("%I64d",&x)
#define 	pi(x) 	cout << x <<" "
#define 	nl 	 cout << '\n'
#define 	mp	   make_pair
#define     pb 	  push_back
#define 	f 	  first
#define 	se 	   second
#define 	pii 	   pair<int,int>
#define 	RESET(a)   	 memset(a,-1,sizeof(a))
#define 	CLEAR(a) 		memset(a,0,sizeof(a))
#define 	all(v)   		v.begin(),v.end()
#define 	trv(it,v) 		for(it=v.begin();it!=v.end();it++)
#define 	rep(i,a,b) 		for(int i=a;i<b;i++)

#define mod 	1000000007
#define MIN 	INT_MIN
#define MAX 	INT_MAX
#define INF 	1e9
#define pic pair<int,char>
int main()
{
    //std::ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
        freopen("2.in", "r", stdin);
        freopen("_1.in", "w", stdout);
    #endif

    int t=1,T;
    si(T);
    while(t<=T)
    {
        int n;
        cin >> n;
        set<pic> S;
        int sum=0;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            sum += x;
            pic p({x,'A'+i});
            S.insert(p);
        }
        vector<string> ans;
        while(!S.empty()){
            //for(auto it : S)
           // cout << it.f<<" "<<it.se<<endl;
            pic p = *S.rbegin();
            string s;
            s += p.se;
            S.erase(p);
            sum--;
            p.f--;
            if(p.f>0){
                S.insert(p);
            }
            if(!S.empty()){
            pic p2 = *S.rbegin();
            double d = (double)p2.f/sum;
            if(d-0.5 > 0){
                S.erase(p2);
                sum--;
                s+=p2.se;
                p2.f--;
                if(p2.f > 0){
                    S.insert(p2);
                }
            }
            }
            ans.pb(s);
        }
        cout<<"Case #"<<t<<": ";
        for(auto it : ans)
            cout << it<<" ";
        nl;
        t++;
    }

   return 0;
}

