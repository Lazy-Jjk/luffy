#include <stdio.h>
int main() {
    int n, sizes[10], seg, off,i;
    printf("Segments: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Size %d: ", i);
        scanf("%d", &sizes[i]);
    }
    printf("Logical (seg:off): ");
    scanf("%d:%d", &seg, &off);
    if (seg < n && off < sizes[seg]) {
        int phys = off;
        for (i = 0; i < seg; i++) phys += sizes[i];
        printf("Physical: %d\n", phys);
    } else printf("Invalid!\n");
    return 0;
}

