#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
struct Zip{
	Zip(char a, int cnt) : a(a), cnt(cnt){}
	char a;
	int cnt;
};

int main(){
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	int t;
	cin>>t;
	cin.ignore();
	for(int i = 0; i < t ; i++){
		cout<<"Case #"<<i + 1<<": ";
		int n,bad = 0;
		cin>>n;
		cin.ignore();
		vector <string> s(n);
		for(int j = 0; j < n; j++){
			getline(cin,s[j]);
		}
		
		vector <vector <Zip> > v(n);
		for(int j = 0 ; j < n; j ++){
			s[j] += '*';
			int cnt = 1;
			for(int z = 1; z< (int)s[j].size(); z++){
				if(s[j][z] == s[j][z-1])
					cnt++;
				else{
					v[j].push_back(Zip(s[j][z-1],cnt));
					cnt = 1;
				}
			}
			if(j > 0 && v[j].size() != v[j-1].size())
				bad = -1;
		}

		if(bad == -1){
			cout<<"Fegla Won\n";
			continue;
		}

		int ans = 0;

		for(int j = 0 ; j < (int)v[0].size() ; j++){
			for(int z = 1 ; z < n; z++)
				if(v[z][j].a !=v[z-1][j].a){
					bad = -1;
					break;
				}
			if(bad == -1)
				break;
			int mn = -1;
			for(int z = 1; z < 101; z++){
				int cnt = 0;
				for(int p = 0; p < n; p++){
					cnt += abs(v[p][j].cnt - z);
				}
				if(mn == -1 || mn > cnt)
					mn = cnt;
			}

			ans += mn;

		}

		if(bad == -1){
			cout<<"Fegla Won\n";
		}else
			cout<<ans<<endl;

	}


}
