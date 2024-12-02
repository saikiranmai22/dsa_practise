import java.util.*;

//to find the longest palindrome substring in a string
public class manacher {
    int manacherAlgo(String s, int N){
        String str=getModified(s,N);
        int len=(2*N)+1;
        int[] P= new int[len];
        int c=0;
        int r=0;
        int maxLen=0;

        for(int i=0;i<len;i++){
            int mirror= (2*c)-i;
            if(i<r){
                P[i]= Math.min(r-1,P[mirror]);
            }
            int a= i+(1+P[i]);
            int b= i-(1+P[i]);
            while(a<len && b>=0 && str.charAt(a)==str.charAt(b)){
                P[i]++;
                a++;
                b--;
            }

            if(i+P[i]>r){
                c=i;
                r=i+P[i];
                if(P[i]>maxLen){
                    maxLen= P[i];
                }
            }
        }
        return maxLen;
    }
    String getModified(String s, int N){
        StringBuilder sb= new StringBuilder();
        for(int i=0;i<N;i++){
            sb.append("#");
            sb.append(s.charAt(i));
        }
        sb.append("#");
        return sb.toString();
    }

    public static void main(String args[]){
        String str= "abbabbbcd";
        int N=str.length();
        System.out.println(new manacher().manacherAlgo(str,N));
    }
}
