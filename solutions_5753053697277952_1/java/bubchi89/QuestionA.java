package oneb;

import java.util.*;

public class QuestionA {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numTests = sc.nextInt();
        for (int numTest = 0; numTest < numTests; numTest++) {
            int n = sc.nextInt();
            PriorityQueue<Party> parties = new PriorityQueue<>((o1, o2) -> o2.numMembers - o1.numMembers);
            for (int i = 0; i < n; i++) {
                char partyName = (char) ('A' + i);
                int partySize = sc.nextInt();
                parties.add(new Party(partyName, partySize));
            }
            String answer = solve(parties);
            System.out.format("Case #%d: %s%n", numTest + 1, answer);
        }
    }

    private static String solve(PriorityQueue<Party> parties) {
        StringBuilder sequence = new StringBuilder();
        int numNonZeroParties = parties.size();
        while (numNonZeroParties > 2) {
            Party largestParty = parties.poll();
            sequence.append(largestParty.name).append(" ");
            parties.add(Party.shrink(largestParty));
            if (largestParty.numMembers == 1) {
                numNonZeroParties--;
            }
            //System.out.println("\t" + Arrays.toString(parties.toArray()));
        }
        while (parties.peek().numMembers > 0) {
            Party partyOne = parties.poll();
            Party partyTwo = parties.poll();
            sequence.append(partyOne.name).append(partyTwo.name).append(" ");
            parties.add(Party.shrink(partyOne));
            parties.add(Party.shrink(partyTwo));
            //System.out.println("\t" + Arrays.toString(parties.toArray()));
        }
        return sequence.toString();
    }

    private static class Party {
        final char name;
        final int numMembers;

        private Party(char name, int numMembers) {
            this.name = name;
            this.numMembers = numMembers;
        }

        public static Party shrink(Party largestParty) {
            return new Party(largestParty.name, largestParty.numMembers - 1);
        }

        @Override
        public String toString() {
            return "Party{" +
                    "name=" + name +
                    ", numMembers=" + numMembers +
                    '}';
        }
    }
}
