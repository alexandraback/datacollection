#include<set>
#include<iostream>
using namespace std;
int main(){
  int T, a, b, card, ans;
  set<int> cards;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    cards.clear();
    ans = -1;
    //1st round
    cin >> a;
    for (int r = 1; r <= 4; ++r)
      for (int c = 1; c <= 4; ++c) {
	cin >> card;
        if (r == a) cards.insert(card);
      };
    //2nd round
    cin >> b;
    for (int r = 1; r <= 4; ++r)
      for (int c = 1; c <= 4; ++c) {
	cin >> card;
        if (r == b) {
	  if (cards.find(card) != cards.end()){
	    if (ans == -1) ans = card;
	    else ans = -2;
	  };
	};
      };
    // ans
    cout << "Case #" << i << ": ";
    switch (ans) {
      case (-2): cout << "Bad magician!"; break;
      case (-1): cout << "Volunteer cheated!"; break;
      default: cout << ans;
    };
    cout << endl;
  };
};
