import java.util.*;

public class CA {
    public static class Party {
        public String letter;
        public Integer n;

        public Party(String letter, Integer n) {
            this.letter = letter;
            this.n = n;
        }

        public String toString() {
            return this.letter + " : " + this.n.toString();
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Integer T = in.nextInt();
        for (Integer _i = 0; _i < T; _i++) {
            Integer N = in.nextInt();
            in.nextLine();
            PriorityQueue<Party> pq = new PriorityQueue<Party>(new Comparator<Party>() {
                public int compare(Party c1, Party c2) {
                    if (Double.compare(c2.n, c1.n) == 0) {
                        return c1.letter.compareToIgnoreCase(c2.letter);
                    }
                    return Double.compare(c2.n, c1.n);
                }
            });
//            List<Party> pq = new ArrayList<>();
            String[] letters = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
            int i = 0;
            int sum = 0;
            for (String c : in.nextLine().split(" ")) {
                int tmp = Integer.valueOf(c);
                pq.add(new Party(letters[i], tmp));
                sum += tmp;
                i++;
            }

            String out = "";
            while (sum > 0) {
//                System.out.println(pq);
//                System.out.println(sum);
                Party first = pq.poll();
                Party second;
                if (pq.size() > 0) {
                    second = pq.peek();
                } else {
                    second = new Party("|", 0);
                }
                if (second.n * 2 <= sum - 2) {
                    // Two from first
                    sum -= 2;
                    first.n -= 2;
                    out += (first.letter + first.letter) + " ";
                    pq.add(first);
                } else {
                    second = pq.poll();
                    Party third;
                    if (pq.size() > 0) {
                        third = pq.peek();
                    } else {
                        third = new Party("|", 0);
                    }
                    if (third.n * 2 <= sum - 2) {
                        // One from each
                        sum -= 2;
                        first.n -= 1;
                        second.n -= 1;
                        pq.add(first);
                        pq.add(second);
                        out += (first.letter + second.letter) + " ";
                    } else {
                        // One from first
                        sum -= 1;
                        first.n -= 1;
                        pq.add(first);
                        pq.add(second);
                        out += (first.letter) + " ";
                    }
                }
            }

            System.out.println("Case #" + String.valueOf(_i + 1) + ": " + out.trim());
        }
    }
}
