package com.gmail.danielcomsa.codejam;

import java.io.*;

/**
 * Created by Daniel Comsa (daniel.comsa@tora.com).
 */
public class Utility {
    public static String getOutputFile(String inputFile) {
        String base = inputFile;
        if (inputFile.endsWith(".in")) {
            base = inputFile.substring(0, inputFile.length() - 3);
        }
        return base + ".out";
    }

    public static BufferedReader getReader(Class aClass, String file) throws FileNotFoundException {
        String path = aClass.getResource(".").getPath();
        return new BufferedReader(new FileReader(path + "/" + aClass.getSimpleName() + "/" + file));
    }

    public static PrintStream getPrintStream(Class aClass, String file) throws FileNotFoundException {
        String path = aClass.getResource(".").getPath() + "/" + aClass.getSimpleName();
        String outputFile = file;
        if (file.endsWith(".in")) {
            outputFile = file.substring(0, file.length() - 3);
        }

        return new PrintStream(path + "/" + outputFile + ".out");

    }

    public static PrintStream getWriter(Class clazz, String outputFile) throws FileNotFoundException {
        return new PrintStream(getPath(clazz, outputFile));
    }

    private static String getPath(Class clazz, String file) {
        String resPath = "/" + clazz.getName().replaceAll("\\.", "/") + "/";
        return clazz.getResource(resPath).getPath() + file;
    }

    public static int readInt(BufferedReader reader) throws IOException {
        return Integer.parseInt(reader.readLine());

    }

    public static int[] readInts(BufferedReader reader) throws IOException {
        String line = reader.readLine();
        String[] tokens = line.split(" ");
        int[] result = new int[tokens.length];
        for (int i = 0; i < result.length; i++) {
            result[i] = Integer.parseInt(tokens[i]);
        }

        return result;
    }

    public static int[][] readMatrix(int width, int height, BufferedReader reader) throws IOException {
        int[][] result = new int[width][];
        for (int i = 0; i < width; i++) {
            result[i] = readInts(reader);
        }
        return result;
    }
}
