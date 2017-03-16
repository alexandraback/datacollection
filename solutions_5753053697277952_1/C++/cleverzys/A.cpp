#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <limits>
#include <queue>
#include <stdexcept>
#include <iomanip> 
#include <sstream>

using namespace std;

//*
#define TRY
	#define SMALL
		#define LARGE

typedef long long ll;
#define N 1000000007



void Solve();

int r,c;
bool b[102][102];
bool f[102][102]={false};
int fx[4]={0,1,0,-1};
int fy[4]={1,0,-1,0};

void main() 
{
#ifdef TRY
	freopen("1.txt", "rt", stdin);
	//freopen("C-large.txt","wt",stdout);
	//freopen("2.out","wt",stdout);
#endif
#ifdef SMALL
	freopen("A-small-attempt0.in","rt",stdin);
	freopen("A-small.txt","wt",stdout);
#endif
#ifdef LARGE
	freopen("A-large.in","rt",stdin);
	freopen("A-large.txt","wt",stdout);
#endif
	int Numcase;
	cin>>Numcase;

	for(int test=1;test<=Numcase;test++)
	{
		cout<<"Case #"<<test<<":";

		Solve();
	}
}
bool cmp(pair<int,int> a,pair<int,int> b);
void Solve(){
	int n,a,b,c;
	vector<pair<int, int>> v;

	cin>>n;
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>a;
		sum+=a;
		v.push_back(make_pair(i,a));
	}
	sort(v.rbegin(),v.rend(),cmp);
	//cout<<v[0].second;
	while(sum!=0){
		int len = v.size();
		if(sum>2){
			if(2 * v[0].second > sum){
				if(sum%2==1) {
					sum -= 1;
					v[0].second -= 1;
					char c = v[0].first+'A';
					cout<<" "<<c;
				}
				else{
					sum -= 2;
					v[0].second -= 2;
					char c = v[0].first+'A';
					cout<<" "<<c<<c;
				}
				
			}
			else{
				if(sum%2==1){
					v[0].second -= 1;
					char c1 = v[0].first+'A';
					cout<<" "<<c1;
					sum -=  1;
				}
				else{
					v[0].second -= 1;v[1].second -= 1;
					char c1 = v[0].first+'A';
					char c2 = v[1].first+'A';
					cout<<" "<<c1<<c2;
					sum -= 2;
				}
				
				
			}
			sort(v.rbegin(),v.rend(),cmp);
		}
		else{
			if(sum==2){
				if(v[0].second == 2){
					sum -= 2;
					v[0].second -= 2;
					char c1 = c1 = v[0].first+'A';
					cout<<" "<<c1;
				}
				else{
					sum -= 2;
					v[0].second -= 1;
					v[1].second -= 1;
					char c1 = v[0].first+'A';
					char c2 = v[1].first+'A';
					cout<<" "<<c1<<c2;
				}
				
			}
			
			
		}
		
	}
	cout<<endl;

}

bool cmp(pair<int,int> a,pair<int,int> b){
	return a.second<b.second;
}