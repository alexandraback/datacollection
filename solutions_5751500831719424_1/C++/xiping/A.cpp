#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

bool trailing_space = true; // for output

struct Solver
{
   int N;
   vector<string> data;

   string rep;

   vector<vector<int> > counts; // the count for each segment

   void read_input()
   {
      cin >> N;
      data.resize(N);
      for(int i = 0; i < N; ++ i)
         cin >> data[i];
   }

   void get_rep_and_counts(const string & str, string & r, vector<int> & cs)
   {
      char prev = str[0];
      int count = 1;
      for(int i = 1; i < str.length(); ++ i)
      {
          if (str[i] != prev)
          {
             cs.push_back(count);
             r.push_back(prev);
             prev = str[i];
             count = 1;
          }
          else
          {
             ++ count;
          }
      }
      cs.push_back(count);
      r.push_back(prev);
   }

   void solve()
   {
      counts.resize(N);
      get_rep_and_counts(data[0], rep, counts[0]);
      for(int i = 1; i < N; ++ i)
      {
          string rep2;
          get_rep_and_counts(data[i], rep2, counts[i]);
          if (rep2 != rep)
          {
             cout << "Fegla Won";
             return;
          }
      }

      int n = 0;
      // now for each segment, figure out the minimal replacement
      // actually get the count of each number
      for(int i = 0; i < rep.length(); ++ i)
      {
         //int cs[101] = {};
         //memset(cs, 0, sizeof(cs));
         int max = 0;
         int sum = 0;
         for(int j = 0; j < N; ++ j)
         {
            //int k = ++ cs[counts[j][i]];
            if (counts[j][i] > max) max = counts[j][i];
            sum += counts[j][i];
         }
         //n += N - max;
         // the optimal value should be the average, but we will brute force calculate here
         int min_shift = sum;
         for(int k = 1; k <= max; ++ k)
         {
         int shift = 0;
         for(int j = 0; j < N; ++ j)
         {
            //int k = ++ cs[counts[j][i]];
            //if (counts[j][i] > max) max = counts[j][i];
            //sum += counts[j][i];
            if (counts[j][i] > k) shift += counts[j][i] - k;
            else shift -= counts[j][i] - k;
         }
            if (shift < min_shift) min_shift = shift;
         }
         n += min_shift;
      }
      cout << n;
   }

   void print_output()
   {
   }

   void execute()
   {
      read_input();
      solve();
      print_output();
   }
};


int main()
{
   long T = 0;
   cin >> T;
   for (long i = 0; i < T; ++ i)
   {
      cout << "Case #" << i + 1 << ':';
      if (trailing_space) cout << ' ';
      Solver s;
      s.execute();
      cout << '\n';
   }

   return 0;
}

