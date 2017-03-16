#include <iostream>
using namespace std;

int sum(int P[],int N){
    int s=0;
    for(int i = 0; i<N;i++){
        s+=P[i];
    }
    return s;
}

char charint(int i){
    return char(i+65);
}

void printmax(int people[],int N){
    int k=0;
    for(int i = 0; i<N;i++){
        if(people[k]<people[i]){
            k=i;
        }
    }

    people[k]--;
    cout << charint(k);
}

void court(int N){
    int * people;
    people=new int[N];
    for(int i = 0; i <N ; i++){
        cin >> people[i];
    }
    int s = sum(people,N);
    if(s%2==1){
        printmax(people,N);
        s--;
        cout << " ";
    };
    while(s>0){
        printmax(people,N);
        s--;
        printmax(people,N);
        s--;
        cout << " ";
    }
}

int main() {
  int t,N;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cin >> N;
    cout << "Case #" << i << ": ";
    court(N);
    cout << endl;
  }
}
