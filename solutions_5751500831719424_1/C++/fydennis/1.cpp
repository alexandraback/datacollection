#include <iostream>
#include <cstring>
#include <cassert>
#include <algorithm>

using namespace std;

void input(char *signature, char *end, unsigned char *char_num) {
    char prev_char = '\0';
    char cur_char;
    char buf[110];
    //int sign_pos = 0;
    
    --char_num;

    cin.getline(buf, 109);
    int buf_len = strlen(buf);
    for (int i = 0; i < buf_len; i++) {
        cur_char = buf[i];

        //cout << "Got: (" << cur_char << ") " << int(cur_char) << endl;

        if (cur_char == '\n') {
            break;
        }

        if (cur_char != prev_char) {
            prev_char = cur_char;
            *signature++ = cur_char;
            ++char_num;
            *char_num = 1;
            assert(signature < end);
        } else {
            ++(*char_num);
        }
    }
    *signature = '\0';
}

int main() {
    unsigned int case_num, case_index;
    cin >> case_num;
    int N;
    char signature_first[100];
    int signature_first_len;
    char signature[100];
    int signature_len;
    unsigned char char_num[100][100];

    char dump[100];

    char *buf;
    for (int case_index = 1; case_index <= case_num; case_index++) {
        cin >> N;
        cin.getline(dump, 100);
        input(signature_first, signature_first + 100, char_num[0]);
        signature_len = strlen(signature_first);

        bool fail = false;
        for (int i = 1; i < N; i++) {
            input(signature, signature+100, char_num[i]);
            if (strcmp(signature, signature_first)) {
                fail = true;
            }

            //cout << "Signature = " << signature << endl;
            //for (int j = 0; j < signature_len; j++) {
                //cout << int(char_num[i][j]) << " ";
            //}
            //cout << endl;
        }

        int temp[110];
        int mid = N / 2;

        cout << "Case #" << case_index << ": ";
        if (!fail) {
            int result = 0;
            for (int i = 0 ; i < signature_len; i++) {
                for (int j = 0; j < N; j++) {
                    temp[j] = char_num[j][i];
                }
                sort(temp, temp + N);
                for (int j = 0; j < N; j++) {
                    result += abs(temp[j] - temp[mid]);
                }
            }
            cout << result;
        } else {
            cout << "Fegla Won";
        }
        cout << endl;
    }
    return 0;
}

