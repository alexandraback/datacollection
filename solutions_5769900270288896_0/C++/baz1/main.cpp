#include <QtCore>
#include <stdio.h>

QString computeCase(QTextStream &in)
{
    int R, C, N, easy, r, result = 0;
    bool odd;
    in >> R >> C >> N;
    easy = R * C;
    odd = (bool) (easy & 1);
    easy = (R * C + 1) >> 1;
    if (N <= easy)
        return "0";
    if ((R <= 2) || (C <= 2))
    {
        if ((R == 1) || (C == 1))
        {
            if (!odd)
                return QString::number(1 + ((N - easy - 1) << 1));
            return QString::number((N - easy) << 1);
        }
        if ((R == 2) || (C == 2))
        {
            r = N - easy;
            if (r <= 2)
                return QString::number(r << 1);
            return QString::number(4 + 3 * (r - 2));
        }
    }
    if ((R == 3) && (C == 3) && (N == 8))
        return "8";
    r = N - easy;
    if (!odd)
    {
        if (r <= 2)
            return QString::number(r << 1);
        r -= 2;
        result += 4;
    }
    easy = odd ? (R + C - 2) : (R + C - 4);
    if (r <= easy)
        return QString::number(result + 3 * r);
    r -= easy;
    result += 3 * easy;
    return QString::number(result + 4 * r);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    if (argc < 2)
    {
        fprintf(stderr, "Error: Missing argument.\n");
        return 1;
    }
    QFile inputFile(argv[1]);
    if (!inputFile.open(QIODevice::ReadOnly))
    {
        fprintf(stderr, "Error: Could not open input file.\n");
        return 1;
    }
    QFile outputFile(QString(argv[1]) + ".out");
    if (!outputFile.open(QIODevice::WriteOnly))
    {
        fprintf(stderr, "Error: Could not open output file.\n");
        inputFile.close();
        return 1;
    }
    int T, i = 0;
    QTextStream input(&inputFile);
    input >> T;
    while (++i <= T)
    {
        QString result = computeCase(input);
        outputFile.write(QString("Case #%1: %2\n").arg(i).arg(result).toUtf8());
    }
    outputFile.close();
    inputFile.close();
    printf("Done.\n");
    return 0;
}
