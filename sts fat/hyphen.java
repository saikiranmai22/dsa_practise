import java.util.*;
public class hyphen {
    static void movSpaceInFront(char str[]){
        int i=str.length-1;
        for(int j=i;j>=0;j--){
            if(str[j]!='-'){
                char c=str[i];
                str[i]=str[j];
                str[j]=c;
                i--; 
            }
        }
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String input= sc.nextLine(); //code -4-lyf
        char str[]= input.toCharArray();
        movSpaceInFront(str);
        System.out.println(String.valueOf(str));
    }
}
