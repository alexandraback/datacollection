
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class AA {
    private Pipe pipe = null;
    
    public AA(String args[]) throws FileNotFoundException, IOException {
        this.pipe = new Pipe(args);
    }

    public static void main(String args[]) throws FileNotFoundException, IOException {
        new AA(args).start();    
    }
   
    public void start() throws FileNotFoundException, IOException {
        long roundCount = pipe.ni();
        for(int round = 1; round <= roundCount; round++) {
            String result = solve();
            String outStr = "Case #" + round + ": " + result + "\n";
            pipe.print(outStr);
//            pipe.nline();
        }
        pipe.close();
    }
    
    public String solve() throws IOException {
        String line[] = new String[5];
        Set<Integer> set = new HashSet<Integer>();
        int firstRow = pipe.ni();
        
        for(int i = 1; i < 5; i++) {
            line[i] = pipe.nline();
        }
        
        String numbers[] = line[firstRow].split(" ");
        for(int i = 0; i < 4; i++) {
            set.add(Integer.parseInt(numbers[i]));
        }
        
        int secondRow = pipe.ni();
        for(int i = 1; i < 5; i++) {
            line[i] = pipe.nline();
        }
        numbers = line[secondRow].split(" ");
        
        Integer ans = null;
        for(int i = 0; i < 4; i++) {
            Integer v = Integer.parseInt(numbers[i]);
            if(set.contains(v)) {
                ans = v;
            } else {
                set.add(v);
            }
        }
        
        if(set.size() == 7) {
            return ans.toString();
        } else if (set.size() == 8) {
            return "Volunteer cheated!";
        } else if (set.size() <=6) {
            return "Bad magician!";
        }
        return "";
    }
    
    private long total(long k, long r) {
        return 2*k*k + (2*r - 1)*k;
    }
    

    private class Pipe {
        private BufferedReader reader;
        private BufferedWriter writer;
        private StringTokenizer tokenizer;

        public Pipe(String args[]) throws FileNotFoundException, IOException {
            if(args != null && args.length >= 1) {
                reader = new BufferedReader(new FileReader(args[0]));
                if(args.length == 2) {
                    writer = new BufferedWriter(new FileWriter(args[1]));
                }
            } else {
                reader = new BufferedReader(new InputStreamReader(System.in));
            }
        }

        public String nline() throws IOException {
            tokenizer = null;
            return reader.readLine();
        }

        public String ns() throws IOException {
            while(tokenizer == null || !tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(reader.readLine());
            }
            return tokenizer.nextToken();            
        }

        public int ni() throws IOException {
            return Integer.parseInt(ns());
        }

        public long nl() throws IOException {
            return Long.parseLong(ns());
        }

        public float nf() throws IOException {
            return Float.parseFloat(ns());
        }

        public double nd() throws IOException {
            return Double.parseDouble(ns());
        }

        public void print(String str) throws IOException {
            System.out.print(str);
            if(writer != null) {
                writer.write(str, 0, str.length());
            }
        }

        public void close() throws IOException {
            if(writer != null) {
                writer.close();
            }
        }
    }
}
