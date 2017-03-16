#include <iostream>
#include <vector>

using namespace std;

int brute(int r,int c,int req) {
  //int max = 0;
  int k = r*c;
  int n = 1 << k;
  vector<vector<bool>> apt;
  apt.resize(r+1);
  for (int i = 0;i <= r;i++)apt[i].resize(c+1);
  int min_noise = r*c*2;

  for (int i = 0;i < n;i++) {
    int tenant = 0;
    for (int j = 0;j < k;j++) {
      int bit = 1 << j;
      int y = j/c;
      int x = j%c;
      apt[y][x] = ((i & bit) == bit);
      if ((i & bit) == bit) tenant++;
    }
    int noise = 0;
    if (tenant == req) {
      noise = 0;
//      printf("value = %d\n",i);
//      for (int i = 0;i < r;i++) {
//        for (int j = 0;j < c;j++) {
//          printf("%d",apt[i][j] == 0 ? 0 : 1);
//        }
//        printf("\n");
//      }
      for (int y = 0;y < r;y++) {
        for (int x = 0;x < c;x++) {
          if (apt[y][x] && apt[y+1][x]) noise++;
          if (apt[y][x] && apt[y][x+1]) noise++;
        }
      }
//      printf("noise = %d\n",noise);
      min_noise = std::min(min_noise,noise);
    }

//    printf("value = %d\n",i);
//    for (int i = 0;i < r;i++) {
//      for (int j = 0;j < c;j++) {
//        printf("%d",apt[i][j] == 0 ? 0 : 1);
//      }
//      printf("\n");
//    }
  }
  return min_noise;

}

int main() {
  int T;
  cin >> T;
  for (int i = 1;i <= T;i++) {
    int r,c,n;
    cin >> r >> c >> n;
    int ans =brute(r,c,n);
    printf("Case #%d: %d\n",i,ans);
  }

}
