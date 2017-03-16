using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ProblemB
{
    class Program
    {
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            var caseCount = int.Parse(Console.ReadLine());
            for (var caseNumber = 1; caseNumber <= caseCount; caseNumber++)
            {
                var line = Console.ReadLine().Split(' ').Select(int.Parse).ToList();
                var rowCount = line[0];
                var columnCount = line[1];
                var tenantCount = line[2];
                var score = GetScore(rowCount, columnCount, tenantCount);
                Console.WriteLine("Case #{0}: {1}", caseNumber, score);
            }
        }

        static int GetScore(int rowCount, int columnCount, int tenantCount)
        {
            if (rowCount == 1)
            {
                if (columnCount % 2 == 1)
                    return GetScore(columnCount / 2, 2, columnCount / 2 - 1, 0, tenantCount);
                return GetScore(columnCount / 2, 1, columnCount / 2, 0, tenantCount);
            }

            if (columnCount == 1)
                return GetScore(columnCount, rowCount, tenantCount);

            var cellCount = rowCount * columnCount;

            if ((columnCount % 2 == 1) && (rowCount % 2 == 1))
            {
                return Math.Min(
                    GetScore((cellCount + 1) / 2, 0, 0, (columnCount / 2) * 2 + (rowCount / 2) * 2, tenantCount),
                    GetScore(cellCount / 2, 0, 4, (columnCount / 2 - 1) * 2 + (rowCount / 2 - 1) * 2, tenantCount));
            }
            else
            {
                return GetScore(cellCount / 2, 0, 2, rowCount + columnCount, tenantCount);
            }
        }

        static int GetScore(int chessCount, int tipCount, int cornerCount, int sideCount, int tenantCount)
        {
            var score = 0;
            if (tenantCount <= chessCount)
                return score;
            var restTenantCount = tenantCount - chessCount;

            if (restTenantCount <= tipCount)
            {
                score += restTenantCount;
                return score;
            }
            score += tipCount;
            restTenantCount -= tipCount;

            if (restTenantCount <= cornerCount)
            {
                score += restTenantCount * 2;
                return score;
            }
            score += cornerCount * 2;
            restTenantCount -= cornerCount;

            if (restTenantCount <= sideCount)
            {
                score += restTenantCount * 3;
                return score;
            }
            score += sideCount * 3;
            restTenantCount -= sideCount;

            score += restTenantCount * 4;
            return score;
        }
    }
}
