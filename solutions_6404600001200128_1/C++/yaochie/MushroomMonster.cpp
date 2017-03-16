#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ifstream fin("A-large.in");
    ofstream fout("outputAlarge.txt");

    int T;
    fin >> T;

    for (int i=0; i<T; i++) {
        int N;
        fin >> N;
        vector<int> shrooms(N);

        for (int j=0; j<N; j++) {
            int temp;
            fin >> temp;
            shrooms[j] = temp;
        }

        //method 1
        int totalOne = 0;
        for (int j=1; j<N; j++) {
            if (shrooms[j] < shrooms[j-1]) totalOne += (shrooms[j-1] - shrooms[j]);
        }

        //method 2
        //find largest rate (largest difference between two times)
        int largestRate = 0;
        for (int j=1; j<N; j++) {
            if (shrooms[j] < shrooms[j-1]) {
                int diff = shrooms[j-1] - shrooms[j];

                if (diff > largestRate) {
                    largestRate = diff;
                }
            }
        }

        int totalTwo = 0;
        for (int j=0; j<(N-1); j++) {
            totalTwo += (shrooms[j] < largestRate) ? shrooms[j] : largestRate;
        }

        cout << "Case #" << i+1 << ": " << totalOne << " " << totalTwo << "\n";
        fout << "Case #" << i+1 << ": " << totalOne << " " << totalTwo << "\n";
    }

    fin.close();
    fout.close();

    return 0;
}
