import java.util.Scanner;
public class simpleSieve {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int num= sc.nextInt();
        boolean[] bool= new boolean[num];
        
        //set the whole array as true
        for(int i=0; i<bool.length;i++){
            bool[i]=true;
        }

        for(int i=2;i<Math.sqrt(num);i++){
            if(bool[i]==true){
                //logic
                for(int j=(i*i);j<num;j=j+i){
                    bool[j]=false;
                }
            }
        }

        //print
        for(int i=2;i<bool.length;i++){
            if(bool[i]==true){
                System.out.println(i);
            }
        }
    }
}
