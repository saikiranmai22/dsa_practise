class Sts1{
static int findMinX(int num[],int rem[], int k)
    {
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
    int num[]={5,7};
    int rem[]={1,3};
    int k=num.length;
    System.out.println(findMinX(num,rem,k));
}}