#include<iostream>
#include<fstream>

using namespace std;

int N;
int firstCards[4][4];
int firstAnswer;
int secondCards[4][4];
int secondAnswer;

ofstream myfile;

void input() {
  cin >> firstAnswer;
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      int tmp;
      cin >> tmp;
      firstCards[i][j] = tmp;
    }
  }
  cin >> secondAnswer;
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      int tmp;
      cin >> tmp;
      secondCards[i][j] = tmp;
    }
  }
}

void process(int n) {
  int answer;
  int count = 0;

  for(int i = 0; i < 4; i++) {
    int tmp = secondCards[secondAnswer - 1][i];
    for(int j = 0; j < 4; j++) {
      if(tmp == firstCards[firstAnswer - 1][j]) {
        answer = tmp;
        count += 1;
      } 
    }
  }

  if(count == 0) {
    myfile << "Case #" << n << ": " << "Volunteer cheated!" << endl;
    cout << "Case #" << n << ": " << "Volunteer cheated!" << endl;
  } else if(count == 1) {
    myfile << "Case #" << n << ": " << answer << endl;
    cout << "Case #" << n << ": " << answer << endl;
  } else {
    cout << "Case #" << n << ": " << "Bad magician!" << endl;
    myfile << "Case #" << n << ": " << "Bad magician!" << endl;
  }
}

int main() {
  cin >> N;
  myfile.open("a.output");
  for(int i = 0; i < N; i++) {
    input();
    process(i + 1);
  }
  myfile.close();
}
