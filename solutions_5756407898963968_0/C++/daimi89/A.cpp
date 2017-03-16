#include <iostream>

using namespace std;

main () {
  int T;

  cin >> T;
  for (int t=1; t<=T; t++) {
    int row1, row2, arr1[16], arr2[16], answer=0, n;

    cin >> row1;
    for (int i=0; i<16; i++) cin >> arr1[i];
    cin >> row2;
    for (int i=0; i<16; i++) cin >> arr2[i];

    for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
	if (arr1[row1*4+i-4]==arr2[row2*4+j-4]) 
	  answer++, n=arr1[row1*4+i-4];

    cout << "Case #" << t << ": ";
    if (answer==1) cout << n << endl;
    else 
      cout << (answer==0 ? "Volunteer cheated!" : "Bad magician!") << endl;
  };
};
