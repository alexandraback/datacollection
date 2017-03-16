import java.util.*;

public class TheRepeater {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numTestCases = sc.nextInt();
        for (int testCase = 1; testCase <= numTestCases; ++testCase) {
            int numWords = sc.nextInt();
            Set<List<Group>> words = new HashSet<>();
            for (int i = 0; i < numWords; ++i)
                words.add(toGroups(sc.next()));
            System.out.printf("Case #%d: %s\n", testCase,
                    isSolvable(words) ? getMinActions(words) : "Fegla Won");
        }
    }

    static boolean isSolvable(Set<List<Group>> words) {
        List<Group> firstWord = words.iterator().next();
        for (List<Group> word : words) {
            if (word.size() != firstWord.size())
                return false;
            for (int i = 0; i < word.size(); ++i)
                if (word.get(i).character != firstWord.get(i).character)
                    return false;
        }
        return true;
    }

    static int getMinActions(Set<List<Group>> words) {
        int numGroups = words.iterator().next().size();
        int totalActions = 0;

        for (int i = 0; i < numGroups; ++i) {
            Collection<Integer> charCounts = new ArrayList<>();
            for (List<Group> word : words)
                charCounts.add(word.get(i).count);

            int minActions = Integer.MAX_VALUE;
            for (int targetCount = 1; targetCount <= 100; ++targetCount) {
                int actions = 0;
                for (int count : charCounts) {
                    actions += Math.abs(count - targetCount);
                }
                minActions = Math.min(minActions, actions);
            }

            totalActions += minActions;
        }
        return totalActions;
    }

    static class Group {
        final char character;
        final int count;

        Group(char character, int count) {
            this.character = character;
            this.count = count;
        }
    }

    static List<Group> toGroups(String s) {
        List<Group> result = new ArrayList<>();
        int i = 0;
        while (i < s.length()) {
            char c = s.charAt(i);
            int count = 0;
            while (i < s.length() && s.charAt(i) == c) {
                ++i;
                ++count;
            }
            result.add(new Group(c, count));
        }
        return result;
    }
}
