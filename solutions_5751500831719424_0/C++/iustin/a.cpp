# include <iostream>
# include <fstream>
# include <string>
# include <vector>
# include <algorithm>
# define DIM 103
# define pb push_back

# define cout fout
using namespace std;

int a[DIM][DIM];

int main()
{
	ifstream fin ("f.in");
	ofstream fout ("f.out");
	
	int T, n;
	string ss, s;
	
	fin>>T;
	
	for(int t=1;t<=T;++t) {
		fin>>n;
		
		int lost = 0;
		
		fin>>s;
		
		ss = s[0];

		int cnt = 1;
		for (unsigned i=1;i<s.size();++i) {
			if (s[i] == ss[ss.size() - 1]) {
				++cnt;
				continue;
			}
			a[ss.size() - 1][0] = 1;
			a[ss.size() - 1][1] = cnt;
			
			cnt=1;	
			ss += s[i];
		}
		
		a[ss.size() - 1][0] = 1;
		a[ss.size() - 1][1] = cnt;
		
		for(int i=1;i<n;++i) {
			fin>>s;
			
			int ps = 0;
			cnt=0;
			
			for(unsigned j=0;j<s.size() && !lost;++j) {
				if (cnt == 0 && ss[ps] != s[j]) {
					lost = 1;
					continue;
				}
				
				if (s[j] == ss[ps]) {
					++cnt;
				} else {
					++ps;
					if (ps < ss.size() && s[j] == ss[ps]) {
						a[ps-1][++a[ps-1][0]] = cnt;
						cnt = 1;
					} else {
						lost = 1;
					}
				}
			}
			
			if (!lost && ps+1 == ss.size() && cnt && s[s.size() - 1] == ss[ps]) {
				a[ps][++a[ps][0]] = cnt;
			} else {
				lost = 1;
			}
		}
			
		if (lost) {
			cout<<"Case #"<<t<<": Fegla Won\n";
		} else {
			int p = n/2 + 1, sol = 0;
			/*
			if (t == 3) {
				for(int i=0;i<2;++i) {
					for ( int j=0;j<=3;++j) {
						cout<<a[i][j]<<" ";
					}
					cout<<endl;
				}
			}*/
			
			for(int i=0;i<ss.size();++i) {
				sort(a[i] + 1, a[i] + a[i][0] + 1);
				
				int v1=0, v2=0;
				for(int j=1;j<=n;++j) {
					v1 += abs(a[i][p-1]-a[i][j]);
					v2 += abs(a[i][p]-a[i][j]);
				}
				
				sol += min(v1, v2);
			}
			
			cout<<"Case #"<<t<<": "<<sol<<"\n";
		}
	}
	
	return 0;
}
				
					
				
				
