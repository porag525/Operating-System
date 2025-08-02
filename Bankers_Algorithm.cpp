#include <iostream>
using namespace std;

int main() {
    int n, m; // n = number of processes, m = number of resources
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter number of resource types: ";
    cin >> m;

    int alloc[n][m], max[n][m], need[n][m], avail[m];

    cout << "Enter Allocation Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> alloc[i][j];

    cout << "Enter Maximum Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> max[i][j];

    cout << "Enter Available Resources:\n";
    for (int i = 0; i < m; i++)
        cin >> avail[i];

    // Calculate need matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    bool finished[n] = {false};
    int safeSeq[n], index = 0;

    for (int k = 0; k < n * n; k++) { // try n times max
        for (int i = 0; i < n; i++) {
            if (!finished[i]) {
                bool canAllocate = true;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate) {
                    for (int j = 0; j < m; j++)
                        avail[j] += alloc[i][j];
                    safeSeq[index++] = i;
                    finished[i] = true;
                }
            }
        }
    }

    // Check if all processes are finished
    bool safe = true;
    for (int i = 0; i < n; i++)
        if (!finished[i])
            safe = false;

    if (safe) {
        cout << "System is in a SAFE STATE.\nSafe sequence: ";
        for (int i = 0; i < n; i++)
            cout << "P" << safeSeq[i] << " ";
        cout << endl;
    } else {
        cout << "System is in an UNSAFE STATE.\n";
    }

    return 0;
}
