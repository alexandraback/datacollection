#include <iostream>

using namespace std;

#define N 4

/**
 * @return number of common integers in both arrays
 *         out is set to the last common number, if exists
 */
int intersect(int row1[N], int row2[N], int *out) {
    int common = 0;
    for (int i = 0;i < N;++i) {
        for (int j = 0;j < N;++j) {
            if (row1[i] == row2[j]) {
                ++common;
                *out = row1[i];
            }
        }
    }

    return common;
}

/**
 * read in a row specified by input from STDIN.
 */
void read_row(int row[N]) {
    int r, num;
    cin >> r;
    --r; // adjust to zero-based
    // skip preceding rows
    for (int i = 0;i < N;++i)
        for (int j = 0;j < N;++j)
            if (i == r)
                cin >> row[j];
            else
                cin >> num;
}

int main() {
    int n, row1[N], row2[N];
    cin >> n;

    for (int i = 0;i < n;++i) {
        read_row(row1);
        read_row(row2);
        int number;
        int common = intersect(row1, row2, &number);

        cout << "Case #" << (i+1) << ": ";
        if (common == 0)
            cout << "Volunteer cheated!";
        else if (common == 1)
            cout << number;
        else
            cout << "Bad magician!";
        cout << endl;
    }
}
