long long sum(int *a, int n) {
    long long ans;
    int i;
    
    ans = i = 0;
    while (i < n)
        ans += a[i++];
    
    return ans;
}
