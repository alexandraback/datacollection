using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ
{
    public class Scanner : System.IO.StringReader
    {
        public Scanner(string src) : base(src) { }
        public Scanner(string[] src) : this(string.Join(" ", src)) { }
        public int ReadInt()
        {
            int val = 0;
            int next = this.Read();
            if (next < 0)
                throw new Exception("Invalid char");
            while (char.IsWhiteSpace((char)next))
            {
                next = this.Read();
                if (next < 0)
                    throw new Exception("Invalid char");
            }
            for (; next >= 0 && !char.IsWhiteSpace((char) next); next = this.Read())
            {
                char nextChar = (char)next;
                if (nextChar < '0' || nextChar > '9')
                    throw new Exception("Invalid char");
                val *= 10;
                val += (nextChar - '0');
            }
            return val;
        }
        public int ReadDigit()
        {
            int next = this.Read();
            if (next < 0)
                throw new Exception("Invalid char");
            while (char.IsWhiteSpace((char)next))
            {
                next = this.Read();
                if (next < 0)
                    throw new Exception("Invalid char");
            }
            char nextChar = (char)next;
            if (nextChar < '0' || nextChar > '9')
                throw new Exception("Invalid char");
            return (int)(nextChar - '0');
        }
    }
}
