class Solution {
    public int longestBalanced(String s) {

        int max_len = 0;
        for(int i=0;i<s.length();i++){
            int freq[] = new int[26];

            for(int j=i;j>=0;j--){
                int ind = s.charAt(j) - 'a';
                freq[ind]++;

                int min_freq = Integer.MAX_VALUE;
                int max_freq = Integer.MIN_VALUE;
                
                for(int k=0;k<26;k++){
    
                    if(freq[k]!= 0) min_freq = Math.min(min_freq,freq[k]);
                    max_freq = Math.max(freq[k],max_freq);
                }
    
                if(max_freq == min_freq) max_len = Math.max(max_len, i - j + 1 );
            }

        }

        return max_len;
    }
}