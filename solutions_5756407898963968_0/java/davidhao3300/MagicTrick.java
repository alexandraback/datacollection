import java.util.*;
import java.io.*;
public class MagicTrick {
    public static void main(String[] args) throws IOException
    {
        Scanner in = new Scanner(new BufferedReader(new FileReader("input.in")));
        PrintWriter out = new PrintWriter(new FileWriter("output.txt"));
        int cases = in.nextInt();
        for (int i = 1; i <= cases; i++)
        {
            ArrayList<Integer> results = new ArrayList<Integer>();
            ArrayList<Integer> pos = new ArrayList<Integer>();
            for (int x = 0; x < 2; x++)
            {
                int row = in.nextInt()-1;
                //System.out.println(row);
                int[][] cards = new int[4][4];
                
                for (int j = 0; j < 4; j++)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        cards[j][k] = in.nextInt();
                        if (row == j) 
                        {
                            //System.out.print(cards[j][k]+" ");
                            if (x == 0) pos.add(cards[j][k]);
                            else
                            {
                                if(pos.contains(cards[j][k]))
                                {
                                    results.add(cards[j][k]);
                                }
                            }
                        }
                    }
                }
                //if (x==0)System.out.println("Pos:"+pos);
            }
            //System.out.println(results);
            if(results.isEmpty())
            {
                out.printf("Case #%d: Volunteer cheated!\n", i);
            }
            else if (results.size() == 1)
            {
                out.printf("Case #%d: %d\n", i, results.get(0));
            }
            else
            {
                out.printf("Case #%d: Bad magician!\n", i);
            }
        }
        
        out.close();
    }
}
