import java.util.*;

public class sortedUniquePErmutation {
    // Generate the next lexicographical permutation
    static boolean nextPermutation(char[] arr) {
        int i = arr.length - 2;
        while (i >= 0 && arr[i] >= arr[i + 1]) {
            i--; }// Find pivot, we need to stop at arr[i]<arr[i+1]

        if (i < 0) {
            return false; }// No more permutations

        int j = arr.length - 1;

        while (arr[j] <= arr[i]) { // we need to stop at arr[j]>=
            j--; }// Find rightmost successor

        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp; // Swap pivot and successor

        Arrays.sort(arr, i + 1, arr.length); // Sort suffix
        return true;
    }

    static void generatePermutations(String s) {
        char[] arr = s.toCharArray();
        Arrays.sort(arr); // Start with the smallest permutation
        System.out.println(String.valueOf(arr));

        while (nextPermutation(arr)) {
            System.out.println(String.valueOf(arr)); // Print next permutation
        }
    }

    public static void main(String[] args) {
        String s = "BAC"; // Input string
        generatePermutations(s); // Generate and print permutations
    }
}