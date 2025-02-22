import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
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
        File file = new File("members.txt");
        if (!file.exists()) {
        System.out.println("Error: 檔案 members.txt 不存在！");
        return;
        }         
        try(BufferedWriter bw = new BufferedWriter(new FileWriter(file,true))) {
            bw.newLine();
            bw.write(student.toFileFormat());
            bw.newLine();
            System.out.println("成功新增學生");
            bw.close();
            
        } catch (Exception e) {
            System.out.println("Error while writing on members.txt");
        }
    }
    public void modifyStudent(){
        boolean found = false;
        Scanner sc = new Scanner(System.in);
        System.out.println("請輸入學號");
        String stuID = sc.nextLine();
        for(Student student:StudentList){
            if(student.getStuID().equals(stuID)){
                found = true;
                System.out.println("找到學號:"+student.getStuID()+"的學生");
                System.out.println("請重新輸入名字");
                String newName = sc.nextLine();
                student.setName(newName);
                System.out.println("請重新輸入電話");
                String newPhone = sc.nextLine();
                student.setPhoneNumber(newPhone);
                while (true) {
                    System.out.println("請重新輸入分數");
                    try {
                        int newScore = Integer.parseInt(sc.nextLine());
                        student.setScore(newScore);
                        break; 
                    } catch (NumberFormatException e) {
                        System.out.println("分數必須是整數，請重新輸入！");
                    }
                }
                updateMembersFile();
                found =true;
                break;
            }
        }
        if(!found){
            System.out.println("沒找到該學號學生");
        }
    }
    private void updateMembersFile() {
        File file = new File("members.txt");
        if (!file.exists()) {
        System.out.println("Error: 檔案 members.txt 不存在！");
        return;
        }         
        try(BufferedWriter bw = new BufferedWriter(new FileWriter(file))) {
            bw.write("編號\t姓名\t電話\t學號\t分數");
            bw.newLine();
            for (Student student : StudentList) {
                bw.write(student.toFileFormat());
                bw.newLine();
            }
            System.out.println("文件 members.txt 已更新！");
            bw.close();
        } catch (IOException e) {
            System.out.println("Error while updating members.txt: " + e.getMessage());
        }
    }

    public void deleteStudent(){
        boolean found = false;
        getAllStudents();
        Scanner sc = new Scanner(System.in);
        System.out.println("請輸入學號");
        String stuID = sc.nextLine();
        for(int i =0; i<StudentList.size();i++){
            if(StudentList.get(i).getStuID().equals(stuID)){
                System.out.println("已刪除學生：" + StudentList.get(i));
                StudentList.remove(i);
                updateMembersFile();
                found =true;
                break;
            }
        }
        if(!found){
            System.out.println("沒找到該學號學生");
        }
    }
    public void getAllStudents(){
        StudentList.clear();
        File file = new File("members.txt");
        if (!file.exists()) {
            System.out.println("Error: 檔案 members.txt 不存在！");
            return;
        }         
        try(BufferedReader br = new BufferedReader(new FileReader(file))) {
            String line;
            boolean isHeader = true; // 標記是否為第一行
            while ((line = br.readLine()) != null) {
                // 如果是第一行（表頭），直接略過
                if (isHeader) {
                    isHeader = false;
                    continue;
                }
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
            br.close();
        } catch (IOException  e) {
            System.out.println("Error: 無法讀取檔案 members.txt");
            e.printStackTrace(); // 顯示詳細錯誤訊息
        }
    }
}
