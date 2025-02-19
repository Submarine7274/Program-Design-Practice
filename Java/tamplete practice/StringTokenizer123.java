/*====================
StringTokenizer練習
====================
請設計一個程式，讓使用者書從鍵盤輸入一列的任意字串，可包含空白及標點符號，
程式能夠以將輸入的一列字串運用指定的分割符號，將其分割成不同的token，並將其依序分行輸出
分割符號如下:
(1)一般水準: 若能用"%"當分隔符號
(2)進階水準: 若能用"%"或是"|"當分隔符號
(2)挑戰水準: 若能用小寫英文字母當分隔符號

範例輸入
95汽油%28.7$%40公升

範例輸出
95汽油
28.7$
40公升
注意
(a)輸入的字串的"%"請利用StringTokenizer做適當處理
(b) 1.一般水準(通過Test Case 1-8)：
	輸入的資料僅以"%"分隔
    2.進階水準(通過Test Case 9)：
	輸入的資料可能以","或是"|"分隔，分隔符號不連續出現
	Ex:95汽油%28.7$|40公升
    3.挑戰水準(通過Test Case 10)：
	輸入的資料以小寫英文字母作為分隔符號
        Ex:95汽油apple28.7$asdf40公升g */
import java.util.Scanner;
import java.util.StringTokenizer;
public class StringTokenizer123 {
    public static void main(String[] args){
		Scanner sc= new Scanner(System.in);
		String str = sc.next();
		StringTokenizer st;
        String delemeters = " |%abcdefghijklmnopqrstuvwxyz";
        st = new StringTokenizer(str,delemeters);
        while(st.hasMoreTokens()){
			System.out.println(st.nextToken());
        }
        sc.close();
    }
}