public class Student extends People{
    private String stu_id;
    private int score;
    public Student(String id, String name, String phone, String stuId, int score){
        super(id,name,phone);
        this.stu_id = stuId;
        this.score = score;
    }
    public String getStuID(){
        return stu_id;
    }
    public void setStuID(String stu_id){
        this.stu_id =stu_id;
    }
    public int getScore(){
        return score;
    }
    public void setScore(int score){
        this.score = score;
    }
    public String toFileFormat() {
        return getID() + "\t" + getName() + "\t" + getPhoneNumber() + "\t" + stu_id + "\t" + score;
    }
    @Override
    public String toString() {
        return "編號: " + getID() + ", 姓名: " + getName() + ", 電話: " + getPhoneNumber() + ", 學號: " + stu_id + ", 分數: " + Integer.toString(score);
    }
}
