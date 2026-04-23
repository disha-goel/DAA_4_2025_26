#include "scheduler.h"
#include <algorithm>
#include <queue>
#include <stdexcept>

void JobScheduler::addJob(int id, const std::string& name, int deadline, int profit) {
    if (deadline < 1) throw std::invalid_argument("Deadline must be >= 1");
    if (profit   < 1) throw std::invalid_argument("Profit must be positive");
    jobs.push_back({id, name, deadline, profit});
}

bool JobScheduler::removeJob(int id) {
    auto it = std::find_if(jobs.begin(), jobs.end(),
                           [id](const Job& j){ return j.id == id; });
    if (it == jobs.end()) return false;
    jobs.erase(it);
    return true;
}

void JobScheduler::clear() { jobs.clear(); }

const std::vector<Job>& JobScheduler::getJobs() const { return jobs; }

// ── Greedy Job Scheduling ────────────────────────────────────────────────────
// 1. Push all jobs into a Max-Heap ordered by profit (highest first)
// 2. Pop each job, assign it to the latest free slot <= its deadline
// 3. If no slot available, job is skipped
// Time Complexity : O(n log n) — heap operations
// Space Complexity: O(n)
// ─────────────────────────────────────────────────────────────────────────────
ScheduleResult JobScheduler::schedule() const {
    if (jobs.empty()) return {{}, {}, {}, 0};

    // Max-Heap: highest profit on top
    auto cmp = [](const Job* a, const Job* b){ return a->profit < b->profit; };
    std::priority_queue<const Job*, std::vector<const Job*>, decltype(cmp)> maxHeap(cmp);

    for (const auto& j : jobs) maxHeap.push(&j);

    // Find max deadline to size the slot array
    int maxDeadline = 0;
    for (const auto& j : jobs)
        maxDeadline = std::max(maxDeadline, j.deadline);

    // slot[t] = job id occupying time slot t, -1 if free (1-indexed)
    std::vector<int> slot(maxDeadline + 1, -1);

    ScheduleResult result;
    result.totalProfit = 0;

    while (!maxHeap.empty()) {
        const Job* job = maxHeap.top(); maxHeap.pop();

        // Find latest free slot <= deadline (greedy choice)
        bool placed = false;
        for (int t = job->deadline; t >= 1; --t) {
            if (slot[t] == -1) {
                slot[t] = job->id;
                result.scheduledJobs.push_back(*job);
                result.timeSlots.push_back(t);
                result.totalProfit += job->profit;
                placed = true;
                break;
            }
        }
        if (!placed) result.skippedJobs.push_back(*job);
    }

    // Sort by time slot for clean output
    int n = result.scheduledJobs.size();
    std::vector<int> idx(n);
    std::iota(idx.begin(), idx.end(), 0);
    std::sort(idx.begin(), idx.end(),
              [&](int a, int b){ return result.timeSlots[a] < result.timeSlots[b]; });

    std::vector<Job> sj; std::vector<int> st;
    for (int i : idx) { sj.push_back(result.scheduledJobs[i]); st.push_back(result.timeSlots[i]); }
    result.scheduledJobs = sj;
    result.timeSlots     = st;

    return result;
}
