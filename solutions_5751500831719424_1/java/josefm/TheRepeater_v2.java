package jam2014.r1b;

import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

/**
 * Title: 
 * 
 * Link: 
 */
public class TheRepeater_v2 {
    public static void main(String[] args) throws Exception {
        resolve("txt/2014/r1b/repeater-tiny2");
        //resolve("txt/2014/r1b/repeater-small");
        resolve("txt/2014/r1b/repeater-large");
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
            int N = scanner.nextInt(); 
            String vals[] = new String[N];
            for(int i=0; i<N; i++) vals[i] = scanner.next();
            
            // Calculate result.
            int result = resolveTestCase(vals);
            
            // Print output.
            String message = "Case #" + (t+1) + ": " + (result<0? "Fegla Won" : result) + "\n";
            System.out.print(message);
            printer.append(message);
        }
        
        printer.flush();
        printer.close();
    }
    
    private static int resolveTestCase(String[] vals) {
        CharCount[][] strs = new CharCount[vals.length][];
        for(int i=0; i<vals.length; i++) strs[i] = toCharCount(vals[i]);
        
        // Calculo movimientos por cada letra.
        int res = 0;
        CharCount[] first = strs[0];
        for(int c=0; c<first.length; c++) {
            
            // Cantidades de la letra 'c'.
            int[] cant = new int[strs.length];
            for(int s=0; s<strs.length; s++) {
                CharCount[] str = strs[s];
                
                if(first.length != str.length || first[c].c != str[c].c) return -1;
                    
                cant[s] = str[c].n;
            }
            
            // Calculo minimos movimientos para unificar la letra 'c'.
            Arrays.sort(cant);
            int min = cant[0];
            int max = cant[cant.length - 1];
            int movC = -1;
            for(int g=min; g<=max; g++) {
                int movs = 0;
                for(int a=0; a<cant.length; a++) {
                    movs += Math.abs(cant[a] - g);
                }
                if(movC < 0 || movs < movC) movC = movs;
            }
            res += movC;
        }
    
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
