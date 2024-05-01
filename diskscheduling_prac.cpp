#include<bits/stdc++.h>
using namespace std;

void fcfs(int arr[], int n, int head){
    int distance = 0;
    int curr_track, seekcount = 0;

    for(int i = 0; i  <n; i++){
        curr_track = arr[i];
        distance = abs(curr_track - head);
        seekcount += distance;

        head = curr_track;
    }


    cout << "The net seek distance is: " << seekcount << endl;
    cout << "The seek sequemce is: " << endl;

    for(int i = 0; i < n; i++){
        cout << arr[i] << "\t\t" ;
    }
}

int main(){
    int arr[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int n = sizeof(arr) / sizeof(arr[0]);
    int head = 50;
    fcfs(arr, n, head);
    return 0;
}