import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class StudentManeger {
    private ArrayList<Student> StudentList= new ArrayList<>();
    public void showAllStudent(){
        getAllStudents();
        for(Student student: StudentList){
            System.out.println(student);
        }
    }
    public void addStudent(){
        Scanner sc = new Scanner(System.in);
        System.out.println("輸入編號");
        String number = sc.nextLine();
        System.out.println("輸入姓名");
        String name = sc.nextLine();
        System.out.println("輸入電話");
        String phone = sc.nextLine();
        System.out.println("輸入學號");
        String stuID = sc.nextLine();
        System.out.println("輸入分數");
        int score = sc.nextInt();
        Student student = new Student(number, name, phone, stuID, score);
        StudentList.add(student);
        try(BufferedWriter bw = new BufferedWriter(new FileWriter("members.txt",true))) {
            bw.write(student.toFileFormat());
            bw.newLine();
            System.out.println("成功新增學生");
            bw.close();
            
        } catch (Exception e) {
            System.out.println("Error while writing on members.txt");
        }
        sc.close();
    }
    public void modifyStudent(){
        boolean found = false;
        Scanner sc = new Scanner(System.in);
        System.out.println("請輸入學號");
        String stuID = sc.nextLine();
        for(Student student:StudentList){
            if(student.getStuID().equals(stuID)){
                found = true;
                System.out.println("請重新輸入名字");
                String newName = sc.nextLine();
                student.setName(newName);
                System.out.println("請重新輸入電話");
                String newPhone = sc.nextLine();
                student.setPhoneNumber(newPhone);
                System.out.println("請重新輸入分數");
                while (true) {
                    System.out.println("請輸入新的分數：");
                    try {
                        int newScore = Integer.parseInt(sc.nextLine());
                        student.setScore(newScore);
                        break; 
                    } catch (NumberFormatException e) {
                        System.out.println("分數必須是整數，請重新輸入！");
                    }
                }
                updateMembersFile();
                return;
            }
        }
        if(!found){
            System.out.println("沒找到該學號學生");
        }
    }
    private void updateMembersFile() {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter("members.txt"))) {
            for (Student student : StudentList) {
                writer.write(student.toFileFormat());
                writer.newLine();
            }
            System.out.println("文件 members.txt 已更新！");
        } catch (IOException e) {
            System.out.println("Error while updating members.txt: " + e.getMessage());
        }
    }

    public void deleteStudent(){
        boolean found = false;
        Scanner sc = new Scanner(System.in);
        System.out.println("請輸入學號");
        String stuID = sc.nextLine();
        for(int i =0; i<StudentList.size();i++){
            if(StudentList.get(i).getStuID().equals(stuID)){
                System.out.println("已刪除學生：" + StudentList.get(i));
                StudentList.remove(i);
                updateMembersFile();
                break;
            }
        }
        if(!found){
            System.out.println("沒找到該學號學生");
        }
    }
    public String getVerefyCode(){
        return "AB12";
    }
    public void getAllStudents(){
        StudentList.clear();
        try(BufferedReader br = new BufferedReader(new FileReader("members.txt"))) {
            String line;
            while((line = br.readLine())!=null){
                String parts[] =line.split("\t");
                if(parts.length == 5){
                    String id =parts[0].trim();
                    String name =parts[1].trim();
                    String phone =parts[2].trim();
                    String stuId =parts[3].trim();
                    int score =Integer.parseInt(parts[4].trim());
                    Student student = new Student(id, name, phone, stuId, score);
                    StudentList.add(student);
                }
            }
            
        } catch (Exception e) {
            System.out.println("Error while loading members");
        }
    }
}
