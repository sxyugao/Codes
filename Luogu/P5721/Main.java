import java.text.DecimalFormat;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt(), cur = 0;
        DecimalFormat df = new DecimalFormat("00");
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                cur++;
                System.out.print(df.format(cur));
            }
            System.out.println();
        }
    }
}