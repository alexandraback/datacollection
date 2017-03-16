#include <iostream>
#include <cstdio>

using namespace std;

int party_amounts[30];

int sum() {
    int total = 0;
    for (int i = 0; i < 30; i++) total += party_amounts[i];
    return total;
}

void reset_parties() { for (int i = 0; i < 30; i++) party_amounts[i] = 0; }

int num_positive() {
    int pos_count = 0;
    for (int i = 0; i < 30; i++) {
        if (party_amounts[i] > 0) pos_count++;
    }
    return pos_count;
}

int find_greatest() {
    int greatest_so_far = 0;
    int index = 0;

    for (int i = 0; i < 30; i++) {
        if (party_amounts[i] > greatest_so_far) {
            greatest_so_far = party_amounts[i];
            index = i;
        }
    }

    return index;
}

int find_greatest(int to_forget) {
    int greatest_so_far = 0;
    int index = 0;

    for (int i = 0; i < 30; i++) {
        if (i == to_forget) continue;
        if (party_amounts[i] > greatest_so_far) {
            greatest_so_far = party_amounts[i];
            index = i;
        }
    }

    return index;
}

int find_greatest(int to_forget1, int to_forget2) {
    int greatest_so_far = 0;
    int index = 0;

    for (int i = 0; i < 30; i++) {
        if (i == to_forget1 || i == to_forget2) continue;
        if (party_amounts[i] > greatest_so_far) {
            greatest_so_far = party_amounts[i];
            index = i;
        }
    }

    return index;
}

int main() {
    int T;
    cin >> T;

    for (int i = 1; i <= T; i++) {
        reset_parties();

        int N;
        cin >> N;

        // Read in sizes
        for (int j = 0; j < N; j++) cin >> party_amounts[j];

        cout << "Case #" << i << ": ";

        while (sum() > 0) {
            //cout << sum() << endl;
            if (sum() == 2) {
                // find the two ones
                int first_one = -1;
                int second_one = -1;

                for (int k = 0; k < 30; k++) {
                    if (party_amounts[k] > 0) {
                        if (first_one != -1) second_one = k;
                        else first_one = k;
                    }
                }

                cout << (char) (first_one + 'A') << (char) (second_one + 'A') << endl;
                party_amounts[first_one]--;
                party_amounts[second_one]--;
            }

            else {
                // find greatest value
                int index = find_greatest();
                int index2 = find_greatest(index);
                int index3 = find_greatest(index, index2);

                // remove both
                if (party_amounts[index] == party_amounts[index2] && party_amounts[index] != 1) {
                    cout << (char) ('A' + index) << (char) ('A' + index2) << " ";
                    party_amounts[index]--;
                    party_amounts[index2]--;
                }

                else {
                    cout << (char) ('A' + index) << " ";
                    party_amounts[index]--;
                }
            }
        }
    }
}