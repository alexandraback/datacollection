import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;

public class main {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static PrintWriter pw = new PrintWriter(System.out);
    public static String line;
    public static StringTokenizer st;
    public static ArrayList<ArrayList<Integer>> adjList;
    public static int[] dr = {-1, 0, 1, 0, -1, 1, 1, -1};
    public static int[] dc = {0, 1, 0, -1, 1, 1, -1, -1};

    public static void main(String[] args) throws Exception{
        int T = Integer.parseInt(br.readLine());
        int cases = 0;
        while(T-- != 0){
            pw.format("Case #%d:", ++cases);
            int N = Integer.parseInt(br.readLine());
            char c = 'A';
            PriorityQueue<Party> PQ = new PriorityQueue<Party>();
            st = new StringTokenizer(br.readLine());
            int total = 0;
            for(int i = 0; i < N; i++){
                int n = Integer.parseInt(st.nextToken());
                total += n;
                PQ.add(new Party(n, c++));
            }

            while(!PQ.isEmpty()){
                // System.out.println(PQ);
                pw.print(" ");
                String out = "";
                Party a = PQ.poll();
                out += String.valueOf(a.c);
                a.n -= 1; total--;
                if(a.n > 0){
                    PQ.add(a);
                }

                if(!PQ.isEmpty()){
                    Party b = PQ.poll();
                    if(b.n > total/2){
                        out += String.valueOf(b.c);
                        b.n--;
                        total--;
                    }
                    if(b.n > 0){
                        PQ.add(b);
                    }
                }
                pw.print(out);
            }
            pw.print("\n");
            // System.out.println();
        }

        pw.close();
        br.close();
    }
}

class Party implements Comparable<Party>{
    public int n;
    public char c;

    Party(int n, char c){
        this.n = n;
        this.c = c;
    }

    @Override
    public int compareTo(Party P){
        if(P.n != this.n){
            return P.n - this.n;
        } else{
            return (int)c - (int)P.c;
        }
    }

    public String toString(){
        return String.valueOf(c) + " " + String.valueOf(n);
    }
}
