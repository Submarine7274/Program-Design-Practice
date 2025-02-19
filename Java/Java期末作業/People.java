public class People{
    private String name;
    private String phone;
    private String id;

    public People(String name, String phone, String id){
        this.name =name;
        this.phone =phone;
        this.id =id;
    }
    public void setName(String name){
        this.name =name;
    }
    public String getName(){
        return name;
    }
    public void setPhoneNumber(String phone){
        this.phone = phone;
    }
    public String getPhoneNumber(){
        return phone;
    }
    public void setID(String id){
        this.id = id;
    }
    public String getID(){
        return id;
    }
}