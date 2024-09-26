public class leaderArray {
    public static void main(String args[]){
        int n=6;
        int arr[]= {2,4,6,3,1,2};
        System.out.println(arr[n-1]);
        int max=arr[n-1];
        for(int i=arr[n-2];i>=0;i--){
            if(max<arr[i]){
                max=arr[i];
                System.out.println(max);
            }
        }
    }
}
