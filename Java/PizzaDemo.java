import java.util.Scanner;

public class PizzaDemo {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int totalPrice=0;
		String line=sc.nextLine();
		String[] token=line.split(" ");
		if(isInt(token[0])){
			switch(token.length){
				case 1:totalPrice=compute(Integer.valueOf(token[0]));
								break;
				case 2:totalPrice=compute(Integer.valueOf(token[0]),
								Integer.valueOf(token[1]));break;
				case 3:totalPrice=compute(Integer.valueOf(token[0]),
								Integer.valueOf(token[1]),
								Integer.valueOf(token[2]));break;
			}	
		}else{
			if(token.length==2){
				totalPrice=compute(token[0],
						Integer.valueOf(token[1]));
			}else{
				totalPrice=compute(token);
			}
		}
		System.out.print(totalPrice);
	}

	private static boolean isInt(String msg) {
		if(java.lang.Character.isDigit(msg.charAt(0))){
			return true;
		}
		return false;
	}

	//Method1
	private static int compute(int pbnum) {
		int totalPrice=0;
        totalPrice = pbnum *500;

		return totalPrice;
	}

	//Method2
	private static int compute(int pbnum, int cbnum) {
		int totalPrice=0;
        totalPrice = pbnum *500 +cbnum *200;
		return totalPrice;
	}

	//Method3
	private static int compute(int pbnum, int cbnum, int dbnum) {
		int totalPrice=0;
        totalPrice = pbnum *500 +cbnum *200 +dbnum*50;
		return totalPrice;
	}

	//Method4
	private static int compute(String item, int num) {
		int totalPrice=0;
        switch(item){
            case "pb":
            totalPrice =num * 500;
            break;
            case "pm":
            totalPrice =num * 400;
            break;
            case "ps":
            totalPrice =num * 300;
            break;
            case "cb":
            totalPrice =num * 200;
            break;
            case "cs":
            totalPrice =num * 100;
            break;
            case "db":
            totalPrice =num * 50;
            break;
            case "ds":
            totalPrice =num * 30;
            break;
            default:
            System.out.print("Wrong code!");
            return 0;
        }
		return totalPrice;
	}
	
	//Method5
	private static int compute(String... token) {
		int totalPrice=0;
		for(int i = 0; i< token.length;i += 2){
            String itemCode = token[i];
            int numbers =Integer.parseInt(token[i+1]);
            totalPrice += compute(itemCode,numbers);
        }
		return totalPrice;
	}
}