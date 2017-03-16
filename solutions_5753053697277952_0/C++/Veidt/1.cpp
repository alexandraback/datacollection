#include <bits/stdc++.h>
using namespace std;

int tt,n,tot,m,eq;

int p[26];


int main(){
    ios_base::sync_with_stdio(false);
    cin >> tt;
    for(int ii=1;ii<=tt;ii++){
	cin >> n;
	tot = 0;
	for(int i=0;i<n;i++){
	    cin >> p[i];
	    tot += p[i];
        }
	cout << "Case #"<< ii << ": ";

	while(tot){
	    m = 0;
	    for(int i=1;i<26;i++) if(p[i] > p[m]) m = i;
	    eq = 0;
	    for(int i=0;i<26;i++) if(p[i] == p[m]) eq++;
	    m = p[m];
	    
	    if(eq % 2){

		for(int i=0;i<26;i++) if(p[i] == m) {
			p[i] --; tot --;
			cout << (char) ('A'+i) << " ";
			break;
		    }
		
	    } else {
		for(int i=0;i<26;i++) if(p[i] == m) {
			p[i] --; tot --;
			cout << (char) ('A'+i) ;
			break;
		    }
		
		for(int i=0;i<26;i++) if(p[i] == m) {
			p[i] --; tot --;
			cout << (char) ('A'+i) << " ";
			break;
		    }
	    }
	}
	cout << endl;
    }
    return 0;
}
