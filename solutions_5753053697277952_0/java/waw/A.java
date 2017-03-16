package _2016_1c;

import java.io.*;
import java.util.*;

public class A {

    public static void main(String[] args) throws FileNotFoundException {
        //Scanner scanner = new Scanner(new FileInputStream(new File("A-large.in.txt")));
        Scanner scanner = new Scanner(new FileInputStream(new File("A-small-attempt0.in.txt")));
        //Scanner scanner = new Scanner(new FileInputStream(new File("test-input.txt")));

        System.setOut(new PrintStream(new FileOutputStream(new File("outputA.txt"))));

        int testCases = scanner.nextInt();
        scanner.nextLine();


        for (int not = 1; not < testCases + 1; not++) {
            int n = scanner.nextInt();

            TreeSet<Party> parties = new TreeSet<>();
            for(int i=0;i<n;i++){
                parties.add(new Party(scanner.nextInt(), (char)('A' + i)));
            }
            List<String> resultList = solve(n, parties);

            String result = "";
            for(String res : resultList){
                result += res + " ";
            }

            result = result.substring(0, result.length() - 1);

            System.out.println(String.format("Case #%d: %s", not, result));
        }
    }

    private static List<String> solve(int n, TreeSet<Party> parties) {
        List<String> result = new ArrayList<>();

        while(!parties.isEmpty()){
            Party firstParty = parties.pollFirst();
            Party secondParty = parties.pollFirst();

            if(parties.isEmpty() && firstParty.count == secondParty.count){
                result.add(String.valueOf(firstParty.letter) + String.valueOf(secondParty.letter));
                addToParties(parties, firstParty.count - 1, firstParty.letter);
                addToParties(parties, secondParty.count - 1, secondParty.letter);
            } else if(firstParty.count - secondParty.count > 1){
                result.add(String.valueOf(firstParty.letter) + String.valueOf(firstParty.letter));
                addToParties(parties, firstParty.count - 2, firstParty.letter);
                addToParties(parties, secondParty.count, secondParty.letter);
            } else{
                result.add(String.valueOf(firstParty.letter));
                addToParties(parties, firstParty.count - 1, firstParty.letter);
                addToParties(parties, secondParty.count, secondParty.letter);
            }

        }

        return result;
    }

    static void addToParties(TreeSet<Party> parties, int newCount, char letter){
        if(newCount > 0){
            parties.add(new Party(newCount, letter));
        }
    }

    static class Party implements Comparable<Party>{
        int count;
        char letter;
        Party(int count, char letter){
            this.count = count;
            this.letter = letter;
        }

        @Override
        public int compareTo(Party o) {
            int compare = Integer.compare(o.count, this.count);
            if(compare == 0){
                return Character.compare(this.letter, o.letter);
            }
            return compare;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Party party = (Party) o;
            return letter == party.letter;
        }

        @Override
        public int hashCode() {
            return Objects.hash(letter);
        }
    }

}
