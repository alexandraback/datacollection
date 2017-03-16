
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;


public class CodeJamA {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        CodeJamA jam = new CodeJamA();
        jam.solve("A-small-attempt0.in");
    }
    
    public void solve(String file) throws FileNotFoundException, IOException {
        File f = new File(file);
        FileReader fin = new FileReader(f);
        BufferedReader in = new BufferedReader(fin);
        int cases = Integer.parseInt(in.readLine());
        File outF = new File("results.txt");
        PrintStream out = new PrintStream(outF);
        for (int i = 1; i <= cases; i++) {
            int firstAnswer = Integer.parseInt(in.readLine());
            ArrayList<Integer> first = new ArrayList();
            ArrayList<Integer> second = new ArrayList();
            for (int j = 0; j < 4; j++) {
                String cur = in.readLine();
                if (j == firstAnswer - 1) {
                    String[] tokens = cur.split(" ");
                    for (int k = 0; k < 4; k++) {
                        first.add(Integer.parseInt(tokens[k]));
                    }
                }
            }
            int secondAnswer = Integer.parseInt(in.readLine());
            for (int j = 0; j < 4; j++) {
                String cur = in.readLine();
                if (j == secondAnswer - 1) {
                    String[] tokens = cur.split(" ");
                    for (int k = 0; k < 4; k++) {
                        if (first.contains(Integer.parseInt(tokens[k]))) {
                            second.add(Integer.parseInt(tokens[k]));
                        }
                    }
                }
            }
            out.print("Case #" + i + ": ");
            if (second.size() == 1) {
                out.println(second.get(0));
            } else if (second.isEmpty()) {
                out.println("Volunteer cheated!");
            } else {
                out.println("Bad magician!");
            }
        }
    }
}
