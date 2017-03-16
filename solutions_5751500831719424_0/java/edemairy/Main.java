
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Formatter;
import java.util.HashSet;
import java.util.Locale;
import java.util.TreeSet;

/**
 *
 * @author edemairy
 */
public class Main {

    private int nbTC;
    private StringBuilder result = new StringBuilder();

    private static class EndException extends RuntimeException {
    }

    public void run() throws IOException {
        //        Scanner scanner = new Scanner(System.in);
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        nbTC = readInt(reader);
//         nbTC = Integer.MAX_VALUE;
//        scanner.nextLine();
        try {
            for (int tc = 1; tc <= nbTC; ++tc) {
                result.append("Case #"+tc+": ");
                result.append(oneTestCase(reader));
                result.append('\n');
            }
        } catch (EndException e) {
        }
        System.out.print(result);
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        Main main = new Main();
        main.run();
    }

    private StringBuilder oneTestCase(BufferedReader reader) throws IOException {
        Formatter formatter = new Formatter(Locale.ENGLISH);
        StringBuilder output = new StringBuilder();
//        for (int i = 0; i < 5; ++i) {
//            formatter.format("%3d", n[i]);
//        }

        int N = readInt(reader);
        if (N==0) {
            output.append("0");
            return output;
        }
        String[] s = new String[N];
        for (int i=0; i<N; i++) {
            s[i] = reader.readLine();
        }
        StringBuilder[] reduced = new StringBuilder[N];
        HashSet<String> orderedReduced = new HashSet<String>();
        for (int i=0; i<N; i++) {
            reduced[i] = new StringBuilder();
            char last = '#';
            for (int c=0; c<s[i].length(); c++) {
                char current = s[i].charAt(c);
                if (current != last) {
                    reduced[i].append(current);
                    last = current;
                }
            }
            orderedReduced.add(reduced[i].toString());
        }
        if (orderedReduced.size() != 1) {
            formatter.format("Fegla Won");
        } else {
            int w = reduced[0].length();
            int[][] freq = new int[N][w];
            for (int i=0; i<N; i++) {
                int cptChar = 0;
                int nbChar = 0;
                char last = '#';
                for (int c=0; c<s[i].length(); c++) {
                char current = s[i].charAt(c);
                if (current != last) {
                    if (last != '#') {
                        freq[i][cptChar] = nbChar;
                        nbChar = 1;
                        cptChar++;
                        reduced[i].append(current);
                        last = current;
                    } else {
                        last = current;
                        nbChar=1;
                    }
                } else {
                    nbChar++;
                }
                freq[i][cptChar] = nbChar;
            }  
            }
            int r = 0;
            for (int cptW=0; cptW < w; cptW++) {
                ArrayList<Integer> se = new ArrayList<Integer>();
                for (int i=0; i<N; i++) {
                    se.add(freq[i][cptW]);
                }
                Collections.sort(se);
                int median = se.get(se.size()/2);
                for (int i=0; i<N; i++) {
                    r += Math.abs(median - freq[i][cptW]);
                }
                
            }
            formatter.format("%d",r);
        }
        
        output.append(formatter.out());
        return output;
    }

    private int readInt(BufferedReader reader) throws IOException {
        int r = 0;
        boolean positive = true;
        char currentChar = (char) reader.read();

        while ((currentChar == ' ') || (currentChar == '\n')) {
            currentChar = (char) reader.read();
        }
        if (currentChar == (char) -1) {
            throw new IOException("end of stream");
        }
        if (currentChar == '-') {
            positive = false;
            currentChar = (char) reader.read();
        }
        while ((currentChar >= '0') && (currentChar <= '9')) {
            r = r * 10 + currentChar - '0';
            currentChar = (char) reader.read();
        }
        if (positive) {
            return r;
        } else {
            return -r;
        }
    }

    private long readLong(BufferedReader reader) throws IOException {
        long r = 0;
        boolean positive = true;
        char currentChar = (char) reader.read();

        while ((currentChar == ' ') || (currentChar == '\n')) {
            currentChar = (char) reader.read();
        }
        if (currentChar == (char) -1) {
            throw new IOException("end of stream");
        }
        if (currentChar == '-') {
            positive = false;
            currentChar = (char) reader.read();
        }
        while ((currentChar >= '0') && (currentChar <= '9')) {
            r = r * 10 + currentChar - '0';
            currentChar = (char) reader.read();
        }
        if (positive) {
            return r;
        } else {
            return -r;
        }
    }

    private char readChar(BufferedReader reader) throws IOException {
        return (char) reader.read();
    }
}
