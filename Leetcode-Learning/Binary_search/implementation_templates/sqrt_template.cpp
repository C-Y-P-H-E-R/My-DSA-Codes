int mySqrt(int x) {
        
        if(x == 0) {
            return 0;
        }
        
        long lo = 0, hi = x, mid = 0;
        while (lo < hi) {
            mid = lo + (hi - lo + 1) / 2;
            if (mid * mid <= long(x)) lo = mid;
            else hi = mid - 1;
        }
        return hi;
        
    }
