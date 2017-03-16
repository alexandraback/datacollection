#include<vector>
#include<cmath>
#include<complex>
#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<float.h>
#include<set>
#include<map>
#include<queue>
#include<math.h>
#include<algorithm>
using namespace std;


typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

#define pb push_back
#define mp make_pair
#define snd second
#define fst first
#define debug printf("--%d--\n",__LINE__)
#define ll long long int

int T, N;
int main(void){
	cin >> T;
	for(int num=1;num<=T;num++){
		cin >> N;
		int m[N];
		int sum = 0;
		for(int i=0;i<N;i++){ cin >> m[i]; sum += m[i];}
		
		cout << "Case #" << num << ":";
		
		vector<pair<int, char> > p;
		for(int i=0;i<N;i++){
			p.pb(mp(-m[i],'A'+i));
		}
		sort(p.begin(), p.end());
		for(int i=0;i<N;i++) p[i].fst *= -1;
		//for(int i=0;i<N;i++) cout << p[i].fst << " " << p[i].snd << endl;
		while(p[0].fst>0){
			string q = "";
			int a = p[0].fst;
			for(int i=0;i<N;i++){
				if (p[i].fst!=a) break;
				q += p[i].snd;
				p[i].fst--;
			}
			if (q.size()==1){
				cout << " " << q[0];
			}else{
				for(int i=0;i<q.size()-2;i++){
					cout << " " << q[i];
				}
				cout << " " << q.substr(q.size()-2,2);
			}
		}
		cout << endl;
	}
	
	return 0;
}
