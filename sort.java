//insertion sort
public class sort {
    public static void main(String args[]){
        int arr[]= {5,4,7,2,1};
        for(int i=1;i<arr.length;i++){
            int x=arr[i];
            int j=i-1;
            while(j>=0 && arr[j]>x){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=x;
        }
        for(int i=0;i<arr.length;i++){
        System.out.print(arr[i]+" ");}
    }
}

//merge sort

// public class sort{
//     public static void main(String args[]){
//         int arr[]= {5,4,7,2,1};
//         void merge(int arr[], int l, int m , int r){
//             int n1=m-l+1;
//             int n2=r-m;
//             int L[]= new int[n1];
//             int R[]= new int[n2];
//             for(int i=0;i<n1;i++){
//                 L[i]=
//             }
//         }
//     }
// }
