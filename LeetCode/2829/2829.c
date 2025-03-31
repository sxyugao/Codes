short minimumSum(short n, short k) {
    if (n <= k / 2)
        return (1 + n) * n / 2;
    return (1 + k / 2) * (k / 2) / 2 +
           (k + k + (n - k / 2) - 1) * (n - k / 2) / 2;
}