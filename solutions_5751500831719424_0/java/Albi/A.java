/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package round1b;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Albi
 */
public class A {

    private final BufferedReader in;
    private final PrintWriter out;
    private int caseNumber;
    
    public A(String fileName) throws FileNotFoundException {
        in = new BufferedReader(new FileReader(new File("files/"+fileName+".in")));
        out = new PrintWriter(new File("files/"+fileName+".out"));
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try {
            new A("A-example").solve();
            new A("A-small").solve();
            //solve("A-large");
        } catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
    
    private void solve() throws IOException {
        String line = in.readLine();
        int T = Integer.parseInt(line);
        for (caseNumber = 1; caseNumber <= T; caseNumber++) {
            solveCase();
        }
        in.close();
        out.close();
    }
    
    private void solveCase() throws IOException {
        System.out.println("Doing case "+caseNumber);
        int numWords = Integer.parseInt(in.readLine());
        List<Integer>[] counts = new List[numWords];
        List<Character>[] chars = new List[numWords];
        boolean feglaWon = false;
        for (int wordi = 0; wordi < numWords; wordi++) {
            int ii = -1;
            char lastChar = ' ';
            String word = in.readLine();
            counts[wordi] = new ArrayList<>();
            chars[wordi] = new ArrayList<>();
            for (int i = 0; i < word.length(); i++) {
                char c = word.charAt(i);
                //System.out.print("["+i+"/"+ii+"/"+c+"/"+lastChar+"]");
                if (lastChar != c) {
                    ii++;
                    lastChar = c;
                    counts[wordi].add(1);
                    chars[wordi].add(c);
                    if (wordi > 0) {
                        try {
                            if (chars[wordi].get(ii) != chars[0].get(ii)) {
                                System.out.println("c1 "+ii);
                                feglaWon = true;
                                break;
                            }
                        } catch (IndexOutOfBoundsException e) {
                            System.out.println("c2 "+ii);
                            feglaWon = true;
                            break;
                        }
                    }
                } else {
                    counts[wordi].set(ii, counts[wordi].get(ii)+1);
                }
            }
            
            if (chars[0].size() != chars[wordi].size()) {
                System.out.println("c3 "+ii);
                feglaWon = true;
                break;
            }
        }
        out.print("Case #"+caseNumber+": ");
        if (feglaWon) {
            out.println("Fegla Won");
            return;
        }
        
        int totalMoves = 0;
        
        for (int col = 0; col < chars[0].size(); col++) {
            int min = 100;
            int max = 1;
            for (int i = 0; i < numWords; i++) {
                int c = counts[i].get(col);
                if (c < min) {
                    min = c;
                }
                if (c > max) {
                    max = c;
                }
            }
            int bestMoves = 10001;
            for (int prop = min; prop <= max; prop++) {
                int moves = 0;
                for (int w = 0; w < numWords; w++) {
                    moves += Math.abs(prop - counts[w].get(col));
                }
                if (moves < bestMoves) {
                    bestMoves = moves;
                }
            }
            totalMoves += bestMoves;
        }
        out.println(totalMoves);
    }
    
}
