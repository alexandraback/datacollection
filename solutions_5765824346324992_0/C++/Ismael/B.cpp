#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;

long long int nbProc(const vector<long long int> & v, long long int T) {
    long long int res = 0;
    for(auto m : v) {
	res += 1 + T/m;
    }
    return res;
}

long long int findT(const vector<long long int> & v, long long int N) {
    long long int a = 0, b = N * 200*1000;
    while(b > a) {
	long long int m = (a+b)/2;
	long long int val = nbProc(v,m);
	if(val >= N)
	    b = m;
	else
	    a = m+1;
	    
    }
    return a;
}

int result(const vector<long long int> & v, long long int N) {    
    long long int T = findT(v,N);
    //cout << "T:" << T << ";   " ;
    int nbProc = 0;
    for(auto m : v) {
	nbProc += T/m + (T%m==0 ? 0 : 1);
    }

    int iDispo = N - nbProc;
    //cout << "I:" << iDispo << ";   " ;

    
    int iMach = 0;
    int nbDispos = 0;
    for(auto m : v) {
	iMach++;
	if(T%m==0) {
	    nbDispos++;
	    if(nbDispos == iDispo) {
		//cout << "M";
		return iMach;
	    }
	    //cout << iMach << " ";
	}
    }
    cout << endl;
    return 0;
}

int main() {
    /*
    vector<long long int > v = {3,1,2};
    for(int i = 1; i < 12; i++) {
	cout <<	result(v,i) << endl;
    }
    */
    
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
	long long int B,N;
	cin >> B >> N;
	vector<long long int> v(B);
	for(int i = 0; i < B; i++) {
	    cin >> v[i];
	}
	cout << "Case #" << t+1 <<": " << result(v,N) << endl;
    }
    
    return 0;
}
