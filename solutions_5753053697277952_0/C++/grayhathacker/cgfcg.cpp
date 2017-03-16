/*
jai shree ram _/\_
A hacker from NITP
*/

#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
typedef set<string> ss;
typedef vector<int> vs;
typedef map<int,char> msi;
typedef pair<int,int> pa;
typedef long long int ll;

set<pa> s;
int i,p,n;
set<pa> ::iterator it2,it;
int main()
{
	freopen("A-sma.in", "r", stdin);
  	freopen("A-smo.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
  	int t,pe=1;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    cout<<"Case #"<<pe++<<": ";
	    s.clear();
	    for(i=0;i<n;i++)
            cin>>p,s.insert(make_pair(p,i));
        while(1)
        {
            it=s.end();
            it--;
            it2=it;
            it--;
            if((*it2).first==1)
                break;
            cout<<(char)('A'+ (*it2).second)<<(char)('A'+ (*it).second)<<" ";
            if((*it2).first-1>0)
                s.insert(make_pair((*it2).first-1,(*it2).second));
            if((*it).first-1>0)
                s.insert(make_pair((*it).first-1,(*it).second));
            s.erase(it2);
            s.erase(it);
        }
        it=s.end();
        it--;
        it--;
        for(it2=s.begin();it2!=it;it2++)
            cout<<(char)('A'+ (*it2).second)<<" ";
        ++it;
        cout<<(char)('A'+ (*it2).second)<<(char)('A'+ (*it).second)<<" ";
        cout<<"\n";
	}
	return 0;
}
