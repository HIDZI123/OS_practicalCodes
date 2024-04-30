//Non-preemptive scheduling algorithm : FCFS

#include<bits/stdc++.h>
using namespace std;

void calculateWT(int at[], int bt[], int n){
    int wt[n];

    wt[0] = 0;

    cout << "Pn\t\t" << "AT\t\t" << "BT\t\t" << "WT\t\t" << endl;

    cout << "1\t\t" << at[0] << "\t\t" << bt[0] << "\t\t" << wt[0] << "\t\t" << endl; 

    for(int i = 1; i < n; i++){
        wt[i] = (at[i-1] + bt[i-1] + wt[i-1]) - at[i];
    }

    for(int i = 1; i < n; i++){
        cout << i+1 << "\t\t" << at[i] << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << endl;
    }

    int sum = 0;

    for(int i = 0; i < n; i++){
        sum += wt[i];
    }

    cout << "The average waiting time is: " << (float)sum /(float) n;
}

int main(){
    int n = 5;

    int at[n] = {0, 1, 2, 3, 4};
    int bt[n] = {4, 3, 1, 2, 5};

    calculateWT(at, bt, n);

    return 0;
}