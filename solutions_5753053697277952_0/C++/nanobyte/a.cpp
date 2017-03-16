#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef stack<long long> ss;
#define get(a) #a

//#define DEBUG
#define local

#define endl '\n'

#ifdef DEBUG
 
#define debug(args...) {dbg,args; cerr<<endl;}
 
#else
 
#define debug(args...) // Just strip off all debug tokens
 
#endif
 
struct debugger
 
{
 
template<typename T> debugger& operator , (const T& v)
 
{
 
cerr<<v<<" ";
 
return *this;
 
}
 
} dbg;

vector<int> arr(10,0);


int main(){
	std::ios::sync_with_stdio(false);
	#ifdef local
		freopen("in.in","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	ll t,n;
	cin>>t;

	ll cases = 1;

	while(t--){
		cin>>n;
		int temp;

		vector< pair<int,char> > arr;

		int sum = 0;
		for(int i = 0;i < 26;i++){
			arr.push_back(make_pair(0,'A'+i));
		}
		for(int i = 0;i < n;i++){
			cin>>temp;
			arr[i].first = temp;
			sum += arr[i].first;
		}

		sort(arr.begin(),arr.end());
		cout<<"Case #"<<cases<<": ";
		while(sum > 0){
			char first = '-' ,second = '-';
			for(int i = 25;i >= 0;i--){
				if(first != '-' && arr[i].first > 0){
					second = arr[i].second;
					arr[i].first--;
					sum--;
					break;
				}
				else if(arr[i].first > 0){
					first = arr[i].second;
					arr[i].first--;
					sum--;
				}
			}

			int flag = 0;

			for(int i = 0;i < 26;i++){
				if(arr[i].first > sum/2){
					flag = 1;
					break;
				}
			}
			if(!flag){
				if(second != '-'){
					cout<<first<<second<<" ";
				}
				else{
					cout<<first<<" ";
				}
			}
			else{
				for(int i = 0;i < 26;i++){
					if(arr[i].second == second){
						arr[i].first++;
						sum++;
						break;
					}
				}
				cout<<first<<" ";
			}
			sort(arr.begin(),arr.end());

		}
		cout<<"\n";

		cases++;
	}
}