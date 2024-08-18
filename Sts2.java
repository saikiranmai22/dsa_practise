import java.util.Scanner;
class Sts2 {
    static int answer(int m, int k,int n, int s, int e, int w){
        if(m<=s*k){
            return m;}
        else if(m<(s*k)+e+1){
            return s*k+(m-s*k);}
        else {
        return -1;}
    }
    public static void main(String[] args){
    int e=1, m=12, k=10, s=1, n=0;
    Scanner sc = new Scanner(System.in);
    // System.out.println("Enter the value of w: ");
    // int w= sc.nextInt();
    int w=1;
    System.out.print(m+k+n+s+e+w);
    System.out.println("Answer:" + answer(m,k,n,s,e,w));
    sc.close();
}   
}
