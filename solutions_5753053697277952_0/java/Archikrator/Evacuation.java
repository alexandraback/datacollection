package google.code_jam.ed2016;

import java.io.InputStream;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.LongStream;


public class Evacuation {

    public static void main(String[] args) {
        InputStream is = System.in;
        Scanner s = new Scanner(is);
        int count = s.nextInt();
        for (int i = 1; i <= count; i++) {
            int p = s.nextInt();
            ArrayList parties = new ArrayList(p);
            for (int j = 0; j < p; j++) {
                parties.add(new Party((char)('A' + j), s.nextInt()));
            }
            System.out.printf("Case #%d: %s%n", i, solve(parties));

        }

    }
    static String solve(ArrayList<Party> parties) {
StringBuilder sb = new StringBuilder();
int remaining = 0;
        for (Party p: parties) {
            remaining+= p.count;
        }
        while (remaining > 0) {
            Collections.sort(parties);
            if (remaining == 3) {
                sb.append(parties.get(0).name).append(' ');
                parties.get(0).count--;
                remaining--;
                if (parties.get(0).count == 0) {
                    parties.remove(0);
                }
            } else if (remaining == 2) {
                for (Party party: parties) {
                    for (int i = 0; i < party.count; i++) {
                        sb.append(party.name);
                    }
                }
                remaining = 0;
            } else {
                remaining -= 2;
                if (parties.get(0).count > parties.get(1).count + 1) {
                    char c= parties.get(0).name;
                    sb.append(c).append(c).append(' ');
                    parties.get(0).count -= 2;
                } else {
                    sb.append(parties.get(0).name).append(parties.get(1).name).append(' ');
                    parties.get(0).count--;
                    parties.get(1).count--;
                }
            }
        }
return sb.toString();
    }

    static class Party implements  Comparable<Party>
    {
        char name;
        int count;

        @Override
        public int compareTo(Party o) {
            return Integer.compare(o.count, this.count);
        }

        public Party(char name, int count) {
            this.name = name;
            this.count = count;
        }
    }

}
