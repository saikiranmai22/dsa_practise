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
    static int finalfunc(int x){
        int count=0;
        int i=1;
        while(count<x){
            if(Palindrome(i)){
                count++;
            }
            i++;
        }

        return i;
    }

    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        // int x=sc.nextInt(); // find the n th binary palindrime 
        int x=9;
        int n=finalfunc(x);
        System.out.println(n-1);
        sc.close();
    }
}