#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
  string name = "A-small-attempt0";
  string path = "";

  freopen((path + name + ".in").c_str(), "r", stdin);
  freopen((path + name + ".out").c_str(), "w", stdout);

  int test_cases;
  cin >> test_cases;
  for (int test_case = 1; test_case <= test_cases; test_case++) {
    int number;
    cin >> number;
    
    vector<int> eat;
    for (int j = 0; j < number ; j++) {
      int a = 0;
      cin >> a;
      eat.push_back(a);
    }
    int max = 0;
    int sum = 0;
    for (int i = 1; i < number; i++) {
      if (eat[i - 1] > eat[i]) { 
        int minus = eat[i - 1] - eat[i];
        sum += minus; 
        max = max > minus ? max : minus;
      }
    }

    int sum2 = 0;
    for (int i = 0; i < number - 1; i++) {
      sum2 +=std::min(eat[i], max);
    }

    cout << "Case #" << test_case << ": " << sum <<" "<<sum2 <<endl;
    cout.flush();
  }
  fclose(stdout);
  fclose(stdin);
  return 0;
}