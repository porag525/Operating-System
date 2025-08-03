#include <iostream>
#include <set>
using namespace std;

int main() {
    multiset<int> blocks = {100, 500, 200, 300, 600}; // free memory blocks
    int processes[] = {212, 417, 112, 426}; // process memory needs
    int n = sizeof(processes)/sizeof(processes[0]);

    for (int i = 0; i < n; ++i) {
        int p = processes[i];

        // Use binary search via lower_bound in multiset
        auto it = blocks.lower_bound(p);

        if (it != blocks.end()) {
            cout << "Process " << p << " -> Block " << *it << endl;
            blocks.erase(it);  // allocate and remove block
        } else {
            cout << "Process " << p << " -> Not allocated\n";
        }
    }

    return 0;
}
