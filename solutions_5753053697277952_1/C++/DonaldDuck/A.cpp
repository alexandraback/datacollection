// Problem A

#include <iostream>
#include <string.h>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <math.h>
#include <fstream>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;

void TestCase(int t) {
	int P;
	int S[26];
	cin >> P;
	for (int i=0; i<P; i++) cin >> S[i];
	
	int num = 0;
	for (int i=0; i<P; i++) num+=S[i];
	
	cout << "Case #" << t << ": ";
	
	while (num > 0) {
		// Guardo se c'è il partito più numeroso di tutti, o ce ne sono due a pari merito
		int mag1 = 0;
		int mag2 = -1;
		
		for (int i=1; i<P; i++) {
			if (S[i] > S[mag1]) {
				mag1 = i;
				mag2 = -1;			
			}
			else if (S[i] == S[mag1])
				mag2 = i;
		}
		
		// A seconda dei casi decido chi fare uscire
		if (mag2 == -1) {
			cout << char('A'+mag1) << " ";
			S[mag1]--;
			num--;
		}
		else if (num != 3) {
			cout << char('A'+mag1) << char('A'+mag2) << " ";
			S[mag1]--;
			S[mag2]--;
			num = num-2;
		}
		else {
			cout << char('A'+mag1) << " ";
			S[mag1]--;
			num--;
		}
	}
	cout << endl;
}

int main() {
	int T;
	cin >> T;
	for (int t=1; t<=T; t++)
		TestCase(t);
	
	return 0;
}
