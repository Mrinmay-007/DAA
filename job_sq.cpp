#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

// Comparison function for sorting by profit (descending)
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    ifstream file("jobs.txt");
    if (!file) {
        cout << "Error opening file.";
        return 1;
    }

    int n;
    file >> n;

    Job jobs[100]; // assuming max 100 jobs
    for (int i = 0; i < n; i++) {
        file >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }
    file.close();

    // Sort jobs by profit descending
    sort(jobs, jobs + n, compare);

    // Find max deadline
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    bool slot[100] = {false};       // max 100 time slots
    char result[100];               // to store job IDs
    int totalProfit = 0;

    // Fill slots greedily
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (!slot[j]) {
                slot[j] = true;
                result[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Output scheduled jobs and total profit
    cout << "Scheduled Jobs: ";
    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i])
            cout << result[i] << " ";
    }
    cout << "\nTotal Profit: " << totalProfit << endl;

    return 0;
}
