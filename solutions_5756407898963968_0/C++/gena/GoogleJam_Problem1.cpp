// GoogleJam_Problem1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"

vector<string> split( const string& s, const string& delim =" " ) {
    vector<string> res;
    string t;
    for ( int i = 0 ; i != (int)s.size() ; i++ ) {
        if ( delim.find( s[i] ) != string::npos ) {
            if ( !t.empty() ) {
                res.push_back( t );
                t = "";
            }
        } else {
            t += s[i];
        }
    }
    if ( !t.empty() ) {
        res.push_back(t);
    }
    return res;
}

vector<int> splitInt( const string& s, const string& delim =" " ) {
    vector<string> tok = split( s, delim );
    vector<int> res;
    for ( int i = 0 ; i != (int)tok.size(); i++ )
        res.push_back( atoi( tok[i].c_str() ) );
    return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
    __int64 start = GetTickCount64();
    if(argc < 3)
    {
        printf("Error. Need in and out files\n");
        return -1;
    }

    FILE * fin = NULL;
    FILE * fout = NULL;

    fopen_s(&fin, argv[1], "rt");
    if(fin == NULL)
    {
        printf("Can't open %s\n", argv[1]);
        return -1;
    }

    fopen_s(&fout, argv[2], "w");
    if(fout == NULL)
    {
        printf("Can't open %s\n", argv[2]);
        return -1;
    }

    char buf[1024];

    char * ps = fgets(buf, sizeof(buf), fin);
    int numTests = atoi(ps);

    int m[2][4][4];
    int a[2];

    for(int t = 1; t <= numTests; ++t)
    {
        for(int r = 0; r < 2; ++r)
        {
            ps = fgets(buf, sizeof(buf), fin);
            a[r] = atoi(ps) - 1;
        
            for(int i = 0; i < 4; ++i)
            {
                ps = fgets(buf, sizeof(buf), fin);
                vector<int> v = splitInt(string(ps));
                for(int k=0; k < 4; ++k)
                {
                    m[r][i][k] = v[k];
                }
            }
        }

        // Intersect m[0][a[0]
        vector<int> res;
        for(int i = 0; i < 4; ++i)
        {
            int * pr = std::find(m[1][a[1]], m[1][a[1]] + 4, m[0][a[0]][i]);
            if(pr != m[1][a[1]] + 4)
            {
                res.push_back(*pr);
            }
        }

        fprintf(fout, "Case #%d: ", t);
        if(res.size() != 1)
        {
            if(res.empty())
            {
                fprintf(fout, "Volunteer cheated!\n");
            }
            else
            {
                fprintf(fout, "Bad magician!\n");
            }
        }
        else
        {
            fprintf(fout, "%d\n", res[0]);
        }
    }

    fclose(fin);
    fclose(fout);

	return 0;
}

