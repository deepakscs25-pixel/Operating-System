#include <stdio.h>

int main() {

    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], type[n];
    int ct[n], tat[n], wt[n];

    
    for(int i = 0; i < n; i++) {
        pid[i] = i + 1;

        printf("\nProcess P%d\n", i+1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Burst Time: ");
        scanf("%d", &bt[i]);

        printf("Type (0-System, 1-User): ");
        scanf("%d", &type[i]);
    }

    
    int sys[50], user[50];
    int s = 0, u = 0;

    for(int i = 0; i < n; i++) {
        if(type[i] == 0)
            sys[s++] = i;
        else
            user[u++] = i;
    }

   
    for(int i = 0; i < s-1; i++) {
        for(int j = i+1; j < s; j++) {
            if(at[sys[i]] > at[sys[j]]) {
                int temp = sys[i];
                sys[i] = sys[j];
                sys[j] = temp;
            }
        }
    }


    for(int i = 0; i < u-1; i++) {
        for(int j = i+1; j < u; j++) {
            if(at[user[i]] > at[user[j]]) {
                int temp = user[i];
                user[i] = user[j];
                user[j] = temp;
            }
        }
    }

    int time = 0;


    for(int i = 0; i < s; i++) {
        int p = sys[i];

        if(time < at[p])
            time = at[p];

        ct[p] = time + bt[p];
        time = ct[p];

        tat[p] = ct[p] - at[p];
        wt[p] = tat[p] - bt[p];
    }


    for(int i = 0; i < u; i++) {
        int p = user[i];

        if(time < at[p])
            time = at[p];

        ct[p] = time + bt[p];
        time = ct[p];

        tat[p] = ct[p] - at[p];
        wt[p] = tat[p] - bt[p];
    }

    printf("\nPID\tAT\tBT\tTYPE\tCT\tTAT\tWT\n");

    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        pid[i], at[i], bt[i], type[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}