package googlecodejam;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class GoogleCodeJam {

    static String PROBLEM_NAME = "A";
    
    public static void taskA(InputReader fin, PrintWriter fout) {
        int T = fin.nextInt();
        
        for (int test = 1; test <= T; test++) {
            int before = 0, after = 0;
            
            int row1, row2, tmp;
            row1 = fin.nextInt();
            for (int i = 1; i <= 4; i++) {
                for (int j = 1; j <= 4; j++) {
                    tmp = fin.nextInt();
                    if (i == row1) {
                        before |= 1 << tmp;
                    }
                }
            }
            
            row2 = fin.nextInt();
            for (int i = 1; i <= 4; i++) {
                for (int j = 1; j <= 4; j++) {
                    tmp = fin.nextInt();
                    if (i == row2) {
                        after |= 1 << tmp;
                    }
                }
            }
            
            int common = before & after;
            
            fout.printf("Case #%d: ", test);
            if (common == 0) {
                fout.printf("Volunteer cheated!");
            } else if ((common & (common - 1)) == 0) {
                fout.printf("%d", Integer.numberOfTrailingZeros(common));
            } else {
                fout.printf("Bad magician!");
            }
            fout.println();
        }
    }
    
    public static void main(String[] args) throws IOException {
        FileInputStream fis = new FileInputStream("data/A.in");
        FileOutputStream fos = new FileOutputStream("data/A.out");
        
//        InputStream inputStream = System.in;
//        OutputStream outputStream = System.out;
        InputStream inputStream = fis;
        OutputStream outputStream = fos;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);

        GoogleCodeJam.taskA(in, out);

        out.close();
    }
    
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public String nextLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}