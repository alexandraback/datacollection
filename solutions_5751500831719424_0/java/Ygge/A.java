import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class A {

    private static final String FILE_NAME = "A-small-attempt0";

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader(FILE_NAME + ".in"));
        BufferedWriter out = new BufferedWriter(new FileWriter(FILE_NAME + ".out"));

        int t = Integer.parseInt(in.readLine());
        for (int c = 1; c <= t; ++c) {
            int n = Integer.parseInt(in.readLine());
            List<Word> words = new ArrayList<Word>();
            for (int i = 0; i < n; ++i) {
                words.add(new Word(in.readLine()));
            }
            if (allSameCharacters(words)) {
                int count = 0;
                for (int i = 0; i < words.get(0).charCounts.size(); ++i) {
                    List<CharCount> charCounts = new ArrayList<CharCount>();
                    for (Word word : words) {
                        charCounts.add(word.charCounts.get(i));
                    }
                    count += calcMin(charCounts);
                }
                out.write(String.format("Case #%d: %d\n", c, count));
            } else {
                out.write(String.format("Case #%d: Fegla Won\n", c));
            }
        }
        out.close();
    }

    private static int calcMin(List<CharCount> charCounts) {
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        for (CharCount charCount : charCounts) {
            min = Math.min(min, charCount.count);
            max = Math.max(max, charCount.count);
        }
        int best = Integer.MAX_VALUE;
        for (int i = min; i <= max; ++i) {
            int current = 0;
            for (CharCount charCount : charCounts) {
                current += Math.abs(charCount.count-i);
            }
            if (current < best) {
                best = current;
            }
        }
        return best;
    }

    private static boolean allSameCharacters(List<Word> words) {
        Word firstWord = words.get(0);
        for (int i = 1; i < words.size(); ++i) {
            if (!firstWord.sameCharacters(words.get(i))) {
                return false;
            }
        }
        return true;
    }

    private static class Word {
        private final List<CharCount> charCounts = new ArrayList<CharCount>();

        private Word(String word) {
            Character lastChar = null;
            int count = 0;
            for (int i = 0; i < word.length(); ++i) {
                Character c = word.charAt(i);
                if (lastChar != null && c != lastChar) {
                    charCounts.add(new CharCount(lastChar, count));
                    count = 1;
                } else {
                    ++count;
                }
                lastChar = c;
            }
            charCounts.add(new CharCount(lastChar, count));
        }

        private boolean sameCharacters(Word word) {
            if (charCounts.size() != word.charCounts.size()) {
                return false;
            }
            for (int i = 0; i < charCounts.size(); ++i) {
                CharCount cc1 = charCounts.get(i);
                CharCount cc2 = word.charCounts.get(i);
                if (cc1.character != cc2.character) {
                    return false;
                }
            }
            return true;
        }
    }

    private static class CharCount {
        private final Character character;
        private final int count;

        private CharCount(Character character, int count) {
            this.character = character;
            this.count = count;
        }
    }
}
