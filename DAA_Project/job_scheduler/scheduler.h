#pragma once
#include "job.h"
#include <vector>

struct ScheduleResult {
    std::vector<Job> scheduledJobs;
    std::vector<int> timeSlots;
    std::vector<Job> skippedJobs;
    int totalProfit;
};

class JobScheduler {
public:
    void addJob(int id, const std::string& name, int deadline, int profit);
    bool removeJob(int id);
    void clear();
    const std::vector<Job>& getJobs() const;

    // Greedy algorithm using Max-Heap (priority_queue)
    ScheduleResult schedule() const;

private:
    std::vector<Job> jobs;
};
