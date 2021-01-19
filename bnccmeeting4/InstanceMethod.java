
class Student
{
	public void name (String name)
	{
		System.out.println("Student name : " + name);
	}
	
	public void score (int number)
	{
		System.out.println("Student score : "+ number);
	}
}

public class InstanceMethod 
{
	public static void main(String[] args) 
	{
		Student s1 = new Student();
		s1.name("Dody");
		s1.score(100);
		
		Student s2 = new Student();
		s2.name("Opi");
		s2.score(90);
	}
}