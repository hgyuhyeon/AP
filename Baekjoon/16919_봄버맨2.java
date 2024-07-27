import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer; 

public class Main {
    static char[][] bomb(char[][] arr, int n, int m) {
        char[][] tmp = new char[n][m];
        for (int i = 0; i < n; i++) Arrays.fill(tmp[i], 'O');
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 'O') {
                    tmp[i][j] = '.';
                    if (i > 0) tmp[i-1][j] = '.';
                    if (i < n-1) tmp[i+1][j] = '.';
                    if (j > 0) tmp[i][j-1] = '.';
                    if (j < m-1) tmp[i][j+1] = '.';
                }
            }
        }
        return tmp;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken()), sec = Integer.parseInt(st.nextToken());
        char[][] arr = new char[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            String str = st.nextToken(); 
            for (int j = 0; j < m; j++) {
                arr[i][j] = str.charAt(j);
            }
        }
        if (sec == 1) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) System.out.print(arr[i][j]);
                System.out.println();
            }
        }
        else if (sec % 2 == 0) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) System.out.print('O');
                System.out.println();
            }
        }
        else {
            arr = bomb(arr, n, m);
            if (sec % 4 == 1) arr = bomb(arr, n, m);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) System.out.print(arr[i][j]);
                System.out.println();
            }
        }
    }
}
