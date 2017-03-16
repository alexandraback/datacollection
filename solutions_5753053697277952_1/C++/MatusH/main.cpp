#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <string>

using namespace std;

ifstream in;
ofstream out;

unsigned int letter[26];
unsigned int number[10];

void count(unsigned int N){
    unsigned int P[N];
    unsigned int max = 0;
    unsigned int maxI = 0;
    unsigned int max2I = 0;

    for (unsigned int i = 0; i < N; i++) {
        in >> P[i];
        if (max < P[i]) {
            max = P[i];
            maxI = i;
        }
    }
    max = 0;
    for (unsigned int i = 0; i < N; i++) {
        if ((max < P[i]) && (i != maxI)) {
            max = P[i];
            max2I = i;
        }
    }

    if ((P[maxI]-P[max2I]) % 2 == 1) {
        char o = 'A'+maxI;
        out << " " << o;
        P[maxI]--;
    }
    for (unsigned int i = P[maxI]; i > P[max2I]; i -= 2) {
        char o = 'A'+maxI;
        out << " " << o << o;
        P[maxI] -= 2;
    }

    for (unsigned int i = 0; i < N; i++) {
        if ((i != maxI) && (i != max2I)) {
            if (P[i] % 2 == 1) {
                char o = 'A'+i;
                out << " " << o;
                P[i]--;
            }
            for (unsigned int j = P[i]; j > 0; j -= 2) {
                char o = 'A'+i;
                out << " " << o << o;
            }
        }
    }

    for (unsigned int i = 0; i < P[max2I]; i++) {
        char o = 'A'+maxI;
        out << " " << o;
        o = 'A'+max2I;
        out << o;
    }
    return;





}


int main()
{
    in.open("A-large.in");
    out.open("output.out");
    string S;
    unsigned long long int T, N;
    //unsigned long long int time, n, timeUp, timeDown;

    if(in.is_open()){
        in >> T;
        for (unsigned int i = 1; i <= T; i++){
            in >> N;

            out << "Case #" << i << ":";

            count(N);

            out << endl;
        }
        in.close();
    }else {
        cout << "fuck";
    }
    out.close();
    return 0;
}
