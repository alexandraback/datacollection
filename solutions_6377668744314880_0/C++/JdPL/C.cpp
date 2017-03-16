#include <iostream>
#include <fstream>
#include <vector>


int main() {
  std::ifstream input;
  std::ofstream output;
  uint64_t T;
  input.open("input.in");
  output.open("output.out");
  input >> T;
  for(uint16_t count=1; count<=T; count++) {
    std::cout << "Case #" << count << "\n";
    int64_t N, left, right, min, a, b, c;
    input >> N;
    std::vector <int64_t> X(N);
    std::vector <int64_t> Y(N);
    std::vector <int64_t> S(N);
    for(int64_t i=0; i<N; i++) { 
      input >> X[i] >> Y[i];
    }
    for(int64_t i=0; i<N; i++) { 
      min=N;
      for(int64_t j=0; j<N; j++) { 
        if(i!=j) {
          a=Y[i]-Y[j];
          b=X[j]-X[i];
          c=X[i]*Y[j]-X[j]*Y[i];
          left=0;
          right=0;
          for(int64_t k=0; k<N; k++) { 
            if(i!=k && j!=k) {
              if((a*X[k])+(b*Y[k])+c>0) right++;
              if((a*X[k])+(b*Y[k])+c<0) left++;
            }
          }
          if(min>left) min=left;
          if(min>right) min=right;
        }
      }
      S[i]=min;
    }
    if(N==1) S[0]=0;
    
    output << "Case #" << count << ":\n";
    for(int64_t j=0; j<N; j++) { 
      output << S[j] << '\n';
    }
  }
}
