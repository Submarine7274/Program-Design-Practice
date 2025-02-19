import java.util.Scanner;
public class AreaDemo {
		
	public static void main(String[] args) {
		double area;
		Scanner sc=new Scanner(System.in);
		String line=sc.nextLine();
		String[] tokens=line.split(" ");
		switch(tokens.length){
			case 1:if(!isDouble(tokens[0])){
						area=compute(Integer.valueOf(tokens[0]));
					}else{
						area=compute(Double.valueOf(tokens[0]));
					}
					System.out.println(area);
					break;
			case 2:if(!isDouble(tokens[0])){
						area=compute(Integer.valueOf(tokens[0]),
										 Integer.valueOf(tokens[1]));
					}else{
						area=compute(Double.valueOf(tokens[0]),
										 Double.valueOf(tokens[1]));
					}
					System.out.println(area);
					break;
		}
		if(tokens.length>2){
			int totalsum=compute(tokens);
			System.out.println(totalsum);
		}	
	}
	
	private static boolean isDouble(String msg) {
		if(msg.indexOf(".")!=-1)return true;
		return false;
	}
	//Method1
	private static int compute(int length) {
		int area=0;
        area = length*1;
		return area;
	}
	
	//Method2
	private static int compute(int length,int weight) {
		int area=0;
        area = length *weight;
		return area;
	}
	
	//Method3
	private static double compute(double bottom) {
		double area=0;
        area = bottom *1 /2;
		return area;
	}
	
	//Method4
	private static double compute(double bottom, double height) {
		double area=0;
        area = bottom *height /2;
		return area;
	}
	
	//Method5
	private static int compute(String... tokens){
		int totalsum=0;
        for(int i =0; i<tokens.length;i++){
            totalsum += Integer.valueOf(tokens[i]);
        }

		return totalsum;
	}
}