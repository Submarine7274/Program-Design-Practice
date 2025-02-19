public class Student {

    public int age;
    public int grade;
    public String name;
    public String id;

    public Student(){
        age = 20;
        grade = 1;
        name = "NoName";
        id = "ACS001";
    }
    public Student(int c_age){
        age = c_age;
        grade = 1;
        name = "NoName";
        id = "ACS001";
    }
    public Student(String c_name){
        age = 20;
        grade = 1;
        name = c_name;
        id = "ACS001";
    }
    public Student(int c_age, int  c_grade, String c_name, String c_id){
        age = c_age;
        grade = c_grade;
        name = c_name;
        id = c_id;
    }
}
