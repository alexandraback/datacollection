#include <iostream>
#include <random>
#include <time.h>
#include <limits>
#include <vector>
#include <sstream>
using namespace std;


class Instance{
public:
  void read();
  void write();

  void compute();
private:
 int _n;
 vector< vector<int> > _inst;
 vector<int> method1;
 vector<int> method2;
};


void Instance::read()
{
  cin >> _n;

  for (int i = 0; i < _n; ++i) {
    int s_max;
    cin >> s_max;

    vector<int> inst;
    _inst.push_back(inst);
    for (int j = 0; j < s_max; ++j) {
      int number;
      cin >> number;
      _inst[i].push_back(number);
    }
  }
}


void Instance::write()
{
   for (int i = 0; i < _inst.size(); ++i) {
     cout << "Case #" << i+1 << ": " << method1[i] << " " << method2[i] << endl;
   }

}




void Instance::compute()
{
  for (int i = 0; i < _inst.size(); ++i) {
    method1.push_back(0);
    method2.push_back(0);
    int max_diff = 0;

    int old = _inst[i][0];
    for (int j = 1; j < _inst[i].size(); ++j){
      int n = _inst[i][j];
      if (n < old) {
        method1[i] += old - n;
      }
      if (old - n  > max_diff) {
        max_diff = old-n;
      }
      old = n;
    }
    old =  _inst[i][0];
    for (int j = 1; j < _inst[i].size(); ++j){
      int n = _inst[i][j];
      int a = max_diff;
      if (a > old) {
        a = old;
      }
      method2[i] += a;

      old = n;
    }

  }

}


int main(int argc, char** argv){
  Instance I;
  I.read();
  I.compute();
  I.write();
}
