package codejam2014;


import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.SortedSet;
import java.util.TreeSet;

public class Repeater {
    
    public static void main(String[] args) throws Exception {
        try {
            new Repeater(args).run();
        } catch (IllegalArgumentException e) {
            System.err.println("Usage: cmd [infile].in.txt [outfile]");
        }
    }

    private String[] m_args;
    
    private File m_inFile;
    private File m_outFile;
    
    Repeater(String[] args) throws Exception {
        m_args = args;
        parseFileArgs(m_args);
    }
    
    public void run() throws Exception {
                
        try (
                Scanner in = new Scanner(m_inFile);
                PrintWriter out = new PrintWriter(new CopyToOutWriter(m_outFile))
       )       
       {       
            int tests = in.nextInt();
            for(int i = 1; i <= tests; i++) {
                int N = in.nextInt();
                List<Word> words = new ArrayList<>();
                for(int index = 0; index < N; index++) {
                    words.add(new Word(in.next()));
                }
                out.printf("Case #%d: %s\n", i, solve(words, N));
            }
       }
    }
    
    private class Word {
        private String m_w;
        List<Character> m_chars = new ArrayList<Character>();
        List<Integer> m_counts = new ArrayList<Integer>();

        Word(String w) {
            m_w = w;
            char lastChar = '\0';
            for(int i = 0; i < m_w.length(); i++) {
                char ch = m_w.charAt(i);
                if (ch == lastChar) {
                    incrementLast();
                } else {
                    addChar(ch);
                }
                lastChar = ch;
            }
        }
        
        private void addChar(Character ch) {
            m_chars.add(ch);
            m_counts.add(1);
        }
        
        private void incrementLast() {
            int count = m_counts.get(m_counts.size()-1);
            m_counts.set(m_counts.size()-1, count+1);
        }
        
        private String simplified() {
            StringBuilder buf = new StringBuilder();
            for(Character ch : m_chars) {
                buf.append(ch);
            }
            return buf.toString();
        }
        
        private int getLength() {
            return m_counts.size();
        }
        
        private int getCountAt(int index) {
            return m_counts.get(index);
        }
        
        private char getCharAt(int index) {
            return m_chars.get(index);
        }
        

    }

    
    private Object solve(List<Word> words, int n) {
        if (!solveable(words, n)) return "Fegla Won";  

        Word first = words.get(0);

        int moves = 0;
        for(int i = 0; i < first.getLength(); i++ ) {
            int median = median(words, i);
            for(Word word : words) {
                moves += Math.abs(word.getCountAt(i) - median);
            }
            
        }

        return moves;
        
    }
    
    private boolean solveable(List<Word> words, int n) {
        String simplified = words.get(0).simplified();
        for(int i = 1; i < n; i++) {
            String other = words.get(i).simplified();
            if (!other.equals(simplified)) return false;
        }
        return true;
    }
    
    private int median(List<Word> words, int index) {
        int n = words.size();
        
        int[] vals = new int[n];
        
        for(int i = 0; i < n; i++) {
            vals[i] = words.get(i).getCountAt(index);
        }
        
        Arrays.sort(vals);
        
        return vals[ n % 2 == 0 ? (n/2)-1 : (n/2)];
        
    }
    

    // Parsing Helper Code below here
    private void parseFileArgs(String[] args) throws Exception {
        if (args.length < 1) {
            throw new IllegalArgumentException("usage: cmd infile [outfile]: cwd = " + new File(".").getAbsolutePath());
        }
        String inFileName = args[0];
        String outFileName = args.length < 2 ? without(inFileName, "in.txt").concat("out.txt") : args[1];

        File inFile = new File(inFileName);
        if (!inFile.canRead()) {
            throw new IllegalArgumentException("Cannot read file " + inFileName);
        }
        m_inFile = inFile;
        m_outFile = new File(outFileName);
        
        System.err.println("In File: " + m_inFile);
        System.err.println("Out File: " + m_outFile);

    }
        
    private String without(String fileName, String suffix) {
        return fileName.endsWith(suffix) ? fileName.substring(0, fileName.length()-suffix.length()) : fileName;
    }
        
    class CopyToOutWriter extends Writer {
        
        private final Writer out;
        private final Writer sys;
        
        CopyToOutWriter(File outFile) throws IOException {
            out = new FileWriter(outFile);
            sys = new OutputStreamWriter(System.out);
        }

        @Override
        public void write(char[] cbuf, int off, int len) throws IOException {
            sys.write(cbuf, off, len);
            out.write(cbuf, off, len);
            sys.flush();
            out.flush();

        }

        @Override
        public void flush() throws IOException {
            sys.flush();
            out.flush();
        }

        @Override
        public void close() throws IOException {
            // sys.close() don't close since it is System.out
            sys.flush();
            out.close();
        }
        
    }

}
