#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

string S[100];
int p[100], n[100], c[100];

int main () {
  int T;
  cin >> T;
  for (int t=1; t<=T; t++) {
    int N, total=0;
    cin >> N;
    for (int i=0; i<N; i++) {
      cin >> S[i];
      n[i]=S[i].length();
      total += n[i];
      p[i]=0;
    };

    bool fail = false;
    int total_cost = 0;
    while (!fail && total>0) {
      for (int i=0; i<N; i++)
	if (p[i]==n[i]) fail=true; // one string empty
      if (!fail) { // all strings at least one symbol left
	char ch=S[0][p[0]];
	for (int i=0; i<N; i++) {
	  c[i]=0;
	  while (p[i]<n[i] && S[i][p[i]]==ch) c[i]++, p[i]++, total--;
	  if (c[i]==0) fail=true;
	};
	if (!fail) {
	  int best_k_cost = N*10000;
	  for (int k=1; k<=100; k++) {
	    int cost_k = 0;
	    for (int i=0; i<N; i++)
	      cost_k += abs(c[i]-k);
	    best_k_cost = min(best_k_cost,cost_k);
	  };
	  total_cost += best_k_cost;
	};
      }
    };
    cout << "Case #" << t << ": ";
    if (fail) 
      cout << "Fegla Won" << endl;
    else 
      cout << total_cost << endl;
  };    

  return 0;
};
