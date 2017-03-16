#include <bits/stdc++.h>

using namespace std;

void makeSimple(string temp, string &answer)
{
    answer="";
    answer+=temp[0];
    for (int i=1; i<(temp.size()); i++)
    {
        if (temp[i]!=answer[answer.size()-1])
        answer+=temp[i];
    }
}

int main()
{
    ifstream fin("test.in");
    ofstream fout ("test.out");
    int cases;
    fin>>cases;
    for (int k=0; k<cases; k++)
    {
        bool condition = false;
        int num, index=0, total=0;
        string temp, palin, simple;
        vector<string> words;
        vector<vector<int> > minOccur;
        fin>>num;
        for (int j=0; j<num; j++)
        {
            fin>>temp;
            words.push_back(temp);
        }
        //fin.close();
        makeSimple(words[0], simple);
        //ofstream fout ("test.txt");
        for (int i=1; i<num; i++)
        {
            makeSimple(words[i], palin);
            if (palin!=simple)
            {
                fout<<"Case #"<<k+1<<": Fegla Won"<<endl;
                {
                    condition = true;
                    break;
                }
            }
        }
        if (condition)
        continue;
        for (int i=0; i<(simple.size()); i++)
        {
            vector<int> newRow;
            for (int j=0; j<num; j++)
                newRow.push_back(0);
            minOccur.push_back(newRow);
        }
        //cout<<simple<<endl;
        for (int i=0; i<num; i++)
        {
            int cur=1;
            if (words[i].size() == 1)
            minOccur[index][i] = 1;
            for (int j=1; j<(words[i].size()); j++)
            {
                if (words[i][j] == words[i][j-1])
                {
                    cur++;
                    if (j==(words[i].size()-1))
                    {
                        /*if (i==0)
                        minOccur.push_back(cur);
                        else if (cur < minOccur[index])
                        minOccur[index] = cur;*/
                        minOccur[index][i] = cur;
                    }
                }
                else
                {
                    /*if (i==0)
                    minOccur.push_back(cur);
                    else if (cur < minOccur[index])
                    minOccur[index] = cur;*/
                    minOccur[index][i] = cur;
                    index++;
                    if (j==(words[i].size() - 1))
                    {
                        minOccur[index][i] = 1;
                    }
                    else
                        cur=1;
                }
            }
            index=0;
        }
        /*for (int i=0; i<(simple.size()); i++)
        {
            for (int j=0; j<num; j++)
                cout<<minOccur[i][j]<<" ";
            cout<<endl;
        }*/
        for (int i=0; i<(simple.size()); i++)
        sort(minOccur[i].begin(), minOccur[i].end());
        int mid = num/2;
        for (int i=0; i<(simple.size()); i++)
        {
            for (int j=0; j<num; j++)
                total+=(abs(minOccur[i][mid] - minOccur[i][j]));
        }
        fout<<"Case #"<<k+1<<": "<<total<<endl;
        total=0;
    }
    return 0;
}
