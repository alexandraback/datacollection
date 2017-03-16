#include <fstream>

using namespace std;

bool maskR1[16], maskR2[16], maskFinal[16];
int boardR1[4][4], boardR2[4][4];

void clearMask(bool mask[]) {
  for (int i = 0; i < 16; i++)
    mask[i] = false;
}

int queryMask(bool mask[]) {
  int result = 0;
  for (int i = 0; i < 16; i++)
    if (mask[i]) {
      if (result == 0) {
	result = i+1;
      } else {
	result = -1;
      }
    }
  return result;
}

int processCase(ifstream& is) {
  int rowR1, rowR2;
  clearMask(maskR1);
  clearMask(maskR2);
  clearMask(maskFinal);
  is >> rowR1; rowR1--;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      is >> boardR1[i][j];
  is >> rowR2; rowR2--;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      is >> boardR2[i][j];
  for (int j = 0; j < 4; j++)
    maskR1[boardR1[rowR1][j]-1] = true;
  for (int j = 0; j < 4; j++)
    maskR2[boardR2[rowR2][j]-1] = true;
  for (int i = 0; i < 16; i++)
    if (maskR1[i] && maskR2[i])
      maskFinal[i] = true;
  return queryMask(maskFinal);
}

int main() {
  ifstream ifs("inputA.txt");
  if (ifs.is_open()) {
    ofstream ofs("outputA.txt");
    if (ofs.is_open()) {
      int T;
      ifs >> T;
      for (int i = 1; i <= T; i++) {
	int result = processCase(ifs);
	ofs << "Case #" << i <<": ";
	if (result == -1)
	  ofs << "Bad magician!" << endl;
	else if (result == 0)
	  ofs << "Volunteer cheated!" << endl;
	else
	  ofs << result << endl;
      }
      ofs.close();
    }
    ifs.close();
  }

  return 0;
}
