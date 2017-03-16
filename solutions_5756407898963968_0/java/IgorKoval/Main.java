import java.io.*;
import java.lang.reflect.Array;
import java.math.BigDecimal;
import java.sql.Time;
import java.util.*;

import java.math.BigInteger;

import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;


public class Main{

    void run(){
        Locale.setDefault(Locale.US);
        boolean oj = System.getProperty("ONLINE_JUDGE") != null;
//        boolean oj = true;
        try{
            if( oj ){
                sc  = new FastScanner( new InputStreamReader(System.in  ) );
                out = new PrintWriter(   new OutputStreamWriter(System.out) );
            } else{
                sc  = new FastScanner(new FileReader("input.txt") );
                out  = new PrintWriter(new FileWriter("C:\\output.txt") );
                //out = new PrintWriter(   new FileWriter("output.txt") );
            }
        } catch (Exception e) {
            MLE();
            System.exit(-1);
        }
        long tB = System.currentTimeMillis();
        solve();
        if( !oj ) System.err.println( "Time: " + (System.currentTimeMillis()-tB)/1e3 );
        out.flush();
    }


    class FastScanner{
        BufferedReader br;
        StringTokenizer st = new StringTokenizer("");
        FastScanner( InputStreamReader a ){
            br = new BufferedReader(a);
        }
        FastScanner( FileReader a ){
            br = new BufferedReader(a);
        }
        String next(){
            while( !st.hasMoreTokens() )
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    return null;
                }
            return st.nextToken();
        }
        String readLine(){
            try {
                return br.readLine();
            } catch (Exception e) {
                return null;
            }
        }
        int nextInt(){ return Integer.parseInt(next()); }
        long nextLong(){ return Long.parseLong(next()); }
    }

    FastScanner sc;
    PrintWriter out;



    public static void main(String[] args){
        new Main().run();
//        new Thread( null, new Runnable() {
//            @Override
//            public void run() {
//                new Main().run();
//            }
//            }, "LOL", 256L * 1024 * 1024 / 2 ).run();
//        }, "LOL", 2000 * 1024 * 1024 ).run();
    }



    void TLE(){ for(;;); }

    void MLE(){
        int[][] adj = new int[1024*1024][];
        for( int i = 0; i < adj.length; ++i )
            adj[i] = new int[1024*1024];
    }

    void exit( int val ){
        out.flush();
        System.exit(val);
    }
    //////////////////////////////////////////////////////////////////////////////////////////

    HashSet<Integer> readRow( int r ){
        HashSet<Integer> ans = new HashSet<>();
        for( int i = 0; i < 4; ++i ){
            for( int j = 0; j < 4; ++j ){
                int cur = sc.nextInt();
                if( i == r )
                    ans.add( cur );
            }
        }
        return ans;
    }

    void solveTest(){
        HashSet<Integer> r0 = readRow(sc.nextInt()-1);
        HashSet<Integer> r1 = readRow(sc.nextInt()-1);
        r0.retainAll( r1 );
        if     ( r0.size() == 0 )
            out.println( "Volunteer cheated!" );
        else if( r0.size() == 1 ){
            for( int v : r0 )
                out.println( v );
        }
        else
            out.println( "Bad magician!" );
    }

    void solve(){
        int cntTests = sc.nextInt();
        for( int t = 0; t < cntTests; ++t ){
            out.printf( "Case #%d: ", t + 1 );
            solveTest();
        }
    }

}