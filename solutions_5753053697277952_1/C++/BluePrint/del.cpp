#include<bits/stdc++.h>
using namespace std;
#define cin fin
#define cout fout
int fun(pair<int,int>p,pair<int,int >q){
	return (p.first<q.first);
}

int main(){
	ifstream fin;
	fin.open("A-large (2).in");
	ofstream fout;
	fout.open("2.txt");
	int pq=1;
	int t;
	cin>>t;
	while(t--){
		cout<<"Case #"<<pq<<": ";
		pq++;
		int n;
		cin>>n;
		vector<pair<int,int> > v;
		long long int sum=0;
		for(int i=0;i<n;i++){
			int ele;
			cin>>ele;
			sum+=ele;
			v.push_back(make_pair(ele,i));
		}
		if(n==2){
			while(v[0].first){
				cout<<"AB ";
				v[0].first--;
			}
			cout<<endl;
			continue;
		}
		make_heap(v.begin(),v.end(),fun);
		while(sum>2){
			int a=v[0].second;
			v[0].first--;
			sum--;
			pop_heap(v.begin(),v.end(),fun);
			char ch='A'+a;
			cout<<ch<<" ";
		}
		//cout<<"zzzz";
		if(sum==2){
			sort(v.begin(),v.end());
			char p=v[n-1].second+'A';
			char q=v[n-2].second+'A';
			cout<<p<<q<<endl;
		}
	}
}
