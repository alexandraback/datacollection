#include <fstream>
#include <vector>
using namespace std;

vector<int> comuni(int A[4], int B[4])
{
    vector<int> R;
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            if(A[i]==B[j])
                R.push_back(A[i]);

    return R;
}

int main()
{
    ifstream in ("input.txt");
    ofstream out ("output.txt");
    int T, r1, r2;
    int tab[8][4];
    in >> T;
    for(int i=1; i<=T; i++)
    {
        in >> r1;
        for(int j=0; j<4; j++)
            for(int k=0; k<4; k++)
                in >> tab[j][k];
        in >> r2;
        for(int j=0; j<4; j++)
            for(int k=0; k<4; k++)
                in >> tab[j+4][k];
        vector<int> R = comuni(tab[r1-1], tab[r2+3]);

        out << "Case #" << i << ": ";

        if(R.empty())
            out << "Volunteer cheated!";
        else if(R.size()==1)
            out << R[0];
        else
            out << "Bad magician!";

        out << endl;

    }
    return 0;
}
