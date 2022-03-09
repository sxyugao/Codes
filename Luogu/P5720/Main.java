import java.util.Scanner;

public class Main {
  public static void main(String[] args) throws Exception {
    Scanner cin = new Scanner(System.in);
    int x = cin.nextInt(), day = 0;
    while (x != 0) {
      x /= 2;
      day++;
    }
    System.out.println(day);
    cin.close();
  }
}