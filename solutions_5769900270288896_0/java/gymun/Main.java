package com.myung;

import java.io.*;
import java.util.HashMap;

/**
 * R1-2 - Noisy Neighbors
 */
public class Main {
    public static void main(String[] args) throws FileNotFoundException, IOException{
        FileOutputStream fos = new FileOutputStream("B-small-attempt1.out");
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(fos));

        FileInputStream fis = new FileInputStream("B-small-attempt1.in");
        InputStreamReader isr = new InputStreamReader(fis);
        BufferedReader reader = new BufferedReader(isr);

        String line = reader.readLine(); // read first line

        int MaxCase = Integer.parseInt(line);

        for(int caseIndex = 1; caseIndex <= MaxCase ; caseIndex++ ) {
            line = reader.readLine();

            String[] splits = line.split(" ");

            int R = Integer.parseInt(splits[0]);
            int C = Integer.parseInt(splits[1]);
            int N = Integer.parseInt(splits[2]);

            //int testcodst = getCost(5, 2, new boolean[]{false, false, true, false, false, true, true, true, true, true});

            minimumCost = Integer.MAX_VALUE;

            boolean[] tenantPosition = new boolean[R*C];

            setTenants(R, C, tenantPosition, 0, N);

            String out = String.format("Case #%d: %d\n", caseIndex, minimumCost);

            System.out.printf(out);
            writer.write(out);
        }

        reader.close();
        writer.close();
    }

    public static int minimumCost = Integer.MAX_VALUE;

    public static void setTenants(int R, int C, boolean[] tenantsPosition, int settingPostion, int remainTenants){

        if(remainTenants < 1) {
            int cost = getCost(R, C, tenantsPosition);
            if(cost < minimumCost) minimumCost = cost;
            return;
        }

        if(settingPostion >= R*C || R*C - settingPostion < remainTenants) return;

        // set tenant
        boolean[] cloned = tenantsPosition.clone();
        cloned[settingPostion] = true;
        setTenants(R, C, cloned, settingPostion+1, remainTenants-1);

        // no set tenant
        setTenants(R, C, tenantsPosition.clone(), settingPostion+1, remainTenants);
    }

    public static int getCost(int R, int C, boolean[] tenantsPosition){
        HashMap<String, Integer> CheckedWall = new HashMap<String, Integer>();

        int maxLength = R*C;

        for( int i = 0; i < maxLength ; i ++ ){
            if(!tenantsPosition[i]) {
                continue;
            }

            int x = i / R;
            int y = i % R;

            if(x > 1 && tenantsPosition[(x-1)*R + (y)])
                CheckedWall.put(String.format("x_%d_%d_y_%d", x-1, x, y), 1);
            if(y > 1 && tenantsPosition[(x)*R + (y-1)])
                CheckedWall.put(String.format("y_%d_%d_x_%d", y-1, y, x), 1);
            if((x+1) < C && tenantsPosition[(x+1)*R + (y)])
                CheckedWall.put(String.format("x_%d_%d_y_%d", x, x+1, y), 1);
            if((y+1) < R && tenantsPosition[(x)*R + (y+1)])
                CheckedWall.put(String.format("y_%d_%d_x_%d", y, y+1, x), 1);
        }

        return CheckedWall.keySet().size();
    }
}
