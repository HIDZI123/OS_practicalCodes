// Premeptive scheduling algorithm : SRTF(premptive SJF)

#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int pid;
    int at;
    int bt;
};

void findWaitingTime(Process proc[], int n, int wt[]){
    int rt[n];
    int complete = 0, minm = INT_MAX, shortest = 0, t = 0, finish_time;
    bool check = false;

    for(int i = 0; i < n; i++){
        rt[i] = proc[i].bt;
    }

    while(complete != n){
        
        for(int i = 0; i <n; i++){
            if ((proc[i].at <= t) && (rt[i] < minm) && (rt[i] > 0) ){
                minm = rt[i];
                shortest = i;
                check = true;

            }
        }

        if (check == false){
            t++;
            continue;
        }

        rt[shortest] --;

        minm = rt[shortest];
        if (minm == 0){
            minm = INT_MAX;
        }

        if (rt[shortest] == 0){
            complete ++;
            check = false;

            finish_time = t+1;
            wt[shortest] = finish_time - proc[shortest].at - proc[shortest].bt;

            if (wt[shortest] < 0){
                wt[shortest] = 0;
            }
        }
        t++;
    }

}

void findTurnaroundTime(Process proc[], int n, int wt[], int tat[])
{

    for (int i = 0; i < n; i++)
    {
        tat[i] = proc[i].bt + wt[i];
    }
}

void findAvgTime(Process proc[], int n)
{
    cout << "Hello world_1";
    int wt[n], tat[n];

    findWaitingTime(proc, n, wt);
    findTurnaroundTime(proc, n, wt, tat);

    int total_wt = 0, total_tat = 0;

    cout << "Pn\t\t"
         << "AT\t\t"
         << "BT\t\t"
         << "WT\t\t"
         << "TAT\t\t" << endl;

    for (int i = 0; i < n; i++)
    {
        total_wt += wt[i];
        total_tat += tat[i];
        cout << proc[i].pid << "\t\t" << proc[i].at << "\t\t" << proc[i].bt << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }

    cout << "The average waiting time is :" << (float)total_wt / (float)n;
    cout << "The average Turn around time is: " << (float)total_tat / (float)n;
}

int main()
{
    int n = 5;
    Process proc[] = {{1, 6, 2}, {2, 2, 5}, {3, 8, 1}, {4, 3, 0}, {5, 4, 4}};
    
    findAvgTime(proc, n);
    cout << "Hello world";

    return 0;
}
