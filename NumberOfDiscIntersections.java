// you can also use imports, for example:
// import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class Solution {
    public int solution(int[] A) {
        // write your code in Java SE 8
        int pairs = 0;
        
        int [] min = new int[A.length];
        int [] max = new int[A.length];
        
        for (int i = 0; i < A.length; ++i) {
            min[i] = i - A[i];
            max[i] = i + A[i];
        }
        
        
        for (int i = 0; i + 1 < A.length; ++i) {
            for (int j = i + 1; j < A.length; ++j) {
                if (max[i] >= min[j])
                    ++pairs;
            }
        }
        
        if (pairs > 10000000)
            return -1;
            
        return pairs;
    }
}