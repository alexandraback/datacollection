import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class Barber {
  
  static Reader sc = new Reader();
  static PrintWriter out = new PrintWriter(System.out);
  
  public static void main(String[] args) throws IOException {
    int t = sc.nextInt();
    
    for (int cas = 1; cas <= t; cas++) {
      int b = sc.nextInt();
      long n = sc.nextLong();
      
      long[] times = new long[b];
      
      for (int i = 0; i < b; i++) {
        times[i] = sc.nextLong();
      }
      
      long left = 0;
      long right = Long.MAX_VALUE / 3L; ////**************************
      long mid = (left + right) / 2L;
      
      while (right - left > 1) {
        long count = countWorFinish(times, mid);
        //long free = countFree(times, mid);
        if (count >= n) {
          right = mid;
        } else {
          left = mid;
        }
        mid = (left + right) / 2L;
      }
      
      long countFinal = countWorFinish(times, left);
//      if (countFinish(times, right) == n) {
//        countFinal = countFinish(times, left);
//      }
      
      out.println("Case #" + cas + ": " + lowerFree(times, left, n, countFinal));  
    }
    
    out.close();
  }
  
  static long countFree(long[] times, long time) {
    long count = 0;    
    for (int i = 0; i < times.length; i++) {
      if (time % times[i] == 0) {
        count++;
      }
    }
    return count;
  }
  
  static long countFinish(long[] times, long time) {
    long count = 0;
    
    for (int i = 0; i < times.length; i++) {
        count += time / times[i];
    }
    return count;
  }
  static long countWorFinish(long[] times, long time) {
    long count = 0;
    
    for (int i = 0; i < times.length; i++) {
      if ( time % times[i] == 0) {
        count += time / times[i];
      } else {
        count += time / times[i] + 1;
      }
    }
    return count;
  }
  
  static int lowerFree(long[] times, long time, long n, long count) {
    long toSkip = (int)(n - count - 1);
    int lower = 0;
    for (int i = 0; i < times.length; i++) {
      if (time % times[i] == 0) {
        lower = i + 1;
        toSkip--;
        if (toSkip < 0) {
          break;
        }
      }
    }
    return lower;
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
