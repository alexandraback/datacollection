#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <tuple>
#include <functional>
#include <sstream>
#include <cassert>


using namespace std;
class TestCase
{
public:
   string eval(istream& is)
   {
      set<int> pos;
      set<int> pos2;
      int a;
      is >> a;
      for (int i = 0; i < 4 ; i++)
      {
      	for (int j = 0; j < 4 ; j++)
      	{
            int n;
            is >> n;
            if (i + 1 == a) pos.insert(n);
      	}
      }
      is >> a;
      for (int i = 0; i < 4; i++)
      {
         for (int j = 0; j < 4; j++)
         {
            int n;
            is >> n;
            if (i + 1 == a) {
               if (pos.find(n) != pos.end()) {
                  pos2.insert(n);
               }
            }
         }
      }
      if (pos2.size() == 1)
      {
         std::stringstream ss; ss << *pos2.begin(); return ss.str();
      }
      if (pos2.size() == 0) {
         return "Volunteer cheated!";
      }
      return "Bad magician!";
   }
};

int main(int argc, char* argv[])
{
   ifstream infile(argv[1]);
   int T;
   infile >> T;
   ofstream out("A.out");
   //ostream& out = std::cout;
   for (int tc = 0; tc < T; ++tc)
   {
      TestCase testcase;
      out << "Case #" << tc + 1 << ": " << testcase.eval(infile) << '\n';
   }
   return 0;
}

