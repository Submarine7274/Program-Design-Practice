import java.util.Scanner;




public class Main {

	
	public static void main(String[] args)  {
		Scanner sc = new Scanner(System.in);
		Student student1=new Student();
		Student student2=new Student();
        Student student3=new Student();
		Student student4=new Student();
		System.out.println("student1 use (1)getGrade, (2)setGrade,(3)getName and (4)setName");
		System.out.println("student2 use (5)setStudent(), student3 use use (6)setStudent(int), student4 use (7)setStudent(int,int,String)");
		student1.setGrade(sc.nextInt());
		student2.setName(sc.next());
		student3.setStudent(sc.nextInt());
		student4.setStudent(sc.nextInt(),sc.nextInt(),sc.next());

		System.out.println("Student1:"+"age="+student1.getAge()+" grade="+student1.getGrade()+" name="+student1.getName());
		System.out.println("Student2:"+"age="+student2.getAge()+" grade="+student2.getGrade()+" name="+student2.getName());
		System.out.println("Student3:"+"age="+student3.getAge()+" grade="+student3.getGrade()+" name="+student3.getName());
		System.out.println("Student4:"+"age="+student4.getAge()+" grade="+student4.getGrade()+" name="+student4.getName());
		
	}

}
