#define MAX_N 26
#include <iostream>
//#include <map>
#include <vector>

void solve_case(int case_num)
{
  std::vector<int> v;
  //std::map<int, int> m;
  int n;
  int p[MAX_N];

  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> p[i];
    //m[p[i]]++;
  }

  //int sz = n;
  while (true) {
    bool found = false;
    for (int i = 0; i < n; i++) {
      if (p[i] != 0) {
	found = true;
	break;
      }
    }
    if (!found) {
      break;
    }
    
    int mx = 0;
    int idx = -1;
    for (int i = 0; i < n; i++) {
      if (p[i] > mx) {
	mx = p[i];
	idx = i;
      }
    }
    p[idx]--;
    v.push_back(idx);
    //sz--;
  }

  std::cout << "Case #" << case_num << ":";
  if (v.size() & 1) {
    std::cout << " " << (char) ('A' + v[0]);
  }
  for (size_t i = v.size() & 1; i < v.size(); i += 2) {
    std::cout << " " << (char) ('A' + v[i]) << (char) ('A' + v[i + 1]);
  }
 
  std::cout << std::endl;
}

int main()
{
  int num_cases;

  std::cin >> num_cases;
  for (int i = 1; i <= num_cases; i++) {
    solve_case(i);
  }
  
  return 0;
}
