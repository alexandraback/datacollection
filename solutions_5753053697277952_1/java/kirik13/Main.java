
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Stream;


// 10^6 ~ 2 sec
public class Main {

    private static final String IN_FILENAME = "/Users/kyesipau/dev/personal/src/A-large.in";
    private static final String OUT_FILENAME = "/Users/kyesipau/dev/personal/src/out.txt";

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader(IN_FILENAME));
        PrintWriter writer = new PrintWriter(OUT_FILENAME, "UTF-8");

        int t = Integer.parseInt(reader.readLine().trim());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(reader.readLine().trim());
            String[] numberStrArray = reader.readLine().trim().split(" ");
            int[] countArray = new int[n];
            for (int j = 0; j < n; j++) {
                countArray[j] = Integer.parseInt(numberStrArray[j]);
            }
            int caseNumber = (i + 1);
            writer.println("Case #" + caseNumber + ": " + solve(countArray));
        }

        reader.close();
        writer.close();
    }

    private static String solve(int[] countArray) {
        int n = countArray.length;
        int totalCount = 0;
        PriorityQueue<Party> partyHeap = new PriorityQueue<>(n);
        for (int i = 0; i < n; i++) {
            totalCount = totalCount + countArray[i];
            partyHeap.add(new Party(countArray[i], (char) ('A' + i)));
        }

        List<String> accumulator = new LinkedList<>();
        solve(partyHeap, totalCount, accumulator);

        int i = 0;
        String result = "";

        for (String token : accumulator) {
            if (i == 0) {
                result = result + token;
            } else {
                result = result + " " + token;
            }
            i++;
        }
        return result;
    }

    private static void solve(PriorityQueue<Party> partyHeap, int totalCount, List<String> accumulator) {
        while (!partyHeap.isEmpty()) {
            if (canRemoveSinglePopular(partyHeap, totalCount)) {
                Party popularParty = partyHeap.poll();
                popularParty.decCount();
                totalCount--;
                accumulator.add(popularParty.getLetter() + "");

                if (popularParty.getCount() > 0) {
                    partyHeap.add(popularParty);
                }
            } else {
                Party first = partyHeap.poll();
                Party second = partyHeap.poll();
                first.decCount();
                second.decCount();
                totalCount = totalCount - 2;
                accumulator.add((first.getLetter() + "") + (second.getLetter() + ""));

                if (first.getCount() > 0) {
                    partyHeap.add(first);
                }
                if (second.getCount() > 0) {
                    partyHeap.add(second);
                }
            }
        }
    }

    private static boolean canRemoveSinglePopular(PriorityQueue<Party> partyHeap, int total) {
        Party popularParty = partyHeap.peek();
        popularParty.decCount();
        total--;
        for (Party party : partyHeap) {
            if (party.getCount() * 2 > total) {
                popularParty.incCount();
                return false;
            }
        }

        popularParty.incCount();
        return true;
    }

    public static class Party implements Comparable<Party> {

        private int count;
        private char letter;

        public Party(int count, char letter) {
            this.count = count;
            this.letter = letter;
        }

        public int getCount() {
            return count;
        }

        public char getLetter() {
            return letter;
        }

        public void decCount() {
            count--;
        }

        public void incCount() {
            count++;
        }

        @Override
        public int compareTo(Party other) {
            if (count > other.getCount()) {
                return -1;
            } else if (count < other.getCount()) {
                return 1;
            } else {
                return hashCode() < other.hashCode() ? -1 : 1;
            }
        }
    }
}
