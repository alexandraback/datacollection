#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define IT(a,it) for(auto it=a.begin(); it != a.end(); it++)
#define REV_IT(a,it) for(auto it=a.rbegin(); it != a.rend(); it++)
#define LL long long
#define LD long double
#define MP make_pair
#define FF first
#define SS second
#define PB push_back
#define INF (int)(1e9)
#define EPS (double)(1e-9)

#ifndef ONLINE_JUDGE
#  define LOG(x) cerr << #x << " = " << (x) << endl
#else
#  define LOG(x) 0
#endif

#define MAXX 500005

using namespace std;

typedef pair <int, int> pi_i;
typedef pair<int, pi_i> pi_ii;

bool cmp(int a, int b){ return a>b; }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }

int n, p[100];
multimap<int, int> mm;
vector<pi_i> vv;

bool chk(int v1,int v2){
	if(v1 > (v2/2)) return false;return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int T, casee = 1;
	cin >> T;
	for(casee=1;casee<=T;casee++){
		cout << "Case #" << casee << ": " ;
		cin >> n;
		mm.clear();
		vv.clear();
		int count = 0;
		for(int i = 0;i < n;i++){
			cin >> p[i];
			count += p[i];
			vv.PB(MP(p[i], i));
			//mm.insert(MP(p[i], i));
		}
		while(count > 0){
			sort(vv.begin(), vv.end());
			vv[n-1].FF--;
			bool solved = true;
			for(int i = 0;i < n;i++){
				if(chk(vv[i].FF, count-1) == false){
					solved = false;
					//cout << i << endl;
					break;
				}
			}
			if(solved){
				cout << (char)('A' + vv[n-1].SS) << " ";
				count-=1;
				continue;
			}
			vv[n-1].FF++;
			if(vv[n-1].FF > 0 && vv[n-2].FF > 0){
				//take 1 from both
				vv[n-1].FF--;
				vv[n-2].FF--;
				solved = true;
				for(int i = 0;i < n;i++){
					if(chk(vv[i].FF, count-2) == false){
						solved = false;break;
					}
				}
				if(solved){
					cout << (char)('A' + vv[n-1].SS) << (char)('A' + vv[n-2].SS) << " ";
					count-=2;
					continue;
				}
				//------------
				vv[n-1].FF -= 1;
				vv[n-2].FF++;
				solved = true;
				for(int i = 0;i < n;i++){
					if(chk(vv[i].FF, count-2) == false){
						solved = false;break;
					}
				}
				if(solved){
					cout << (char)('A' + vv[n-1].SS) << (char)('A' + vv[n-1].SS) << " ";
					count-=2;
					continue;
				}
				//---------------
				vv[n-1].FF += 1;
				solved = true;
				for(int i = 0;i < n;i++){
					if(chk(vv[i].FF, count-1) == false){
						solved = false;break;
					}
				}
				if(solved){
					cout << (char)('A' + vv[n-1].SS) << " ";
					count-=1;
					continue;
				}
			}else if(vv[n-1].FF > 0){
				if(count >= 2){
					vv[n-1].FF-=2;
					bool solved = true;
					for(int i = 0;i < n;i++){
						if(chk(vv[i].FF, count-2) == false){
							solved = false;break;
						}
					}
					if(solved){
						cout << (char)('A' + vv[n-1].SS) << (char)('A' + vv[n-1].SS) << " ";
						count-=2;
						continue;
					}
					//---------------
					vv[n-1].FF += 1;
					solved = true;
					for(int i = 0;i < n;i++){
						if(chk(vv[i].FF, count-1) == false){
							solved = false;break;
						}
					}
					if(solved){
						cout << (char)('A' + vv[n-1].SS) << " ";
						count-=1;
						continue;
					}
				}
			}
		}
		cout << endl;
	}
	fclose(stdin);
	fclose(stdout);
return 0;	
}

