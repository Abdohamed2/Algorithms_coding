#include <bits/stdc++.h>
using namespace std;

class Process
{
public:
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time = 0;
    int turnaround_time = 0;
    int waiting_time = 0;
};

class RoundRobin
{
public:
    int quantum;
    int num_processes;
    int current_time = 0;
    vector<Process *> finished;
    vector<Process *> processes;
    queue<Process *> ready;

    RoundRobin(int q, int n) : quantum(q), num_processes(n) {}

    void createProcesses()
    {
        for (int i = 0; i < num_processes; i++)
        {
            Process *p = new Process();
            cin >> p->id >> p->arrival_time >> p->burst_time;
            p->remaining_time = p->burst_time;
            processes.push_back(p);
        }
        sort(processes.begin(), processes.end(),
             [](Process *a, Process *b)
             { return a->arrival_time < b->arrival_time; });
    }

    void printQueue(queue<Process *> q)
    {
        if (q.empty())
        {
            cout << "[Empty]\n";
            return;
        }
        cout << "[ ";
        while (!q.empty())
        {
            cout << "P" << q.front()->id;
            q.pop();
            if (!q.empty())
                cout << ", ";
        }
        cout << " ]\n";
    }

    void run()
    {
        int i = 0;
        while (i < num_processes || !ready.empty())
        {
            while (i < num_processes && processes[i]->arrival_time <= current_time)
            {
                ready.push(processes[i]);
                i++;
            }

            printQueue(ready);

            if (ready.empty())
            {
                current_time++;
                continue;
            }

            Process *p = ready.front();
            ready.pop();

            int exec_time = min(quantum, p->remaining_time);
            current_time += exec_time;
            p->remaining_time -= exec_time;

            while (i < num_processes && processes[i]->arrival_time <= current_time)
            {
                ready.push(processes[i]);
                i++;
            }

            if (p->remaining_time > 0)
            {
                ready.push(p);
            }
            else
            {
                p->completion_time = current_time;
                p->turnaround_time = p->completion_time - p->arrival_time;
                p->waiting_time = p->turnaround_time - p->burst_time;
                finished.push_back(p);
            }
        }
        printQueue(ready);
    }

    void display()
    {
        cout << "\nProcess\tCT\tTAT\tWT\n";
        double avg = 0;
        for (auto p : finished)
        {
            cout << "P" << p->id << "\t"
                 << p->completion_time << "\t"
                 << p->turnaround_time << "\t"
                 << p->waiting_time << endl;
            avg += p->waiting_time;
        }
        cout << "Average Waiting Time = " << avg / num_processes << endl;
    }
};

int main()
{
    int quantum, n;
    cout << "Enter quantum time:\n";
    cin >> quantum;
    cout << "Enter number of processes:\n";
    cin >> n;

    RoundRobin rr(quantum, n);
    rr.createProcesses();
    rr.run();
    rr.display();

    return 0;
}