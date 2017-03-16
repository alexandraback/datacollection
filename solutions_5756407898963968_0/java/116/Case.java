package problem1;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import com.google.common.collect.Sets;
import com.google.common.collect.Sets.SetView;

/**
 * A test case for the first problem
 * 
 * @author 116@lab0.net
 * 
 */
public class Case
{
    private List<Integer>             rows  = new ArrayList<>(2);
    private List<List<List<Integer>>> grids = new ArrayList<>(2); // y,x
                                                                  
    /**
     * 
     * @param input
     *            row1, grid1, row2, grid2
     */
    public Case(List<String> input)
    {
        for (int i = 0; i < 2; ++i)
        {
            rows.add(Integer.parseInt(input.get(0 + i * 5)));
            grids.add(new ArrayList<List<Integer>>());
            for (int y = 0; y < 4; ++y)
            {
                String[] split = input.get(1 + y + i * 5).split(" ");
                grids.get(i).add(new ArrayList<Integer>(4));
                for (int x = 0; x < 4; ++x)
                {
                    grids.get(i).get(y).add(Integer.parseInt(split[x]));
                }
            }
        }
    }
    
    public String getResult()
    {
        Set<Integer> ints0 = new HashSet<>(grids.get(0).get(rows.get(0)-1));
        Set<Integer> ints1 = new HashSet<>(grids.get(1).get(rows.get(1)-1));
        
        SetView<Integer> res = Sets.intersection(ints0, ints1);
//        System.out.println(rows);
//        System.out.println(res);
        switch (res.size())
        {
            case 0:
                return "Volunteer cheated!";
            case 1:
                return String.valueOf(res.iterator().next());
            default:
                return "Bad magician!";
        }
    }
    
    @Override
    public String toString()
    {
        StringBuilder sb = new StringBuilder();
        for (List<List<Integer>> grid : grids)
        {
            for (List<Integer> row : grid)
            {
                for (int i : row)
                {
                    System.out.printf("%3d", i);
                }
                System.out.println();
            }
            System.out.println();
        }
        
        return sb.toString();
    }
    
}
