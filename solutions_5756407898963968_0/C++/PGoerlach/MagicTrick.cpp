#include <iostream>
#include <fstream>

using namespace std;

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
    int A[4];
    int B[4];
    int C;
    int answer = -1;
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
        
        if(!datei.good())
            throw 2;
        datei >> answer;
        if(answer <= 0)
            throw 3;
        
        for(int i = 0; i < 4; i++)
        {
            if(i == answer - 1)
            {
                for(int j = 0; j < 4; j++)
                {
                    if(!datei.good())
                        throw 2;
                    datei >> A[j];
                }
            }
            else
                for(int j = 0; j < 4; j++)
                {
                    if(!datei.good())
                        throw 2;
                    datei >> C;
                }
        }
        
        if(!datei.good())
            throw 2;
        datei >> answer;
        if(answer <= 0)
            throw 3;
        
        for(int i = 0; i < 4; i++)
        {
            if(i == answer - 1)
            {
                for(int j = 0; j < 4; j++)
                {
                    if(!datei.good())
                        throw 2;
                    datei >> B[j];
                }
            }
            else
                for(int j = 0; j < 4; j++)
                {
                    if(!datei.good())
                        throw 2;
                    datei >> C;
                }
        }
        
        int solution = -1;
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(A[i]==B[j])
                {
                    if(solution > 0)
                    {
                        cout << "Bad magician!" << endl;
                        solution = -2;
                        goto outOfLoop;
                    }
                    else
                    {
                        solution = A[i];
                    }
                }
            }
        outOfLoop:
        if(solution > 0)
            cout << solution << endl;
        else if(solution == -1)
            cout << "Volunteer cheated!" << endl;
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
