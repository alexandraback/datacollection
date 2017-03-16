#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<math.h>
#include<fstream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define      pii               std::pair<int,int>
#define      vi                std::vector<int>
#define      mp(a,b)           make_pair(a,b)
#define      pb(a)             push_back(a)
#define      each(it,s)        for(auto it = s.begin(); it != s.end(); ++it)
#define      rep(i, n)         for(int i = 0; i < (n); ++i)
#define      fill(a)           memset(a, 0, sizeof (a))
#define      sortA(v)          sort(v.begin(), v.end())
#define      sortD(v)          sort(v.begin(), v.end(), greater<auto>())
#define      X                 first
#define      Y                 second
ll MOD = 1000000007;

int main() {
    freopen("in.txt","rt",stdin);
   freopen("out.txt","wt",stdout);
    int t;
    cin>>t;
    for(int tt=1; tt<=t; tt++) {
        int n;
        cin>>n;
        int arr[27];
       vector< pair <int,char> > pq;
        for(int i=0; i<n; i++) {
            cin>>arr[i];
            pq.push_back({arr[i],'A'+i});
        }
        sort(pq.begin(),pq.end());
        cout<<"Case #"<<tt<<": ";
     int m =n-1;
        while(pq[m].first>pq[m-1].first)
		{
			cout<<pq[n-1].second<<" ";
			pq[m].first-=1;
		}
		for(int i=0;i<m-1;i++)
		{
			while(pq[i].first>0)
			{
				cout<<pq[i].second<<" ";
				pq[i].first-=1;
			}
		}
		while(pq[m].first>0)
		{
			cout<<pq[m-1].second<<pq[m].second<<" ";
			pq[m].first-=1;
		}
        cout<<"\n";
    }
}
