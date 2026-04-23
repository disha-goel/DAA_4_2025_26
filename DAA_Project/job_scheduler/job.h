#pragma once
#include <string>

struct Job {
    int id;
    std::string name;
    int deadline;   // latest time slot by which job must finish
    int profit;     // profit if completed on time
};
