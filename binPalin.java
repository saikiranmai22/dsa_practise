import java.util.Scanner;
public class binPalin {
    static boolean Palindrome(int n){
        String s=Integer.toBinaryString(n);
        int i=0,j=s.length()-1;
        while(i<j){
            if(s.charAt(i)!=s.charAt(j)){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int x=sc.nextInt();
        System.out.println(Palindrome(x));
    }
}