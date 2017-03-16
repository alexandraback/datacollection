import java.util.*;

/**
 *
 * @author rahuljaisingh
 */
public class cj {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for(int i = 1; i <= T; i++)
        {
            System.out.print("Case #" + i + ": ");
            int N = sc.nextInt();
            int[] A = new int[N];
            for(int j = 0; j < N; j++)
            {
                A[j] = sc.nextInt();
            }
            solve(A);
        }
            
    }
    public static void solve (int[] A)
    {
        int id1 = -1, id2 = -1;
        int max = 0;
        for(int i = 0; i < A.length; i++)
        {
            if(A[i] > max)
            {
                max = A[i];
                id1 = i;
            }
        }
        if(max == 0)
        {
            System.out.println();
            return;
        }
        int sum = 0;
        for(int i = 0; i < A.length; i++)
        {
            sum += A[i];
        }
        if(max != 1 || sum != 3)
        {
            for(int j = 0; j < A.length; j++)
            {
                if(A[j] == max && j != id1)
                {
                    id2 = j;
                }
            }
        }
        System.out.print((char)(65 + id1));
        A[id1]--;
        if(id2 != -1)
        {
            System.out.print((char)(65 + id2));
            A[id2]--;
        }
        for(int i = 0; i < A.length; i++)
        {
            if(A[i] != 0)
            {
                System.out.print(" ");
                solve(A);
                return;
            }
        }
        System.out.println();
    }
}