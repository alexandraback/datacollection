#include <iostream>
#include <string>

using namespace std;

int parties[26];

int main(){
  int T;
  cin >> T;
  for(int i = 0; i < T; i++){
    string ret;
    int members;
    int par;
    cin >> par;
    for (int j = 0; j < 26; j++){
      parties[j] = 0;
    }
    for(int j = 0; j < par; j++){
      int cur;
      cin >> cur;
      parties[j] = cur; 
      members += cur;
    }
    cout << "Case #" << i + 1 << ": " << ret;
    while(members > 0){
      if (members % 2 == 1){
        int max = 0;
        int num = 0;
        for(int a = 0; a < 26 ; a++){
          if(parties [a] > max ){
            max = parties[a];
            num = a;
          }
        }
        members--;
        parties[num]--;
        cout << " "  << char('A' + num);
      } else {
        int maxa = 0;
        int numa = 0;
        int maxb = 0;
        int numb = 0;
        for(int a = 0; a < 26 ; a++){
          if(parties [a] > maxa ){
            maxa = parties[a];
            numa = a;
          } else if (parties[a] > maxb){
            maxb = parties[a];
            numb = a;
          }

        }
        parties[numa] --;
        parties[numb] --;
        members -= 2;
        cout << " " << char('A' + numa)  << char('A' + numb);
      }
    }
    cout << endl;
  }
}

