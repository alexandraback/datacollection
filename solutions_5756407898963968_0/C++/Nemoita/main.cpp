#include <iostream>
using namespace std;

#if 1
#define INPUT_FILE  "A-small.in.txt"
#define OUTPUT_FILE "A-small.out.txt"
#else
#define INPUT_FILE  "A-large.in.txt"
#define OUTPUT_FILE "A-large.out.txt"
#endif


int main(int argc, const char * argv[])
{
    freopen(INPUT_FILE, "r", stdin);
	freopen(OUTPUT_FILE, "w+", stdout);
    
    int row [4];
    int dummyrow [4];
    int T, t;
    
    scanf("%i\n", &T);
    
    // For each test case
    for (t = 0; t < T; t++)
    {
        int count = 0;
        int irow;
        int card;
        
        scanf("%i\n", &irow);
        irow--;
        
        for (int i = 0; i < 4; i++)
        {
            if (i == irow)
                scanf("%i %i %i %i\n",&row[0],&row[1],&row[2],&row[3]);
            else
                scanf("%i %i %i %i\n",&dummyrow[0],&dummyrow[1],&dummyrow[2],&dummyrow[3]);
        }
        
        scanf("%i\n", &irow);
        irow--;
        
        for (int i = 0; i < 4; i++)
        {
            if (i == irow)
            {
                for (int j = 0; j < 4; j++)
                {
                    int dummycard;
                    scanf("%i", &dummycard);
                    for (int k = 0; k < 4; k++)
                    {
                        if (dummycard == row[k])
                        {
                            card = dummycard;
                            count++;
                            break;
                        }
                    }
                }
            }
            else
                scanf("%i %i %i %i\n",&dummyrow[0],&dummyrow[1],&dummyrow[2],&dummyrow[3]);
        }
    
        cout << "Case #" << t+1 << ": ";
        
        if (count == 1)
            cout << card;
        else if (count > 1)
            cout << "Bad magician!";
        else
            cout << "Volunteer cheated!";
        
		cout << endl;
    }
    return 0;
}