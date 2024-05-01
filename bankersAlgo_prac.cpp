#include <bits/stdc++.h>
using namespace std;

#include <stdio.h>
#include <unistd.h>

void bankers(int alloc[][3], int max[][3], int available[], int n, int m)
{
    int result[n], fin[n];
    int need[n][m];
    int index = 0;

    for (int i = 0; i < n; i++)
    {
        fin[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (fin[i] == 0)
            {
                int flag = 0;
                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > available[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    result[index++] = i;
                    for (int j = 0; j < m; j++)
                    {
                        available[j] += need[i][j];
                    }
                    fin[i] = 1;
                }
            }
        }
    }

    int flag = 1;

    for (int i = 0; i < n; i++)
    {
        if (fin[i] == 0)
        {
            cout << "The sequence is not safe";
            flag = 0;
            break;
        }
    }

    if (flag == 1)
    {
        cout << "The safe sequence is : " << endl;
        for (int i = 0; i < n - 1; i++)
        {
            cout << "P " << result[i] << "->";
        }
        cout << "P " << result[n - 1] << endl;
    }
}

int main()
{
    int n, m;
    n = 5;
    m = 3;
    int alloc[5][3] = {{0, 1, 0},
                       {2, 0, 0},
                       {3, 0, 2},
                       {2, 1, 1},
                       {0, 0, 2}};

    int max[5][3] = {{7, 5, 3},
                     {3, 2, 2},
                     {9, 0, 2},
                     {2, 2, 2},
                     {4, 3, 3}};

    int avail[3] = {3, 3, 2};

    bankers(alloc, max, avail, n, m);

    return 0;
}