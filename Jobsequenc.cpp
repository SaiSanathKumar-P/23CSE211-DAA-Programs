#include <stdio.h>
#include <stdlib.h>

/* Structure to store job details */
struct Job {
    int jobId;
    int deadline;
    int profit;
};

/* Function used by qsort to sort jobs by profit (descending order) */
int sortByProfit(const void *a, const void *b) {
    struct Job *j1 = (struct Job *)a;
    struct Job *j2 = (struct Job *)b;

    return j2->profit - j1->profit;
}

int main() {

    int n;

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    struct Job jobs[n];

    /* Read job information */
    for(int i = 0; i < n; i++) {
        printf("Enter deadline and profit for Job %d: ", i+1);
        scanf("%d %d", &jobs[i].deadline, &jobs[i].profit);

        jobs[i].jobId = i + 1;
    }

    /* Sort jobs in decreasing order of profit */
    qsort(jobs, n, sizeof(struct Job), sortByProfit);

    /* Find the maximum deadline */
    int maxDeadline = 0;
    for(int i = 0; i < n; i++) {
        if(jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    /* Create time slots for scheduling jobs */
    int slots[maxDeadline];

    for(int i = 0; i < maxDeadline; i++)
        slots[i] = -1;

    int totalProfit = 0;

    /* Schedule jobs */
    for(int i = 0; i < n; i++) {

        /* Try to place job in latest possible free slot */
        for(int j = jobs[i].deadline - 1; j >= 0; j--) {

            if(slots[j] == -1) {
                slots[j] = jobs[i].jobId;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    /* Display scheduled jobs */
    printf("\nSelected Jobs: ");

    for(int i = 0; i < maxDeadline; i++) {
        if(slots[i] != -1)
            printf("J%d ", slots[i]);
    }

    printf("\nTotal Profit = %d\n", totalProfit);

    return 0;
}
