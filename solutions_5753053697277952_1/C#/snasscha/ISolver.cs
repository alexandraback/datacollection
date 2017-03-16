using System.IO;

namespace GoogleCodeJam
{
    public interface ISolver
    {
        string Solve(StreamReader fileReader);
    }
}