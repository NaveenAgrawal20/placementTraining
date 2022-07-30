import java.util.*;
class Solution
{

	public static void main(String[] args) {
		Solution s = new Solution()
;
		Scanner scn = new Scanner(System.in);
		// String []input1 = {"world","hello","madam"};
		// String []input1 = {"AbC"};
		int input2 = scn.nextInt();
		System.out.println(Arrays.toString(s.stringEncoder(input1,input2)));
	}
	public String[] stringEncoder(String []input1,int input2)
	{

		String []output = new String[input1.length];
		for(int i = 0;i<input1.length;++i)
		{
			String str = input1[i];
			// System.out.print(str);
			// //get mid
			char c = str.charAt(str.length()/2);
			String outStr = str.charAt(0)+""+c+""+str.charAt(str.length()-1);
			String ans = outStr;
			for(int j = 1;j<=input2;++j)
				ans += outStr;

			output[i] = ans;
		}
		return output;
	}
}