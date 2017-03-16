#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;

int N;
string arr[100];
vector< pair<string, vector<int> > > data;

int main()
{
    string filename = "A-large";
    ifstream infile((filename+".in").c_str());
    ofstream outfile((filename+".out").c_str());

    int T;
    infile >> T;

    for(int t=0; t<T; t++)
    {
        data.clear();
        infile >> N;
        for(int i=0; i<N; i++)
        {
            infile >> arr[i];
        }
        for(int i=0; i<N; i++)
        {
            string res="";
            vector<int> countArr;
            for(int j=0; j<arr[i].length(); )
            {
                char c = arr[i][j];
                res += c;
                int count=0;
                while(j < arr[i].length() && arr[i][j]==c)
                {
                    count++;
                    j++;
                }
                cout << count << " ";
                countArr.push_back(count);
            }
            cout << endl;
            cout << res << endl;
            data.push_back(make_pair(res,countArr));
        }

        string theone = data[0].first;
        bool flag = false;
        for(unsigned int i=0; i<data.size(); i++)
        {
            if(theone != data[i].first)
            {
                cout << "FEGLA: " << theone << " " << data[i].first << endl;
                flag = true;
                break;
            }
        }

        if(flag)
            outfile << "Case #" << t+1 << ": " << "Fegla Won" << endl;
        else
        {
            int steps=0;
            for(unsigned int i=0; i<theone.length(); i++)
            {
                vector<int> nbrs;
                for(unsigned int j=0; j<N; j++)
                {
                    nbrs.push_back(data[j].second.at(i));
                }
                sort(nbrs.begin(),nbrs.end());

                int min = 9999999999;

                for(int maj=nbrs[0]; maj<=nbrs[nbrs.size()-1]; maj++)
                {
                    int temp=0;
                    for(unsigned int k=0; k<nbrs.size(); k++)
                    {
                        temp += abs(maj-nbrs[k]);
                    }
                    if(temp<min)
                        min=temp;
                }
                steps += min;
            }
            outfile << "Case #" << t+1 << ": " << steps << endl;
        }

    }

    return 0;
}
