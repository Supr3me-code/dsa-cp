// Given a set of N jobs where each jobi has a deadline and profit associated
// with it.

// Each job takes 1 unit of time to complete and only one job can be scheduled
// at a time. We earn the profit associated with job if and only if the job is
// completed by its deadline.

// Find the number of jobs done and the maximum profit.

// Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated
// with that Job.

class Solution {
   public:
    bool comparator(Job job1, Job job2) { return (job1.profit > job2.profit); }
    vector<int> JobScheduling(Job arr[], int n) {
        vector<int> result;
        sort(arr, arr + n, comparator);
        int maxi = arr[0].dead;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, arr[i].dead);
        }
        int slot[maxi + 1];
        for (int i = 0; i < n; i++) {
            slot[i] = -1;
        }
        int count = 0;
        int totalProfit = 0;

        for (int i = 0; i < n; i++) {
            for (int j = arr[i].dead; j > 0; j--) {
                if (slot[j] == -1) {
                    slot[j] = i;
                    count++;
                    totalProfit += arr[i].profit;
                    break;
                }
            }
        }
        result.push_back(count);
        result.push_back(totalProfit);
        return result;
    }
};

struct Job {
    int id;      // Job Id
    int dead;    // Deadline of job
    int profit;  // Profit if job is over before or on deadline
};
class Solution {
   public:
    bool static comparison(Job a, Job b) { return (a.profit > b.profit); }
    // Function to find the maximum profit and the number of jobs done
    pair<int, int> JobScheduling(Job arr[], int n) {
        sort(arr, arr + n, comparison);
        int maxi = arr[0].dead;
        for (int i = 1; i < n; i++) {
            maxi = max(maxi, arr[i].dead);
        }

        int slot[maxi + 1];

        for (int i = 0; i <= maxi; i++) slot[i] = -1;

        int countJobs = 0, jobProfit = 0;

        for (int i = 0; i < n; i++) {
            for (int j = arr[i].dead; j > 0; j--) {
                if (slot[j] == -1) {
                    slot[j] = i;
                    countJobs++;
                    jobProfit += arr[i].profit;
                    break;
                }
            }
        }

        return make_pair(countJobs, jobProfit);
    }
};