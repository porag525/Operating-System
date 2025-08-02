#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

int main() {
    int n, frames;
    cout << "Enter number of pages: ";
    cin >> n;

    vector<int> pages(n);
    cout << "Enter page reference string:\n";
    for (int i = 0; i < n; i++) cin >> pages[i];

    cout << "Enter number of frames: ";
    cin >> frames;

    unordered_set<int> s;
    queue<int> q;
    int faults = 0;

    for (int i = 0; i < n; i++) {
        if (s.find(pages[i]) == s.end()) {
            if (s.size() == frames) {
                int old = q.front(); q.pop();
                s.erase(old);
            }
            s.insert(pages[i]);
            q.push(pages[i]);
            faults++;
        }
    }

    cout << "\nPage Faults (FIFO): " << faults << endl;
    return 0;
}
