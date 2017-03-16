import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: chenbin
 * Date: 4/18/15
 * Time: 9:25 AM
 * To change this template use File | Settings | File Templates.
 */
public class C {

    public static void main(String... args) {
        C c = new C();
        Scanner scanner = new Scanner(System.in);
        int caseNum = scanner.nextInt();
        for(int i=0; i< caseNum; i++) {

            int N = scanner.nextInt();
            int[] input = new int[N];
            for (int j = 0; j < N; j++) {
                input[j] = scanner.nextInt();
            }


            System.out.println(String.format("Case #%d: %d %d", i + 1, c.method1(input), c.method2(input)));
        }
    }


    public int method1(int[] input) {
        int total =0;
        for(int i=0; i< input.length-1; i++) {
            if(input[i+1] < input[i]) {
                total += input[i] - input[i+1];
            }
        }
        return total;
    }

    public int method2(int[] input) {
        int gap = 0;
        for(int i=0; i< input.length-1; i++) {
            if(input[i+1] < input[i]) {
                gap = Math.max(gap, input[i] - input[i+1]);
            }
        }

        int total =0;
        for(int i=0; i< input.length -1; i++) {
            if(input[i] > gap) {
                total += gap;
            } else {
                total += input[i];
            }
        }
        return total;
    }
}
