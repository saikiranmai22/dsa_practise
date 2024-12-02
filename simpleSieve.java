import java.util.Scanner;
// all the prime numbers upto gven number n
public class simpleSieve {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int num= sc.nextInt(); //imput n =11
        boolean[] bool= new boolean[num+1]; //0-10 so +1 for 11
        
        //set the whole array as true
        for(int i=0; i<bool.length;i++){ //length will be 12
            bool[i]=true;
        }
 
        for(int i=2;i<=Math.sqrt(num);i++){
            if(bool[i]==true){
                //logic
                for(int j=(i*i);j<=num;j=j+i){
                    bool[j]=false;
                }
            }
        }

        for(int i=2;i<=num;i++){
            if(bool[i]==true){
                System.out.println(i);
            }
        }
        sc.close();
    }
}
