import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;

public class SenateEasy {
  
  static Reader sc = new Reader();
  static PrintWriter out = new PrintWriter(System.out);
  
  public static void main(String[] args) throws IOException {
    int t = sc.nextInt();
    
    for (int cas = 1; cas <= t; cas++) {
      int n = sc.nextInt();
      
      LinkedList<LinkedList<Character>> res = new LinkedList<LinkedList<Character>>();
      int[] nums = sc.nextIntArrray(n);
      
      Integer count = 0;
      for (int i = 0; i < n; i++) {
        count += nums[i];
      }
      
      out.print("Case #" + cas + ": ");
      get(nums, count, res, n);
      out.println();
      
    }
    
    out.close();
  }
  
  static boolean get(int[] nums, Integer count, LinkedList<LinkedList<Character>> res,int n) {
    if (count == 0) {
      int printed = 0;
      for (LinkedList<Character> list : res) {
        if (printed != 0) {
          out.print(" ");
        }
        String cur = "";
        for (char c : list) {
          cur += c;
        }
        printed++;
        out.print(cur);
      }
      return true;
    }
    
    for (int i = 0; i < n + 1; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0 && j == 0) {
          continue;
        }
        
        boolean bad = false;
        
        if (i > 0) {
          nums[i - 1]--;
          count--;
          if (nums[i - 1] < 0) {
            bad = true;
          }
        }
        if (j > 0) {
          nums[j - 1]--;
          count--;
          if (nums[j - 1] < 0) {
            bad = true;
          }
        }
        
        if (!bad) {
          for (int k = 0; k < n; k++) {
            if (nums[k] > count / 2) {
              bad = true;
              break;
            }
          }
        }
        
        if (bad) {
          if (i > 0) {
            nums[i - 1]++;
            count++;
          }
          if (j > 0) {
            nums[j - 1]++;
            count++;
          }
          continue;
        }
        
        LinkedList<Character> list = new LinkedList<Character>();
        if (i > 0) {
          list.add((char)('A' + (i - 1)));  
        }
        if (j > 0) {
          list.add((char)('A' + (j - 1)));  
        }
        res.add(list);
        boolean done = get(nums, count, res, n);
        
        if (done) {
          return true;
        }
        
        res.removeLast();
        
        if (i > 0) {
          nums[i - 1]++;
          count++;
        }
        if (j > 0) {
          nums[j - 1]++;
          count++;
        }
        
      }
    }
    
    return false;
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
