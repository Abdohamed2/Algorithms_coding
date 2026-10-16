#include <bits/stdc++.h>
using namespace std;
class process
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
class roundrobibn

{
public:
    int quantum;
    int nomofprocess;
    int current_time = 0;
    vector<process *> finish;
    vector<process *> processes;
    queue<process *> r;
    roundrobibn(int q, int nopr)
    {
        quantum = q;
        nomofprocess = nopr;
    }

    void createprocess()
    {
        for (int i = 0; i < nomofprocess; i++)
        {
            process *p = new process();
            cin >> p->id;
            cin >> p->arrival_time;
            cin >> p->burst_time;
            p->remaining_time = p->burst_time;
            processes.push_back(p);
        }
        sort(processes.begin(), processes.end(), [](process *a, process *b)
             { return a->id < b->id; });
    }
    void printqueue(queue<process *> ready)
    {
        if (ready.empty())
        {
            cout << "[Empty]\n";
            return;
        }
        cout << "[ ";
        while (!ready.empty())
        {
            cout << "P" << ready.front()->id;
            ready.pop();
            if (!ready.empty())
                cout << ", ";
        }
        cout << " ]\n";
    }
    void updatereadyqueue()
    {
        int i = 0;
        while (i < nomofprocess || !r.empty())
        {
            while (i < nomofprocess && processes[i]->arrival_time <= current_time)
            {
                r.push(processes[i]);
                i++;
            }
            printqueue(r);
            if (r.empty())
            {
                // this condition important to the state of minimum arrival time is not equal to current_time or you have empty readyqueue but not all processes engaged into it
                current_time++;
                continue;
            }
            process *p = r.front();
            r.pop();

            int exectime = min(quantum, p->remaining_time);
            current_time += exectime;
            p->remaining_time -= exectime;
            while (i < nomofprocess && processes[i]->arrival_time <= current_time)
            {
                r.push(processes[i]);
                i++;
            }
            if (p->remaining_time > 0)
            {
                r.push(p);
            }
            else
            {
                p->completion_time = current_time;
                p->turnaround_time = p->completion_time - p->arrival_time;
                p->waiting_time = p->turnaround_time - p->burst_time;
                finish.push_back(p);
            }
        }
        printqueue(r);
    }
    void display()
    {
        cout << "\nProcess\tCT\tTAT\tWT\n";

        for (auto p : finish)
        {
            cout << "P" << p->id << "\t"
                 << p->completion_time << "\t"
                 << p->turnaround_time << "\t"
                 << p->waiting_time << endl;
        }

        double avg = 0;
        for (auto p : finish)
            avg += p->waiting_time;

        cout << "Average Waiting Time = " << avg / nomofprocess << endl;
    }
};
int main()
{
    int quantum, n;
    cout << " cin quantum time\n";
    cin >> quantum;
    cout << " cin number of processes\n";
    cin >> n;
    roundrobibn check(quantum, n);
    check.createprocess();
    check.updatereadyqueue();
    check.display();
}