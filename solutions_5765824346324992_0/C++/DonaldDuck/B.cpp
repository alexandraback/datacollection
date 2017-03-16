// Problem B

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <algorithm>
#include <set>
#include <string.h>
#include <map>
#include <queue>
#include <stack>

#define pb push_back
#define mp make_pair

#define MAXB 1000

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef set<int> si;
typedef vector<ii> vii;
typedef pair<ll,int> plli;

int solve() {
	int N, B;
	ll m[MAXB];
	cin >> B >> N;
	for (int i=0; i<B; i++) cin >> m[i];
	
	if (N<=B) return N;
	
	ll t;
	ll lb = 0;
	ll ub = 100000000000000;
	
	// Cerco il minimo t tale che al tempo t le persone servite siano almeno N.
	// Questo minimo è l'istante in cui viene servito l'N-esimo
	
	ll x;
	while (lb < ub) {
		t = (lb+ub)/2;
		x=0;
		for (int i=0; i<B; i++)
			x+=((t+m[i]-1)/m[i] + (t%m[i]==0));
			//x+=(t/m[i] + (t%m[i]!=0));
		if (x>=N) ub = t;
		else lb = t+1;
		//cout << t << " ";
	}
	t = lb;
	//cout << "Tempo " << t << "  x " << x << endl;
	
	// Ora t rappresenta il tempo a cui viene servito l'N-esimo.
	// Guardo quanta gente è servita dopo il tempo t-1:
	ll y = 0;
	for (int i=0; i<B; i++) y+=((t-1+m[i]-1)/m[i] + ((t-1)%m[i]==0));
	
	ll z = N-y; // Gente da servire all'istante t
	//cout << "z " << z << endl;
	for (int i=0; i<B; i++)
		if (t%m[i] == 0) {
			if (z==1) return i+1;
			z--;
		}
		
	assert(false);
	return 0;
}

int main() {
	int T;
	cin >> T;
	for (int t=1; t<=T; t++)
		cout << "Case #" << t << ": " << solve() << endl;
	
	return 0;
}
