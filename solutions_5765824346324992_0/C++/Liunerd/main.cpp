#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    string filename = "small";
    string infile = filename + ".in";
    string outfile = filename + ".out";
    fin.open(infile.c_str(), fstream::in);
    fout.open(outfile.c_str(), fstream::out);
    int testcase;
    fin >> testcase;
    for(int test = 1; test <= testcase; ++test){
        int B, N;
        fin >> B >> N;
        int m;
        vector<int> minutes;
        for(int i = 0; i < B; ++i){
            fin >> m;
            minutes.push_back(m);
        }
        int y = 0;
        if(B >= N){ // lined in front
            y = N;
        }else if(minutes[0] == minutes[B-1]){ // all barbers same speed
            y = N % B;
            if(y == 0) y = B;
        }else{
            int g = 1, c = 0;
            for(int i = 0; i < B; ++i) g *= minutes[i];
            for(int i = 0; i < B; ++i) c += g/minutes[i];
            N %= c;
            if(N == 0) N = c;
            if(N <= B) y = N;
            else {
                vector<int> left(B, 0);
                for(int i = 0; i < B; ++i) left[i] = minutes[i];
                N -= B;
                while(true){
                    int mini = 2147483647, available = 0;
                    for(int i = 0; i < B; ++i) if(mini > left[i]) mini = left[i];
                    for(int i = 0; i < B; ++i) left[i] -= mini;
                    for(int i = 0; i < B; ++i) if(left[i] == 0) ++available;
                    if(available >= N){
                        for(y = 0; y < B; ++y) if(left[y] == 0){
                            --N;
                            if(N == 0) break;
                        }
                        if(y == 0) ++y;
                        break;
                    }else{
                        for(int i = 0; i < B; ++i) if(left[i] == 0) left[i] = minutes[i];
                        N -= available;
                    }
                }
            }
        }
    	fout << "Case #" << test << ": " << y << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
