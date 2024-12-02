import java.util.*;
public class leaderArray
{
public static void main(String[] args) {
// Scanner s = new Scanner(System.in);
// System.out.println("Enter size of the array");
      //   int n = s.nextInt();
      //   int[] arr = new int[n];
      int n=6;
      int arr[]= {2,4,6,3,1,2};
// System.out.println("Enter elements of the array");
//         for (int i = 0; i < n; i++){ 
//         arr[i] = s.nextInt();
      //   }
      findLeaders(arr, n);
}
static void findLeaders(int arr[], int size){

    int rightMaximum=arr[arr.length-1];   
 System.out.print(rightMaximum+" ");
 
       for (int i = size-2; i>=0; i--) {
          if(arr[i] > rightMaximum){
             rightMaximum=arr[i];
             System.out.print(rightMaximum+" ");
          }
       }
    }
 }
 