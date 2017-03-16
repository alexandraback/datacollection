import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

/**
 * @autor: julio
 */
public class Main {

    public static void main(String[] args) throws IOException {


        BufferedReader br = new BufferedReader(new InputStreamReader(Thread.currentThread().getContextClassLoader().getResourceAsStream("in.small")));
        int T = Integer.parseInt(br.readLine());
        for(int t=0;t<T;t++){
            int N = Integer.parseInt(br.readLine());

            List<List<Pair>> words = new ArrayList<>();

            for(int n=0;n<N;n++) {
                String word = br.readLine();
                List<Pair> pairs = new ArrayList<>();
                char lastChar = '\0';
                Pair currentPair = null;
                for(char c: word.toCharArray()){
                    if(c != lastChar) {
                        currentPair = new Pair(c);
                        pairs.add(currentPair);
                    }
                    currentPair.count++;
                    lastChar = c;
                }
                words.add(pairs);
            }
            sort(words);
            int delta = getDelta(words);

            System.out.println("Case #" + (t+1) + ": " + (delta >= 0 ? delta : "Fegla Won"));
        }

    }

    private static int getDelta(List<List<Pair>> words) {
        List<Pair> firstWord = words.get(words.size() / 2);
        for(List<Pair> word: words){
            if(firstWord.size() != word.size()){
                return -1;
            }
        }

        int totalOps = 0;
        for (int i = 0; i < firstWord.size(); i++) {
            int minOps = -1;
            for(List<Pair> targetWord: words) {
                int opsToChange = 0;
                for(List<Pair> tryWord: words) {
                    if(targetWord != tryWord){
                        Pair paira = targetWord.get(i);
                        Pair pairb = tryWord.get(i);
                        if(!paira.character.equals(pairb.character)){
                            return -1;
                        }
                        int diff = Math.abs(paira.count - pairb.count);
                        opsToChange+=diff;
                    }
                }
                if(minOps == -1 || opsToChange < minOps){
                    minOps = opsToChange;
                }
            }
            totalOps += minOps;
        }



        return totalOps;
    }

    private static int wordLen(List<Pair> pairs){
        int c=0;
        for(Pair p:pairs){
            c+=p.count;
        }
        return c;
    }

    private static void sort(List<List<Pair>> words){
        Collections.sort(words, new Comparator<List<Pair>>() {
            @Override
            public int compare(List<Pair> o1, List<Pair> o2) {
                int l1 = wordLen(o1);
                int l2 = wordLen(o2);
                return Integer.compare(l1,l2) * -1;
            }
        });
    }

    private static class Pair {
        Character character;
        int count = 0;

        private Pair(Character c) {
            this.character = c;
        }

        @Override
        public String toString() {
            return "Pair{" +
                "character=" + character +
                ", count=" + count +
                '}';
        }
    }
}
