#include <bits/stdc++.h>
using namespace std;

void BestFit(int blocksize[], int n, int processing[], int m)
{
    int allocate[n];

    for (int i = 0; i < n; i++)
    {
        allocate[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        int bestIndex = -1;
        for (int j = 0; j < m; j++)
        {
            if (blocksize[j] >= processing[i])
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
            allocate[i] = bestIndex;
            blocksize[bestIndex] -= processing[i];
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock no.\n";

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t\t" << processing[i] << "\t\t";
        if (allocate[i] != -1)
        {
            cout << allocate[i] + 1 << endl;
        }
        else
        {
            cout << "Block not allocated\n";
        }
    }
}

void FirstFit(int blocksize[], int n, int processing[], int m)
{
    int allocate[n];

    for (int i = 0; i < n; i++)
    {
        allocate[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (blocksize[j] >= processing[i])
            {
                allocate[i] = j;
                blocksize[j] -= processing[i];
                break;
            }
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock no.\n";

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t\t" << processing[i] << "\t\t";
        if (allocate[i] != -1)
        {
            cout << allocate[i] + 1 << endl;
        }
        else
        {
            cout << "Block not allocated\n";
        }
    }
}

void WorstFit(int blocksize[], int n, int processing[], int m)
{
    int allocate[n];

    for (int i = 0; i < n; i++)
    {
        allocate[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        int worstIndex = -1;
        for (int j = 0; j < m; j++)
        {
            if (blocksize[j] >= processing[i])
            {
                if (worstIndex == -1)
                {
                    worstIndex = j;
                }
                else if (blocksize[worstIndex] < blocksize[j])
                {
                    worstIndex = j;
                }
            }
        }

        if (worstIndex != -1)
        {
            allocate[i] = worstIndex;
            blocksize[worstIndex] -= processing[i];
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock no.\n";

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t\t" << processing[i] << "\t\t";
        if (allocate[i] != -1)
        {
            cout << allocate[i] + 1 << endl;
        }
        else
        {
            cout << "Block not allocated\n";
        }
    }
}

int main()
{
    int blocksize[] = {100, 500, 200, 300, 600};
    int processing[] = {212, 417, 112, 426};
    int m = sizeof(blocksize) / sizeof(blocksize[0]);
    int n = sizeof(processing) / sizeof(processing[0]);

    cout << "\n BestFit: ";
    BestFit(blocksize, n, processing, m);

    cout << "\n FirstFit: ";
    FirstFit(blocksize, n, processing, m);

    cout << "\n WorstFit: ";
    WorstFit(blocksize, n, processing, m);

    return 0;
}