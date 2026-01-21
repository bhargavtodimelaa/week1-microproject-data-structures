#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

typedef struct {
    int id;
    char pName[20];
    int priority;
    float BT;
} Process;

int count = 0;

void Add(Process table[]);
void Display(Process table[]);
void BubbleSortByPid(Process table[]);
void InsertionSortByBT(Process table[]);
void ShellSortByPid(Process table[]);
void LinearSearchByPid(Process table[]);
void BinarySearchByPid(Process table[]);

void Add(Process table[]) {
    if (count >= SIZE) {
        printf("Process table is full!\n");
        return;
    }

    printf("Enter process-%d details\n", count + 1);

    printf("Enter PID: ");
    scanf("%d", &table[count].id);

    printf("Enter process name: ");
    scanf("%s", table[count].pName);

    printf("Enter priority: ");
    scanf("%d", &table[count].priority);

    printf("Enter BT: ");
    scanf("%f", &table[count].BT);

    count++;
}

void Display(Process table[]) {
    if (count == 0) {
        printf("No processes available\n");
        return;
    }

    4for (int i = 0; i < count; i++) {
        printf("\nProcess-%d", i + 1);
        printf("\nPID=%d\tName=%s\tPriority=%d\tBT=%.2f\n",
               table[i].id,
               table[i].pName,
               table[i].priority,
               table[i].BT);
    }
}
void BubbleSortByPid(Process table[]) {
    Process temp;

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (table[j].id > table[j + 1].id) {
                temp = table[j];
                table[j] = table[j + 1];
                table[j + 1] = temp;
            }
        }
    }

    printf("Sorted by PID using Bubble Sort.\n");
}
void InsertionSortByBT(Process table[]) {
    Process key;
    int j;

    for (int i = 1; i < count; i++) {
        key = table[i];
        j = i - 1;

        while (j >= 0 && table[j].BT > key.BT) {
            table[j + 1] = table[j];
            j--;
        }

        table[j + 1] = key;
    }

    printf("Sorted by BT using Insertion Sort.\n");
}
void ShellSortByPid(Process table[]) {
    Process temp;

    for (int gap = count / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < count; i++) {
            temp = table[i];

            int j;
            for (j = i; j >= gap && table[j - gap].id > temp.id; j -= gap) {
                table[j] = table[j - gap];
            }

            table[j] = temp;
        }
    }

    printf("Sorted by PID using Shell Sort.\n");
}
void LinearSearchByPid(Process table[]) {
    if (count == 0) {
        printf("No processes available.\n");
        return;
    }

    int key, found = 0;
    printf("Enter PID to search: ");
    scanf("%d", &key);

    for (int i = 0; i < count; i++) {
        if (table[i].id == key) {
            printf("Process found:\n");
            printf("PID=%d Name=%s Priority=%d BT=%.2f\n",
                   table[i].id, table[i].pName,
                   table[i].priority, table[i].BT);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Process not found.\n");
}
void BinarySearchByPid(Process table[]) {
    if (count == 0) {
        printf("No processes available.\n");
        return;
    }

    int key;
    printf("Enter PID to search: ");
    scanf("%d", &key);

    int low = 0, high = count - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (table[mid].id == key) {
            printf("Process found:\n");
            printf("PID=%d Name=%s Priority=%d BT=%.2f\n",
                   table[mid].id, table[mid].pName,
                   table[mid].priority, table[mid].BT);
            return;
        } else if (table[mid].id < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("Process not found.\n");
}

int main() {
    Process table[SIZE];
    int choice;

    while (1) {
        printf("\n\n1.Add");
        printf("\n2.Display");
        printf("\n3.Bubble sort by PID");
        printf("\n4.Insertion sort by BT");
        printf("\n5.Shell sort by PID");
        printf("\n6.Linear search by PID");
        printf("\n7.Binary search by PID");
        printf("\n8.Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: Add(table); break;
            case 2: Display(table); break;
            case 3: BubbleSortByPid(table); break;
            case 4: InsertionSortByBT(table); break;
            case 5: ShellSortByPid(table); break;
            case 6: LinearSearchByPid(table); break;
            case 7: BinarySearchByPid(table); break;
            case 8: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
