#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;

int T;
int main(){
	freopen("A-small-attempt0.in", "r", stdin);	
	freopen("a.txt", "w", stdout);
	cin>>T;
	int r;
	int a[4][4];
	for(int t=1; t<=T; ++t){
		set<int> s;
		s.clear();
		cin >> r;
		--r;
		for(int i=0; i<4; ++i)
		{
			for(int j=0; j<4; ++j)
			{
				cin >> a[i][j];
			}
		}
		for(int i=0; i<4; ++i)
		{
			s.insert(a[r][i]);
		}
		cin >> r;
		--r;
		for(int i=0; i<4; ++i)
		{
			for(int j=0; j<4; ++j)
			{
				cin >> a[i][j];
			}
		}
		vector<int> ans;
		ans.clear();
		for(int i=0; i<4; ++i)
		{
			//cout << a[r][i] << " " << endl;
			if (s.find(a[r][i]) != s.end())
				ans.push_back(a[r][i]);
		}
		if (ans.size() == 0)
			cout<<"Case #"<<t<<": "<< "Volunteer cheated!" <<endl;
		else if (ans.size()>1)
			cout<<"Case #"<<t<<": "<< "Bad magician!" <<endl;
		else 
			cout<<"Case #"<<t<<": "<< ans[0] <<endl;
	}	
}
