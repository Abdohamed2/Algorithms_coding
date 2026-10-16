#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Patient
{
    int id;
    string name;
    int severity;
    int arrivalTime;
};

vector<Patient> heap;

bool higherPriority(Patient a, Patient b)
{
    if (a.severity != b.severity)
        return a.severity > b.severity;
    return a.arrivalTime < b.arrivalTime;
}

void heapifyUp(int index)
{
    while (index > 0)
    {
        int parent = (index - 1) / 2;

        if (higherPriority(heap[index], heap[parent]))
        {
            swap(heap[index], heap[parent]);
            index = parent;
        }
        else
        {
            break;
        }
    }
}

void heapifyDown(int index)
{
    int n = heap.size();

    while (true)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int best = index;

        if (left < n && higherPriority(heap[left], heap[best]))
            best = left;

        if (right < n && higherPriority(heap[right], heap[best]))
            best = right;

        if (best != index)
        {
            swap(heap[index], heap[best]);
            index = best;
        }
        else
        {
            break;
        }
    }
}

// Insert Patient
void insertPatient(Patient p)
{
    heap.push_back(p);
    heapifyUp(heap.size() - 1);
}

// View next patient
void viewNextPatient()
{
    if (heap.empty())
    {
        cout << "No patients.\n";
        return;
    }

    Patient p = heap[0];
    cout << "Next Patient: "
         << p.name
         << " (Severity: " << p.severity
         << ", Arrival: " << p.arrivalTime << ")\n";
}

// Treat Next Patient
void treatNextPatient()
{
    if (heap.empty())
    {
        cout << "No patients.\n";
        return;
    }

    cout << "Treating: " << heap[0].name << endl;

    heap[0] = heap.back();
    heap.pop_back();

    if (!heap.empty())
        heapifyDown(0);
}

// Update Severity
void updateSeverity(int patientId, int newSeverity)
{
    for (int i = 0; i < heap.size(); i++)
    {
        if (heap[i].id == patientId)
        {
            int oldSeverity = heap[i].severity;
            heap[i].severity = newSeverity;

            if (newSeverity > oldSeverity)
                heapifyUp(i);
            else
                heapifyDown(i);

            return;
        }
    }

    cout << "Patient not found.\n";
}

// Display
void displayAllPatients()
{
    if (heap.empty())
    {
        cout << "No patients.\n";
        return;
    }

    for (Patient p : heap)
    {
        cout << "ID: " << p.id
             << ", Name: " << p.name
             << ", Severity: " << p.severity
             << ", Arrival: " << p.arrivalTime
             << endl;
    }
}
int main()
{

    insertPatient({1, "Ahmed", 8, 1});
    insertPatient({2, "Sara", 10, 2});
    insertPatient({3, "Ali", 10, 3});
    insertPatient({4, "Mona", 6, 4});
    insertPatient({5, "Omar", 9, 5});
    insertPatient({6, "Nour", 7, 6});
    insertPatient({7, "Youssef", 5, 7});
    insertPatient({8, "Laila", 8, 8});
    insertPatient({9, "Hassan", 9, 9});
    insertPatient({10, "Aya", 4, 10});
    insertPatient({11, "Khaled", 10, 11});
    insertPatient({12, "Dina", 6, 12});
    insertPatient({13, "Tamer", 3, 13});
    insertPatient({14, "Rania", 7, 14});
    insertPatient({15, "Mahmoud", 8, 15});
    insertPatient({16, "Salma", 9, 16});
    insertPatient({17, "Mostafa", 2, 17});
    insertPatient({18, "Hoda", 5, 18});
    insertPatient({19, "Karim", 6, 19});
    insertPatient({20, "Mariam", 10, 20});

    cout << "=== All Patients ===\n";
    displayAllPatients();

    cout << "\n=== Next Patient ===\n";
    viewNextPatient();

    cout << "\n=== Treat Next Patient ===\n";
    treatNextPatient();

    cout << "\n=== After Treatment ===\n";
    viewNextPatient();

    cout << "\n=== Update Severity of Patient 10 to 12 ===\n";
    updateSeverity(10, 12);

    cout << "\n=== Next Patient After Update ===\n";
    viewNextPatient();

    cout << "\n=== Final Heap ===\n";
    displayAllPatients();

    return 0;
}