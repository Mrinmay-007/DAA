#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    string id;
    int deadline;
    int profit;
};

// Sort by profit in descending order
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

void jobSequencing(vector<Job>& jobs) {
    // Sort jobs by descending profit
    sort(jobs.begin(), jobs.end(), compare);

    // Find max deadline
    int maxDeadline = 0;
    for (auto& job : jobs)
        maxDeadline = max(maxDeadline, job.deadline);

    // Time slots for jobs (0-indexed)
    vector<string> slots(maxDeadline, "");

    int totalProfit = 0;
    int count = 0;

    for (auto& job : jobs) {
        // Find a free slot from job.deadline - 1 to 0
        for (int j = min(maxDeadline, job.deadline) - 1; j >= 0; j--) {
            if (slots[j] == "") {
                slots[j] = job.id;
                totalProfit += job.profit;
                count++;
                break;
            }
        }
    }

    cout << "\nScheduled Jobs: ";
    for (auto& jobId : slots)
        if (jobId != "")
            cout << jobId << " ";
    cout << "\nTotal Profit: " << totalProfit << endl;
}

int main() {
    ifstream file("jobs.txt");
    if (!file) {
        cerr << "Error: Could not open file.\n";
        return 1;
    }

    int n;
    file >> n;

    vector<Job> jobs(n);
    for (int i = 0; i < n; i++) {
        file >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    file.close();

    cout << "Job Sequencing using Greedy Algorithm\n";
    jobSequencing(jobs);

    return 0;
}

