package jam2014.r1b;

import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

/**
 * Title: 
 * 
 * Link: 
 */
public class TheRepeater_v1 {
    public static void main(String[] args) throws Exception {
        resolve("txt/2014/r1b/repeater-tiny");
        resolve("txt/2014/r1b/repeater-small");
        //resolve("txt/2014/r1b/repeater-large");
    }
    
    private static void resolve(String dataFile) throws Exception {
        // Initialize input and output.
        Locale.setDefault(Locale.US);
        Scanner scanner = new Scanner(new File(dataFile + ".in"));
        PrintWriter printer = new PrintWriter(dataFile + ".out");
        
        // Read number of test cases.
        int T = scanner.nextInt();
        
        // Evaluate each test case.
        for(int t=0; t<T; t++) {
            // Read input.
            int N = scanner.nextInt(); //N= 2
            String str1 = scanner.next();
            String str2 = scanner.next();
            
            // Calculate result.
            int result = resolveTestCase(str1, str2);
            
            // Print output.
            String message = "Case #" + (t+1) + ": " + (result<0? "Fegla Won" : result) + "\n";
            System.out.print(message);
            printer.append(message);
        }
        
        printer.flush();
        printer.close();
    }
    
    private static int resolveTestCase(String str1, String str2) {
        int res = distance(toCharCount(str1), toCharCount(str2));
        return res;
    }
    
    private static int distance(CharCount[] str1, CharCount[] str2) {
        int res = 0;
        
        if(str1.length != str2.length) return -1;
        
        for(int i=0; i<str1.length; i++) {
            if(str1[i].c == str2[i].c) {
                res += Math.abs(str1[i].n - str2[i].n);
            } else {
                return -1;
            }
        }
        
        return res;
    }
    
    private static CharCount[] toCharCount(String str) {
        List<CharCount> res = new ArrayList<>();
        
        char[] aux = str.toCharArray();
        for(int i=0; i<aux.length; i++) {
            if(res.isEmpty() || res.get(res.size() - 1).c != aux[i]) {
                CharCount algo = new CharCount();
                algo.c = aux[i];
                algo.n = 1;
                res.add(algo);
            } else {
                res.get(res.size() - 1).n++;
            }
        }
        
        return res.toArray(new CharCount[res.size()]);
    }
}

class CharCount {
    public char c = ' ';
    public int n = 0;
}
