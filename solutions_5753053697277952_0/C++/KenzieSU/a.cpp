#include <bits/stdc++.h>

using namespace std;

int p[26];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tn;
	cin>>tn;
	for(int tc=1; tc<=tn; tc++)
	{
		int n;
		cin>>n;
		for(int i=0; i<n; i++)
			cin>>p[i];
		int mn=p[0];
		int mx=p[0];
		for(int i=1; i<n; i++)
		{
			if(p[i]<mn)
				mn = p[i];
			if(p[i]>mx)
				mx = p[i];
		}
		cout << "Case #" << tc << ": ";
		bool fl = true;
		while(fl)
		{
			fl = false;
			for(int i=0; i<n; i++)
				if(p[i]!=mn && p[i]==mx)
				{
					fl=true;
					cout<<(char)('A'+i)<<" ";
					p[i]--;
				}
			if(fl)
				mx--;
		}
		for(int i=0; i<n-2; i++)
			while(p[i])
			{
				cout<<(char)('A'+i)<<" ";
				p[i]--;
			}
		for(int i=0; i<mn; i++)
			cout<<(char)('A'+n-2)<<(char)('A'+n-1)<<" ";
		cout<<endl;
	}

	return 0;
}