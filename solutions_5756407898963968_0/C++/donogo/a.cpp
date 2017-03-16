#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

set <int> inter( set <int> A, set <int> B) {
  set <int> X;
  set <int>::iterator p;
  set <int>::iterator q;

  //  cout << "A";
  //  for (p = A.begin(); p!= A.end(); p++) {
  //    cout << *p << " ";
  //  }
  //  cout << endl;
  //  cout << "B";
  //  for (p = B.begin(); p!= B.end(); p++) {
  //    cout << *p << " ";
  //  }
  //  cout << endl;
  

  for (p = A.begin(); p != A.end(); p++) {
    q = B.find(*p);
    if (q != B.end()) {
      X.insert(*p);
    }
  }
  return X;
}


int main(void) {
  int T, t;
  vector <set <int> > S1, S2, S0;
  set <int> S;
  int r1, r2;
  int i, j, x;
  set <int> INTER;

  cin >> T;

  for (t = 1; t <= T; t++) {
    cin >> r1;
    S1 = S0;
    for (i = 0; i < 4; i++) {
      S1.push_back(S);
      for (j = 0; j < 4; j++) {
	cin >> x;
	S1[i].insert(x);
      }

    }

    cin >> r2;
    S2 = S0;
    for (i = 0; i < 4; i++) {
      S2.push_back(S);
      for (j = 0; j < 4; j++) {
	cin >> x;
	S2[i].insert(x);
      }
    }

    INTER = inter(S1[r1-1], S2[r2-1]);

    set <int> :: iterator p;

    //    for (p = INTER.begin(); p != INTER.end(); p++) {
    //      cout << *p << ",";
    //    }
    //    cout << endl;

    cout << "Case #" << t << ": ";

    switch (INTER.size()) {
    case 0:
      cout << "Volunteer cheated!" << endl;
      break;
    case 1:
      cout << *(INTER.begin()) << endl;
      break;
    default:
      cout << "Bad magician!" << endl;
      break;
    }

  }


  return 0;
}
