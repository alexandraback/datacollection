#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

class ProblemSolver {
public:
   ProblemSolver(istream& in, ostream& out) :
      in(in),
      out(out) { }

   void solve()
   {
      int T;
      in >> T;

      for (int t = 1; t <= T; t++) {
         solve_case(t);
      }
   }

private:
   void solve_case(int t);

   istream& in;
   ostream& out;
   vector<int> members;
};

void ProblemSolver::solve_case(int t)
{
   out << "Case #" << t << ":";
   int num_parties;
   in >> num_parties;
   members.clear();
   for (int i = 0; i < num_parties; i++) {
      int a;
      in >> a;
      members.push_back(a);
   }

   int sum;
   do {
      int majority = -1;
      for (int i = 0; i < num_parties; i++) {
         if (members[i] > majority) {
            majority = members[i];
         }
      }

      int num_active_parties = 0;
      for (int i = 0; i < num_parties; i++) {
         if (members[i] > 0) {
            num_active_parties++;
         }
      }

      int max_leaving = 2;
      if (num_active_parties > 2) {
         max_leaving = 1;
      }

      int max_two = 0;
      out << " ";
      for (int i = 0; i < num_parties; i++) {
         if (members[i] == majority) {
            max_two++;
            if (max_two <= max_leaving) {
               out << char('A' + i);
               members[i] -= 1;
            }
         }
      }

      sum = 0;
      for (auto mem : members) {
         sum += mem;
      }
   }
   while (sum > 0);

   out << endl;
}


int main()
{
//   istream& in = cin;
   ifstream in;
   in.open("../instances/A-small-attempt1.in");
//   in.open("../instances/A-small.in");
//   in.open("../instances/A-large.in");

//   ostream& out = cout;
   ofstream out;
   out.open("../instances/A-small.out");
//   out.open("../instances/A-large.out");

   if (not in) {
      cout << "could not open file!" << endl;
      return 1;
   }

   ProblemSolver solver{in, out};
   solver.solve();

   return 0;
}

