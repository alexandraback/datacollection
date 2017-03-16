#include <iostream>

using namespace std;

int main(){
  int count[16];
  int card[4][4];
  int t,i,j,k,m,n;
  i=0;
  cin>>t;
  while(t--){
    if (i>0) cout << endl;
    cout << "Case #" << ++i << ": ";
    for (m=0; m<16; m++){
      count[m]=0;
    }
    cin>>j;
    j--;
    for (m=0; m<4; m++){
      for (n=0; n<4; n++){
        cin>>card[m][n];
      }
    }
    for (n=0; n<4; n++) count[card[j][n]-1]++; 
    cin>>j;
    j--;
    for (m=0; m<4; m++){
      for (n=0; n<4; n++){
        cin>>card[m][n];
      }
    }
    for (n=0; n<4; n++) count[card[j][n]-1]++; 
    m=0;
    for (n=0; n<16; n++){
      if (count[n]==2){
        j=n;
        m++;
      }
    }
    if (m==1) cout << j+1;
    if (m>1) cout << "Bad magician!";
    if (m==0) cout << "Volunteer cheated!";
  }
  return 0;
}
