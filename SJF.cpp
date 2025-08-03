#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int pid; // Process ID
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

// Custom comparison function to sort by burst time
bool compareProcesses(const Process &a, const Process &b)
{
    return a.burst_time <= b.burst_time;
}

void calculateTimes(vector<Process> &processes)
{
    int n = processes.size();
    sort(processes.begin(), processes.end(), compareProcesses); // Sort by burst time

    int current_time = 0;
    for (int i = 0; i < n; ++i)
    {
        if (current_time < processes[i].arrival_time)
        {
            current_time = processes[i].arrival_time; // CPU idle until arrival
        }
        processes[i].completion_time = current_time + processes[i].burst_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        current_time = processes[i].completion_time;
    }
}

int main()
{

    vector<Process> processes = {
        {1, 4, 5},
        {2, 0, 2},
        {3, 1, 5},
        {4, 6, 7},
        {5, 2, 3}};

    calculateTimes(processes);

    cout << "PID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n";
    for (const auto &p : processes)
    {
        cout << p.pid << "\t" << p.arrival_time << "\t" << p.burst_time << "\t"
             << p.completion_time << "\t\t" << p.turnaround_time << "\t\t" << p.waiting_time << "\n";
    }

    return 0;
}