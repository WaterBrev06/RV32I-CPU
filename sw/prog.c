#define N 8

int main(void) {
    volatile int a[N];              // volatile: really stored in memory, not optimized away
    int x = 3;
    for (int i = 0; i < N; i++) {   // fills a with 3,0,5,2,7,4,1,6
        a[i] = x;
        x += 5;
        if (x >= 8) x -= 8;
    }
    for (int i = 0; i < N - 1; i++)                 // bubble sort
        for (int j = 0; j < N - 1 - i; j++)
            if (a[j] > a[j + 1]) { int t = a[j]; a[j] = a[j + 1]; a[j + 1] = t; }

    int r = 0;                      // pack the sorted values into one word
    for (int i = 0; i < N; i++) r = (r << 4) | a[i];
    return r;                       // sorted 0..7, so expect 0x01234567
}
