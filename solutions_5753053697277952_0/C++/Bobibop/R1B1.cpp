#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

#ifndef max
#define max(a,b) (a<b?b:a)
#endif

#ifndef min
#define min(a,b) (a>b?b:a)
#endif

vector<vector<int> > fileToVectorVectorInt(string filename) {
    std::vector<vector<int> > v;
    char *buf = (char*)malloc(1024*sizeof(char));
    size_t n;
    if (FILE *fp = fopen(filename.c_str(), "r"))
    {
        while (getline(&buf, &n, fp) > 0) {
            istringstream iss(buf);
            vector<string> tokens{istream_iterator<string>{iss},
                                  istream_iterator<string>{}};
            vector<int> x(tokens.size());
            transform(tokens.begin(), tokens.end(), x.begin(), [](string a) {return stoi(a);});
            v.push_back(x);
        }
        fclose(fp);
    }
    return v;
}

bool exitIJ(int i, int j, vector<int> &in, int &tot) {
    if (tot <= 1 || in[i] == 0 || in[j] == 0 || (i == j && in[i] <= 1))
    {
        return false;
    }
    in[i]--;
    in[j]--;
    tot -= 2;
    if (tot == 0)
    {
        return true;
    }
    for (auto k = in.begin(); k != in.end(); ++k)
    {
        if(2*(*k) > tot)
        {
            in[i]++;
            in[j]++;
            tot += 2;
            return false;
        }
    }
    return true;
}

bool exitI(int i, vector<int> &in, int &tot) {
    if (tot == 0 || in[i] == 0)
    {
        return false;
    }
    in[i]--;
    tot -= 1;
    if (tot == 0)
    {
        return true;
    }
    for (auto k = in.begin(); k != in.end(); ++k)
    {
        if(2*(*k) > tot)
        {
            in[i]++;
            tot += 1;
            return false;
        }
    }
    return true;
}

string f(vector<int> x) {
    int nbPersonnes = accumulate(x.begin(), x.end(), 0);
    string out = "";
LOOP:
    while(nbPersonnes > 0) {
        for (unsigned i = 0; i < x.size(); ++i)
        {
            for (unsigned j = 0; j < x.size(); ++j)
            {
                if(exitIJ(i, j, x, nbPersonnes)) {
                    out += 'A' + i;
                    out += 'A' + j;
                    out += ' ';
                    goto LOOP;
                }
            }
        }
        for (unsigned i = 0; i < x.size(); ++i)
        {
            if(exitI(i, x, nbPersonnes)) {
                out += 'A' + i;
                out += ' ';
                goto LOOP;
            }
        }
    }

    return out;
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        cerr << "Usage : " << argv[0] << " <filename>" << endl;
        exit(1);
    }

    string filename = string(argv[1]);
    vector<vector<int> > input = fileToVectorVectorInt(filename);

    for (int i = 0; i < input[0][0]; ++i)
    {
        cout << "Case #" << (i+1) << ": " << f(input[2*(i+1)]) << endl;
    }

    exit(0);
}