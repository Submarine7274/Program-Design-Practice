import java.util.Scanner;

public class Bill{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Item[] items = new Item[3];
        for (int i = 0; i < items.length; i++) {
            String name = sc.next();
            int quantity = sc.nextInt();
            double price = sc.nextDouble();
            items[i] = new Item(name, quantity, price);
        }
        double total = 0;
        for (Item i : items) {
            i.printItem();
            total += i.getSubTotal();
        }
        System.out.printf("sum %.0f", total);
    }
}

class Item{
    String name;
    int quantity;
    double price;

    public Item(String name, int quantity, double price){
        this.name = name;
        this.quantity = quantity;
        this.price = price;
    }

    public double getSubTotal(){
        return quantity *price;
    }
    public void printItem(){
        System.out.printf("%s %d %.0f %.0f\n", name, quantity, price,getSubTotal());
    }
}