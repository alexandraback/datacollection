import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

/**
 * Created by jarrett on 02/05/15.
 */
public class B {
    public static void main(String[] args) throws IOException {

        BufferedReader in = new BufferedReader(new FileReader(new File("read.txt")));
        int numCases = Integer.parseInt(in.readLine());
        for (int i = 0; i < numCases; i++) {
            String[] input = in.readLine().split(" ");
            int r = Integer.parseInt(input[0]);
            int c = Integer.parseInt(input[1]);
            int t = Integer.parseInt(input[2]);
            int count = 0;
            int[][] house = new int[r][c];
            int half;
            int result;
            if((r*c)%2 == 0){
                half = (r*c)/2;
            }
            else{
                half = (r*c)/2 +1;
            }
            if(t <= half){
                result = 0;
            }
            else{
                fillTenants(house, r, c);
                for(int j = (r*c)-t; j>0; j--){
                    removeHighest(house, r, c);
                }
                result = unhap(house,r,c);
            }





            System.out.println("Case #" + (i+1) + ": " + result);

        }
    }
    public static void removeHighest(int[][] house, int r, int c){
        int highest = 0;
        int p = 0;
        int q = 0;
        int i = 0;
        int j = 0;
        for(i=0; i< r; i++) {
            for (j = 0; j < c; j++) {
                if(house[i][j] > highest){
                    highest = house[i][j];
                    p = i;
                    q = j;
                }
            }
        }
        house[p][q] = 0;
        if(p>0){
            house[p-1][q]--;
        }
        if(p<r-1){
            house[p+1][q]--;
        }
        if(q>0){
            house[p][q-1]--;
        }
        if(q<c-1){
            house[p][q+1]--;
        }

    }
    public static int unhap(int[][] house, int r, int c){
        int count = 0;
        int i = 0;
        int j = 0;
        for(i=0; i< r; i++) {
            for (j = 0; j < c; j++) {
                if(house[i][j] > 0) {
                    count += house[i][j];
                    house[i][j] = 0;
                    if (i > 0) {
                        house[i - 1][j]--;
                    }
                    if (i < r - 1) {
                        house[i + 1][j]--;
                    }
                    if (j > 0) {
                        house[i][j - 1]--;
                    }
                    if (j < c - 1) {
                        house[i][j + 1]--;
                    }
                }

            }
        }
        return count;
    }
    public static void  fillTenants(int[][] house, int r, int c){

        for(int i = 0; i< r; i++){
            for(int j = 0; j< c; j++){
                if((i==0 && j == 0) ||(i==0 && j == c-1) || (i==r-1 && j ==0) || (i==r-1 && j==c-1)){
                    if(r==1 || c ==1){
                        house[i][j] = 1;
                    }
                    else {
                        house[i][j] = 2;
                    }
                }
                else if(i==0 || j ==0 ||i==r-1 || j==c-1){
                    if(r==1 || c ==1){
                        house[i][j] = 2;
                    }
                    else {
                        house[i][j] = 3;
                    }
                }
                else{
                    house[i][j] = 4;
                }

            }
        }


    }
}
