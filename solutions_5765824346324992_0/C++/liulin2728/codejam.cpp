#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <map>
#include <set>

using namespace std;

int gcd(int a, int b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int lcm(int a, int b)
{
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

int main(int argc, char *argv[])
{
  string name = "B-small-attempt0";
  string path = "";

  freopen((path + name + ".in").c_str(), "r", stdin);
  freopen((path + name + ".out").c_str(), "w", stdout);

  int test_cases;
  cin >> test_cases;
  for (int test_case = 1; test_case <= test_cases; test_case++) {
    int number;
    cin >> number;
    int site;
    cin >>site;
    
    vector<int> haircut;
    for (int j = 0; j < number ; j++) {
      int a = 0;
      cin >> a;
      haircut.push_back(a);
    }
    int result = std::accumulate(haircut.begin(), haircut.end(), 1, lcm);
    int sum = 0;
    for (int i = 0; i < number; i++) {
      sum += result/haircut[i];
    }
    site = site%sum;
    
    vector<set<int> > time(result);

    for (int i = 0; i < number; i++) {
      int j = 0;
      int count = haircut[i];
      while (j<result) {
        time[j].insert(i);
        j += count;
      }
    }

    int answer = 0;
    bool ifYes = false;
    if (site == 0) site = sum;
    for (int i = 0; i < result; i++) {
      for( auto setbegin = time[i].begin(); setbegin != time[i].end(); setbegin++) {
        if (site == 1) {
          answer = *setbegin;
          ifYes = true;
          break;
        }
        else {
          site--;
        }
      } 
      if (ifYes) break;
    } 
    


    cout << "Case #" << test_case << ": " << answer+1<<endl;
    cout.flush();
  }
  fclose(stdout);
  fclose(stdin);
  return 0;
}