import java.util.Scanner;
public class remianderTheorem {
    static int Min(int num[], int rem[], int k){
        int x=1;
        while(true){
            int j;
            for(j=0;j<k;j++){
                if(x%num[j]!=rem[j]){
                    break;
                }
            }
            if(j==k){
                return x;
            }
            x++;
        }
    }
    public static void main(String args[]){
        Scanner sc= new Scanner(System.in);
        int size=sc.nextInt();
        int a[]=new int[size];
        int m[]= new int[size];

        for(int i=0;i<size;i++){
            a[i]=sc.nextInt();
        }
        for(int i=0;i<size;i++){
            m[i]=sc.nextInt();
        }
        System.out.println(Min(m,a,size));
        sc.close();
    }
}
