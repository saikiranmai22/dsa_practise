import java.util.Scanner;
class Sts4 {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        int a= sc.nextInt();
        int b= sc.nextInt();
        System.out.println(answer(a,b));
    }
    static int answer(int a, int b){
        if(a==0)
        return b;
        
        return answer(b%a,a);
    }
    
}
