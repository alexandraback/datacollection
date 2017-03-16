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
public class R1AHaircut {
    
    private static int calcular(int[] tiempos, long tiempo) {
        int atendidos = 0;
        tiempo--;
        for (int i = 0; i < tiempos.length; i++) {
            atendidos += 1 + tiempo / tiempos[i];
        }
        return atendidos;
    }


    private static int solve(BufferedReader reader) throws Exception {
        String linea = reader.readLine();
        String[] pedazos = linea.split(" ");
        int cantidad = Integer.parseInt(pedazos[0]);
        int position = Integer.parseInt(pedazos[1]);
        linea = reader.readLine();
        pedazos = linea.split(" ");
        int[] tiempos = new int[cantidad];
        for (int i = 0; i < tiempos.length; i++) {
            tiempos[i] = Integer.parseInt(pedazos[i]);
        }
        long tiempoMin = 1;
        long tiempoMax = 2;
        int atendidosMax = calcular(tiempos, tiempoMax);
        
        while (atendidosMax < position) {
            tiempoMin = tiempoMax;
            tiempoMax *= 2;
            atendidosMax = calcular(tiempos, tiempoMax);
        }
        long delta = tiempoMax - tiempoMin;
        
        while (delta > 1) {
            long tiempoNuevo = (tiempoMax + tiempoMin) / 2;
            int atendidosNuevo = calcular(tiempos, tiempoNuevo);
            if (atendidosNuevo > position) {
                tiempoMax = tiempoNuevo;
            } else {
                tiempoMin = tiempoNuevo;
            }
            delta = tiempoMax - tiempoMin;
        }
        atendidosMax = calcular(tiempos, tiempoMax);
        while (atendidosMax >= position) {
            tiempoMax--;
            atendidosMax = calcular(tiempos, tiempoMax);
        }
        int i = 0;
        long calcTiempo = tiempoMax;
        while (atendidosMax <= position) {
            if (calcTiempo % tiempos[i] == 0) {
                atendidosMax++;
                if (atendidosMax == position)
                    return i + 1;
            }
            i++;
            if (i >= tiempos.length) {
                System.out.println("arstoienrastoeirsnat");
                calcTiempo++;
                i = 0;
            }
        }
        return i;
    }

    private static void solve(String filename) throws Exception {
        BufferedReader reader = new BufferedReader(
                new InputStreamReader(new FileInputStream(filename + ".in")));
        PrintStream writer = new PrintStream(new File(filename + ".out"));
        int numCases = Integer.parseInt(reader.readLine());
        for (int i = 0; i < numCases; i++) {
            writer.println(String.format("Case #%d: %d", i + 1, solve(reader)));
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
