import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * Created with IntelliJ IDEA.
 * User: yilin
 * Date: 14-4-11
 * Time: 下午11:54
 * To change this template use File | Settings | File Templates.
 */
public class Dashboard {

    public static Set findElements(Scanner input, int line){
        Set<Integer> first = new HashSet<Integer>();
        for(int i=1;i<5;i++){
            String cards = input.nextLine();
            if(i==line){
                for(String num: cards.split(" ")){
                    first.add(Integer.parseInt(num));
                }
            }
        }
        return first;
    }

    public static void main(String argsp[]) throws FileNotFoundException {
        Scanner input = new Scanner(new FileReader("input"));
        Set<Integer> first,second;
        // first line
        input.nextLine();
        int lineA, lineB;
        int count =0;
        while(input.hasNext()){
            count++;
            lineA = input.nextInt();
            input.nextLine();
            first = findElements(input,lineA);
            lineB = input.nextInt();
            input.nextLine();
            second = findElements(input,lineB);
            first.retainAll(second);
            int n = first.size();
            if(n==0){
                System.out.printf("Case #%d: Volunteer cheated!\n", count);
            }
            if(n==1){
                int card = first.iterator().next();
                System.out.printf("Case #%d: %d\n", count,card);
            }
            if (n>1){
                System.out.printf("Case #%d: Bad magician!\n", count);
            }

        }

    }
}
