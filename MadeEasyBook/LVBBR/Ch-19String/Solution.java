import java.io.*;
import java.util.LinkedList;
import java.util.Queue;

class RotateStr{

	public boolean isRotated(String s1,String s2)
	{
		if(s1.length() != s2.length())
			return false;
		if(s1.equals(s2))
			return true;

		Queue<Character> q = new LinkedList<Character>();
		for(int i = 0;i<s1.length();++i)
			q.add(s1.charAt(i));
		Queue<Character> q2 = new LinkedList<Character>();
		for(int i = 0;i<s2.length();++i)
			q2.add(s2.charAt(i));
		

		int numOfOper = s1.length();
		while(numOfOper > 0)
		{
			char topChar = q.poll();
			q.add(topChar);
			if(q.equals(q2))
				return true;
			numOfOper--;
		}
		return false;
	}

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s1 = br.readLine();
		String s2 = br.readLine();
		// System.out.println(s1);
		// System.out.println(s2);
		RotateStr sol = new RotateStr();
		System.out.println(sol.isRotated(s1,s2));
	}
}