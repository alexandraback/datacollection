#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long LL;

//*******************
//*******************
int n;
void read() {
	cin>>n;
	vector<int> v;
	priority_queue<pair<int, char> > q;
	int ile = 0;
	for(int i=0; i<n; i++)
	{
		int a; cin>>a;
		ile += a;
		q.push({a, 'A'+i});
	}
	if(q.size() == 2)
	{	
		auto a = q.top(); q.pop();
		auto b = q.top(); q.pop();

	 	for(int i=0; i<a.first; i++)
	 		cout<<a.second<<b.second<<" ";
	 	
	}
	else
	{
		while(!q.empty())
		{
			if(q.top().first*2 > ile)
				cout<<"KURWA"<<endl;

			while(ile > 2)
			{
				auto a = q.top();
				q.pop();
				a.first -- ;
				cout<<a.second<<" ";
				if(a.first != 0)
					q.push(a);
				ile --;
			}
			auto a = q.top(); q.pop();
			auto b = q.top(); q.pop();
			cout<<a.second<<b.second<<" ";
		}
	}
}

void solve() {

}

void clean() {

}

int main() {
	ios::sync_with_stdio(false);
	int z;
	cin >> z;
	for(int zz=1; zz<=z; zz++)
	{

	cout<<"Case #"<<zz<<": ";
		read();
		solve();
		clean();
		cout<<endl;
	}
  return 0;
}