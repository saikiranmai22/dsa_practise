class subsetsum{
    public static void main(String args[]){
        String P="abcde";
        String Q="12345678912345678912345678";
        int  k=5;
        int count=0;
        for(int i=0;i<P.length();i++){
            int sum=0;
            for(int j=i;j<P.length();j++){
                int ch=P.charAt(j)-'a';
                sum=sum+Q.charAt(ch)-'0';
                if(sum<=k){
                    count++;
                }
            }
        }
        System.out.println(count);
    }
}