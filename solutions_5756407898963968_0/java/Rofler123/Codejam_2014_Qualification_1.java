
package codejam_2014_qualification_1;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.InputMismatchException;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Codejam_2014_Qualification_1
{
    private static int T;
    private static final String filename = "A-small-attempt0";
    private static int[][] a_arr = new int[4][4];
    private static int[][] b_arr = new int[4][4];
    private static int a;
    private static int b;
    public static void main(String[] args)
    {
        String file_content = read_file(filename + ".in");
        try
        {
            PrintWriter writer = new PrintWriter(filename + ".out", "UTF-8");
            Scanner sc = new Scanner(file_content);
            T = sc.nextInt();
            for(int t=0; t<T; t++)
            {
                a = sc.nextInt();
                a--;
                for(int i=0; i<4; i++)
                {
                    for(int j=0; j<4; j++)
                    {
                        a_arr[i][j] = sc.nextInt();
                    }
                }
                b = sc.nextInt();
                b--;
                for(int i=0; i<4; i++)
                {
                    for(int j=0; j<4; j++)
                    {
                        b_arr[i][j] = sc.nextInt();
                    }
                }
                int[] a_list = a_arr[a].clone();
                int[] b_list = b_arr[b].clone();
                int commonalities=0;
                int number = -1;
                for(int i=0; i<4; i++)
                {
                    for(int j=0; j<4; j++)
                    {
                        if(a_list[i] == b_list[j])
                        {
                            commonalities++;
                            number = a_list[i];
                        }
                    }
                }
                writer.print("Case #" + (t + 1) + ": ");
                if (commonalities == 1) {
                    writer.println(number);
                } else if (commonalities > 1) {
                    writer.println("Bad magician!");
                } else if (commonalities == 0) {
                    writer.println("Volunteer cheated!");
                }
            }
            writer.close();
            sc.close();
        } catch(InputMismatchException imme) {
        } catch(FileNotFoundException e) {
        } catch (UnsupportedEncodingException ex) {
            Logger.getLogger(Codejam_2014_Qualification_1.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    private static String read_file(String f)
    {
        String file_content = "";
        try
        {
            BufferedReader br = new BufferedReader(new FileReader(f));
            StringBuilder sb = new StringBuilder();
            String line = br.readLine();
            while (line != null)
            {
                sb.append(line);
                sb.append("\n");
                line = br.readLine();
            }
            file_content = sb.toString();
        } catch (FileNotFoundException e) {
        } catch (IOException ex) {
            Logger.getLogger(Codejam_2014_Qualification_1.class.getName()).log(Level.SEVERE, null, ex);
        }
        return file_content;
    }
}

