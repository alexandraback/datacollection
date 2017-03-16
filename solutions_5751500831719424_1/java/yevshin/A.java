package round1B;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class A
{
        public static void main(String[] args) throws Exception
        {
            BufferedReader reader = new BufferedReader( new InputStreamReader( System.in ) );
            int ntests = Integer.parseInt( reader.readLine() );
            for( int test = 1; test <= ntests; test++ )
            {
                int n = Integer.parseInt( reader.readLine() );
                String[] lines = new String[n];
                for(int i = 0; i < n; i++)
                    lines[i] = reader.readLine();
                System.out.println( "Case #" + test + ": " + solve(lines) );
            }
        }

        private static String solve(String[] lines)
        {
            RLE[][] rle = new RLE[lines.length][];
            for(int i = 0; i < lines.length; i++)
                rle[i] = rle(lines[i]);
            for(int i = 1; i < lines.length; i++)
                if(rle[0].length != rle[i].length)
                    return "Fegla Won";
            int result = 0;
            for(int i = 0; i < rle[0].length; i++)
            {
                for(int j = 1; j < lines.length; j++)
                    if(rle[j][i].letter != rle[0][i].letter)
                        return "Fegla Won";
                
                int best = Integer.MAX_VALUE;
                for(int y = 1; y <= 100; y++)
                {
                    int diff = 0;
                    for(int j = 0; j < lines.length; j++)
                        diff += Math.abs( y - rle[j][i].count );
                    if(diff < best)
                        best = diff;
                }
                result += best;
            }
            return String.valueOf( result );
        }
        
        private static RLE[] rle(String s)
        {
            List<RLE> result = new ArrayList<RLE>();
            int i = 0;
            while( i < s.length() )
            {
                char letter = s.charAt( i );
                int count = 1;
                for(i++; i < s.length() && s.charAt( i ) == letter; i++)
                    count++;
                result.add( new RLE(letter, count) );
            }
            return result.toArray( new RLE[result.size()] );
        }
        
        private static class RLE
        {
            char letter;
            int count;
            public RLE(char letter, int count)
            {
                this.letter = letter;
                this.count = count;
            }
            
        }

}
