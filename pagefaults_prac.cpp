#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int pages = sizeof(arr) / sizeof(arr[0]);
    int frames = 3;
    int pageFault = 0;
    int s;

    cout << "Incoming\t" << "Frame1\t\t\t" << "Frame2\t\t\t" <<"Frame3\t\t\t" ;
    int temp[frames];
    for(int i = 0; i < frames; i++){
        temp[i] = -1;
    }

    for(int m = 0; m < pages; m++){
        s = 0;

        for(int n = 0; n < frames; n++){
            if (arr[m] == temp[n]){
                s++;
                pageFault--;         
            }
        }

        pageFault++;

        if (pageFault <= frames && s == 0 ){
            temp[m] = arr[m];
        }

        else if (s==0){
            temp[(pageFault - 1) % frames] = arr[m];
        }
        cout << endl;

        cout << arr[m] << "\t\t" ;

        for(int i = 0; i < frames; i++){
            if (temp[i] != -1){
                cout << temp[i] << "\t\t\t";
            }
            else{
                cout << "-" << "\t\t\t";
            }
        }
    }

    cout << "\nThe total no of page faults are: " << pageFault;

    return 0;
}