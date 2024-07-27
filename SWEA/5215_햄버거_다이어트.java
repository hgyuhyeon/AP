import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
class Solution
{
    static int max_score = 0;
    static void search(int[][] ham, int cal, int limit, int idx, int score) {
        if (cal <= limit) max_score = Math.max(max_score, score);
        if (idx == ham.length) return;
        search(ham, cal + ham[idx][1], limit, idx+1, score + ham[idx][0]);
        search(ham, cal, limit, idx+1, score);
    }
     
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());
         
        for (int t = 1; t <= tc; t++) {
            max_score = 0;
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken()), l = Integer.parseInt(st.nextToken());
            int[][] ham = new int[n][2];
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                ham[i][0] = Integer.parseInt(st.nextToken());
                ham[i][1] = Integer.parseInt(st.nextToken());
            }
            search(ham, 0, l, 0, 0);
            System.out.println("#" + t + " " + max_score);
        }
    }
}