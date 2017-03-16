package current.a;


import com.google.common.base.Function;
import com.google.common.collect.Lists;
import org.apache.commons.io.IOUtils;

import java.io.*;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class A extends Problem<Case> {
    public static final int ILLEGAL = -1;
    public static final String ILLEGAL_STRING = "Fegla Won";

    @Override
    public String solve(Case aCase) {
        int moves = aCase.countMoves();
        if (moves == ILLEGAL) {
            return ILLEGAL_STRING;
        }
        return String.valueOf(moves);
    }

    @Override
    public List<Case> parse(String data) {
        final Scanner sc = new Scanner(data);
        final List<Case> cases = Lists.newArrayList();
        long num_cases = sc.nextLong();
        for (int case_num = 0; case_num < num_cases; case_num++) {
            final int numWords = sc.nextInt();
            final List<String> words = Lists.newArrayList();
            for (int i = 0; i < numWords; i++) {
                words.add(sc.next());
            }
            Case aCase = new Case(words);
            cases.add(aCase);
        }
        return cases;
    }

    @Override
    public void preCompute() {
    }

    public static void main(String[] args) {
        Problem problem = new A();
        problem.main(args[0]);
    }
}

class Case {
    private List<String> words;
    private List<List<Pair>> pairs;

    public Case(final List<String> words) {
        this.words = words;
        pairs = Lists.newArrayList();
        pairWords();
    }

    public int countMoves() {
        int moves = 0;
        List<Pair> start = pairs.get(0);
        for (int i = 1; i < pairs.size(); i++) {
            List<Pair> next = pairs.get(i);
            if (start.size() != next.size()) {
                return A.ILLEGAL;
            }
        }
        for (int i = 0; i < start.size(); i++) {
            final List<Pair> spotPair = Lists.newArrayList();
            for(List<Pair> word: pairs) {
                Pair a = start.get(i);
                Pair b = word.get(i);
                if (a.getChar() != b.getChar()) {
                    return A.ILLEGAL;
                }
                spotPair.add(b);
            }
            //moves += Math.abs(a.getCount() - b.getCount());
            int round = balence(spotPair);
            moves += round;
        }
        return moves;
    }

    private int balence(List<Pair> spotPair) {
        final List<Integer> numbers = Lists.newArrayList();
        for(final Pair pair: spotPair) {
            numbers.add(pair.getCount());
        }
        Collections.sort(numbers);
        final List<Integer> medians = median(numbers);
        final List<Integer> distances = calcDistances(medians, numbers);
        return Collections.min(distances);
    }

    private List<Integer> calcDistances(List<Integer> medians, List<Integer> numbers) {
        final List<Integer> distances = Lists.newArrayList();
        for(Integer median: medians) {
            int distance = 0;
            for(Integer number: numbers) {
                distance += Math.abs(number - median);
            }
            distances.add(distance);
        }
        return distances;
    }

    private void pairWords() {
        for (String word : words) {
            final List<Pair> pair = pairWord(word);
            pairs.add(pair);
        }
    }

    private List<Pair> pairWord(String word) {
        final List<Pair> pairs = Lists.newArrayList();
        int count = 1;
        char currChar = word.charAt(0);
        Pair currPair = new Pair(currChar);
        for (int i = 1; i < word.length(); i++) {
            int nextChar = word.charAt(i);
            if (nextChar != currChar) {
                currPair.setCount(count);
                pairs.add(currPair);
                count = 1;
                currChar = word.charAt(i);
                currPair = new Pair(currChar);
            } else {
                count++;
            }
        }
        currPair.setCount(count);
        pairs.add(currPair);
        return pairs;
    }

    public List<Integer> median(List<Integer> a) {
        int middle = a.size() / 2;

        if (a.size() % 2 == 1) {
            return Lists.newArrayList(a.get(middle));
        } else {
            return Lists.newArrayList(a.get(middle - 1), a.get(middle));
        }
    }
}

class Pair {
    private char c;
    private int count;

    public Pair(char c) {
        this.c = c;
        count = 0;
    }

    public void setCount(int count) {
        this.count = count;
    }

    public int getCount() {
        return count;
    }

    public char getChar() {
        return c;
    }
}


abstract class Problem<T> {
    public abstract String solve(T t);

    public abstract List<T> parse(final String data);

    public abstract void preCompute();

    public void display(final List<String> results, final String filename) {
        final String base = filename.substring(0, filename.lastIndexOf('.'));
        final String outFileName = base + ".out";

        BufferedWriter writer = null;
        try {
            writer = new BufferedWriter(new FileWriter(new File(outFileName)));
            int case_num = 1;
            for (String result : results) {
                final String answer = String.format("Case #%d: %s", case_num, result);
                System.out.println(answer);
                writer.write(answer + "\n");
                case_num++;
            }
        } catch (IOException e) {
            e.printStackTrace();
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            IOUtils.closeQuietly(writer);
        }
    }

    public void main(String filename) {
        preCompute();
        final String data = readLines(filename);
        final List<T> cases = parse(data);
        final List<String> results = Lists.transform(cases, new Function<T, String>() {
            @Override
            public String apply(T t) {
                return solve(t);
            }
        });
        display(results, filename);
    }

    private String readLines(final String filename) {
        try {
            final String content = new Scanner(new File(filename)).useDelimiter("\\Z").next();
            return content;
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            System.exit(1);
        }
        return null;
    }
}