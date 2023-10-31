#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int grid[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    int count = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                int size = 1;
                if (i > 0 && grid[i-1][j] == 1) {
                    continue;
                }
                for (int k = i+1; k < n; k++) {
                    if (grid[k][j] == 1) {
                        size++;
                    } else {
                        break;
                    }
                }
                if (size > 1) {
                    count++;
                    sum += size;
                }
                j += size-1;
            }
        }
    }
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (grid[i][j] == 1) {
                int size = 1;
                if (j > 0 && grid[i][j-1] == 1) {
                    continue;
                }
                for (int k = j+1; k < n; k++) {
                    if (grid[i][k] == 1) {
                        size++;
                    } else {
                        break;
                    }
                }
                if (size > 1) {
                    count++;
                    sum += size;
                }
                i += size-1;
            }
        }
    }
    int avg_size = sum / count;
    printf("%d", avg_size);
    return 0;
}