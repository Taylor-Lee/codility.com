import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class Solution {
    public int solution(int[] A) {
        int pairs = 0;
        
        ArrayList<Integer> min = new ArrayList<Integer>();
        int [] max = new int[A.length];
        
        for (int i = 0; i < A.length; ++i) {
            long min_val = (long)i - (long)A[i];
            long max_val = (long)i + (long)A[i];
            
			// Check arithmetic overflow
            if (min_val >= Integer.MIN_VALUE)
                min.add(i - A[i]);
            else
                min.add(Integer.MIN_VALUE);
            
            if (max_val <= Integer.MAX_VALUE)
                max[i] = i + A[i];
            else
                max[i] = Integer.MAX_VALUE;
        }
        
        Collections.sort(min);
        
        for (int i = 0; i + 1 < A.length; ++i) {
        	int count = getCountOfAndlessMin(min, max[i]);
        	
        	if (count > 0) {
            	// Remove duplicated count
            	count -= i;
               	pairs += count;
        	}
        }
        
        if (pairs > 10000000)
            return -1;
         
        return pairs;
    }
	
	int getCountOfAndlessMin(ArrayList<Integer> min, int max) {
		int left = 0;
		int right = min.size() - 1;
		int half = (int)((left + right) * 0.5);
		

		while (left < right) {
			if (min.get(half) < max) {
				left = half + 1;
			} else if (min.get(half) == max) {
			    int sameValue = 0;
			    while (half + 1 < min.size() && min.get(half + 1) == max) {
			    	++half;
			    }
			    
			    break;
			} else {
				right = half - 1;
			}
			
			half = (int)((left + right) * 0.5);
		}
		
		if (min.get(half) > max)
			--half;
		
		return half;
	}
}