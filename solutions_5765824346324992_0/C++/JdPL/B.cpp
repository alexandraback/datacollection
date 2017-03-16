#include <iostream>
#include <fstream>
#include <vector>

template <class T>
T gcd(T a,T b) {return (a==0) ? b : gcd(b%a,a);}

template <class T>
T lcm(T a,T b) {return (a*b)/gcd(a,b);}

int main() {
  std::ifstream input;
  std::ofstream output;
  int64_t T;
  input.open("input.in");
  output.open("output.out");
  input >> T;
  for(uint16_t count=1; count<=T; count++) {
    std::cout << "Case #" << count << "\n";
    int64_t B, N, newStart=1, mod=0, barber=1, time=0;
    input >> B >> N;
    std::vector <int64_t> barberTime(B);
    for(int64_t i=0; i<B; i++) { 
      input >> barberTime[i];
      newStart=lcm(newStart, barberTime[i]);
    }
    for(int64_t i=0; i<B; i++) { 
      mod+=newStart/barberTime[i];
    }
    std::vector <int64_t> barberNext(B);
    N%=mod;
    if(N==0) N+=mod;
    while(N) {
      for(int64_t i=0; i<B; i++) { 
        if(barberNext[i]==time) {
          barberNext[i]+=barberTime[i];
          N--;
        }
        if(N==0) {
          barber=i+1;
          break;
        }
      }
      time++;
    }
    
    
    output << "Case #" << count << ": ";
    output << barber;
    output << '\n';
  }
}
