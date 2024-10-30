import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        ESmailikZhordana solver = new ESmailikZhordana();
        solver.solve(1, in, out);
        out.close();
    }

    static class ESmailikZhordana {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            String result = "0000000000000000000000000011111111111100000000000000000000000000000000000000000000000011111111111111111111000000000000000000000000000000000000000000111111111111111111111111000000000000000000000000000000000000010011111111111111111111111111100000000000000000000000000000000011000111111111111111111111111111000000000000000000000000000000111110011111111111111111111111111111000000000000000000000000000111111000111111111111111111111111111110000000000000000000000001111111110011111111111111111111111111111110000000000000000000001111111111000111111111111111111111111111111100000000000000000001111111111110011111111111111111111011111111111000000000000000001111111111111000101111111111111111100001111111110000000000000001111111111111110010100010111111111111101111111111100000000000000111111111111111001000100011011111111100000111111110000000000000111111111111111110001010100100111111111110111111111100000000000111111111111111110010111011000111111111100001011111111000000000001111111111111111011110100101001111111110110001111111100000000010011111111111111000000011110110011111111001110001111111000000011100111111111111101010111010001101011111110010010011111110000001011111111111111100111000001011100001111111101011100111111000000100011111111111100110110111111010101111111100111010111111100000110100111111111110110001111000000010011111111000001111111111000010011111111111111000010100101010111101111111001010010111111100011101010111111111110111000111111001000111111101111101001111111000000100011111111110001001110100111101011111110010011101111111100111110101111111111010110101011000000111111111101011000001111110010000010111111111111001110000101110111111111110000110110111111011011101111111111111110010010111100001111001110011010001011111110001010001111111111111101011110100111111110111101000011101111111111101110111111111111110000101011001111100011000110101011111111100010001001111111111111101000000101100011011001001111100111111111101011101111111111111111111101111111011000001110100100111111111100001000111111111111111111100000010100001010001110111011111111111101101111111111111111111111110111000101101110010000100011111111010100101111111111111111111001110001010011111101111000100111111100011110111111111111111111001110011111011111100010001110111111111111010011111111111111111110001011001111111111101101100011111110001001011111111111111111100010000001111111111010000010111111111110101100011111111111111000111010111111111111100010111000111111101010000101111111111110001110001000101111111111011001001011111100100010111111111111001110001110111000111111111001001111101111110011111110111111111101101110001110110111111111110111101000111111001000010011111111110000001110010000000111111111000100110111111100001100011111111111101110101111011101011111111001010111111111100001100111011111111100101110100111011100111111001100000111111110000011110001111111111000101011000001011011111110010110111111110000000000011111111111001010000111110000001111111111001011111111000000110111111111111110111011010011101101111111110110111111111100000001110011111111111001000111011011100011111110000011111111100000000000011111111111110001001001000100101111111011011111111100000000001100111111111111101101101101110111111111001001111111110000000000011011111111111100011100010010001111111110111111111110000000000000111111111111111000010101100010111111110001111111110000000000000011111111111111100100011100101111111111011111111111000000000000000111111111111100011011000111111111111000111111111000000000000000001111111111110011000001001111111111110111111111000000000000000000011111111111001111111111111111111111111111111000000000000000000000111111111000111111111111111111111111111111000000000000000000000000111111100111111111111111111111111111110000000000000000000000000001111110011111111111111111111111111110000000000000000000000000000001110001111111111111111111111111100000000000000000000000000000000011001111111111111111111111111100000000000000000000000000000000000000111111111111111111111110000000000000000000000000000000000000000001111111111111111111100000000000000000000000000000000000000000000000011111111111100000000000000000000000000";
            int r = in.nextInt(), c = in.nextInt();
            out.println(result.charAt(c * 64 + r) == '1' ? "IN" : "OUT");
        }

    }

    static class FastScanner {
        public BufferedReader br;
        public StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public FastScanner(String fileName) {
            try {
                br = new BufferedReader(new FileReader(fileName));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

    }
}