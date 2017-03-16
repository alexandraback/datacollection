#include<iostream>
#include<algorithm>
using namespace std;
const int maks = 200;
int t, n, l;
string s[maks];
string un[maks];
int unc[maks][maks];
int min_changes=0;

void makeu(int x) {
  un[x] = ""; int nr=0;unc[x][nr]=1;
  for (int i = 0; i < s[x].size(); ++i) {
	  if (i==0 || s[x].at(i) != s[x].at(i-1)) {
		  un[x]+=s[x].at(i);
                  if (i!=0) { nr++; unc[x][nr]=1; };
	  } else {
		  unc[x][nr]++;
	  };
  };
};

int main(){
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cin >> n;
    for (int j = 0; j < n; ++j) {
      cin >> s[j];
      makeu(j);
    };
    bool fegla = true;
    for (int j = 1; (j < n) && (fegla); ++j) {
	    if (un[j]!=un[j-1]) fegla=false;
    };
    cout << "Case #" << i << ": ";
    if (!fegla)
      cout << "Fegla Won\n";
    else {
      min_changes=0;
      /*
      for (int j = 0; j < n; ++j) {
	      cout << j << ": " <<  s[j] << " " << un[j] << " ";
	      for (int k = 0; k < un[j].size(); k++) cout << unc[j][k] << " ";
	      cout << endl;
      };*/
      //count min
      for (int j = 0; j < un[0].size(); ++j) { // j - letter
	  // cout << "=" << un[0].at(j) << " ";
	      int sum = 0, mks=0;
	      for (int k = 0; k < n; ++k) { // k - string
                 mks=max(mks, unc[k][j]);
	      };
	    //  cout << "mks=" << mks<<endl;
	      int best=-1;
	      for (int k = 1; k <= mks; k++) {
                      int cur=0;
		      for (int p = 0; p < n; p++){
                         cur+=abs(unc[p][j]-k);
		      };
		      if (best==-1 || cur<best) best=cur;
	//	      cout << "k=" << k << " cur=" <<cur<< endl;
	      };
	  //    cout << "best=" << best << endl;
              min_changes += best;
      };
      cout << min_changes << endl;
    };
  };
};
