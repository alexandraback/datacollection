using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam_Test
{
    public class Program
    {
        public static void Main(string[] args)
        {
            // Einstellungen für kontkretes Problem
            var showResultInOneLine = true;

            // Inputfile suchen
            var file = Directory.GetFiles("../../../WorkingDir", "*.in").FirstOrDefault();
            if (string.IsNullOrEmpty(file)) throw new FileNotFoundException("No Inputfile found");

            var lines = File.ReadAllLines(file);

            // Anzahl der Tests steht immer in der ersten Zeile
            var caseCount = int.Parse(lines[0]);

            // Aufbau eines Tests hat immer gleichviele Inputzeilen (bisher^^)
            var linesPerCase = (lines.Length - 1) / caseCount;

            // Testfälle splitten
            var cases = CreateCases(lines, linesPerCase, caseCount);

            var sbResult = new StringBuilder();

            var counter = 1;
            foreach (var job in cases)
            {
                var result = ExcecuteSingleCase(job, sbResult);

                sbResult.Append("Case #" + counter++ + ":");

                if (showResultInOneLine)
                {
                    sbResult.Append(" " + result);
                }
                else
                {
                    sbResult.AppendLine();
                    sbResult.Append(result);
                }
                sbResult.AppendLine();
            }

            File.WriteAllText(file + ".result", sbResult.ToString());
            new FileInfo(file).MoveTo(file + ".processed");
        }

        public static string ExcecuteSingleCase(string input, StringBuilder sbResult)
        {
            var strings = input.Split(new[] { Environment.NewLine }, StringSplitOptions.None).ToList();

            // Immer erst ein Char

            int result = 0;

            while (strings.Any(x => x.Length > 0))
            {
                var toCompareChar = strings.First(x => x.Length > 0).First();

                var opNum = RearangeStringsForFirstChar(toCompareChar, ref strings); // TODO Ref gut?
                if (opNum == -1) return "Fegla Won";

                result += opNum;
            }

            return result.ToString();
        }

        private static int RearangeStringsForFirstChar(char toCompareChar, ref List<String> strings)
        {
            // Unmögliche raushauen
            foreach (var curString in strings)
            {
                if (curString.Count() == 0 || curString.First() != toCompareChar) return -1;
            }

            var charStrings = CreateStringsWithFirstChar(toCompareChar, strings);

            var result = RearangeCharEqualStrings(charStrings.Select(x => x.Key).ToList());

            // Strings für nächsten charrun anpassen
            strings.Clear();
            strings.AddRange(charStrings.Select(x => x.Value));

            return result;
        }

        private static int RearangeCharEqualStrings(List<string> strings)
        {
            if (strings.Count == 2)
            {
                var res = strings[0].Length - strings[1].Length;
                return res < 0 ? res * -1 : res;  // TODO Richtige Funktion benutzen
            }

            var opList = new List<string>();
            opList.AddRange(strings);

            var result = 0;

            while (opList.Any(x => x.Length > 0))
            {
                result += EqualizeFirstChar(ref opList);
            }

            return result;
        }

        private static int EqualizeFirstChar(ref List<string> opList)
        {
            var hasChars = opList.Count(x => x.Length > 0);

            var result = 0;

            if (hasChars != opList.Count)
            {
                if (hasChars > opList.Count / 2)
                {   // Virtuell Auffüllen
                    result += opList.Count - hasChars;
                }
                else
                {   // Virtuell Abschneiden
                    result += hasChars;
                }
            }

            var copy = new List<string>();
            copy.AddRange(opList);
            opList.Clear();

            opList.AddRange(copy.Select(x => x.Length > 0 ? x.Substring(1) : x));

            return result;
        }

        private static List<KeyValuePair<string, string>> CreateStringsWithFirstChar(char toCompareChar, List<string> strings)
        {
            var result = new List<KeyValuePair<string, string>>();

            foreach (var curString in strings)
            {
                result.Add(CutAllButFirstChars(toCompareChar, curString));
            }

            return result;
        }

        private static KeyValuePair<string, string> CutAllButFirstChars(char toCompareChar, string curString)
        {
            var start = "";

            foreach (var curChar in curString)
            {
                if (curChar != toCompareChar) break;

                start += toCompareChar;
            }

            return new KeyValuePair<string, string>(start, curString.Length == start.Length ? "" : curString.Substring(start.Length));
        }

        private static IEnumerable<String> CreateCases(string[] caseLines, int linesPerCase, int caseCount)
        {
            var curLine = 1; // 1 wegen der Zeile mit der Anzahl der Tests

            for (var i = 0; i < caseCount; i++)
            {
                var curSb = new StringBuilder();

                var lineCount = int.Parse(caseLines[curLine]);
                var count = 0;

                curLine++; // Die Zeile mit der Anzahl überspringen

                do
                {
                    curSb.Append(caseLines[curLine++]);
                    if (++count < lineCount)
                    {
                        curSb.AppendLine();
                    }
                }
                while (count < lineCount);

                yield return curSb.ToString();
            }
        }
    }
}
