/*
 * codeforces2.cpp
 *
 *  Created on: 19-Mar-2016
 *      Author: bajaj
 */




#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <deque>


using namespace std;

typedef long long int LL;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> AdjList;    // graph representation
vector< pair<int, ii> > EdgeList; // edgelist for kruskal algorithm


#define inp_s ios_base::sync_with_stdio(false)
#define cinnull cin.tie(NULL)

#define DRT() int test_case; cin>>test_case;while(test_case--)
#define FOR(i,a,b) for(LL i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) for(int i=0;i<n;i++)
#define rdarr(a,n) REP(i,n) cin >> a[i];


LL min(LL a, LL b){
	return a < b ? a : b;
}

LL max(LL a, LL b){
	return a > b ? a : b;
}

int max(int a, int b){
	return a > b ? a : b;
}


int n;

int main(){

	freopen("/Users/bajaj/Downloads/A-large (2).in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t=1;

	int test_c;
	cin>>test_c;


	while(test_c){

		int n;
		cin>>n;

		priority_queue<pair<int, char> > pq;

		int sum=0;

		int ascii = 65;

		REP(i,n){
			int val;
			cin>>val;
			sum+=val;
			pq.push(make_pair(val, 65+i));
		}

		cout<<"Case #"<<t<<": ";

		while(sum){

			pair<int, char> pi = pq.top();
			pq.pop();

			pair<int, char> pii = pq.top();
			pq.pop();

			if(pi.first != 0){
				cout<<pi.second;

				pi.first--;

				if(pi.first)
					pq.push(pi);

				sum--;
			}

			if(pii.first !=0){
				double ans = (double)pii.first/(double)sum;

				if(ans>0.5){
					pii.first--;
					cout<<pii.second<<" ";
					sum--;
				}
				else{
					cout<<" ";
				}

				if(pii.first)
					pq.push(pii);
			}


		}
		t++;
		cout<<"\n";


		test_c--;
	}




	return 0;

}
