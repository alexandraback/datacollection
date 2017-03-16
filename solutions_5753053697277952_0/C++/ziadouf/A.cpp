#include <stdio.h>
#include <functional>
#include <bitset>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <string.h>
#include <numeric>
using namespace std;

 typedef vector<int> vi; 
 typedef vector<vi> vvi; 
 typedef pair<int,int> ii; 
 typedef long long ll;
 #define sz(a) int((a).size()) 
 #define pb push_back 
 #define all(c) (c).begin(),(c).end() 
 #define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
 #define present(c,x) ((c).find(x) != (c).end()) 
 #define cpresent(c,x) (find(all(c),x) != (c).end()) 

int cnt[50];

int main ()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	
	int TC;
	cin >> TC;
	int CC = 1;
	while (TC--)
	{
		printf("Case #%d: ",CC++);
		
		int N;
		cin >> N;
		for (int i=0 ; i<N ; i++) cin >> cnt[i];
		vector <string> ret;
		
		priority_queue < ii , vector<ii> , greater<ii> > pq;
		for (int i=0 ; i<N ; i++)
		{
			pq.push(make_pair(-cnt[i],i));
		}
		
		while (!pq.empty())
		{
			string ans;
			
			ii cur = pq.top();
			ii cur2;
			
			pq.pop();
			int first_party = -1 , second_party = -1;
			first_party = cur.second;
			int first_count = -cur.first;
			int second_count;
			
			// Check for second
			if (pq.size() == 1 && pq.top().first == -first_count)
			{
				ii cur2 = pq.top();
				pq.pop();
				second_party = cur2.second;
				second_count = -cur2.first;
			}
			
			ans += ('A' + first_party);
			if (second_party != -1) ans += ('A' + second_party);
			
			if (first_count != 1)
			{
				pq.push(make_pair(-(first_count-1),first_party));
			}
			
			if (second_party != -1 && second_count != 1)
			{
				pq.push(make_pair(-(second_count-1),second_party));
			}
			ret.pb(ans);
		}
		for (int i=0 ; i<sz(ret) ; i++)
		{
			if (i) cout << " ";
			cout << ret[i];
		}
		cout << endl;
	}
	
}
