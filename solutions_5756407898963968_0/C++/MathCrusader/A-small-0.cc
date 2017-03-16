#include <iostream>
using namespace std;

int main(){
  int table_a[5][5];
  int table_b[5][5];
  
  int T;
  cin >> T;
  for(int cases =1; cases <=T; cases++){
    bool is_my_card[17];
    for(int i=1;i<=16;i++){
      is_my_card[i] = true;
    }
    
    int a;
    cin >> a;
    for(int i=1;i<=4;i++){
      for(int j=1;j<=4;j++){
        cin >> table_a[i][j];
      }
    }
    
    int b;
    cin >> b;
    for(int i=1;i<=4;i++){
      for(int j=1;j<=4;j++){
        cin >> table_b[i][j];
      }
    }
    
    for(int i=1;i<=4;i++){
      for(int j=1;j<=4;j++){
        if(i != a){
          is_my_card[ table_a[i][j] ] = false;
        }
      }
    }
    
    for(int i=1;i<=4;i++){
      for(int j=1;j<=4;j++){
        if(i != b){
          is_my_card[ table_b[i][j] ] = false;
        }
      }
    }
    
    int ctr = 0;
    for(int i=1;i<=16;i++){
      if(is_my_card[i]){
        ctr++;
      }
    }
    
    cout << "Case #" << cases << ": ";
    if(ctr >= 2){
      cout << "Bad magician!" << endl;
    } else if(ctr == 0){
      cout << "Volunteer cheated!" << endl;
    } else if(ctr == 1){
      for(int i=1;i<=16;i++){
        if(is_my_card[i]){
          cout << i << endl;
        }
      }
    }
  }
  return 0;
}
