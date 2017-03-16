#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    FILE *input = fopen("A-small.txt", "r");
    FILE *output = fopen("out.txt", "w");
    int t;
    fscanf(input, "%d", &t);
    for(int q = 0; q < t; q++)
    {
        int first[4];
        int row1; fscanf(input, "%d", &row1);
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                if(i == row1-1)
                {
                    fscanf(input, "%d", &first[j]);
                }
                else
                {
                    int temp;
                    fscanf(input, "%d", &temp);
                }
            }
        }
        int second[4];
        int row2; fscanf(input, "%d", &row2);
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                if(i == row2-1)
                {
                    fscanf(input, "%d", &second[j]);
                }
                else
                {
                    int temp;
                    fscanf(input, "%d", &temp);
                }
            }
        }
        //================
        int matches = 0;
        int index = -1;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                if(first[i] == second[j])
                {
                    index = i;
                    matches++;
                }
            }
        }
        fprintf(output, "Case #%d: ", q+1);
        if(matches == 0) fprintf(output, "Volunteer cheated!\n");
        else if (matches > 1) fprintf(output, "Bad magician!\n");
        else fprintf(output, "%d\n", first[index]);
    }
    return 0;
}
