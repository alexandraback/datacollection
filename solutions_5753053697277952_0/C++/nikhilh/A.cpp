#include <bits/stdc++.h>

using namespace std;

bool comp (pair <int,char> a, pair <int,char> b)
{
	return a.first < b.first;
}

int main()
{
	int t;
	cin>>t;

	for(int c=1;c<=t;c++)
	{
		printf("Case #%d: ",c);

		int n;
		cin>>n;

		priority_queue < pair<int,char>, vector < pair<int,char> >, decltype(&comp)> A(&comp);

		int p = 0;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;

			p += x;

			A.push(make_pair(x,'A'+i));
		}

		while(!A.empty())
		{
			pair <int,char> a;

			a = A.top();
			A.pop();
			printf("%c",a.second);

			a.first -= 1;
			p -=1;

			if(a.first)
				A.push(a);

			a = A.top();
			if(a.first > p/2)
			{
				printf("%c",a.second);
				A.pop();
				a.first -= 1;
				p-=1;
				if(a.first)
					A.push(a);
			}
			printf(" ");
		}

		printf("\n");
	}
}