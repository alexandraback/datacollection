#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cstdint>
using std::cout;
using std::cin;
using std::endl;
typedef int64_t Int;

int main()
{
  Int ncases;
  cin >> ncases;
  for(Int case_ = 1; case_ <= ncases; case_++)
  {
    Int n;
    cin >> n;
  
    std::vector<Int> out;
    std::vector<Int> in(n, 0);
   
    for(Int i = 0; i < n; i++)
    {
      Int a;
      cin >> a;
      out.push_back(a);
    };

  
    std::vector<std::string> moves;  
    Int in_sum = 0;

    while(std::accumulate(out.begin(), out.end(), 0) > 0)
    {
      for(Int first = 0; first < n; first++)
      {
        if(out[first] > 0)
        {
          if(2 * (in[first] + 1) <= (in_sum + 1))
          {
            out[first]--;
            in[first]++;
            in_sum++;
            moves.push_back(std::string(1, 'A' + first));
            break;
          }
          else
          {
            bool found = false;
            for(Int second = 0; second < n; second++)
            {
              if(
                first != second &&
                out[second] > 0 &&
                2 * (in[first] + 1) <= (in_sum + 2) &&
                2 * (in[second] + 1) <= (in_sum + 2))
              {
                out[first]--;
                out[second]--;
                in[first]++;
                in[second]++;
                in_sum += 2;
                std::string move;
                move += 'A' + first;
                move += 'A' + second;
                moves.push_back(move);
                found = true;
                break;
              }
            }

            if(found) break;
          }
        }
      }
      //for(Int i = 0; i < n; i++) cout << in[i] << " ";
      //cout << endl;
    }

    cout << "Case #" << case_ << ":";
    std::reverse(moves.begin(), moves.end());
    for(auto& e : moves) cout << " " << e;
    cout << endl;
  }

  return 0;
}
