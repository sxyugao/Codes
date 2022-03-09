import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), m = in.nextInt(), k = in.nextInt();
        int[] cnt = new int[k];
        Boolean[][] vis = new Boolean[k][m];
        Arrays.fill(cnt, 0);
        for (int i = 0; i < k; i++)
            Arrays.fill(vis[i], false);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                int x = in.nextInt() - 1;
                if (!vis[x][j]) {
                    vis[x][j] = true;
                    cnt[x]++;
                }
            }
        for (int i = 0; i < k; i++)
            System.out.print(cnt[i] + " ");
    }
}