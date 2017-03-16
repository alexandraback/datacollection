#include <iostream>
#include <cstring>

using namespace std;

void swap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap(char &a, char &b) {
    char temp;
    temp = a;
    a = b;
    b = temp;
}

int main() 
{
    int case_num;
    int n, count;
    int party[26];
    char party_name[26];
    cin >> case_num;
    for (int case_id = 0; case_id < case_num; case_id++) {
        cout << "Case #" << case_id + 1 << ":";
        cin >> n;
        count = 0;
        memset(party, 0, sizeof(party));
        for (int i = 0; i < n; i++) {
            cin >> party[i];
            party_name[i] = 'A' + i;
            count += party[i];
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (party[i] < party[j]) {
                    swap(party[i], party[j]);
                    swap(party_name[i], party_name[j]);
                }
            }
        }
        while (count > 0 && party[2] != 0) {
            cout << " " << party_name[0];
            party[0]--;
            count--;
            int pos = 0;
            while (pos < 25 && party[pos] < party[pos+1]) {
                swap(party[pos], party[pos+1]);
                swap(party_name[pos], party_name[pos+1]);
                pos++;
            }
        }
        for (int i = 0; i < count / 2; i++) {
            cout << " " << party_name[0] << party_name[1];
        }
        cout << endl;
    }
    return 0;
}
