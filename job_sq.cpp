
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

// Sort jobs by descending profit
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

    vector<Job> jobs(n);
    for (int i = 0; i < n; i++) {
        file >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    file.close();

    sort(jobs.begin(), jobs.end(), compare);

    int maxDeadline = 0;
    for (auto j : jobs) maxDeadline = max(maxDeadline, j.deadline);

    vector<bool> slot(maxDeadline, false);
    vector<char> result(maxDeadline, '-');
    int totalProfit = 0;

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

    cout << "Scheduled Jobs: ";
    for (char id : result) {
        if (id != '-') cout << id << " ";
    }
    cout << "\nTotal Profit: " << totalProfit << endl;

    return 0;
}

