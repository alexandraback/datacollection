// Magic Trick
import java.util.Scanner;
import java.util.Arrays;

public class ProblemA
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);

        int t = in.nextInt();
        for(int i = 0; i < t; i++)
        {
            int q1 = in.nextInt();
            int[][] arr1 = new int[5][5];
            for(int r = 1; r <= 4; r++)
            {
                for(int c = 1; c <= 4; c++)
                {
                    arr1[r][c] = in.nextInt();
                }
            }
            
            int q2 = in.nextInt();
            int[][] arr2  = new int[5][5];
            for(int r = 1; r <= 4; r++)
            {
                for(int c = 1; c <= 4; c++)
                {
                    arr2[r][c] = in.nextInt();
                }
            }

            int[] nums = new int[17];
            Arrays.fill(nums, 0);
            for(int c = 1; c <= 4; c++)
            {
                nums[arr1[q1][c]]++;
                nums[arr2[q2][c]]++;
            }

            int matches = 0;
            int ind = -1;
            for(int j = 1; j < nums.length; j++)
            {
                if(nums[j] == 2)
                {
                    matches++;
                    ind = j;
                }
            }

            System.out.printf("Case #%d: ", i + 1);
            if(matches == 0)
                System.out.printf("Volunteer cheated!\n");
            else if(matches == 1)
                System.out.printf("%d\n", ind);
            else
                System.out.printf("Bad magician!\n");
        }

        in.close();
    }
}
