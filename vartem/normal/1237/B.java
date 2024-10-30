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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.nextIntArray(n);
            int[] b = in.nextIntArray(n);
            Utils.reverse(a);
            Utils.reverse(b);
            int[] pos = new int[n];
            for (int i = 0; i < n; i++) {
                pos[a[i] - 1] = i;
            }
            int maxStart = 0;
            int ans = 0;
            for (int i = 0; i < n; i++) {
                if (pos[b[i] - 1] < maxStart) {
                    ans++;
                }
                maxStart = Math.max(pos[b[i] - 1], maxStart);
            }
            out.println(ans);
        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

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

        public int[] nextIntArray(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }

    }

    static class Utils {
        public static void reverse(int[] a) {
            for (int i = 0, j = a.length - 1; i < j; i++, j--) {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }

    }
}