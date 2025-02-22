import java.util.*;
public class CountNumbers {
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        String input = sc.nextLine();
        String[] inputNumbers = input.split("\\s+");
        int[] numbers = new int[Math.min(inputNumbers.length, 50)];
        for(int i =0; i<numbers.length;i++){
            numbers[i] = Integer.parseInt(inputNumbers[i]);
        }
        Map<Integer, Integer> frequencyMap = new HashMap<>();
        for(int num :numbers){
            frequencyMap.put(num, frequencyMap.getOrDefault(num, 0)+1);
        }
        List<Map.Entry<Integer, Integer>> sorted = new ArrayList<>(frequencyMap.entrySet());
        sorted.sort((entry1, entry2) -> entry2.getKey().compareTo(entry1.getKey()));
        int count =0;
        int size = sorted.size();
        for (Map.Entry<Integer, Integer> entry : sorted) {
            count++;
            if (count == size) {
                System.out.print(entry.getKey() + " " + entry.getValue());
            } else {
                System.out.println(entry.getKey() + " " + entry.getValue());
            }
        }
        sc.close();
    }
}
