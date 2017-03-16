import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Map.*;
import java.math.*;
public class PA {
     public static void main(String[] args) throws Exception {
            solveProblem();
        }
        static String readLine(BufferedReader br) throws Exception {
            String line = br.readLine();
            while(line != null && line.trim().length() == 0) 
                   line = br.readLine();
            if(line != null) return line.trim();
            return line;
            
        }
        static class Item implements Comparable<Item> {
            char ch;
            int count;
            public Item(char ch, int count) { this.ch = ch; this.count = count;}
            public int compareTo(Item that) {
              return this.count < that.count ? -1 : this.count == that.count ? 0 : 1;
            }
        }
        public static Item[] get(String row) {
            Item[] result = new Item[100];
            result[0] = new Item(row.charAt(0), 1);
            int j = 0;
            for(int i = 1; i<row.length(); i++) {
               if(row.charAt(i) == result[j].ch) result[j].count++;
               else {
                 j++;
                 result[j] = new Item(row.charAt(i), 1);
               }
            } 
            return result;                
        }

        public static String solve(int N, String[] rows) {
            Item[][] result = new Item[N][100];
            for(int i = 0; i<N; i++) result[i] = get(rows[i]);
            int count  = 0;
            for(int i = 0; i<100; i++) {
               Item current = result[0][i];
               for(int j = 1; j<N; j++) {
                 Item next = result[j][i];
                 if(current == null && next == null) continue;
                 else if(current == null || next == null) return "Fegla Won";
                 else {
                   if(current.ch != next.ch) return "Fegla Won";
                 }
               }
               if(current == null) break;
               Item[] tmp = new Item[N];
               for(int j = 0; j<N; j++) tmp[j] = result[j][i];
               Arrays.sort(tmp);
               int mid = N/2;
               for(int j = 0; j<N; j++) {
                 count += Math.abs(tmp[j].count - tmp[mid].count);
               } 
            }
            return "" + count;            
        } 

        public static void solveProblem() throws Exception {
            final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringBuffer sb = new StringBuffer();
            String line = readLine(br);
            int T = Integer.parseInt(line);
            for(int i = 1; i<=T; i++) {
               int N = Integer.parseInt(readLine(br));
               String[] rows = new String[N];
               for(int j = 0; j<N; j++) {
                 rows[j] = readLine(br);
               }
               String result = solve(N, rows);
               sb.append("Case #" + i + ": " + result + "\n");
            }
            System.out.print(sb.toString());
        }
}
