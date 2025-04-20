//OS Codes 

// 1 To study Fork System Call
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child Process: PID = %d\n", getpid());
    } else {
        printf("Parent Process: PID = %d\n", getpid());
    }
    return 0;
}

// 2 To study FCFS Scheduling Algorithm
#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n];

    for (int i = 0; i < n; i++) {
        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }


    printf("Process\tBurst\tWaiting\tTurnaround\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }
 
    return 0;
}


//3 To study SJF Scheduling Algorithm
#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int bt[n], p[n], wt[n], tat[n];
    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter burst time for P%d: ", p[i]);
        scanf("%d", &bt[i]);
    }
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (bt[i] > bt[j]) {
                int t = bt[i]; bt[i] = bt[j]; bt[j] = t;
                t = p[i]; p[i] = p[j]; p[j] = t;
            }
    wt[0] = 0;
    for (int i = 1; i < n; i++) wt[i] = wt[i - 1] + bt[i - 1];
    for (int i = 0; i < n; i++) tat[i] = wt[i] + bt[i];

    printf("Process\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) printf("P%d\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);
    return 0;
}

//4 To Study the Producer Consumer Problem
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>

sem_t empty, full;
int buffer[10], in = 0, out = 0;

void produce() {
    int val;
    sem_wait(&empty);
    printf("Enter value to produce: ");
    scanf("%d", &val);
    buffer[in] = val;
    printf("Produced: %d\n", buffer[in]);
    in = (in + 1) % 10;
    sem_post(&full);
}

void consume() {
    sem_wait(&full);
    int val = buffer[out];
    printf("Consumed: %d\n", val);
    out = (out + 1) % 10;
    sem_post(&empty);
}

int main() {
    sem_init(&empty, 0, 10);
    sem_init(&full, 0, 0);

    int choice;
    while (1) {
        printf("\n1. Produce\n2. Consume\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            produce();
        } else if (choice == 2) {
            consume();
            
        } else if (choice == 3) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }

    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}

//5 To Study Memory Management using fixed partitioning
#include <stdio.h>

int main() {
    int total_memory = 200, used_memory = 0;
    int n, size;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Enter memory required for Process %d: ", i);
        scanf("%d", &size);

        if (size <= (total_memory - used_memory)) {
            used_memory += size;
            printf("Memory Allocated to Process %d\n", i);
            printf("Remaining Memory: %d\n", total_memory - used_memory);
        } else {
            printf("Not enough memory for Process %d! Remaining: %d\n", i, total_memory - used_memory);
        }
    }

    if (used_memory == total_memory) {
        printf("No memory left!\n");
    } else {
        printf("Memory left after allocation: %d\n", total_memory - used_memory);
    }

    return 0;
}


//6 To study First Fit Algorithm
#include <stdio.h>

int main() {
    int blocks[10], processes[10], b, p;
    printf("Enter number of blocks: ");
    scanf("%d", &b);
    for (int i = 0; i < b; i++) {
        printf("Enter size of Block %d: ", i + 1);
        scanf("%d", &blocks[i]);
    }
    printf("Enter number of processes: ");
    scanf("%d", &p);
    for (int i = 0; i < p; i++) {
        printf("Enter size of Process %d: ", i + 1);
        scanf("%d", &processes[i]);
    }
    for (int i = 0; i < p; i++) {
        int allocated = 0;
        for (int j = 0; j < b; j++) {
            if (blocks[j] >= processes[i]) {
                printf("Process %d allocated to Block %d\n", i + 1, j + 1);
                blocks[j] -= processes[i];
                allocated = 1;
                break;
            }
        }
        if (!allocated) printf("Process %d not allocated\n", i + 1);
    }
    return 0;
}


//7 To study Best fit Algorithm
#include <stdio.h>

int main() {
    int blocks[10], processes[10], b, p;
    printf("Enter number of blocks: ");
    scanf("%d", &b);
    for (int i = 0; i < b; i++) {
        printf("Enter size of Block %d: ", i + 1);
        scanf("%d", &blocks[i]);
    }
    printf("Enter number of processes: ");
    scanf("%d", &p);
    for (int i = 0; i < p; i++) {
        printf("Enter size of Process %d: ", i + 1);
        scanf("%d", &processes[i]);
    }
    for (int i = 0; i < p; i++) {
        int best = -1;
        for (int j = 0; j < b; j++) {
            if (blocks[j] >= processes[i]) {
                if (best == -1 || blocks[j] < blocks[best]) best = j;
            }
        }
        if (best != -1) {
            printf("Process %d allocated to Block %d\n", i + 1, best + 1);
            blocks[best] -= processes[i];
        } else {
            printf("Process %d not allocated\n", i + 1);
        }
    }
    return 0;
}





