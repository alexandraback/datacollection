#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int abs(int a)
{
    if(a >= 0) return a;
    else return -a;
}

int main(int argc, char *argv[])
{
    //Eingabe des Dateinamens über Konsole oder Übergabe als Eingabeparameter
    char* filename;
    if(argc > 1)
    {
        filename = argv[1];
    }
    else
    {
        char buffer[256];
        cout << "Input file name (up to 255 Characters): " << endl;
        cin >> buffer;
        filename = buffer;
    }
    
    int T = 0;
    int N = 2;
    
    try
    {
        ifstream datei(filename);
        if(!datei.is_open())
            throw 1;
        
        if(!datei.good())
            throw 2;
        datei >> T;
        if(T <= 0)
            throw 3;
        
        for(int k = 0; k < T; k++)
    {
        cout << "Case #" << k+1 << ": ";
        
        datei >> N;
        string a[N];
        int position[N];
        //cout << "rara";
        for(int i = 0; i < N; i++)
        {
            datei >> a[i];
            //cout << a[i] << "0";
            position[i] = 0;
        }
        //cout << "haah";
        
        int totalcost = 0;
        //cout << N;
        while(true)
        {
            //cout << position[0];
            char curr = a[0].at(position[0]);
            
            int len[N];
            
            for(int i = 0; i < N; i++)
            {
                len[i] = 0;
                for(int j = position[i]; j < a[i].size(); j++)
                {
                    if(a[i].at(j) == curr)
                    {
                        len[i]++;
                        if(j == a[i].size()-1)
                        {
                            position[i] = a[i].size();
                        }
                    }
                    else
                    {
                        position[i] = j;
                        break;
                    }
                    
                }
                if(len[i] == 0)
                {
                    cout << "Fegla Won";
                    goto nextcase;
                }
            }
            
            //get min:
            int min = 1000000;
            for(int x = 1; x <= 100; x++)
            {
                int sum = 0;
                for(int i = 0; i < N; i++)
                {
                    sum += abs(x-len[i]);
                }
                if(sum < min)
                {
                    min = sum;    
                }
            }
            totalcost += min;
            
            for(int i = 0; i < N; i++)
            {
                if(position[0] == a[0].size() && position[i] != a[i].size())
                {
                    cout << "Fegla Won";
                    goto nextcase;
                }
            }
            if(position[0] == a[0].size())
                break;
        }
        cout << totalcost;
        
        nextcase:
        cout << endl;
    }
    }
    catch(int e)
    {
        cout << "Fehler (Nr. " << e << ") beim Einlesen der Datei.";
        int a;
    cin >> a;
        return 1;
    }
    
    //int a;
    //cin >> a;
    return 0;    
}
