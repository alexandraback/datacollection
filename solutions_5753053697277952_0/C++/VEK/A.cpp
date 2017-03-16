#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <limits.h>

int min(int a, int b) {return (a<b)?a:b;}
int max(int a, int b) {return (a>b)?a:b;}

using namespace std;

typedef long long unsigned llu;

unsigned testNum, s_num, p[26], total_num;

template <typename T>
string num_to_str ( T Number )
  {
     ostringstream ss;
     ss << Number;
     return ss.str();
  }

unsigned get_max ()
{
  unsigned mx = 0;
  unsigned mx_i = 0;
  for (unsigned j = 0; j < s_num; ++j)
    {
      if (p[j] > mx)
        {
          mx = p[j];
          mx_i = j;
        }
    }
  return mx_i;
}

void remove (unsigned j)
{
  --p[j];
  --total_num;
}

void add (unsigned j)
{
  ++p[j];
  ++total_num;
}

bool has_majority ()
{
  for (unsigned j = 0; j < s_num; ++j)
    {
      if (p[j]*2 > total_num)
        return true;
    }
  return false;
}

int main(int argc, char **argv)
{
  ifstream ifile("A-small-attempt0.in");
  FILE *ofile = fopen("out.txt", "w");
  ifile >> testNum;
  for (unsigned i = 0; i < testNum; ++i) {
    total_num = 0;
    ifile >> s_num;
    for (unsigned j = 0; j < s_num; ++j)
      {
        ifile >> p[j];
        total_num += p[j];
      }
    printf ("Case #%d: ", i+1);
    fprintf (ofile, "Case #%d: ", i+1);
    while (total_num > 0)
      {
        unsigned evac = get_max ();
        printf ("%c", (char)evac+'A');
        fprintf (ofile, "%c", (char)evac+'A');
        remove (evac);
        if (total_num == 0)
          break;
        evac = get_max ();
        remove (evac);
        if (has_majority ())
          {
            add (evac);
            printf (" ");
            fprintf (ofile, " ");
          }
        else
          {
            printf ("%c ", (char)evac+'A');
            fprintf (ofile, "%c ", (char)evac+'A');
          }
      }
    printf ("\n");
    fprintf (ofile, "\n");
  }
  ifile.close();
  fclose(ofile);
  return 0;
}
