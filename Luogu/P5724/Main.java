import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt(), max = -1, min = 1001;
        for (int i = 0; i < n; i++) {
            int x = cin.nextInt();
            if (x > max) {
                max = x;
            }
            if (x < min) {
                min = x;
            }
        }
        System.out.println(max - min);
        cin.close();
    }
}