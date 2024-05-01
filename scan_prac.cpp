// Scan disk scheduling algos

#include <bits/stdc++.h>
using namespace std;

int disk_size = 200;

void scan(int arr[] , int n, int head, string direction){
    int distance =0, curr_track,seek_count = 0;
    vector<int>seek_sequence;
    vector<int>left;
    vector<int>right;

    if (direction == "left"){
        left.push_back(0);
    }
    else if (direction == "right"){
        right.push_back(disk_size - 1);
    }

    for(int i = 0; i < n; i++){
        if (arr[i] < head){
            left.push_back(arr[i]);
        }
        if (arr[i] > head)
			right.push_back(arr[i]);
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int run = 2;
    while(run--){
        if (direction == "left"){
            for(int i = left.size() - 1; i>=0; i--){
                curr_track = left[i];
                seek_sequence.push_back(left[i]);
                distance = abs(curr_track - head);
                seek_count += distance;
                head = curr_track;
            }
            direction = "right";
        }
        else if (direction == "right"){
            for(int i = 0; i < right.size(); i++){
                curr_track = right[i];
                seek_sequence.push_back(right[i]);
                distance = abs(curr_track - head);
                seek_count += distance;
                head = curr_track;
            }
            direction = "left";
        }
    }

    cout << "Total number of seek operations = "
		<< seek_count << endl;

	cout << "Seek Sequence is" << endl;

	for (int i = 0; i < seek_sequence.size(); i++) {
		cout << seek_sequence[i] << "\t";
	}
     
}

int main()
{
    int arr[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int n = sizeof(arr) / sizeof(arr[0]);
    int head = 50;
    string direction = "right";

    scan(arr, n, head, direction);

    return 0;
}