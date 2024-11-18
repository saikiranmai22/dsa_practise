import java.util.Scanner;
class Sts3 {
    public static void main (String [] args){
    Scanner sc=new Scanner (System.in);
    int n=sc.nextInt();
    String s=Integer.toBinaryString(n);
    
    String dummy="";
    for(int i=s.length()-1;i>=0;i--){
        dummy=dummy+s.charAt(i);
    }
    if(dummy.equals(s)){
        System.out.println("palindrome");
    }
    else{
        System.out.println("Not a palindrome");
    }
    sc.close();
    }
}
