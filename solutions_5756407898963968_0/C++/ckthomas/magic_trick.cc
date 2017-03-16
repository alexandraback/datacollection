#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int Nprob;
  cin >> Nprob;
  for (int np=0; np<Nprob; np++)
  {
    int row1;
    int row2;
    vector<int> config1(16,0);
    vector<int> config2(16,0);
    cin >> row1;
    for (int i=0; i<16; i++)
      cin >> config1[i];
    cin >> row2;
    for (int i=0; i<16; i++)
      cin >> config2[i];
    int num_matches = 0;
    int solution = 0;
    for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
        if (config1[(row1-1)*4+i] == config2[(row2-1)*4+j])
        {
          num_matches++;
          solution = config1[(row1-1)*4+i];
        }

    cout << "Case #" << np+1 <<": ";
    if (num_matches == 0)
      cout << "Volunteer cheated!\n";
    else if (num_matches > 1)
      cout << "Bad magician!\n";
    else
      cout << solution << "\n";

  }
}
