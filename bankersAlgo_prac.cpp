#include <bits/stdc++.h>
using namespace std;

void bankers(int alloc[][3], int max[][3], int avail[], int n, int m)
{
    int result[n], index = 0;
    int need[n][m];
    int fin[n];

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
                    if (need[i][j] > avail[j])
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
                        avail[j] += need[i][j];
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
            flag = 0;
            cout << "The given sequence is not safe";
            break;
        }
    }

    if (flag == 1)
    {
        cout << "Following is the SAFE Sequence" << endl;
        for (int i = 0; i < n - 1; i++)
            cout << " P" << result[i] << " ->";
        cout << " P" << result[n - 1] << endl;
    }
}

int main()
{
    int n = 5;
    int m = 3;

    int alloc[n][3] = {{0, 1, 0},
                       {2, 0, 0},
                       {3, 0, 2},
                       {2, 1, 1},
                       {0, 0, 2}};

    int max[n][3] = {{7, 5, 3},
                     {3, 2, 2},
                     {9, 0, 2},
                     {2, 2, 2},
                     {4, 3, 3}};

    int avail[m] = {3, 3, 2};

    bankers(alloc, max, avail, n, m);
    return 0;
}