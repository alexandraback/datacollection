#include <fstream>
using namespace std;

int main()
{
    ifstream fin("c.in");
    ofstream fout("c.out");
    
    int T, N, P[26], i, j, M1, M2, h1, h2;
    char L[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    fin >> T;
    for (unsigned int x = 1; x <= T; x++)
    {
        h1 = h2 = M1 = M2 = 0;
        fout << "Case #" << x << ":";
        fin >> N;
        for (i = 0; i < N; i++) fin >> P[i];
        for (i = 0; i < N; i++)
        {
            if (P[i] >= M1)
            {
                h2 = h1;
                M2 = M1;
                M1 = P[i];
                h1 = i;
            }
            else if (P[i] >= M2)
            {
                M2 = P[i];
                h2 = i;
            }
        }
        while (P[h1] > P[h2])
        {
            fout << ' ' << L[h1];
            P[h1]--;
        }
        for (i = 0; i < N; i++) if (i != h1 && i != h2) for (j = 0; j < P[i]; j++) fout << ' ' << L[i];
        for (i = 0; i < P[h1]; i++) fout << ' ' << L[h1] << L[h2];
        fout << '\n';
    }
    
    fin.close();
    fout.close();
    return(0);
}
