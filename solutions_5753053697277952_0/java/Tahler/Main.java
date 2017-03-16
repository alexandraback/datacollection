import java.util.Scanner;

// no party ever has an absolute majority
//  - no more than half of the senators in the senate room belong to the same party.
public class Main {
    public static final char[] ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ".toCharArray();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int nTests = scanner.nextInt();
        for (int i = 0; i < nTests; i++) {
            int nParties = scanner.nextInt();
            int[] partyPopulations = new int[nParties];
            for (int j = 0; j < nParties; j++) {
                partyPopulations[j] = scanner.nextInt();
            }

            EvacuationPlan plan = new EvacuationPlan(partyPopulations);
            System.out.println("Case #" + (i + 1) + ": " + plan.solution());
        }
    }

    private static class EvacuationPlan {
        private int[] partyMembers;
        private int memberCount;

        public EvacuationPlan(int[] partyMembers) {
            this.partyMembers = partyMembers;
            this.memberCount = getMemberCount(partyMembers);
        }

        public String nextStep() {
            String step = "";
            int maxIndex1 = findMaxIndex(this.partyMembers);
            partyMembers[maxIndex1] -= 1;
            memberCount -= 1;
            char taken1 = ALPHABET[maxIndex1];
            step += taken1;
            if (hasMajority(partyMembers)) {
                int maxIndex2 = findMaxIndex(partyMembers);
                partyMembers[maxIndex2] -= 1;
                memberCount -= 1;
                char taken2 = ALPHABET[maxIndex2];
                step += taken2;
            }
            return step;
        }

        private boolean hasMajority(int[] partyMembers) {
            for (int memberCount : partyMembers) {
                if (memberCount > this.memberCount / 2) {
                    return true;
                }
            }
            return false;
        }

        private static int getMemberCount(int[] partyMembers) {
            int sum = 0;
            for (int memberCount : partyMembers) {
                sum += memberCount;
            }
            return sum;
        }

        private static int findMaxIndex(int[] partyMembers) {
            int maxInt = 0;
            int maxIndex = 0;
            for (int i = 0; i < partyMembers.length; i++) {
                int memberCount = partyMembers[i];
                if (memberCount > maxInt) {
                    maxInt = memberCount;
                    maxIndex = i;
                }
            }
            return maxIndex;
        }

        public String solution() {
            StringBuilder builder = new StringBuilder();
            while (memberCount > 0) {
                String nextStep = this.nextStep();
                builder.append(nextStep);
                builder.append(' ');
            }
            return builder.toString();
        }
    }
}
