#include<bits/stdc++.h>

#define MIN(a, b) (((a) < (b))?(a):(b))
#define MAX(a, b) (((a) > (b))?(a):(b))

using namespace std;

const char INPUT[] = "HelloWorld.inp";
const char OUTPUT[] = "HelloWorld.out";

int tried(int idR, int idC, int idN, int r, int c, int n, int a[][20]){
  if (idN > n){
    return 1000000000;
  }

  //cout << idR << " " << idC << " ";

  if (idC > c){
    idC = 1; ++ idR;
    if (idR > r){
      if (idR == r + 1 && idC == 1 && idN == n){
        int temp = 0;
        for (int idR2 = 1; idR2 <= r; ++ idR2){
          for (int idC2 = 1; idC2 <= c; ++ idC2){
            if (a[idR2][idC2] == 1 && a[idR2 - 1][idC2] == 1){
              ++ temp;
            }
            if (a[idR2][idC2] == 1 && a[idR2][idC2 - 1] == 1){
              ++ temp;
            }
            //cout << a[idR2][idC2] << " ";
          }
          //cout << endl;
        }
        //cout << endl;
        return temp;
      } else {
        return 1000000000;
      }
    }
  }

  //cout << idR << " " << idC << endl;
  a[idR][idC] = 0;
  int result = tried (idR, idC + 1, idN, r, c, n, a);
  a[idR][idC] = 1;
  result = MIN(result , tried(idR, idC + 1, idN + 1, r, c, n, a));
  a[idR][idC] = 0;

  return result;
}



int main(void){
  freopen(INPUT, "r", stdin);
  freopen(OUTPUT, "w", stdout);

  int numTest;
  cin >> numTest;

  int a[20][20];

  for (int idTest = 0; idTest < numTest; ++ idTest){
    int result = 0;

    int r, c, n;
    cin >> r >> c >> n;

    for (int idR = 0; idR <= r + 1; ++ idR){
      for (int idC = 0; idC <= c + 1; ++ idC){
        a[idR][idC] = 0;
      }
    }

    result = tried (1, 1, 0, r, c, n, a);

    cout << "Case #" << idTest + 1 << ": " << result << endl;
  }

  return 0;
}
