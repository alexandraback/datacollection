#include <fstream>
#include <iostream>
#include <string>
#include <queue>
#include <vector>


using namespace std;

static long long B,N;

struct tuple {
  long long num;
  long long time;
};

tuple raiseTime (tuple a, long long t){
  tuple aux = a;
  aux.time+=t;
  return aux;
}



struct mycomp {
  bool operator()(const tuple& a, const tuple&b) {
    if(a.time<b.time) {
      return false;
    } else if(a.time>b.time) {
      return true;
    } else{
      return a.num > b.num;
    }

  }

};

long long gcd(long long a,long long b){
  if(b==0)
    return a;
  else
    return gcd(b,a%b);
}

long long lcm(long long a, long long b){
  return a*(b/gcd(a,b));
}

long long lcm(long long* array,long long length) {
  
  long long tmp = array[0];

  for(long long i=1; i<length;i++){
    tmp = lcm(tmp, array[i]);
  }
  return tmp;

}

int main() {

  ifstream input ("B-small-attempt3.in");
  //ifstream input ("test.txt");
  ofstream output ("output.txt");
  int T;
  input >> T;
  for (int i=1; i<=T; i++) {
    input >> B >> N;
    long long barber[1002];
    tuple barb[1002];
    for(long long j=0;j<B;j++) {
      long long c;
      input >> c;
      barber[j] = c;
      barb[j].num = j;
      barb[j].time = c;
    }

    //solve
    int res=0;

    long long least_cm = lcm(barber,B);
    cout << least_cm << endl;

    long long total_custs = 0;
    for(int j=0;j<B;j++){
      total_custs+=(least_cm/barber[j]);
    }

    N = ((N-1)%(total_custs));
    priority_queue<tuple,vector<tuple>,mycomp>q(barb,barb+B);
    int cust = N-B;
    int k=0;

    if(N<B){
      res = N+1;
      goto done;
    }
    
    while(k<=cust){
      tuple a = q.top();
      q.pop();
      tuple aux = raiseTime(a,barber[a.num]);
      q.push(aux);
      res=aux.num+1;
      k++;
    }
    

    

    


  done:
    output << "Case #" << i <<": " << res << "\n";
  }

  input.close();
  output.close();

  return 0;
}
