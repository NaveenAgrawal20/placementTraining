import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];

        String[] st = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st[i]);
        }
//        for (int i = 0; i < n; i++) {
//            System.out.println(arr[i]);
//        }

        System.out.println(minSwaps(arr));
    }

    public static int minSwaps(int []arr) {
        int n = arr.length;

        Pair []pairs = new Pair[n];
        for(int i = 0;i<n;i++){
            pairs[i] = new Pair(arr[i],i);
        }
        Arrays.sort(pairs);
        // for (int i = 0; i < n; i++) {
        //     System.out.print(pairs[i].val + " " + pairs[i].idx + " ");
        // }

        boolean[] visited = new boolean[n];
        int ans = 0;

        for(int i = 0;i<n;i++)
        {
            int j = i;
            int cycle_count = 0;
            while(!visited[j])
            {
                visited[j] = true;
                j = pairs[j].idx;
                cycle_count++;
            }
            if(cycle_count > 0)
                ans += cycle_count - 1;
        }
        return ans;
    }

    private static class Pair implements Comparable<Pair> {
        int val, idx;

        Pair(int val, int idx) {
            this.val = val;
            this.idx = idx;
        }

        @Override
        public int compareTo(Pair o) {
            return this.val - o.val; // incrsng order acc to val
        }
    }
}
/*
4
3 4 1 2

8
6 4 2 14 8 10 12 16

5
4 5 2 1 5
*/