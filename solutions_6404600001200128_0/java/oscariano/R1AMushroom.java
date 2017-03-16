/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package com.podervisual.codejam;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;

/**
 *
 * @author osdroid
 */
public class R1AMushroom {

    private static int[] solve(BufferedReader reader) throws Exception {
        String linea = reader.readLine();
        linea = reader.readLine();
        String[] pedazos = linea.split(" ");
        int[] valores = new int[pedazos.length];
        for (int i = 0; i < valores.length; i++) {
            valores[i] = Integer.parseInt(pedazos[i]);
        }
        int[] resultado = new int[2];

        resultado[0] = 0;
        resultado[1] = 0;
        int max = 0;
        for (int i = 1; i < valores.length; i++) {
            int diferencia = valores[i - 1] - valores[i];
            if (diferencia > 0) {
                resultado[0] += diferencia;
            }
            if (diferencia > max) {
                max = diferencia;
            }
        }
        
        for (int i = 0; i < valores.length - 1; i++) {
            if (valores[i] < max) {
                resultado[1] += valores[i];
            } else {
                resultado[1] += max;
            }
        }
        return resultado;
    }

    private static void solve(String filename) throws Exception {
        BufferedReader reader = new BufferedReader(
                new InputStreamReader(new FileInputStream(filename + ".in")));
        PrintStream writer = new PrintStream(new File(filename + ".out"));
        int numCases = Integer.parseInt(reader.readLine());
        for (int i = 0; i < numCases; i++) {
            int[] resultado = solve(reader);
            writer.println(String.format("Case #%d: %d %d", i + 1, resultado[0], resultado[1]));
        }
        writer.close();
    }
    
    public static void main(String[] args) throws Exception {
        System.out.println("File?: ");
        BufferedReader lector = new BufferedReader(
                new InputStreamReader(System.in));
        String filename = lector.readLine();
        solve(filename);
    }
    
}
