#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// G:\Fun\code_blocks_proj\google_codejam_r1_q1_cpp

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
        int n, m;
        fin >> n;
        vector<int> mushrooms;
        for(int i = 0; i < n; ++i){
            fin >> m;
            mushrooms.push_back(m);
        }
        int y = 0, z = 0, max_eat = 0;
        for(int i = 1; i < n; ++i){
            if(mushrooms[i] < mushrooms[i-1]){
                y += mushrooms[i-1] - mushrooms[i];
                if(max_eat < mushrooms[i-1] - mushrooms[i]) max_eat = mushrooms[i-1] - mushrooms[i];
            }
        }
        for(int i = 0; i < n-1; ++i) z += mushrooms[i] < max_eat ? mushrooms[i] : max_eat;
    	fout << "Case #" << test << ": " << y << " " << z << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
