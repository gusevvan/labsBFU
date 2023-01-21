#include <iostream>

template <typename T>
void arrCopy(T* src, T* dst, int size) {
    long long *cursrc = (long long*)src,
                                *curdst = (long long*)dst;
    int n = (sizeof(T) * size) / sizeof(long long);
    for (int i = 0; i < n; ++i) {
        *(curdst + i) = *(cursrc + i);
    }
    char *remsrc = (char*)src,
            *remdst = (char*)dst;
    for (int i = 0; i < (sizeof(T) * size) % sizeof(long long); ++i) {
        *(remdst + n * sizeof(long long) + i) = *(remsrc + n * sizeof(long long) + i);
    }
}

int main() {
    int N;
    std::cin >> N;
    int a[N];
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i];
    }
    int b[N];
    arrCopy(a, b, N);
    for (int i = 0; i < N; ++i) {
        std::cout << b[i] << " ";
    }
}
