#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include <string.h>
#include <bitset>
#include <functional>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <iomanip>
#define mp(a, b) make_pair(a, b)
typedef long long ll;
using namespace std;




int main(){
	int T;
	int N;
	
	cin >> T;
	for (int t = 0; t < T; t++){
		vector<pair<int, int>> P;
		cin >> N;
		int num = N;
		int sum = 0;
		int flag = 0;
		int min = 10000;
		for (int i = 0; i < N; i++){
			int a;
			cin >> a;
			sum += a;
			P.push_back(make_pair(a,i));
		}
		

		cout << "Case #" << t + 1 << ": ";

		if (N>2){
			for (int j = 0; j < sum - 2; j++){
				sort(P.begin(), P.end());
				cout << (char)(P[N - 1].second + 'A') << " ";
				P[N - 1].first--;
			}
			sort(P.begin(), P.end());
			cout << (char)(P[N - 1].second + 'A') << (char)(P[N - 2].second + 'A') << endl;

		}
		else{
			for (int j = 0; j < sum; j += 2){
				cout << "AB ";
			}
			cout << endl;
		}
		
	}


	return 0;
}