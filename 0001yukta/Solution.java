import java.io.*;
import java.util.*;

class Solution {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		// int k = 231;
		// String t = ""+k;
		Solution t = new Solution();
		// System.out.println(t.createPIN(1274, 5283, 1937));
		// System.out.println(t.createPIN(8530, 5620, 7532));

		// int []arr = {10,41,18,50,43,31,29,25,59,96,67};
		// int []arr = {4,12,26,102,193,72,71,73,107,212,15,108,223,53,81};
		// System.out.println(t.findSumOfPrimes(arr,11));

		// int []arr2 = {10,20,30,40};


		int []arr2 = {1, 2, 1, 4, 1, 2, 8};

		// int []arr2 = {1, 1, 2, 4, 1, 2, 8};
		// int []arr2 = {0,1,0,1,2,1};
		System.out.println(t.solve(arr2, 6));

		int []arr3 = {1, 2, 3};
		System.out.println(t.solve(arr3, 3));

		int []arr4 = {1, 2, 1, 2};
		System.out.println(t.solve(arr4, 4));
		// System.out.println(t.findSumOfPrimes(arr2,4));



	}

	public int solve(int []arr, int n) {

		boolean flag = false;
		for (int i = 0; i < n; ++i) {
			if (arr[i] > 0)
				flag = true;
		}
		if (flag == false)
			return 0;

		HashMap<Integer,Integer> set = new HashMap<>();
		for (int i = n-1; i >=0 ; --i) 
		{
			if (arr[i] > 0) {
				if (set.containsKey(arr[i]))
				{
					if(set.get(arr[i]) > 0)
						set.put(arr[i], -1*set.get(arr[i]));					
				}
				else
					set.put(arr[i],i);
			}

		}
		int ans = 0,ele = 0;
		for(int k:set.keySet())
			if(set.get(k) < 0 && ans < set.get(k))
			{
				ans = set.get(k);
				ele = k;
			}

		if(ans == 0)
			return arr[n-1];
		return ele;
	}











	public int findSumOfPrimes(int []input1, int input2) {
		// int n = Arrays.stream(input1).max().getAsInt();

		int n = 0;
		for (int i = 0; i < input2; ++i)
			n = Math.max(n, input1[i]);
		boolean prime[] = new boolean[n + 1];
		for (int i = 0; i <= n; i++)
			prime[i] = true;

		for (int p = 2; p * p <= n; p++) {
			if (prime[p] == true) {
				for (int i = p * p; i <= n; i += p)
					prime[i] = false;
			}
		}

		Arrays.sort(input1);
		int sum = 0, lp = 0;
		for (int i = 0; i < input2; ++i) {
			if (prime[input1[i]] == true) {
				lp = input1[i];
				sum += input1[i];
			}
		}
		if (sum == 0) {
			for (int i = 0; i < input2 - 1; ++i)
				sum += input1[i];
			return sum;
		}
		return sum - lp;
	}

	public int createPIN(int input1, int input2, int input3) {
		int []th = new int[10];
		int n = input1;
		while (n > 0) {
			th[n % 10]++;
			n /= 10;
		}
		n = input2;
		while (n > 0) {
			th[n % 10]++;
			n /= 10;
		}
		n = input3;
		while (n > 0) {
			th[n % 10]++;
			n /= 10;
		}

		// max
		int t = 0, h = Integer.MAX_VALUE, thIdx = 0, hIdx = 0;
		int ten = 0, one = Integer.MAX_VALUE;
		for (int i = 0; i < 10; ++i) {
			if (t <= th[i]) {
				t = th[i];
				thIdx = i;
			}
			if (th[i] != 0 && h > th[i]) {
				h = th[i];
				hIdx = i;
			}
			if (th[i] != 0) {
				ten = Math.max(ten, i);
				one = Math.min(one, i);
			}

		}
		int key = thIdx * 1000 + hIdx * 100 + ten * 10 + one;

		// int key = ten*1000+one*100+thIdx*10+hIdx;
		return key;
	}

	public int findKey(int input1, int input2, int input3) {

		// WRITE CODE HERE
		int large = 0;
		while (input3 > 0) {
			large = Math.max(large, input3 % 10);
			input3 /= 10;
		}
		input2 = input2 / 100;
		// System.out.println(input1/1000);
		int key = ((input1 / 1000) * (input2 % 10)) - large;
		return key;
	}

	public int findTotalOccurence(int input1, int input2) {
		//WRITE
		int ans = 0;

		int r = input1;
		while (r <= input2) {
			if (r % 10 == input1)
				ans++;
			if (r != 0 && r / 10 == input1) {
				r++;
				ans++;
			} else
				r++;
		}
		return ans;
	}
}