import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
public class strobogrammatic {

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
        // int n=num.length();
        // for (int i=0,j=(n-1);i<=j;i++,j--){
        //     char left=num.charAt(i);
        //     char right=num.charAt(j);
        //     char mapping= map.getOrDefault(left, '-');
        //     if (mapping =='-'){
        //         return false;
        //     }
        //     if(mapping!=right){
        //         return false;
        //     }
        // }
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
    }
      
}
