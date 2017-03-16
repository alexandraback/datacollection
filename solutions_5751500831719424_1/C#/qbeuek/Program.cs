using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace repeater
{
    class Program
    {
        class Span
        {
            public char Letter;
            public int Length;
        }

        static void Main(string[] args)
        {
            using (var inputStream = new StreamReader(@"..\..\input.txt"))
            using (var outputStream = new StreamWriter(@"..\..\output.txt"))
            {
                var caseCount = int.Parse(inputStream.ReadLine());
                for (var caseNumber = 1; caseNumber <= caseCount; caseNumber++)
                {
                    var stringCount = int.Parse(inputStream.ReadLine());
                    var strings = new List<string>();
                    for (var i = 0; i < stringCount; i++)
                        strings.Add(inputStream.ReadLine());

                    var spans = new List<List<Span>>();
                    foreach (var input in strings)
                    {
                        var output = new List<Span>();
                        Span current = null;
                        foreach (var letter in input)
                        {
                            if (current == null)
                            {
                                current = new Span();
                                current.Letter = letter;
                                current.Length = 0;
                            }
                            if (current.Letter == letter)
                                current.Length++;
                            else
                            {
                                output.Add(current);
                                current = new Span();
                                current.Letter = letter;
                                current.Length = 1;
                            }
                        }
                        if (current != null)
                            output.Add(current);
                        spans.Add(output);
                    }

                    var count = spans[0].Count;
                    var broken = false;
                    foreach (var span in spans)
                    {
                        if (count != span.Count)
                        {
                            broken = true;
                            break;
                        }
                    }

                    for (var i = 0; i < count; i++)
                    {
                        if (broken)
                            break;
                        var letter = spans[0][i].Letter;
                        foreach (var span in spans)
                        {
                            if (letter != span[i].Letter)
                            {
                                broken = true;
                                break;
                            }
                        }
                    }

                    if (broken)
                    {
                        outputStream.WriteLine("Case #{0}: Fegla Won", caseNumber);
                        continue;
                    }
                    else
                    {
                        var result = 0;
                        for (var i = 0; i < count; i++)
                        {
                            var minimumChanges = int.MaxValue;
                            var minCount = spans.Min(s => s[i].Length);
                            var maxCount = spans.Max(s => s[i].Length);
                            for (var j = minCount; j <= maxCount; j++)
                            {
                                var changes = 0;
                                foreach (var span in spans)
                                {
                                    changes += Math.Abs(span[i].Length - j);
                                }
                                if (changes < minimumChanges)
                                    minimumChanges = changes;
                            }
                            result += minimumChanges;
                        }
                        outputStream.WriteLine("Case #{0}: {1}", caseNumber, result);
                    }
                }
            }
        }
    }
}
