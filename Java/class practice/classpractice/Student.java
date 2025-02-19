public class Student {

    public int age;
    public int grade;
    public String name;
    public String id;

    // (1) 無參數建構子
    public Student() {
        this(20, 1, "NoName", "ACS001");  // 呼叫擁有四個參數的建構子
    }

    // (2) 一個參數的建構子（年齡）
    public Student(int c_age) {
        this(c_age, 1, "NoName", "ACS001");  // 呼叫擁有四個參數的建構子
    }

    // (3) 一個參數的建構子（姓名）
    public Student(String c_name) {
        this(20, 1, c_name, "ACS001");  // 呼叫擁有四個參數的建構子
    }

    // (4) 四個參數的建構子
    public Student(int c_age, int c_grade, String c_name, String c_id) {
        this.age = c_age;
        this.grade = c_grade;
        this.name = c_name;
        this.id = c_id;
    }
}