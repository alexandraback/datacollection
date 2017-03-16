//
// Created by Yuxiang LI on 09/04/16.
//
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int T,n;
string s1, s2;
vector<int> number(26);

int main(){
    ifstream in("AA.in");
    ofstream out("output.out");
    in >> T;

    for(int cases = 1; cases <= T; cases++){
        in >> n;
        int s = 0;
        for(int i = 0; i < n; i++) {
            in >> number[i];
            s += number[i];
        }
        out << "Case #" << cases << ": ";
        while(s != 0){
            int max1 = 0;
            for(int i = 1; i < n; i++){
                if (number[i] > number[max1])
                    max1 = i;
            }
            number[max1]--;
            s--;
            int max2 = 0;
            for(int i = 1; i < n; i++){
                if (number[i] > number[max2])
                    max2 = i;
            }
            if (s - number[max2] < number[max2]){
                out << char(max2+int('A')) << char(max1+int('A')) << ' ';
                number[max2]--;
                s--;
            }else{
                out << char(max1+int('A')) << ' ';
            }
        }
        out << endl;
    }
    in.close();
    out.close();
    return 0;
}
