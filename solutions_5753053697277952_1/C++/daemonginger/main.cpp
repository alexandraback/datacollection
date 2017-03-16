#include<bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define PI 3.14159265359
#define endl '\n'

using namespace std;

const int N = 27;
int tests,n,t[N];

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin >> tests;
	for(int te=1;te<tests+1;te++)
	{
		cin >> n;
		int sum = 0;
		for(int i=0;i<n;i++)
		{
			cin >> t[i];
			sum += t[i];
		}
		cout << "Case #" << te << ": ";
		
		
		while(sum > 0)
		{
			int m_max=0,i_max=0,nb=0;
			for(int i=0;i<n;i++)
			{
				nb += (t[i] > 0);
				if(m_max < t[i])
				{
					m_max = t[i];
					i_max = i;
				}
			}
			if(nb != 2)
			{
				--t[i_max];
				--sum;
				cout << (char)('A'+i_max) << " ";
			}
			else
			{
				for(int i=0;i<n;i++)
					if(t[i] > 0)
					{
						cout << (char)('A'+i);
						--t[i];
					}
				cout << " ";
				sum -= 2;
			}
		}
		cout << endl;
	}
	
	return 0;
}