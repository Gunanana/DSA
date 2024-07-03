#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct process {
    int pno, bt, at, ct, wt, btLeft, tat;
} process;

typedef struct node {
    process *proc;
    struct node *next;
} node;

typedef struct {
    node *front, *rear;
} queue;

queue *createQueue() {
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = q->rear = NULL;
    return q;
}

int isEmpty(queue *q) {
    return q->front == NULL;
}

void enqueue(queue *q, process *proc) {
    node *temp = (node *)malloc(sizeof(node));
    temp->proc = proc;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

process *dequeue(queue *q) {
    if (isEmpty(q))
        return NULL;
    node *temp = q->front;
    process *proc = temp->proc;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return proc;
}

void processTable(process *processQ, int n) {
    printf("\n%51s\n", "PROCESS TABLE");
    printf("| P No. | Arrival Time | Burst Time | Completion Time | Turn Around Time | Waiting Time |\n");
    for (int i = 0; i < n; i++) {
        printf("|  %3d  |      %3d     |     %3d    |       %3d       |       %3d        |      %3d     |\n",
               processQ[i].pno, processQ[i].at, processQ[i].bt, processQ[i].ct, processQ[i].tat, processQ[i].wt);
    }
}

void ganttChart(int *gc, int gcSize) {
    printf("\nGANTT CHART\n");
    printf("|");
    for (int i = 0; i < gcSize; i += 3) {
        printf(" <%d> P%d <%d> |", gc[i], gc[i + 1], gc[i + 2]);
    }
}

void roundRobin(process *arr, int quantum, int n) {
    int time = 0, completed = 0, q = 0;
    int gc[1000]; // Assuming gantt chart won't exceed 1000 entries
    int gcSize = 0;
    queue *readyQ = createQueue();

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (arr[i].at == time) {
                enqueue(readyQ, &arr[i]);
            }
        }

        if (!isEmpty(readyQ)) {
            process *frontProcess = dequeue(readyQ);
            int execTime = (frontProcess->btLeft < quantum) ? frontProcess->btLeft : quantum;
            time += execTime;
            frontProcess->btLeft -= execTime;

            gc[gcSize++] = time - execTime;
            gc[gcSize++] = frontProcess->pno;
            gc[gcSize++] = time;

            if (frontProcess->btLeft > 0) {
                enqueue(readyQ, frontProcess);
            } else {
                frontProcess->ct = time;
                frontProcess->tat = frontProcess->ct - frontProcess->at;
                frontProcess->wt = frontProcess->tat - frontProcess->bt;
                completed++;
            }
        } else {
            time++;
        }
    }

    processTable(arr, n);
    ganttChart(gc, gcSize);

    double avgtat = 0, avgwt = 0;
    for (int i = 0; i < n; i++) {
        avgtat += arr[i].tat;
        avgwt += arr[i].wt;
    }
    avgtat /= n;
    avgwt /= n;
    printf("\n\nAverage Turn Around time: %.4f ms\n", avgtat);
    printf("Average Waiting Time: %.4f ms\n\n", avgwt);
}

int main() {
    int num, quantum;
    printf("\nEnter number of processes: ");
    scanf("%d", &num);
    if (num <= 0) {
        printf("Please enter a valid positive integer for the number of processes.\n");
        return 1;
    }
    printf("Enter quantum time: ");
    scanf("%d", &quantum);
    if (quantum <= 0) {
        printf("Please enter a valid positive integer for the quantum time.\n");
        return 1;
    }
    printf("\n");

    process *arr = (process *)malloc(num * sizeof(process));
    for (int i = 0; i < num; i++) {
        arr[i].pno = i + 1;
        printf("Enter process No.%d's details below\n", arr[i].pno);
        printf("Arrival Time: ");
        scanf("%d", &arr[i].at);
        printf("Burst time: ");
        scanf("%d", &arr[i].bt);
        arr[i].btLeft = arr[i].bt;
    }

    roundRobin(arr, quantum, num);
    free(arr);
    return 0;
}


