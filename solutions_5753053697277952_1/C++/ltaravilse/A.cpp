#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <queue>
#include <sstream>
#include <cmath>

using namespace std;

#define forn(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

int main()
{
	int casos;
	cin >> casos;
	for(int casito = 1; casito <= casos; casito++)
	{
		int n;
		cin >> n;
		int tot = 0;
		vector<pair<int,char> > vec(n);
		forn(i,n)
		{
			cin >> vec[i].first;
			tot += vec[i].first;
			vec[i].second = 'A'+i;
		}
		printf("Case #%d:",casito);
		sort(all(vec));
		reverse(all(vec));
		while(!vec.empty())
		{
			printf(" %c",vec[0].second);
			tot--;
			vec[0].first--;
			if(vec.size() >= 2 && vec[1].first*2 > tot)
			{
				printf("%c",vec[1].second);
				tot--;
				vec[1].first--;
			}
			sort(all(vec));
			reverse(all(vec));
			while(vec[vec.size()-1].first == 0)
				vec.pop_back();
		}
		printf("\n");
	}
}