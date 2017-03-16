#include <list>
#include <queue>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct Party
{
    char c;
    int count;

    bool operator < (const Party& p) const
    {
        return count < p.count;
    }
    Party(char k, int kn) : c(k), count(kn) {}
};

int main(int argc, char** argv)
{
    if(argc < 3)
    {
        cout << "Usage : "<<argv[0] <<" test.in test.out";
        return 0;
    }
    cout << argv[0] << " " << argv[1] << " " << argv[2] << endl;

    ifstream in(argv[1]);
    if(!in.is_open()) {
        cout << "Failed to open " << argv[1] << endl;
        return 0;
    }

    ofstream out(argv[2]);
    if(!out.is_open()) {
        cout << "Failed to open " << argv[2] << endl;
        return 0;
    }

    int T;
    in >> T;
    for(int i = 0; i < T; ++i)
    {
        int N;
        in >> N;
        priority_queue<Party> vec;
        for(int j = 0; j < N; ++j)
        {
            int count = 0;
            in >> count;

            if(count)
            vec.push(Party('A'+j, count));
        }

        cout << "Solving case : " << i<<endl;
        out << "Case #" << i+1 << ": ";
        while(!vec.empty())
        {
            Party max = vec.top(); vec.pop();
            if(vec.empty())
            {
                cout <<" Invalid scenario\n";
                break;
            }
            Party max2 = vec.top(); vec.pop();
            int max3C = 0;
            if(!vec.empty())
            {
                Party max3 = vec.top();
                max3C = max3.count;
            }
            if(max.count == 1 and max2.count == 1 and max3C ==1)
            {
                out<< " " << max.c;
                vec.push(Party(max2.c, max2.count));
            }
            else if(max.count == max2.count)
            {
                out<< " " << max.c << max2.c;
                if(max.count > 1)
                vec.push(Party(max.c, max.count-1));
                if(max2.count > 1)
                vec.push(Party(max2.c, max2.count-1));
            }
            else
            {
                if(max.count > 1)
                {
                    out<< " " << max.c;
                    vec.push(Party(max.c, max.count-1));
                }
                if(max2.count)
                vec.push(Party(max2.c, max2.count));
            }
        }
        out << endl;
    }
    return 0;
}





