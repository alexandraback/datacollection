#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include "mylib.h"
using namespace std;

void solve_case();

/**
 * Reads the input from stdin and prints the result
 */
int main(int argc, char** argv)
{
    int num_tests;
    cin >> num_tests;

    for (int i = 0; i < num_tests; ++i) {
        printf("Case #%d: ", i+1);
        solve_case();
    }

    return 0;
}

char *get_occ(string s)
{
    char *occ = (char *) malloc(s.size()+1);
    occ[0] = s[0];
    int pos = 0;
    for (unsigned int i = 1; i < s.size(); ++i) {
        if (s[i] != occ[pos])
            occ[++pos] = s[i];
    }
    for (unsigned int i = pos+1; i <= s.size(); ++i)
        occ[i] = '\0';
    return occ;
}

void write_counts(string s, int ** nums, int k)
{
    nums[k][0] = 1;
    int pos = 0;
    char c = s[0];
    for (unsigned int i = 1; i < s.size(); ++i) {
        if (s[i] == c)
            nums[k][pos]++;
        else {
            nums[k][++pos] = 1;
            c = s[i];
        }
    }
    for (unsigned int i = pos+1; i <=s.size(); ++i)
        nums[k][i] = 0;
}

bool check_occs(char * occ, string s)
{
    unsigned int i = 0;
    unsigned int pos = 0;
    while (occ[i] != '\0') {
        if (s[pos] != occ[i])
            return false;
        while (pos < s.size() && s[pos] == occ[i]) 
            pos++;
        i++;
    }
    if (occ[i] != '\0') return false;
    if (pos != s.size()) return false;
    return true;
}

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int get_median(int **nums, int column, int N)
{
    int *temp = (int *) malloc(N*sizeof(*temp));
    for (int i = 0; i < N; ++i)
        temp[i] = nums[i][column];
    qsort(temp, N, sizeof(int), cmpfunc);
    return temp[N/2];
}

int medians(int **nums, int N)
{
    int num_letters = 0;
    int total = 0;
    while(nums[0][num_letters]) num_letters++;
    for (int i = 0; i < num_letters; ++i) {
        int median = get_median(nums, i, N);
        for (int j = 0; j < N; ++j)
            total += (median > nums[j][i]) ? median - nums[j][i] : nums[j][i] - median;
    }
    return total;
}

void solve_case()
{
    int N;
    cin >> N;
    //int **nums = (int **) malloc(N*sizeof(*nums));
    int **nums = malloc_2d<int>(N, 200);
    bool failed = false;

    string s;
    cin >> s;
    char *occ = get_occ(s);
    write_counts(s, nums, 0);
    for (int i = 1; i < N; ++i) {
        cin >> s;
        if (!check_occs(occ, s))
            failed = true;
        write_counts(s, nums, i);
    }
    if (failed == true)
        cout << "Fegla Won" << endl;
    else
        cout << medians(nums, N) << endl;
}
