public class reverseArray {
    //reverse the array based on the k value
    public static void main(String args[]){
        int k=3;
        int arr[]={1,2,3,4,5};
        int n= arr.length;
        k=k%n;
        int dum[]=new int[n];
        for(int i=0;i<n;i++){
            dum[i]=arr[i];
        }
        for(int i=0;i<n-k;i++){
            arr[i]=dum[i+k];
        }
        for(int i=n-k;i<n;i++){
            arr[i]=dum[i-n+k];
        }
        for(int i=0;i<n;i++){
            System.out.print(arr[i]+" ");
        }
    }
}
