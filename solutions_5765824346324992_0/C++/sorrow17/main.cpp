#include <fstream>
void solve(std::ifstream&,std::ofstream&);

int main(){
  std::ifstream fin("B.in");
  std::ofstream fout("B.out");
  solve(fin,fout);
  fin.close();
  fout.close();
  return 0;
}