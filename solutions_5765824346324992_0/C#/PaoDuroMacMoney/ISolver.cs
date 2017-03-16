using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B
{
    interface ISolver
    {
        String Solve(StreamReader v_Reader);
    }
}
