import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        System.out.print("#" + test_case + " ");
        int[][] v = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                v[i][j] = sc.nextInt();
            }
        }

        int ans = 0;
        for (int i = 0; i <= n - m; i++) {
            for (int j = 0; j <= n - m; j++) {  // 추가된 루프: 모든 부분 배열을 검사
                int sum = 0;
                for (int x = i; x < i + m; x++) {
                    for (int y = j; y < j + m; y++) {
                        sum += v[x][y];
                    }
                }
                ans = Math.max(ans, sum);
            }
        }

        System.out.println(ans);
        sc.close();
    }
}