import java.awt.Point;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;

public class Log {
  
  static Reader sc = new Reader();
  static PrintWriter out = new PrintWriter(System.out);
  
  public static void main(String[] args) throws IOException {
    int t = sc.nextInt();
    
    for (int cas = 1; cas <= t; cas++) {
      int n = sc.nextInt();
      
      Point[] points = new Point[n];
      
      for (int i = 0; i < n; i++) {
        points[i] = new Point(sc.nextLong(), sc.nextLong());
      }
      
      int[] minCuts = new int[n];
      Arrays.fill(minCuts, 1000);
      
      for (int mask = 0; mask < (1 << n); mask++) {
        
        ArrayList<Point> set = new ArrayList<Point>();
        
        int nonCut = 0;
        for (int bit = 0; bit < n; bit++) {
          if( (mask & (1 << bit)) != 0) {
            Point cur = points[bit];
            set.add(cur);
            nonCut++;
          }
        }
        
        int treesCut = n - nonCut;
        
        ArrayList<Point> hull = convexHull(set);
        
        for (int i = 0; i < n; i++) {
          if ((mask & (1 << i)) != 0) {
            for (Point cur : hull) {
              if (cur.eq(points[i])) {
                minCuts[i] = Math.min(minCuts[i], treesCut);
              }
            }
          }
        }
      }
      
      out.println("Case #" + cas + ":");
      for (int i = 0; i < n; i++) {
        out.println(minCuts[i]);
      }
    }
    

    
    out.close();
  }
  
  public static ArrayList<Point> convexHull(ArrayList<Point> p) {
    int n = p.size();
    if (n <= 1)
      return p;
    Collections.sort(p, new Comparator<Point>() {
      @Override
      public int compare(Point o1, Point o2) {
        int sx = (int) Math.signum(o1.x - o2.x);
        return sx != 0 ? sx : (int) Math.signum(o1.y - o2.y);
      }
    });
    Point[] q = new Point[n * 2];
    int cnt = 0;
    for (int i = 0; i < n; q[cnt++] = p.get(i++))
      for (; cnt > 1 && !cw(q[cnt - 2], q[cnt - 1], p.get(i)); --cnt)
        ;
    for (int i = n - 2, t = cnt; i >= 0; q[cnt++] = p.get(i--))
      for (; cnt > t && !cw(q[cnt - 2], q[cnt - 1], p.get(i)); --cnt)
        ;
    ArrayList<Point> res = new ArrayList<Point>();
    int len = cnt - 1 - (q[0].eq(q[1]) ? 1 : 0);
    for (int i = 0; i < len; ++i)
      res.add(q[i]);
    return res;
  }

  static boolean cw(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) <= 0;
  }
  
  static class Point implements Comparable<Point> {
    long x, y;
    
    public boolean eq(Point p) {
      return Math.abs(x - p.x) == 0 && Math.abs(y - p.y) == 0;
    }

    public Point(long x, long y) {
      this.x = x;
      this.y = y;
    }

    @Override
    public int compareTo(Point o) {
      if (cmp(y, o.y) != 0)
        return cmp(y, o.y);
      return cmp(x, o.x);
    }

    public Point sub(Point a){
      return new Point(x - a.x,y - a.y);
    }

    public Point add(Point a){
      return new Point(x + a.x,y + a.y);
    }

    public double cross(Point a){
      return x*a.y - y*a.x;
    }

    @Override
    public String toString() {
      return "(" + x + ", " + y + ")";
    }   
  }
  static int cmp(long a, long b) {
    if (a - b == 0)
      return 0;
    return Long.compare(a, b);
  }
  
  static class Reader {
    final private int BUFFER_SIZE = 1 << 12; private byte[] buffer; private int bufferPointer, bytesRead; private boolean eof = false;
    public Reader() {buffer = new byte[BUFFER_SIZE];bufferPointer = bytesRead = 0;}
    public boolean reachedEOF() {return eof;}
    private void fillBuffer() throws IOException {bytesRead = System.in.read(buffer, bufferPointer = 0, BUFFER_SIZE); if (bytesRead == -1) { buffer[0] = -1;eof = true;}}
    private byte read() throws IOException {if (bufferPointer == bytesRead)fillBuffer();return buffer[bufferPointer++];}
    public String next() throws IOException {StringBuilder sb = new StringBuilder();byte c;while ((c = read()) <= ' ') {if (c == -1)return null;};do {sb.append((char) c);} while ((c = read()) > ' ');if (sb.length() == 0)return null;return sb.toString();}
    public String nextLine() throws IOException {StringBuilder sb = new StringBuilder();byte c;boolean read = false;while ((c = read()) != -1) {if (c == '\n') {read = true;break;}if (c >= ' ')sb.append((char) c);}if (!read)return null;return sb.toString();}
    public int nextInt() throws IOException {int ret = 0;byte c = read();while (c <= ' ')c = read();boolean neg = (c == '-');if (neg)c = read();do {ret = ret * 10 + c - '0';} while ((c = read()) >= '0' && c <= '9');if (neg)return -ret;return ret;}
    public long nextLong() throws IOException {long ret = 0;byte c = read();while (c <= ' ')c = read();boolean neg = (c == '-');if (neg)c = read();do {ret = ret * 10L + c - '0';} while ((c = read()) >= '0' && c <= '9');if (neg)return -ret;return ret;}
    public double nextDouble() throws IOException {double ret = 0, div = 1;byte c = read();while (c <= ' ')c = read();boolean neg = (c == '-');if (neg)c = read();do {ret = ret * 10 + c - '0';} while ((c = read()) >= '0' && c <= '9');if (c == '.')while ((c = read()) >= '0' && c <= '9')ret += (c - '0') / (div *= 10);if (neg)return -ret;return ret;}
    public int[] nextIntArrray(int n) throws IOException {int[] a = new int[n];for (int i = 0; i < n; i++)a[i] = nextInt();return a;}
    public int[][] nextIntMatrix(int n, int m) throws IOException {int[][] map = new int[n][m];for (int i = 0; i < n; i++)map[i] = nextIntArrray(m);return map;}
    public char[][] nextCharacterMatrix(int n) throws IOException {char[][] a = new char[n][];for (int i = 0; i < n; i++)a[i] = next().toCharArray();return a;}
    public void close() throws IOException {if (System.in == null)return;System.in.close();}
  }
  
  static void print(int[] A) {for(int i=0;i<A.length;i++){if(i!=0) out.print(' ');out.print(A[i]);}out.println();}
  static <T> void print(Iterable<T> A) {int i = 0;for(T act : A){if(i!=0)out.print(' ');out.print(act);i++;}out.println();}
  static void printPlus1(Iterable<Number> A) {int i = 0;for(Number act : A){if(i!=0)out.print(' ');out.print(act.longValue() + 1L);i++;}out.println();}
  static void debug(Object... o) { System.err.println(Arrays.deepToString(o)); }
  
  /*
  long s = System.currentTimeMillis();
  debug(System.currentTimeMillis()-s+"ms");
   */
}
