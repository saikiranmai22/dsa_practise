public class longestSeqOf1 {
    static int func(int arr[], int k){
        int start=0;
        int end=0;
        int count=0;
        int max=-1;
        for(end=0;end<arr.length;end++){
            if(arr[end]==0){
                count++;
            }
            while(count>k){
                if(arr[start]==0){
                    count--;
                }
                start++;
            }
            max=Math.max(max,end-start+1);
        }        
        return max;
    }
    public static void main(String args[]){
        // int arr[]={1,1,1,0,0,0,1,1,1,1};
        int arr[]={1,1,1,1,0,0,1,1};
        int k=1;
        System.out.println(func(arr,k));
    }
}