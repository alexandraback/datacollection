#include <bits/stdc++.h>
#define MAX 33
using namespace std;

int t,n;
int d[MAX];

int main(){

  cin >> t;
  for(int c = 1; c<=t; c++){
    memset(d, 0, sizeof d);
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++){
      cin >> d[i];
      sum += d[i];
    }

    vector<string> ans;
    while(sum){
      string cur = "";

      // get first max
      int fmax = 0, ifmax;
      for(int i = 0; i < n; i++){
	if(d[i] > fmax){
	  fmax = d[i];
	  ifmax = i;
	}
      }
      d[ifmax]--;
      sum--;
      cur += 'A'+ifmax;

      // get second max if condition continue to holds
      int smax = 0, ismax=-1;
      for(int i = 0; i < n; i++){
	if(d[i] > smax){
	  smax = d[i];
	  ismax = i;
	}
      }

      if(ismax!=-1 && d[smax]-1 <= sum/2 && sum != 2){
	d[ismax]--;
	sum--;
	cur += 'A'+ismax;
      }
      //      cout << "pushing " << cur << endl;
      ans.push_back(cur);
    }

    cout << "Case #" << c << ": ";
    for(int i = 0; i < (int)ans.size(); i++){
      cout << ans[i] << " \n"[i == (int)ans.size()-1];
    }
  }

  return 0;
}
