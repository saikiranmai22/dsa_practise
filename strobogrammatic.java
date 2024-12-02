import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
public class strobogrammatic {
// if a given number looks the same after 180 degree rotation
    static boolean Stro(String num){
        Map<Character, Character> map= new HashMap<>();
        map.put('0','0');
        map.put('1','1');
        map.put('8','8');
        map.put('6','9');
        map.put('9','6');
        int start=0, end=num.length()-1;
        while(start<=end){
            if(num.charAt(start)!=map.getOrDefault(num.charAt(end), ' ')){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        String num=sc.nextLine();
        if(Stro(num)){
            System.out.println("True");
        }
        else{
            System.out.println("False");
        }
        sc.close();
    }
      
}
 