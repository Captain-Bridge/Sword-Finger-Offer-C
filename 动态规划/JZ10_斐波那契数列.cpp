class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 
     * @return int整型
     */
    int Fibonacci(int n) {
        if(n==1) return 1;
        if(n==2) return 1;
        int pre = 1;
        int curr = 1;
        for(int i = 3; i <= n; i++){
            int temp = pre;
            pre = curr;
            curr = temp + curr;
        }
        return curr;
    }
};