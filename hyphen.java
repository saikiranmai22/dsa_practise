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
        char str[]= "code -4-lyf".toCharArray();
        movSpaceInFront(str);
        System.out.println(String.valueOf(str));
    }
}
