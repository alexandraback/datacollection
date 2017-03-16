import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.util.StringTokenizer;

public class B {
    public final static int MODULO = 1000000007;

    public static void main(String[] args)
    {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        PrintWriter out = new PrintWriter(outputStream);
        B solver = new B();
        solver.solve(1, new InputStreamReader(inputStream), out);
        out.close();
    }
    
    static int unhappiness(boolean[][] grid)
    {
      int r = 0;
      
      int R = grid.length;
      int C = grid[0].length;
      
      for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
          if(j < C - 1 && grid[i][j] && grid[i][j+1]) r++;
          if(i < R - 1 && grid[i][j] && grid[i+1][j]) r++;
        }
      }
      return r;
    }

    public void solve(int test, Reader input, PrintWriter out)
    {
        MyScanner in = new MyScanner(input);
        
        int T = in.nextInt();
        
        for(int t = 1; t <= T; t++) {
          int R = in.nextInt();
          int C = in.nextInt();
          int N = in.nextInt();
          int RC = R * C;
          
          int res = 1000000;
          
          boolean[][] grid = new boolean[R][C];
          
          for(int i = 0; i < (1 << RC); i++) {
            if(Integer.bitCount(i) == N) {
              for(int j = 0; j < RC; j++) {
                int r = j / C;
                int c = j % C;
                grid[r][c] = (i & (1 << j)) != 0;
              }
              int u = unhappiness(grid);
//              System.out.println(Integer.toBinaryString(i) + " " + u);
//              for(boolean[] a : grid)
//                System.out.println(Arrays.toString(a));
              res = Math.min(res, u);
            }
          }
//          System.out.println();
          out.printf("Case #%d: %d\n", t, res);
        }
        
    }

    //-----------MyScanner class for faster input----------
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner(Reader reader) {
            br = new BufferedReader(reader);
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine(){
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

    }
    //--------------------------------------------------------

}
