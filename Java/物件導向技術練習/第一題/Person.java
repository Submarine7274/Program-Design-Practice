public class Person {
    public String name;
    public int height;
    public int weight;
    public Person(String myName, int myHeight, int myWeight){
        this.name =myName;
        this.height =myHeight;
        this.weight = myWeight;
    }
    public void getBMI(){
        int bmi = Math.round(weight / ((height/100) * (height/100)));
        System.out.print(bmi);
    }
}
