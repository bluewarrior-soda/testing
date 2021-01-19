
class Animal
{
	String name;
	String type;
	int age;
	
	public Animal (String name, String type, int age)
	{
		System.out.println(name + " " + type + " " + age);
	}
	
	public static void num_of_legs (int number)
	{
		System.out.println("Number of legs: " + number);
	}
}

public class ConstructorMethod 
{
	public static void main(String[] args) 
	{
		Animal animal = new Animal("Fish", "Clownfish", 2);
		animal.num_of_legs(0);
	}

}