#include <iostream>
#include <fstream>

using namespace std;

ifstream in;
ofstream out;

int No = 0;
// 1-16 = Cards
int Bad = 18;
int Cheated = 19;

/// Check if n is in line
int isIn(int n, int line[4])
{
    for (int i = 0; i < 4; i++)
        if (n == line[i])
            return line[i];
    return 0;
}

/// Gets which / how much numbers are in both arrays
int intersect(int lineA[4], int lineB[4])
{
    int res = Cheated;
    for (int i = 0; i < 4; i++)
    {
        if (isIn(lineA[i], lineB) && res == Cheated)
            res = lineA[i];
        else if (isIn(lineA[i], lineB))
            res = Bad;
    }
    return res;
}

/// Reads 5 lines from the input and returns the guessed line.
int* parse_grid()
{
    int *line = new int[4];

    int guess;
    string dump;

    // Read first guess
    in >> guess;
    std::getline(in, dump);
    //cout << "g: " << guess << "\n";
    // Skip guess-1 lines
    int i = 1;
    for (; i < guess; i++)
    {
        std::getline(in, dump);
      //  cout << "d1: " << dump << "\n";
    }
    // Read line
    for (int j = 0; j < 4; j++)
        in >> line[j];
    std::getline(in, dump);
    // Skip rest of lines
    i++;
    for (; i <= 4; i++)
    {
        std::getline(in, dump);
        //cout << "d2: " << dump << "\n";
    }

    return line;
}

int run_case()
{
    int *lineA = parse_grid();
    int *lineB = parse_grid();

    //cout << "Line A: " << lineA[0] << lineA[1] << lineA[2] << lineA[3] << "\n";
    //cout << "Line B: " << lineB[0] << lineB[1] << lineB[2] << lineB[3] << "\n";

    // Calculate and return result
    int res = intersect(lineA, lineB);

    delete [] lineA;
    delete [] lineB;
    return res;
}

int main()
{
    int n_cases = 0;
    int n_case  = 0;

    in.open("A-small-attempt0.in");

    if (!in.is_open() || !in.good())
    {
        cerr << "Could not open input file!\n";
        return 1;
    }

    out.open("output.txt", ofstream::trunc);

    if (!out.is_open() || !out.good())
    {
        cerr << "Could not open output file!\n";
        return 2;
    }

    //int arr[] = {1,2,3,4};
    //cout << "isIn: " << isIn(1, arr) << "\n";
    //int arr2[] = {-1,20,30,40};
//    cout << "intersect: " << intersect(arr, arr2) << "\n";

    in >> n_cases;

    for (n_case = 1; n_case <= n_cases; n_case++)
    {
        int res = run_case();
        out << "Case #" << n_case << ": ";
        if (res > 0 && res < 17)
            out << res << "\n";
        else if (res == 18)
            out << "Bad magician!\n";
        else if (res == 19)
            out << "Volunteer cheated!\n";
        else
            out << "Fatal error. -_- (" << res << ")\n";
    }

    in.close();




    return 0;
}

/*    std::string line;

    std::getline(in, line);
    std::stringstream stream(line);

    if (!in.good())
        return false;

    std::string trash, local, remote;
    stream >> trash >> local >> remote;*/
