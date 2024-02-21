#include <stdio.h>

void move(int n, int source, int destination, int intermediate) {
    if (n == 1) {
        printf("Move disk 1 from shaft %d to shaft %d\n", source, destination);
        return;
    }
    move(n - 1, source, intermediate, destination);
    printf("Move disk %d from shaft %d to shaft %d\n", n, source, destination);
    move(n - 1, intermediate, destination, source);
}

int main() {
    int num_disks = 4;
    move(num_disks, 1, 3, 2);
    return 0;
}

