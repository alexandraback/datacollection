#include <iostream>
#include <vector>
using namespace std;
int matrix[5][5];
int provavel[5][3];

int main(int, char**)
{
  int test_cases;
  cin >> test_cases;

  for(int id = 1; id <= test_cases; id++)
  {
    for(int m = 1; m <= 2; m++){
      int line;
      int buffer;
      cin >> line;
      for(int y = 1; y <= 4;y++)
      {
        for(int x = 1; x <= 4; x++)
        {
          if(y == line){
            cin >> provavel[x][m];
          } else
          {
            cin >> buffer;
          }
        }
      } //pegou uma matriz e provaveis

    }//End pegar cartar
    
    //Verifica cartas
    vector<int> cartas;
    for(int i = 1; i <= 4; i++)
    {
      for(int j = 1; j <= 4; j++)
      {
        if(provavel[i][1] == provavel[j][2]){
          cartas.push_back(provavel[i][1]);
        }
      }
    }

    if(cartas.empty())
    {
      cout << "Case #" << id << ": Volunteer cheated!" << endl;
    }else if(cartas.size() > 1)
    {
      cout << "Case #" << id << ": Bad magician!" << endl;
    } else
    {
      cout << "Case #" << id << ": " << cartas[0] << endl;
    }
    
  }//end cases
  return 0;
}