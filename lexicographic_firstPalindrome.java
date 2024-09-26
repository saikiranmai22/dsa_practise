import java.util.*;
public class lexicographic_firstPalindrome {
    public static void main (String args[]){
        String input="aabcc";
        int l= input.length();
        char arr1[]= input.toCharArray();
        
        ArrayList<String> palindromes= new ArrayList<>();
        HashSet <String> permutations = new HashSet<>();
        permute(arr1,0,permutations);
        for(String x: permutations){
            if(isPalindrome(x)){
                palindromes.add(x);
            }
        }
        Collections.sort(palindromes);

        for(String y:palindromes){
            System.out.println(y);
        }
    }

    public static void permute(char arr1[], int l, Set<String> permutations){
        if(l==arr1.length){
            permutations.add(new String(arr1));
        }
        else{
            for(int i=l;i<arr1.length;i++){
                // swap(arr1,l,i);
                char temp=arr1[l];
                arr1[l]=arr1[i];
                arr1[i]=temp;

                permute(arr1,l+1,permutations);
                temp=arr1[l];
                arr1[l]=arr1[i];
                arr1[i]=temp;

            }
        }
    }

    public static boolean isPalindrome(String str){
        int start=0;
        int end=str.length()-1;
        while(start<end){
            if(str.charAt(start)!=str.charAt(end)){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
}
