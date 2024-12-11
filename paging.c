#include <stdio.h>
#include <stdlib.h>

void simulatePaging(int pageSize, int processSize) {
    int numPages = (processSize + pageSize - 1) / pageSize;
    printf("\nProcess size: %d bytes\nPage size: %d bytes\nPages required: %d\n", processSize, pageSize, numPages);

    printf("Logical to Physical Address Translation\nEnter a logical address (0 to %d): ", processSize - 1);
    int logicalAddress;
    scanf("%d", &logicalAddress);

    if (logicalAddress >= 0 && logicalAddress < processSize) {
        int pageNumber = logicalAddress / pageSize;
        int offset = logicalAddress % pageSize;
        int physicalAddress = pageNumber * pageSize + offset;
        printf("Logical Address: %d => Physical Address: %d\n", logicalAddress, physicalAddress);
    } else {
        printf("Invalid logical address!\n");
    }
}

int main() {
    int pageSize, processSize;
    printf("Enter process size (bytes): ");
    scanf("%d", &processSize);
    printf("Enter page size (bytes): ");
    scanf("%d", &pageSize);

    if (pageSize > 0 && processSize > 0) {
        simulatePaging(pageSize, processSize);
    } else {
        printf("Invalid input!\n");
    }
    return 0;
}

