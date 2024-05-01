#include <bits/stdc++.h>
using namespace std;

void bestFit(int blocksize[], int m, int process[], int n)
{

    int allocation[n];
    for (int i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        int bestIndex = -1;
        for (int j = 0; j < m; j++)
        {
            if (blocksize[j] >= process[i])
            {
                if (bestIndex == -1)
                {
                    bestIndex = j;
                }
                else if (blocksize[bestIndex] > blocksize[j])
                {
                    bestIndex = j;
                }
            }
        }

        if (bestIndex != -1)
        {
            allocation[i] = bestIndex;
            blocksize[bestIndex] -= process[i];
        }
    }

    cout << "\nProcess\t\t"
         << "Process Size\t"
         << "Block No" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t\t" << process[i] << "\t\t";
        if (allocation[i] != -1)
        {
            cout << allocation[i] + 1 << endl;
        }
        else
        {
            cout << "Block not allocated" << endl;
        }
    }
}
void firstFit(int blocksize[], int m, int process[], int n)
{
    int allocation[n];
    for (int i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (blocksize[j] >= process[i])
            {
                allocation[i] = j;
                blocksize[j] = -process[i];
                break;
            }
        }
    }

    cout << "\nProcess\t\t"
         << "Process Size\t"
         << "Block No" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t\t" << process[i] << "\t\t";
        if (allocation[i] != -1)
        {
            cout << allocation[i] + 1 << endl;
        }
        else
        {
            cout << "Block not allocated" << endl;
        }
    }
}
void worstFit(int blocksize[], int m, int process[], int n)
{
    int allocate[n];
    for (int i = 0; i < n; i++)
    {
        allocate[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        int wrsIndex = -1;
        for (int j = 0; j < m; j++)
        {
            if (blocksize[j] >= process[i])
            {
                if (wrsIndex == -1)
                {
                    wrsIndex = j;
                }
                else if (blocksize[wrsIndex] < blocksize[j])
                {
                    wrsIndex = j;
                }
            }
        }

        if (wrsIndex != -1)
        {
            allocate[i] = wrsIndex;
            blocksize[wrsIndex] -= process[i];
        }
    }

    cout << "\nProcess\t\t"
         << "Process Size\t"
         << "Block No" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t\t" << process[i] << "\t\t";
        if (allocate[i] != -1)
        {
            cout << allocate[i] + 1 << endl;
        }
        else
        {
            cout << "Block not allocated" << endl;
        }
    }
}

int main()
{
    int blockSize[] = {100, 500, 200, 300, 600};
    int process[] = {212, 417, 112, 426};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(process) / sizeof(process[0]);

    cout << "\nBestFit: ";
    bestFit(blockSize, m, process, n);

    cout << "\nFirstFit: ";
    firstFit(blockSize, m, process, n);

    cout << "\nWorstFit: ";
    worstFit(blockSize, m, process, n);

    return 0;
}