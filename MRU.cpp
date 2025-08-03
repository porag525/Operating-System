#include<bits/stdc++.h>
using namespace std;

int findLRUIndex(vector<pair<int, int>>& frames) {
    int maxTime = frames[0].second;
    int index = 0;
    for (int i = 1; i < frames.size(); i++) {
        if (frames[i].second > maxTime) {
            maxTime = frames[i].second;
            index = i;
        }
    }
    return index;
}

int main() {
    int n, frameSize;
    cout << "Enter number of pages: ";
    cin >> n;
    vector<int> pages(n);

    cout << "Enter page reference string: ";
    for (int i = 0; i < n; i++) cin >> pages[i];

    cout << "Enter number of frames: ";
    cin >> frameSize;

    vector<pair<int, int>> frames; // {page, last_used_time}
    int pageFaults = 0, time = 0;

    for (int i = 0; i < n; i++) {
        time++;
        int current = pages[i];
        bool found = false;

        // Check if page already in frame
        for (auto& p : frames) {
            if (p.first == current) {
                p.second = time; // update last used time
                found = true;
                break;
            }
        }

        if (!found) {
            pageFaults++;
            if (frames.size() < frameSize) {
                frames.push_back({current, time});
            } else {
                int lruIndex = findLRUIndex(frames);
                frames[lruIndex] = {current, time};
            }
        }

        // Print current frame state
        cout << "After accessing " << current << ": [ ";
        for (auto& p : frames) cout << p.first << " ";
        cout << "]\n";
    }

    cout << "\nTotal Page Faults = " << pageFaults << endl;
    return 0;
}
