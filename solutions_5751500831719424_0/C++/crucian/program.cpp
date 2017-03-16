#include <bits/stdc++.h>
#define Sort(x) sort(x.begin(),x.end())
typedef long long LL;
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) {
	bool ok = false;
	int m;
	cin>>m;
	vector <string> A(m);
	vector <int> siz(m);
	for(int j = 0; j < m; j++) {
	    cin>>A[j];
	    siz[j] = A[j].size();
	}
	string tmp1 = "", tmp2 = "";
	for(int j = 0; j < A.size(); j++) {
	    tmp2 = "";
	    tmp2 += A[j][0];
	    for(int k = 1; k < A[j].size(); k++) {
		if(A[j][k] != A[j][k-1]) tmp2 += A[j][k];
	    }
	    if(j > 0 && tmp1 != tmp2) {
		ok = true;
		cout<<"Case #"<<i+1<<": Fegla Won"<<endl;
		break;
	    }
	    tmp1 = tmp2;
	}
	if(ok == true) continue;
	int res = 0;
	vector <int> cha[100];
	for(int j = 0; j < m; j++) {
	    int licznik = 1;
	    for(int k = 1; k < A[j].size(); k++) {
		if(A[j][k] != A[j][k-1]) {
		    cha[j].push_back(licznik);
		    licznik = 1;
		} else {
		    licznik++;
		}
	    }
	    cha[j].push_back(licznik);
	}
	for(int j = 0; j < cha[0].size(); j++) {
// 	    cout<<cha[0][j]<<" "<<cha[1][j]<<endl;
	    int mn = 99999;
	    for(int k = 0; k < m; k++) {
		int sum = 0;
		for(int l = 0; l < m; l++) {
		    if(l != k) {
			sum += abs(cha[l][j]-cha[k][j]);
		    }
		}
		mn = min(sum,mn);
	    }
	    res += mn;
	}
	
	cout<<"Case #"<<i+1<<": "<<res<<endl;
    }
    
}