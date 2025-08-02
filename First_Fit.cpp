#include <iostream>
#include <vector>
using namespace std;

int main() {
    int nb, np;
    cout << "Enter number of memory blocks: ";
    cin >> nb;
    vector<int> blockSize(nb);
    cout << "Enter sizes of " << nb << " memory blocks:\n";
    for (int i = 0; i < nb; i++) cin >> blockSize[i];

    cout << "Enter number of processes: ";
    cin >> np;
    vector<int> processSize(np);
    cout << "Enter sizes of " << np << " processes:\n";
    for (int i = 0; i < np; i++) cin >> processSize[i];

    vector<int> allocation(np, -1);

    for (int i = 0; i < np; i++) {
        for (int j = 0; j < nb; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    cout << "\n--- First Fit Allocation ---\n";
    cout << "Process\tSize\tBlock\n";
    for (int i = 0; i < np; i++) {
        cout << i + 1 << "\t" << processSize[i] << "\t";
        if (allocation[i] != -1) cout << allocation[i] + 1 << "\n";
        else cout << "Not Allocated\n";
    }

    return 0;
}
