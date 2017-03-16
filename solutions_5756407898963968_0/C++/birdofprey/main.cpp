#include <QFile>
#include <QtGlobal>
#include <QTextStream>

#include <iostream>

// #define STDOUT

QTextStream input;

#ifndef STDOUT
    QTextStream output;
#else
    std::ostream &output = std::cout;
#endif

void SolveCase()
{
    int row1, row2, cards1[4][4], cards2[4][4];
    input >> row1;
    for(int r = 0; r < 4; ++r)
        for(int c = 0; c < 4; ++c)
            input >> cards1[r][c];
    input >> row2;
    for(int r = 0; r < 4; ++r)
        for(int c = 0; c < 4; ++c)
            input >> cards2[r][c];
    int answer = -1;
    --row1; --row2;
    for(int A1 = 0; (A1 < 4) && (answer >= -1); ++A1) {
        for(int A2 = 0; A2 < 4; ++A2) {
            if(cards1[row1][A1] == cards2[row2][A2]) {
                if(answer == -1) answer = cards1[row1][A1];
                else answer = -2;
                break;
            }
        }
    }
    if(answer > 0) output << answer << '\n';
    else if(answer == -2) output << "Bad magician!\n";
    else output << "Volunteer cheated!\n";
}

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    QFile infile("input.txt");
    infile.open(QIODevice::ReadOnly);
    input.setDevice(&infile);

#   ifndef STDOUT
        QFile outfile("output.txt");
        outfile.open(QIODevice::WriteOnly);
        output.setDevice(&outfile);
#   endif

    uint T; input >> T;
    for(uint t = 1; t <= T; ++t)
    {
        output << "Case #" << t << ": ";
        SolveCase();
    }

    return 0;
}
