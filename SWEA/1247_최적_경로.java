import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
class Solution
{
    static int min_dist;
    static int[][] end = new int[1][2];
    static int cal (int[] a, int[] b) {
        return Math.abs(b[0]-a[0]) + Math.abs(b[1]-a[1]);
    }
    static void recursive(int[][] loc, int[] cur, boolean[] v, int cnt, int dist) {
        if (dist > min_dist) return;
        if (cnt == loc.length) {
            dist += cal(cur, end[0]);
            min_dist = Math.min(min_dist, dist);
        }
        else {
            for (int i = 0; i < loc.length; i++) {
                if (!v[i]) {
                    v[i] = true;
                     
                    dist += cal(cur, loc[i]);
                    recursive(loc, loc[i], v, cnt+1, dist);
                    v[i] = false;
                    dist -= cal(cur, loc[i]);
                }
            }
        }
    }
    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());
         
        for (int t = 1; t <= tc; t++) {
            min_dist = Integer.MAX_VALUE;
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            int[][] loc = new int[n][2], start = new int[1][2];
            boolean[] v = new boolean[n];
            start[0][0] = Integer.parseInt(st.nextToken());
            start[0][1] = Integer.parseInt(st.nextToken());
            end[0][0] = Integer.parseInt(st.nextToken());
            end[0][1] = Integer.parseInt(st.nextToken());
            for (int i = 0; i < n; i++) {
                loc[i][0] = Integer.parseInt(st.nextToken());
                loc[i][1] = Integer.parseInt(st.nextToken());
            }
             
            recursive(loc, start[0], v, 0, 0);
             
            System.out.println("#" + t + " " + min_dist);
        }
    }
}