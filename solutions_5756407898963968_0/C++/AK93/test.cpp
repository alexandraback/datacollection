#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <fstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <limits.h>
#include <time.h>

using namespace std;
typedef long long ll;

const int mod = 1e9+7;
const double eps = 1e-11;

int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test;
	cin>>test;
	for(int tt = 0; tt < test; tt++){
		int n;
		cin>>n;
		vector<char> used(16, false);
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				int x;
				cin>>x;
				if(i == n-1)
					used[x-1] = 1;
			}
		}
		cin>>n;
		int count = 0, res = 0;
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				int x;
				cin>>x;
				if(i == n-1){
					if(used[x-1]){
						res = x;
						count++;
					}
				}
			}
		}
		cout<<"Case #"<<tt+1<<": ";
		if(count == 0){
			cout<<"Volunteer cheated!\n";
		}
		else{
			if(count == 1)
				cout<<res<<"\n";
			else
				cout<<"Bad magician!\n";
		}
	}
    return 0;
}