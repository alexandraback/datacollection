#include <iostream>
#include <vector>
using namespace std;

class Tree{
public:
  int id, x, y;
  int n;
  Tree(int a, int b, int c){
    id=a; x=b; y=c; n=10000;
  }
};

int min(int a, int b){
  return a<b ? a : b;
}
int min3(int a, int b, int c){
  return min(a,min(b,c));
}

vector<Tree> ts;

int main(){
  int T;
  cin >> T; cin.ignore();
  for(int i=0; i<T; i++){
    ts.clear();
    int N;
    cin >> N; cin.ignore();
    for(int j=0; j<N; j++){
      int X,Y;
      cin >> X >> Y; cin.ignore();
      ts.push_back(Tree(j,X,Y));
    }

    for(int j=0; j<N; j++){
      for(int k=0; k<N; k++){
        if(k==j) continue;
        int countu, countc, countd;
        countu = countc = countd = 0;
        long long dx1 = ts[k].x - ts[j].x;
        long long dy1 = ts[k].y - ts[j].y;
        for(int l=0; l<N; l++){
          if(l==k || l==j) continue;
          long long dx2 = ts[l].x - ts[j].x;
          long long dy2 = ts[l].y - ts[j].y;
          if(dy1*dx2 == dy2*dx1){
            countc++;
          } else if((double)dy1*(double)dx2/(double)dx1 > (double)dy2){
            countu++;
          } else {
            countd++;
          }
        }
        ts[j].n = min3(countu, countd, ts[j].n);
      }
    }
    cout << "Case #" << i+1 << ":" << endl;
    for(int j=0; j<N; j++){
      cout << ts[j].n << endl;
      }
  }

  return 0;
}
