/*
Google Codejam
Lehmniscate
Michael Hooton
mchlhtn@gmail.com
2014
*/


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main() {
   string line = "asdf";
   ifstream input ("C:/Users/Michael/Downloads/A-small-attempt0.in");
   if(input.is_open())
      getline(input, line);

   stringstream ss(line);
   int MaxCases;
   ss >> MaxCases;
   ofstream output ("C:/Users/Michael/Downloads/A-small-attempt0.out", ios::trunc);
   for(int i = 0; i < MaxCases; i++)
   {
      //first
      getline(input, line);
      stringstream a(line);
      int row_a;
      a >> row_a;
      string row;
      for(int j = 0; j < 4; j++) {
         getline(input, line);
         if(row_a == j+1)
            row = line;
      }
      stringstream in(row);
      int cards[4];
      in >> cards[0] >> cards[1] >> cards[2] >> cards[3];

      //second
      getline(input, line);
      int row_b;
      stringstream b(line);
      b >> row_b;
      for(int j = 0; j < 4; j++) {
         getline(input, line);
         if(row_b == j+1)
            row = line;
      }
      stringstream in2(row);
      int cardsb[4];
      in2 >> cardsb[0] >> cardsb[1] >> cardsb[2] >> cardsb[3];

      int check = -1;
      for(int j = 0; j < 4; j++) {
         for(int k = 0; k < 4; k++) {
            if(cards[j] == cardsb[k])
               if(check < 0)
                  check = j;
               else
                  check = 4;
         }
      }
      if(check < 0)
         output << "Case #" << (i+1) << ": " << "Volunteer Cheated!" << endl;
      else if(check > 3)
         output << "Case #" << (i+1) << ": " << "Bad Magician!" << endl;
      else
         output << "Case #" << (i+1) << ": " << cards[check] << endl;
   }
      input.close();
      output.close();
   return 0;
}