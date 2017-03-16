import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;


public class SenateEvacuation {
  public static void main(String[] args)
  {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    PrintWriter out = new PrintWriter(outputStream);
    SenateEvacuation solver = new SenateEvacuation();
    solver.solve(1, new InputStreamReader(inputStream), out);
    out.close();
  }
  
  static class Pair implements Comparable<Pair> {
    int first;

    int second;

    Pair(int f, int s)
    {
      first = f;
      second = s;
    }

    public int compareTo(Pair o)
    {
      int r = -(first - o.first);

      if(r == 0)
        r = second - o.second;

      return r;
    }

    @Override
    public boolean equals(Object obj)
    {
      Pair o = (Pair)obj;
      return this.compareTo(o) == 0;
    }

    @Override
    public int hashCode()
    {
      return first * 101 + second;
    }

    @Override
    public String toString()
    {
      return "Pair(" + first + "," + second + ")";
    }
  }


  public void solve(int test, Reader input, PrintWriter out)
  {
    MyScanner in = new MyScanner(input);
    
    int T = in.nextInt();
    
    for(int t = 1; t <= T; t++) {
      int N = in.nextInt();
      
      PriorityQueue<Pair> pq = new PriorityQueue<>();
      int sum = 0;
      for(int i = 0; i < N; i++) {
        Pair p = new Pair(in.nextInt(), i);
        sum += p.first;
        pq.add(p);
      }

      ArrayList<String> res = new ArrayList<>();
      
      while(!pq.isEmpty()) {
        Pair p = pq.poll();
        char a = (char)(65 + p.second);
        p.first--;
        sum -= 1;
        if(p.first > 0)
          pq.add(p);
        int maj = 0;
        if(pq.size() > 0)
          maj = (sum  + pq.size() - 1) / pq.size();
        p = pq.peek();
        char b = 0;
        if(p != null && p.first == maj) {
          if(pq.size() != 2 || p.first != 1) {
            p = pq.poll();
            p.first--;
            if(p.first > 0)
              pq.add(p);
            sum -= 1;
            b = (char)(65 + p.second);
          }
        }
        if(b != 0)
          res.add("" + a + b);
        else
          res.add("" + a);
      }
      out.printf("Case #%d:", t);
      for(String r : res)
        out.printf(" %s", r);
      out.println();
    }

  }

  //-----------MyScanner class for faster input----------
  public static class MyScanner {
    BufferedReader br;

    StringTokenizer st;

    public MyScanner(Reader reader)
    {
      br = new BufferedReader(reader);
    }

    String next()
    {
      while(st == null || !st.hasMoreElements()) {
        try {
          st = new StringTokenizer(br.readLine());
        }
        catch(IOException e) {
          e.printStackTrace();
        }
      }
      return st.nextToken();
    }

    String rest()
    {
      StringBuilder res = new StringBuilder();
      while(st != null && st.hasMoreTokens()) {
        res.append(st.nextToken());
        if(st.hasMoreTokens())
          res.append(' ');
      }
      return res.toString();
    }

    int nextInt()
    {
      return Integer.parseInt(next());
    }

    int[] nextIntArray(int n)
    {
      int[] r = new int[n];
      for(int i = 0; i < n; i++)
        r[i] = nextInt();
      return r;
    }

    long nextLong()
    {
      return Long.parseLong(next());
    }

    double nextDouble()
    {
      return Double.parseDouble(next());
    }

    String nextLine()
    {
      String str = "";
      try {
        str = br.readLine();
      }
      catch(IOException e) {
        e.printStackTrace();
      }
      return str;
    }

  }
  //--------------------------------------------------------
}
