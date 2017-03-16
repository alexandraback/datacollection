import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * Created by slycer on 5/2/15.
 */
public class NoisyNeighbors {

    public static void main ( String [] arg ) throws FileNotFoundException {

        Scanner s = new Scanner( System.in );
        System.setOut( new PrintStream( "NoisyNeighbors.out" ) );

        int cases = s.nextInt();
        for ( int t=1; t<=cases; t++ ){
            int r = s.nextInt();
            int c = s.nextInt();
            int n = s.nextInt();
            bestScore = 1<<24;
            seen = new HashSet<>();
            solve( new boolean[r][c], n );
            System.out.println("Case #" + t + ": " + bestScore);
            System.err.println("Case #" + t + ": " + bestScore);

        }
    }

    static int bestScore = 0;
    static Set<String> seen = new HashSet<>();
    public static void  solve( boolean [][] building, int left ){
            String state= state( building );
        if ( seen.contains( state ) ){
            return ;
        } else {
            seen.add( state );
        }

            if ( left == 0 ){
                int score = happines( building );
                //print( building );
                bestScore = Math.min( bestScore, score );

            } else {
                for ( int i=0; i<building.length; i++ ){
                    for ( int j=0; j<building[0].length; j++ ){
                        if ( building[i][j] == false ){
                            building[i][j] = true;
                            solve( building, left -1 );
                            building[i][j] = false;
                        }
                    }
                }
            }
    }

    public static void print( boolean [][] building ){
        System.err.println();
        for ( int i=0; i<building.length; i++ ){
            for ( int j=0; j<building[0].length; j++ ){
                System.err.print( building[i][j] + " " );
            }
            System.err.println();
        }
    }

    public static String state( boolean [][] building ){
        String ret = "";
        for ( int i=0; i<building.length; i++ ){
            for ( int j=0; j<building[0].length; j++ ){
                ret+= building[i][j];
            }
        }
        return ret;
    }

    public static int happines(  boolean [][] building ){
        int score = 0;
        for ( int i=0; i<building.length; i++ ){
            for ( int j=0; j<building[0].length; j++ ){
                if ( building[i][j] ){
                    if ( i>0 && building[i-1][j] ){
                        score ++;
                    }
                    if ( j>0 && building[i][j-1] ){
                        score ++;
                    }
                }
            }
        }
        return score;
    }

}
