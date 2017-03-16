using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam
{
    public interface Algorithm
    {
        int LinesNeeded { get; }
        object Solve(string[] input);
    }
}
