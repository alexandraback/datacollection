#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	REP(q,t){
		int n;
		cin>>n;
		string a[101];
		string c[101];
		REP(i,n)
				cin>>a[i];
		REP(i,n){
			char last = '[';
			REP(j,(int)a[i].size()){
				if(a[i][j] == last){
				} else{
					c[i].push_back(a[i][j]);
					last = a[i][j];
				}
			}
		}
		bool flag = true;
		REP(i,n-1){
			if(c[i] != c[i+1]){
				flag = false;
				break;
			}
		}
		cout<<"Case #"<<q + 1<<": ";
		if(!flag){
			cout<<"Fegla Won";
		} else{
			int d[101][101];
			REP(i,101){
				REP(j,101){
					d[i][j] = 0;
				}
			}

			string ex = c[0];
			REP(i,n){
				int idx = 0;
				REP(j,(int)a[i].size()){
					if(ex[idx] == a[i][j]){
						d[i][idx]++;
					} else{
						idx++;
						d[i][idx]++;
					}
				}
			}
			int result = 0;
			REP(i,(int)ex.size()){
				int resulttemp = 1000000000;
				REP(j,101){
					int sum = 0;
					REP(k,n){
						sum += abs(j +  - d[k][i]);
					}
					resulttemp = min(resulttemp,sum);
				}
				result += resulttemp;
			}
			cout<<result;
		}
		cout<<'\n';
	}

	return 0;
}

