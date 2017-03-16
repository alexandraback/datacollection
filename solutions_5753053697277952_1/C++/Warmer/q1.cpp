#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<=n;i++)
const int MOD = 1000002013;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

int i, j, k, m, n, l;
map<char,int> charCount;

int main() {
    //freopen("x.in", "r", stdin);

	//freopen("A-small-attempt0.in", "r", stdin);
	//freopen("A-small-attempt0.out", "w", stdout);

	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	char start = 'A';
	int total = 0;
	int tt, tn; cin >> tn;
	F1(tt,tn) {
		//cerr << tt << endl;
		int size = 0;
		cin >> size;
		for (int p = 0; p<26; p++){
			charCount[(char)start+p] = 0;
		}
		total = 0;
		for (int j = 0; j < size; j++){
			int tmp;
			cin >> tmp;
			total += tmp;
			charCount[(char)start+j] = tmp;
		}
		printf("Case #%d: ", tt);
		char a1, a2;
		while (total>0){
			//find at least one party to remove
			//find a max party first
			int maxKey = 0;
			for (int j = 1; j<size; j++){
				if (charCount[(char)(start+maxKey)]<charCount[(char)(start+j)]){
					maxKey = j;
				}
			}
			a1 = (char)(maxKey+start);
			cout << a1;
			charCount[(char)(start+maxKey)]--;
			total--;
			//find a2
			if (total ==0){
				break;
			}
			maxKey = 0;
			for (int j = 1; j<size; j++){
				if (charCount[(char)(start+maxKey)]<charCount[(char)(start+j)]){
					maxKey = j;
				}
			}
			if (total==2){
				//do nothing wait for next
			}
			else if (charCount[(char)(start+maxKey)]>=total/2.0){
				a2 = (char)(start+maxKey);
				charCount[(char)(start+maxKey)]--;
				total--;
				cout << a2;
			}
			else{
				for (int j = 0; j<size; j++){
					if (charCount[(char)(start+j)]>0){
						cout << (char)(start+j);
						total--;
						charCount[(char)(start+j)]--;
						break;
					}
				}
			}
			if (total>0){
				cout <<" ";
			}
		}
		
		
  		cout << endl;
	}
	return 0;
}
