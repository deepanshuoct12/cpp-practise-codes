 int lpd(int n){  //largest prime divisor
        int ret = 1;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                ret = max(ret,i);
                ret = max(ret,n/i);
            }
        }
        return ret;
    }
