#include <fstream>

using namespace std;

int r, c;
int mat[20][20];

int backtr (int lin, int col, int ram, int x) {
    if (col == c + 1)
        return backtr(lin + 1, 1, ram, x);
    else if (lin == r + 1)
        return ((!ram) ? (x) : (20 * r * c + 1));

    int ans = backtr(lin, col + 1, ram, x);

    mat[lin][col] = 1;
    int aux = backtr(lin, col + 1, ram - 1, x + mat[lin - 1][col] + mat[lin][col - 1]);
    mat[lin][col] = 0;

    if (aux < ans)
        ans = aux;

    return ans;
}

int main()
{
    ifstream cin("B.in");
    ofstream cout("B.out");

    int t = 0;
    cin >> t;

    int cati;
    for (int tt = 1; tt <= t; tt++) {
        cin >> r >> c >> cati;

        cout << "Case #" << tt << ": " << backtr(1, 1, cati, 0) << '\n';
    }

    cin.close();
    cout.close();
    return 0;
}
