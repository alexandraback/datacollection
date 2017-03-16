using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CJ2014_The_Repeater
{
    class Program
    {
        static void Main(string[] args)
        {
            //List<string> test = new List<string>(new string[] { "aaa", "a", "aa" });
            //test.Sort(new LenghtComparer());
            //Console.WriteLine(new LenghtComparer().Compare("aaaa", "a"));

            //Environment.Exit(0);

            string fileName = "A-large";

            StreamReader sr = new StreamReader(fileName + ".in");
            int T = Convert.ToInt32(sr.ReadLine());

            StreamWriter sw = new StreamWriter(fileName + ".out");

            for (int t = 0; t < T; t++)
            {
                int stringCount = Convert.ToInt32(sr.ReadLine());

                List<StringWithMeta> stringList = new List<StringWithMeta>();

                for (int i = 0; i < stringCount; i++)
                {
                    stringList.Add(new StringWithMeta( sr.ReadLine()));
                }

                bool canBeDone = true;

                string minimalString = null;

                for (int i = 0; i < stringList.Count && canBeDone; i++)
                {
                    string currentMinimalString = stringList[i].value[0].ToString();

                    for (int j = 1; j < stringList[i].value.Length; j++)
                    {
                        if (stringList[i].value[j] != currentMinimalString[currentMinimalString.Length - 1])
                        {
                            currentMinimalString += stringList[i].value[j];
                        }
                    }

                    if (minimalString == null)
                    {
                        minimalString = currentMinimalString;
                    }

                    else if (minimalString != currentMinimalString)
                    {
                        canBeDone = false;
                    }
                }

                string output = "Fegla Won";

                if (canBeDone)
                {
                    //    string goalString = stringList[(int)Math.Floor((float)(stringList.Count / 2))];

                    //    List<char> goalStringMeta = new List<char>(new char[] { goalString[0] });
                    //    List<int> goalStringMetaCount = new List<int>(new int[] { 1 });

                    //    for (int i = 1; i < goalString.Length; i++)
                    //    {
                    //        while (i < goalString.Length && goalString[i] == goalStringMeta[goalStringMeta.Count - 1])
                    //        {
                    //            goalStringMetaCount[goalStringMetaCount.Count - 1]++;
                    //            i++;
                    //        }

                    //        if (i < goalString.Length)
                    //        {
                    //            goalStringMeta.Add(goalString[i]);
                    //            goalStringMetaCount.Add(1);
                    //        }
                    //    }

                    int neededSteps = 0;

                    foreach (StringWithMeta currentString in stringList)
                    {
                        List<char> currentStringMeta = new List<char>(new char[] { currentString.value[0] });
                        List<int> currentStringMetaCount = new List<int>(new int[] { 1 });

                        for (int i = 1; i < currentString.value.Length; i++)
                        {
                            while (i < currentString.value.Length && currentString.value[i] == currentStringMeta[currentStringMeta.Count - 1])
                            {
                                currentStringMetaCount[currentStringMetaCount.Count - 1]++;
                                i++;
                            }

                            if (i < currentString.value.Length)
                            {
                                currentStringMeta.Add(currentString.value[i]);
                                currentStringMetaCount.Add(1);
                            }
                        }

                        currentString.meta = currentStringMeta;
                        currentString.metaCount = currentStringMetaCount;
                    }

                    List<int> goalStringMetaCount = new List<int>();
                    for (int i = 0; i < minimalString.Length; i++)
                    {
                        stringList.Sort((a, b) => a.metaCount[i].CompareTo(b.metaCount[i])); //stringMetaCountList[stringList.IndexOf(a)][i].CompareTo(stringMetaCountList[stringList.IndexOf(b)][i]));
                        goalStringMetaCount.Add(stringList[(int)Math.Floor((float)(stringList.Count / 2))].metaCount[i]);
                    }

                    foreach (StringWithMeta currentString in stringList)
                    {
                        for (int i = 0; i < goalStringMetaCount.Count; i++)
                        {
                            neededSteps += Math.Abs(currentString.metaCount[i] - goalStringMetaCount[i]);
                        }
                    }

                    output = neededSteps.ToString();
                }

                sw.WriteLine("Case #{0}: {1}", t + 1, output);
            }

            sw.Close();
        }

        public class StringWithMeta
        {
            public string value;
            public List<char> meta;
            public List<int> metaCount;

            public StringWithMeta(string value)
            {
                this.value = value;
            }
        }

        //class LenghtComparer : IComparer<string>
        //{
        //    public int Compare(string a, string b)
        //    {
        //        return a.Length.CompareTo(b.Length);

        //        //if (a.Length < b.Length)
        //        //{
        //        //    return -1;
        //        //}

        //        //if (a.Length > b.Length)
        //        //{
        //        //    return 1;
        //        //}

        //        //return 0;
        //    }
        //}
    }
}