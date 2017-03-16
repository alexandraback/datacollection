#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main()
  {
  long cases;
  
  std::ifstream fin(L"A-small-attempt4.in");
  std::ofstream fout(L"A-small-attempt4.out");
  std::istream& in = fin;
  std::ostream& out = fout;
  
  /*
  std::istream& in = std::cin;
  std::ostream& out = std::cout;
  */
  std::string al = "ABCDEFGHIJKLMNOPQRSTVUWXYZ";
  in >> cases;
  for (long i = 1; i <= cases; ++i)
    {
    int n;
    in >> n;
    std::vector<int> parties(n);
    int sum = 0;
    for (int j = 0; j < n; ++j)
      {
      in >> parties[j];
      sum += parties[j];
      }

    std::string result = "";

    for (int j = 0; j < sum - 2; ++j)
      {
      int max = -1, index = -1;
      
      for (int k = 0; k < n; ++k)
        if (parties[k] > max)
          {
          max = parties[k];
          index = k;
          }

      parties[index]--;
      result += al[index];
      if (j % 2 == 1 || j == sum - 3)
        result += " ";
      }

    int index_1 = -1, index_2 = -1;
    for (int k = 0; k < n; ++k)
      {
      if (parties[k] == 2)
        {
        index_1 = k;
        index_2 = k;
        }
      else
       {
       if (parties[k] == 1)
          {
          if (index_1 == -1)
            index_1 = k;
          else
            index_2 = k;
          }
        }
      }
    
    result += al[index_1];
    result += al[index_2];
    out << "Case #" << i << ": " << result << std::endl;
    }

  return 0;
  }