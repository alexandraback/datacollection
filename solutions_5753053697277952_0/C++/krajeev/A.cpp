#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int num_case=1;num_case <= t;num_case++){
		int n;
		cin>>n;
		vector<int> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		priority_queue<pair<int,int> > pq;
		for(int i=0;i<n;i++){
			pq.push(make_pair(v[i],i));
		}
		cout<<"Case #"<<num_case<<": ";
		while(!pq.empty()){
			pair<int,int> t = pq.top();
			pq.pop();
			if(pq.empty()){
				int d = min(t.first,2);
				for(int j=0;j<d;j++)
					cout<<(char)('A'+t.second);
				cout<<" ";
				t.first-=d;
				if(t.first>0)
					pq.push(t);
				continue;
			}
			pair<int,int> t2 = pq.top();
			if(t.first-t2.first>0){
				int d = min(2,t.first-t2.first);
				for(int j=0;j<d;j++)
					cout<<(char)('A'+t.second);
				cout<<" ";
				t.first-=d;
				if(t.first>0)
					pq.push(t);
				continue;
			}
			if(t.first == t2.first){
				pq.pop();
				if(pq.empty() ||  pq.top().first!=t.first){
					cout<<(char)('A'+t.second)<<(char)('A'+t2.second)<<" ";
					t.first-=1;
					t2.first-=1;
					if(t.first>0)
						pq.push(t);
					if(t2.first>0)
						pq.push(t2);
				}
				else{
					pq.push(t2);
					cout<<(char)('A'+t.second)<<" ";
					t.first -=1;
					if(t.first>0)
						pq.push(t);
				}
			}
		}
		cout<<endl;
	}
}