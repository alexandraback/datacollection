/**
*	
*	BY : Rajan Parmar
*/
#include <iostream>
#include <string>
#include <cmath>
#include <time.h>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <memory.h>
using namespace std;
#pragma warning(disable:4996)
#define N 30000
#define fi first
#define se second
#define mp make_pair
#define gc getchar_unlocked
#define mod 1000000007

typedef long long int ll;
typedef pair<ll, ll > pi;
typedef pair<ll, pi > pii;


struct sena{
	
	int no;
	char ch;
	sena(int n , char c):no(n) , ch(c) {}
	
	bool operator < (const sena& str) const
    {
        return (no < str.no);
    }
};
vector < sena > vec;
int main() {


	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-sol.out", "w", stdout);
	int t;
	int c = 1;
	int n;
	cin >> t;
	
	while(t--){
		cin >> n;
		int x;
		for(int i = 0 ; i < n ; i++){
			cin >> x;
			vec.push_back(sena(x , 'A'+i ));
		}
		sort(vec.begin() , vec.end());
		int sz = vec.size();
		cout << "Case #" << c++ <<": ";
		while(vec[sz - 1].no != 1){
			cout << vec[sz-1].ch ;
			vec[sz-1].no--;
			if(vec[sz-2].no>1){
				cout << vec[sz-2].ch ;
				vec[sz-2].no--;
			}
			cout << " ";	
			sort(vec.begin() , vec.end());
		}
		int tsz = sz - 1;
		while(tsz>=0 && vec[tsz].no !=0){
			tsz--;
		}
		tsz++;
		if( (sz - tsz)%2 == 0 ){
			
			while(vec[sz - 1].no != 0){
			cout << vec[sz-1].ch ;
			vec[sz-1].no--;
			
				cout << vec[sz-2].ch<<" " ;
				vec[sz-2].no--;
			
				
			sort(vec.begin() , vec.end());
		}
		}
		else{
			cout << vec[sz-1].ch<<" ";
			vec[sz-1].no--;
			sort(vec.begin() , vec.end());
			while(vec[sz - 1].no != 0){
			cout << vec[sz-1].ch ;
			vec[sz-1].no--;
			
				cout << vec[sz-2].ch  ;
				vec[sz-2].no--;
			
			cout <<" ";	
			sort(vec.begin() , vec.end());
			
		}
		}
		cout << endl;
		vec.clear();
	}
	
			//cout << "Case #" << c++ <<": " << n * mul << "\n";
		
	
	return 0;
}
