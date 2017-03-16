using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;

namespace TheRepeater
{
    class Calc
    {
        private List<string> strings;

        public Calc(List<string> strings)
        {
            // TODO: Complete member initialization
            this.strings = strings;
        }

        class CharDesc
        {
            public char C;
            public int Count;
            public override string ToString()
            {
                return "[C=" + C + ";Count=" + Count + "]";
            }
        }

        class StringDesc
        {
            public List<CharDesc> Chars= new List<CharDesc>();
        }

        private StringDesc[] items;

        internal int Calculate()
        {
            items = new StringDesc[strings.Count()];
            for (int cStr=0;cStr<strings.Count();++cStr)
            {
                StringDesc stringDesc = new StringDesc();
                string str = strings[cStr];
                int strPos = 0;
                while (true)
                {
                    if (strPos >= str.Length)
                        break;
                    char curChar = str[strPos];
                    int charCount = 1;
                    ++strPos;
                    while ((strPos<str.Length) && (str[strPos]==curChar))
                    {
                        ++charCount;
                        ++strPos;
                    }
                    stringDesc.Chars.Add(new CharDesc() { C = curChar, Count = charCount });
                }
                items[cStr] = stringDesc;
                if (items[0].Chars.Count != items[cStr].Chars.Count)
                    return -1;

            }
            if (items.Count()!=strings.Count())
            {
                Debugger.Break();
            }
            int sumAll = 0;
            for (int cChar=0;cChar<items[0].Chars.Count();++cChar)
            {
                char thisChar = items[0].Chars[cChar].C;
                List<int> charCounts = new List<int>();
                for (int cStr = 0; cStr < items.Count(); ++cStr)
                {
                    if ((cChar >= items[cStr].Chars.Count()) || (thisChar != items[cStr].Chars[cChar].C))
                        return -1;
                    charCounts.Add(items[cStr].Chars[cChar].Count);
                }
                // find mediana
                charCounts = charCounts.OrderBy(i => i).ToList();
                int medianaPos = charCounts.Count() / 2;
                int medianaVal = charCounts[medianaPos];
                int sumToMediana = 0;
                for (int cCount=0;cCount<charCounts.Count();++cCount)
                {
                    sumToMediana += Math.Abs(charCounts[cCount] - medianaVal);
                }
                sumAll += sumToMediana;
            }
            return sumAll;
        }
    }
}
