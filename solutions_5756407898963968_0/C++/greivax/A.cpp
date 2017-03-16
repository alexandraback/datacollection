#include <algorithm>
#include <iostream>
using namespace std;

int data1[4][4], data2[4][4];

int main(){
  int T;
  cin >> T;
  for(int i = 1; i <= T; ++i){
    int r1, r2;
    cin >> r1;
    --r1;
    for(int x = 0; x < 4; ++x)
      for(int y = 0; y < 4; ++y)
        cin >> data1[x][y];
    cin >> r2;
    --r2;
    for(int x = 0; x < 4; ++x)
      for(int y = 0; y < 4; ++y)
        cin >> data2[x][y];
    sort(&data1[r1][0], &data1[r1][0] + 4);
    sort(&data2[r2][0], &data2[r2][0] + 4);
    int i1 = 0, i2 = 0, r = 0, k = -1;
    while(i1 < 4 and i2 < 4){
      if(data1[r1][i1] < data2[r2][i2])
        ++i1;
      else if(data1[r1][i1] > data2[r2][i2])
        ++i2;
      else {
        k = data1[r1][i1];
        ++i1;
	++i2;
	++r;
      }
    }
    cout << "Case #"<<i<<": ";
    if(r == 0)
      cout << "Volunteer cheated!";
    else if(r == 1)
      cout << k;
    else
      cout << "Bad magician!";
    cout << endl;
  }
}
