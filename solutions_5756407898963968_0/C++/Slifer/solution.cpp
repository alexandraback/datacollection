#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//*************************
//****  Magic_Trick ****
//************************* 

class MagicTrick
{
public:
       MagicTrick() {}
       void examine();
       void set(int i,int j,int numb) { board[i][j] = numb; }
       void set2(int i,int j,int numb) { board2[i][j] = numb; }
       void volunteersChoice(int r1,int r2) { i1=r1-1; i2=r2-1; }
       void printMessage(int ,ostream & = std::cout) const;
private:
        enum Status{CORRECT,BAD_MAGICIAN,VOLUNTEER_CHEATED} status;
        int board[4][4];
        int board2[4][4];
        int number;
        int i1,i2;
};

void MagicTrick::examine()
{
  int k=0;
  for (int i=0;i<4;i++){
      for (int j=0;j<4;j++){
          if (board[i1][i] == board2[i2][j]) { k++; number=board[i1][i]; break; }
      }
  }
  if (k == 0) status = VOLUNTEER_CHEATED;
  else if (k == 1) status = CORRECT;
  else status = BAD_MAGICIAN;
}

void MagicTrick::printMessage(int k,ostream &out) const
{ 
  out << "Case #" << k << ": "; 
  switch (status){
         case CORRECT: out << number; break;
         case BAD_MAGICIAN: out << "Bad magician!"; break;
         case VOLUNTEER_CHEATED: out << "Volunteer cheated!"; break;
  }
}



//*******************
//*****  MAIN   *****
//*******************

int main()
{
  ifstream input("A-small-attempt0.in");
  if (!input) exit(1);
  ofstream output("out.txt");
  if (!output) exit(1);
  
  int T;
  int r1,r2,numb;
  input >> T;
  
  for (int k=1;k<=T;k++){
      MagicTrick mt;
      input >> r1;
      for (int i=0;i<4;i++){
          for (int j=0;j<4;j++){
              input >> numb;
              mt.set(i,j,numb);
          }
      }
      input >> r2;
      for (int i=0;i<4;i++){
          for (int j=0;j<4;j++){
              input >> numb;
              mt.set2(i,j,numb);
          }
      }
      mt.volunteersChoice(r1,r2);
      mt.examine();
      mt.printMessage(k,output);
      output << endl;
  }
  input.close();
  output.close();
  
  scanf("%*c");
  return 0;
}
