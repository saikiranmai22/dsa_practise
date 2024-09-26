import java.util.Scanner;
public class MaxSum {

    static int Max_sum(int arr[],int n){
    int left=0;
    int right=0;
    int point=0;
    int min=Integer.MAX_VALUE;

    int sum[]=new int[n];
    sum[0]=arr[0];
    int total=arr[0];
    for(int i=1;i<n;i++){
        sum[i]=arr[i-1]+arr[i];
        total+=sum[i];
    }
    for(int i=1;i<n-1;i++){
        left=sum[i]-arr[i];
        right=total-sum[i];

        if(right-left<min){
            min=right-left;
            point=i;
        }
    }
    return min;
}
    public static void main(String args[]){
    Scanner sc= new Scanner(System.in);
    int n=sc.nextInt();
    int arr[]=new int[n];
    for(int i=0;i<n;i++){
        arr[i]=sc.nextInt();
    }
    int x=Max_sum(arr,n);
    System.out.println(x);
    sc.close();
    }
    
}

