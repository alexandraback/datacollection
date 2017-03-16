#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int main() {
  int data_size = 0;
  in >> data_size;
  for (int i = 0; i < data_size; ++i) {
    int n;
    in >> n;
    vector<int> senators(n);
    int stayed = 0;
    for (int j = 0; j < n; ++j) {
      in >> senators[j];
      stayed += senators[j];
    }
    out << "Case #" << i + 1 << ": ";
    while (stayed > 0) {
      int max1 = 0;
      int max2 = 1;
      for (int j = 1; j < n; ++j) {
        if (senators[j] > senators[max1]) {
          if (j == max2) {
            max2 = max1;
          }
          max1 = j;
        } else if (senators[j] <= senators[max1] && senators[j] > senators[max2]) {
          max2 = j;
        }
      }
      if (senators[max1] > senators[max2] || stayed == 3) {
        out << static_cast<char>('A' + max1) << ' ';
        --stayed;
        --senators[max1];
      } else {
        out << static_cast<char>('A' + max1) << static_cast<char>('A' + max2) << ' ';
        stayed -= 2;
        --senators[max1];
        --senators[max2];
      }
    }
    out << "\n";
  }
  return 0;
}
