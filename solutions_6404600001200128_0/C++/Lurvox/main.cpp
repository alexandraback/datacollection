#include <fstream>
#include <iostream>
#include <string>
#include <queue>


using namespace std;

static int N;
static int m[1001];


int solve1() {

  int count = 0;
  for(int i=1; i<N;i++) {
    if(m[i]< m[i-1])
      count = count + m[i-1]-m[i];
  }
 
  return count;


}

int solve2() {

  priority_queue<int> q;

  for(int i=1; i<N;i++) {
    if(m[i]< m[i-1]){
      int diff = m[i-1]-m[i];
      q.push(diff);
    }
  }

  if(q.empty()){
    return 0;
  }

  int high_diff = q.top();

  int count = 0;
  for(int i=0; i<N-1;i++) {
    if(m[i]< high_diff){
      count+=m[i];
    } else{
      count+=high_diff;
    }
  }

  return count;



}


int main() {

  ifstream input ("A-small-attempt0.in");
  ofstream output ("output.txt");
  int T;
  string shy = "";
  input >> T;
  for (int i=1; i<=T; i++) {
    input  >> N;
    for(int j=0;j<N;j++) {
      input >> m[j];
    }
    output << "Case #" << i <<": " << solve1() << " " << solve2() << "\n";
  }

  input.close();
  output.close();

  return 0;
}
