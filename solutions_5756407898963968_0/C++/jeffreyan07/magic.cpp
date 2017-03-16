#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

struct testcase {
    int v1, v2;
    int arr1[4][4];
    int arr2[4][4];
};

vector<testcase*> cases;

bool readFile() {
    std::string line;
    std::ifstream cfile("minput.txt");

    if(cfile.is_open()) {
        getline(cfile, line);
        int num = std::stoi(line);
        for(int i = 0; i < num; i++) {
            getline(cfile, line);
            testcase *loaded = new testcase();
            std::string::size_type sz = 0;
            loaded->v1 = std::stoi(line);

            for(int j = 0; j < 4; j++) {
                getline(cfile, line);
                sz = 0;
                for(int k = 0; k < 4; k++) {
                    loaded->arr1[j][k] = std::stoi(line, &sz, 0);
                    line = line.substr(sz);
                }
            }

            getline(cfile, line);
            loaded->v2 = std::stoi(line);

            for(int j = 0; j < 4; j++) {
                getline(cfile, line);
                sz = 0;
                for(int k = 0; k < 4; k++) {
                    loaded->arr2[j][k] = std::stoi(line, &sz, 0);
                    line = line.substr(sz);
                }
            }
            cases.push_back(loaded);
        }
        cfile.close();
    }
    else return false;

    return true;
}

void writeFile(vector<string*> towrite) {
    ofstream out;
    out.open("mout.txt");
    for(unsigned int i = 0; i < towrite.size(); i++) {
        out << *towrite[i] << endl;
    }
    out.close();
}

int main(int argc, char **argv) {
    readFile();

    vector<string*> towrite;

    for(int i = 0; i < cases.size(); i++) {
        testcase *tc = cases[i];
        int possible[4];
        for(int j = 0; j < 4; j++) {
            possible[j] = tc->arr1[tc->v1-1][j];
        }

        int matches = 0;
        int match = 0;
        for(int j = 0; j < 4; j++) {
            int a = tc->arr2[tc->v2-1][j];
            if(a == possible[0] || a == possible[1] || a == possible[2] || a == possible[3]) {
                matches++;
                match = a;
            }
        }

        stringstream stream;

        if(matches == 1)
            stream << "Case #" << i+1 << ": " << match;
        else if(matches == 0)
            stream << "Case #" << i+1 << ": Volunteer cheated!";
        else
            stream << "Case #" << i+1 << ": Bad magician!";

        string *result = new string( stream.str() );
        towrite.push_back(result);
    }

    writeFile(towrite);

    return 0;
}
