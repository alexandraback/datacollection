#include <vector>
#include <iostream>


int gcd ( int a, int b ){
  int c;
  while ( a != 0 ){
    c = a; a = b%a;  b = c;
  }
  return b;
}

int lcm(int a, int b){
    int temp = gcd(a, b);
    return temp ? (a / temp * b) : 0;
}



int solve(std::vector<int> M, int n, int b){

  if(b == 1) return 1;

  int gcd_accum = gcd(M[0], M[1]);
  int lcm_accum = lcm(M[0], M[1]);

  for(int i = 2; i<b; i++){
    gcd_accum = gcd(gcd_accum, M[i]);
    lcm_accum = lcm(lcm_accum, M[i]);
  }

  for(int i = 0; i<b; i++){
    M[i] /= gcd_accum;
  }

  int gran_vuelta = 0;

  for(int i = 0; i<b; i++){
    gran_vuelta += lcm_accum/M[i];
  }

  while(n-gran_vuelta > 0){
    n -= gran_vuelta;
  }


  if(n <= b) return n;

  int resultado = 0;

  std::vector<int> M_ = M;
  if(n>b){
    n-=b;
    while(n>0){
      for(int j = 0; j<b; j++){
        M_[j]--;

        //std::cout << i << " " << j << " " << ni << std::endl; 
        if(M_[j] == 0){
          n--;
          if(n == 0){
            return j+1; // indexo desde j
          } else{
            M_[j] = M[j];
          }
        }
      }
    }  
  } else return n;



}


int main(){
  int casos = 0;
  std::cin >> casos;
  for(int i = 0; i<casos; i++){
    int b, n;
    std::cin >> b >> n;

    int resultado = 0;
    std::vector<int> M;

    for(int j = 0; j<b; j++){
       int _t;
       std::cin >> _t;
       M.push_back(_t);
    }
 

      


    std::cout << "Case #" << i+1 << ": " << 
      solve(M, n, b) << std::endl;
  }

}



