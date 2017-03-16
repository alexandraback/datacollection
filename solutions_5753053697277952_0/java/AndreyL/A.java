package round1.roundC;

import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

public class A {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new FileReader("src/round1/roundC/A-small-attempt0 (2).in"));
        PrintWriter pw = new PrintWriter("src/round1/roundC/A-large.out");
        int testCases = sc.nextInt();
     //   testCases=1;
        String alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ";


        for (int casen = 0; casen < testCases; casen++) {
            pw.printf("Case #%d: ",casen+1);

            int n = sc.nextInt();
            int arr[]=new int[n];
            for (int i = 0; i < n; i++) {
                arr[i]=sc.nextInt();
            }
//            int sum=0;
//            for (int i = 0; i < n; i++) {
//                sum+=arr[i];
//            }
            int max = findMax(arr);
           // System.out.println(Arrays.toString(arr));
            while(max!=0) {

                Queue<Integer> indexOfMax = numOfMax(max, arr);

               // System.out.println(indexOfMax);
                if (indexOfMax.size() % 2 == 1) {
                    int t = indexOfMax.poll();
                    arr[t]--;
                    pw.print(alphabet.charAt(t) + " ");
                }
                while (!indexOfMax.isEmpty()) {
                    int t1 = indexOfMax.poll();
                    int t2 = indexOfMax.poll();
                    arr[t1]--;
                    arr[t2]--;
                    pw.print(alphabet.charAt(t1) );
                    pw.print(alphabet.charAt(t2) + " " );
                }
                max = findMax(arr);
            }
            pw.println();





            pw.flush();
        }

        pw.close();
        sc.close();

    }
    public static int findMax(int[] arr){
        int max=0;
        for (int i = 0; i < arr.length; i++) {
            if(arr[i]>max){
                max=arr[i];
            }
        }
        return max;
    }

    public static Queue<Integer> numOfMax(int max,int[] arr){

        Queue<Integer> arrOfIndexOfMaxNum=new LinkedList<>();
        for (int i = 0; i < arr.length; i++) {
            if(arr[i]==max) arrOfIndexOfMaxNum.add(i);
        }
       return arrOfIndexOfMaxNum;
    }

}
