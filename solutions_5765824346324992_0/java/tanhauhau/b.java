import java.io.*;
import java.util.*;

public class Main1 {
    static InputReader reader;
    static OutputWriter writer;

    static int[] bt, time;

    public static void main(String[] args){
        reader = new InputReader(System.in);
        writer = new OutputWriter(System.out);
        int n = reader.nextInt();
        int b, m;
        bt = new int[1001];
        time = new int[1001];
        for(int i=1;i<=n;i++){
            b = reader.nextInt();
            m = reader.nextInt();
            for(int j=0;j<b;j++){
                time[j] = reader.nextInt();
            }
            writer.println("Case #%d: %d", i, solve(b, m));

        }
        writer.flush();
    }
    static long gcd(long a, long b){
        while (b > 0){
            long temp = b;
            b = a % b; // % is remainder
            a = temp;
        }
        return a;
    }
    static long lcm(long a, long b){
        return a * (b / gcd(a, b));
    }
    static long lcm(int[] input, int n){
        long result = input[0];
        for(int i = 1; i < n; i++){
            result = lcm(result, input[i]);
        }
        return result;
    }
    private static int solve(int b, int m) {
        long lcm = lcm(time, b);
        int s = 0;
        for(int i=0;i<b;i++){
            s += lcm/time[i];
        }
        m = m % s;
        if(m == 0){
            int min = Integer.MAX_VALUE, mini = 0;
            for(int i=0;i<b;i++){
                if(time[i] <= min){
                    min = time[i];
                    mini = i;
                }
            }
            return mini+1;
        }
        //prefill
        for(int i=0;i<b;i++){
            bt[i] = time[i];
            m--;
            if(m==0)
                return i+1;
        }
        int min, mini = 0;
        while(m > 0){
            //find min
            min = Integer.MAX_VALUE;
            mini = 0;
            for(int i=0;i<b;i++)
                if(bt[i] < min) {
                    min = bt[i];
                    mini = i;
                }
            //minus the time
            for(int i=0;i<b;i++)
                bt[i] -= min;
            //
            bt[mini] = time[mini];
            m--;
        }
        return mini + 1;
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (Exception e) {
                    return null;
                }
            }
            return tokenizer.nextToken();
        }
        public char nextChar(){
            try {
                char c = '\0';
                while(c == '\0' || c == '\n' || c == '\r')
                    c = (char) reader.read();
                return c;
            }catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        public String nextLine(){
            if(tokenizer != null && tokenizer.hasMoreTokens()){
                StringBuilder sb = new StringBuilder(tokenizer.nextToken());
                while(tokenizer.hasMoreTokens()){
                    sb.append(" ").append(tokenizer.nextToken());
                }
                return sb.toString();
            }else{
                try {
                    return reader.readLine();
                }catch(Exception e){
                    return null;
                }
            }
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }
    }

    static class OutputWriter {
        public BufferedWriter writer;
        OutputWriter(OutputStream stream) {
            writer = new BufferedWriter(new OutputStreamWriter(stream));
        }
        public void print(String string){
            try {
                writer.write(string, 0, string.length());
            }catch(Exception e){e.printStackTrace();}
        }
        public void print(char c){
            try {
                writer.write(c);
            }catch(Exception e){e.printStackTrace();}
        }
        public void print(String format, Object... args) {
            try {
                String string = String.format(format, args);
                writer.write(string, 0, string.length());
            }catch(Exception e){e.printStackTrace();}
        }
        public void print(int x){
            try {
                String string = String.format("%d", x);
                writer.write(string, 0, string.length());
            }catch(Exception e){e.printStackTrace();}
        }
        public void print(double x){
            try {
                int x_int = (int) (x * 100 + 1e-6); // add 1e-6 to avoid precision error when converting to int
                String string = String.format("%d.%02d", x_int/100, x_int%100);
                writer.write(string, 0, string.length());
            }catch(Exception e){e.printStackTrace();}
        }
        public void print(long x){
            try {
                String string = String.format("%d", x);
                writer.write(string, 0, string.length());
            }catch(Exception e){e.printStackTrace();}
        }
        public void println(String string){
            print(string);
            newline();
        }
        public void println(char c){
            print(c);
            newline();
        }
        public void println(String format, Object... args) {
            print(format, args);
            newline();
        }
        public void println(int x){
            print(x);
            newline();
        }
        public void println(long x){
            print(x);
            newline();
        }
        public void println(double x){
            print(x);
            newline();
        }
        public void println(){
            newline();
        }

        private void newline() {
            try {
                writer.newLine();
            }catch(Exception e){e.printStackTrace();}
        }
        private void flush(){
            try {
                writer.flush();
            }catch(Exception e){e.printStackTrace();}
        }
    }
}
