// find a path from the top left cell in a matrix to bottom most right cell
public class maneuvering {
    static int numberOfPaths(int m, int n)
    {
        // Create a 1D array to store results of subproblems
        int[] dp = new int[n];
        dp[0] = 1; // number of ways to reach the cell in the j-th column of the current row

        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j - 1]; }
            }
            return dp[n - 1];
        }
        public static void main(String args[]){
            System.out.println(numberOfPaths(3, 3));
        }
}
