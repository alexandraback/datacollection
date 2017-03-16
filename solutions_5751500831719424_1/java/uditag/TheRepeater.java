import java.io.*;
import java.util.ArrayList;
import java.util.List;

/**
 * Created with IntelliJ IDEA.
 * User: udit.aga
 * Date: 5/3/14
 * Time: 9:34 PM
 * To change this template use File | Settings | File Templates.
 */
public class TheRepeater {

    private static BufferedReader bufferedReader;
    private static BufferedWriter bufferedWriter;
    private static int N;
    private static String[] strings;

    public static void main(String[] args) throws IOException {
        bufferedReader = new BufferedReader(new FileReader("C:\\Users\\udit.aga\\Downloads\\A-large.in"));
        bufferedWriter = new BufferedWriter(new FileWriter("C:\\Users\\udit.aga\\Downloads\\out.txt"));

        int T = readInt();
        int k=0;
        while (T > 0){
            T--;
            k++;
            N = readInt();
            strings = new String[N];
            for(int i=0;i<N;i++){
                strings[i] = bufferedReader.readLine();
            }
            int minMoves = calculateMinMovesRequired();

            bufferedWriter.write("Case #"+k+": ");
            if(minMoves == -1){
                bufferedWriter.write("Fegla Won\n");
            }
            else
                bufferedWriter.write(minMoves+"\n");
            bufferedWriter.flush();
        }

        bufferedWriter.close();
        bufferedReader.close();
        return;
    }

    private static int calculateMinMovesRequired() {
        int minMoves = 0;
        int[][] count = new int[1000][N];
        List<Character> list = new ArrayList<Character>();

        int index =0;
        for(int i=0;i<N;i++){
            int length = strings[i].length();
            char last = strings[i].charAt(0);
            index=0;
            int counter = 1;
            for(int j=1;j<length;j++){
                if(strings[i].charAt(j)  == last)
                    counter++;
                else{
                    if(i == 0)
                        list.add(last);
                    else if(index >= list.size() ||  last != list.get(index))
                        return -1;
                    count[index][i] = counter;
                    last = strings[i].charAt(j);
                    counter = 1;
                    index++;
                }
            }
            if(i == 0)
                list.add(last);
            else if(index != (list.size()-1) ||  last != list.get(index))
                return -1;
            count[index][i] = counter;

        }

        index  = list.size();
        int[] optimalLength = new int[index+1];
        for(int i=0;i<index;i++){
            int min = count[i][0];
            int max = min;
            for(int j =1;j<N;j++){
                min = Math.min(min,count[i][j]);
                max = Math.max(max,count[i][j]);
            }
            if(min == 0)
                return  -1;

            optimalLength[i] = min;
            int minIndividualMoves = Integer.MAX_VALUE;
            while(optimalLength[i] <= max){
                int temp = 0;
                for(int j= 0;j<N;j++){
                    temp += Math.abs(optimalLength[i] - count[i][j]);
                }
                minIndividualMoves = Math.min(minIndividualMoves,temp);
                optimalLength[i]++;
            }

            minMoves += minIndividualMoves;
        }

        return minMoves;
    }

    private static int readInt() throws IOException {
        String input;
        input = bufferedReader.readLine();
        int val;
        val = Integer.parseInt(input);
        return val;
    }
}
