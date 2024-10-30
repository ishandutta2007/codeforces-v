import java.io.*;
import java.util.*;

public class A {

    public void solve() {
        int n = in.nextInt(), m = in.nextInt(), k = in.nextInt();
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int a = in.nextInt();
            if (a == 2) {
                if (k > 0) {
                    k--;
                } else {
                    if (m > 0) {
                        m--;
                    } else {
                        ans++;
                    }
                }
            } else {
                if (m > 0) {
                    m--;
                } else {
                    ans++;
                }
            }
        }
        out.println(ans);
    }

    FastScanner in;
    PrintWriter out;

    public void run() {
        try {
            in = new FastScanner();
            out = new PrintWriter(System.out);
            solve();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastScanner(String name) {
            try {
                br = new BufferedReader(new FileReader(name));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextToken());
        }

        public long nextLong() {
            return Long.parseLong(nextToken());
        }

        public double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }

    public static void main(String[] args) {
        new A().run();
    }
}