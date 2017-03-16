package googleJam.round1b2014;

import java.io.*;
import java.util.Arrays;

/**
 * Created by andi on 5/2/2015.
 */
public class B {
    public static void main(String[] args){
        BufferedReader buffer = null;
        BufferedWriter bw = null;

        try{
            buffer = new BufferedReader(new FileReader("D:\\gjam\\TestB.in"));
            File file = new File("D:\\gjam\\TestBB.out");
            if (!file.exists()) {
                file.createNewFile();
            }

            FileWriter fw = new FileWriter(file.getAbsoluteFile());
            bw = new BufferedWriter(fw);

            String line = buffer.readLine();
            if(line != null ){
                Integer caseCount = Integer.parseInt(line);

                for(int i=1; i<= caseCount; i++ ){
                    System.out.println("-------CASE="+i+"-------------------------");
                    StringBuffer output = new StringBuffer();

                    line = buffer.readLine();
                    String[] l = line.split(" ");
                    Integer R = Integer.parseInt(l[0]);
                    Integer C = Integer.parseInt(l[1]);
                    Integer N = Integer.parseInt(l[2]);

                    long result = solve(R,C,N);
                    //System.out.println(R+" "+C+" "+N);
                    output.append("Case #"+i+": "+result+"\n");
                    //System.out.println("Result = "+result);

                    bw.write(output.toString());
                }

            }
        }
        catch(IOException e){
            e.printStackTrace();
        }
        finally {
            try {

                if (buffer != null) buffer.close();
                if (bw != null) bw.close();

            } catch (IOException ex) {
                ex.printStackTrace();
            }


        }

    }

    public static int solve(int R, int C, int N){
        if(N == 0) return 0;
        if(N == R*C){
            int[][] house = initializeHouse(R, C, 1);
            return noiseIndex(house);
        }
        else{
            int values = 1;
            if(2*N>R*C){
                //set only empty pos
                values = 0;
            }
            int[][] house = initializeHouse(R, C, values==0?1:0);
            int n = N;
            if(values == 0) n = R*C-N;
            return generatePosition(house,n,0,0,values );
        }
    }

    public static int noiseIndex(int[][] house){
        int result = 0;
        for(int i=0; i< house.length; i++){
            for(int j=0; j<house[0].length; j++){
                if(house[i][j] == 0) continue;
                if(i+1 < house.length){
                    if(house[i+1][j] == 1) result ++;
                }
                if(j+1 < house[0].length){
                    if(house[i][j+1] == 1) result ++;
                }
            }
        }
        return result ++;
    }

    public static int[][] initializeHouse(int R, int C, int value){
        int[][] house = new int[R][C];
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                house[i][j] = value;
            }
        }
        return house;
    }

    public static int generatePosition( int[][] house, int N, int I, int J, int val){
        int minValue = Integer.MAX_VALUE;
        for(int i=I; i< house.length; i++){

            for(int j=J; j<house[0].length; j++){
                int prevVal = house[i][j];
                house[i][j] = val;
                if(N-1 == 0) {
                    int minVal = noiseIndex(house);
                    if(minVal < minValue) minValue = minVal;
                    house[i][j] = prevVal;
                }
                else {
                    int[][] cH = new int[house.length][house[0].length];
                    arrayCopy(house, cH);
                    house[i][j] = prevVal;
                    int minVal = generatePosition(cH, N - 1, i, j, val);
                    if(minVal < minValue) minValue = minVal;
                }
            }
            J = 0;
        }
        return minValue;
    }

    public static void main3(String[] args){
        int[][] houses = new int[][]{
                {1},
                {0},
                {0},
                {1}
        };
        int res = noiseIndex(houses);
        System.out.println(res);

    }

    public static void arrayCopy(int[][] aSource, int[][] aDestination) {
        for (int i = 0; i < aSource.length; i++) {
            System.arraycopy(aSource[i], 0, aDestination[i], 0, aSource[i].length);
        }
    }
}
