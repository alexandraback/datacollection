#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
#include <set>

#define ll long long

using namespace std;

void solve(int t) {

	int n;
	cin>>n;
	priority_queue<pair<int, int> > pq;
	int total = 0;
	for(int i=0; i<n; ++i){
		int t;
		cin>>t;
		total += t;
		pq.push(make_pair(t, i));
	}

	// cout<<pq.top().first<<"\n";


	cout<<"Case #"<<t<<": ";


	while(pq.size()) {
		string str = "";

		if(pq.size() == 1){ //impossible
			pair<int, int> pp = pq.top();
			while(pp.first){
				pp.first--;
				total--;

				str += char(pp.second + 'a');
			}
			pq.pop();

		} else {

			pair<int, int> pp1 = pq.top(); pq.pop();
			pair<int, int> pp2 = pq.top(); pq.pop();

			if (pp1.first > 1 && (pp2.first*2 <= (total-2) )  ) {
				pp1.first-=2;
				if(pp1.first != 0){
					pq.push(pp1);
				}
				pq.push(pp2);

				str += char(pp1.second + 'A');
				str += char(pp1.second + 'A');
				total -= 2;


			} else
			if (pp2.first *2 <= total-1) {
				pp1.first -= 1;
				if(pp1.first != 0){
					pq.push(pp1);
				}
				pq.push(pp2);
				str += char(pp1.second + 'A');
				total --;
			} else {


				pp1.first --;
				pp2.first--;
				if(pp1.first != 0){
					pq.push(pp1);
				}

				if(pp2.first != 0){
					pq.push(pp2);
				}

				str += char(pp1.second + 'A');
				str += char(pp2.second + 'A');
				total -= 2;

			}

		}

		cout<<str<<" ";

	}
	cout<<"\n";

	// cout<<"Case #"<<t<<": "<<ss(letters)<<"\n";

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin>>T;
	int t = 1;
	while(T--)
		solve(t++);

	return 0;

}