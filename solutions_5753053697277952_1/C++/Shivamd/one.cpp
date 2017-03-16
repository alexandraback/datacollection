#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll t,n,i,a,tt=1;
set< pair< ll ,ll > >s;

int main()
{
	 freopen("in.in", "r", stdin);
	  freopen("out.txt", "w", stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>a;
			s.insert(make_pair(a,i-1));
		}

		cout<<"Case #"<<tt<<": ";
        set< pair< ll ,ll > >::iterator it,it1;
		while(1)
		{
			if(s.size()==2){
				it = s.end();
				it--;
				it1 = it;
				it1--;
				//cout<<it1->first<<" "<<it->first<<"   ";


				if(it1->first==it->first)
				{
					ll aa =  it1->first;
					ll bb = it->first;
					ll aa1 = it1->second;
					ll bb1 = it->second;

					while(aa>0)
					{
						cout<<char('A'+ aa1)<<char('A'+ bb1)<<" ";
						aa--;
					}
				}

				break;
			}
			it = s.end();
			it--;
			ll aa1 = it->first;
			ll bb1 = it->second;
			cout<<char('A'+bb1)<<" ";
			s.erase(make_pair(aa1,bb1));
			if(aa1>1)
			s.insert(make_pair(aa1-1,bb1));



		}
		cout<<"\n";
		tt++;
		s.clear();
	}

	return 0;
}
