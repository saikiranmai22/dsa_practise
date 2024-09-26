public class sts23_9 {
    public static void main(String args[]){
        int arr[]={3,3,4,2,4,4,2,4,4};
        int n=arr.length;
        System.out.print(answer(arr,n));
    }
    static int answer(int arr[], int n){
        int element=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(count==0){
                element=arr[i];
                count=1;
            }
            else if(element ==arr[i]){
                count++;
            }
            else{
                count--;
            }
        }
        int s=0;
        for(int i=0;i<n;i++){
            if(element==arr[i]){
                s++;
            }
        }
        if(s>n/2){
            return element;
        }
        return 0;
    }
}
