public class Student {
    private int age;
    private int grade;
    private String name;

    public Student(){
        age = 20;
        grade = 1;
        name = "NoName";
    }
    public Student(int cage,int cgrade,String cname){
        age = cage;
        grade = cgrade;
        name = cname;
    }
    public boolean setStudent(){
        grade = 1;
        age = 20;
        name= "NoName";
        return true;
    }
    public boolean setStudent(int sgrade){
        grade = sgrade;
        age = 20;
        name= "NoName";
        return true;
    }
    public boolean setStudent(int sage, int sgrade, String sname){
        age = sage;
        grade = sgrade;
        name = sname;
        return true;
    }

    public int getAge(){
        return age;
    }
    public boolean setAge(int sage){
        age = sage;
        return true;
    }
    public int getGrade(){
        return grade;
    }
    public boolean setGrade(int sgrade){
        grade = sgrade;
        return true;
    }
    public String getName(){
        return name;
    }
    public boolean setName(String sname){
        name = sname;
        return true;
    }
    //public static void main(String[] args){
    //    System.out.println("student1 use getGrade and setGrade, student2 use getName and setName");
    //}
}
