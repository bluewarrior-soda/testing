
public class StringMethod 
{
	public static void main(String[] args) 
	{
		String str1 = "I join some student organizations";
		String[] str1_count = str1.split("\\s+");
		System.out.println(str1);
		System.out.println(str1_count.length); // check number of words
		
		String str2 = "   Binus University  ";
		System.out.println(str2.trim()); // ignore leading and last spaces
		
		int total_value = 10;
	}
}