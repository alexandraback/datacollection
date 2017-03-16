import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: Pavel
 * Date: 09.04.2016
 * Time: 17:26
 */
public class CodeJam {



    public static void main(String[] argv) {
        System.out.println("Run");

        Scanner scanner = new Scanner(System.in);

        int count = scanner.nextInt();

        //int i = 1;

        for (int i = 1; i <= count; i++) {
            int N = scanner.nextInt();

            int[] parties = new int[N];

            for (int j = 0; j < N; j++) {
                                 parties[j] = scanner.nextInt();
            }

            System.out.println("Case #" + i + ":" + getResult(parties));
        }
    }


    private static String getResult(int[] parties) {
        String ret = "";

        int count = 0;

        for (int party: parties)
            count +=party;

        while (count > 0) {
            ret+=" ";


                int max = 0;

                for (int party : parties)
                    if (party > max)
                        max = party;

                for (int i = 0; i < parties.length; i++) {
                    if (parties[i] == max) {
                        ret += (char)('A' + i);
                        parties[i]--;
                        count--;
                        break;
                    }
                }

            if (count != 2) {
                max = 0;

                for (int party : parties)
                    if (party > max)
                        max = party;

                for (int i = 0; i < parties.length; i++) {
                    if (parties[i] == max) {
                        ret += (char)('A' + i);
                        parties[i]--;
                        count--;
                        break;
                    }
                }
            }

        }

        return ret;
    }

}
