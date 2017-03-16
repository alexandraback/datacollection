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
  for(uint16_t num=1; num<=T; num++) {
    std::cout << "Case #" << num << "\n";
    int64_t N, max=0, count=0, count2=0;
    input >> N;
    std::vector <int64_t> mushrooms(N);
    input >> mushrooms[0];
    for(int64_t i=1; i<N; i++) {
      input >> mushrooms[i];
      if(mushrooms[i]<mushrooms[i-1]) count+=mushrooms[i-1]-mushrooms[i];
      if(mushrooms[i-1]-mushrooms[i]>max) max=mushrooms[i-1]-mushrooms[i];
    }
    for(int64_t i=0; i<N-1; i++) {
      if(mushrooms[i]<max) {
        count2+=mushrooms[i];
      } else {
        count2+=max;
      }
    }
    output << "Case #" << num << ": ";
    output << count << ' ' << count2;
    output << '\n';
  }
}
