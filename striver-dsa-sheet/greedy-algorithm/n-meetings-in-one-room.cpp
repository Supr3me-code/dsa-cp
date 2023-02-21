// There is one meeting room in a firm. There are N meetings in the form of
// (start[i], end[i]) where start[i] is start time of meeting i and end[i] is
// finish time of meeting i. What is the maximum number of meetings that can be
// accommodated in the meeting room when only one meeting can be held in the
// meeting room at a particular time?

// Note: Start time of one chosen meeting can't be equal to the end time of the
// other chosen meeting.

class Solution {
   public:
    struct Meeting {
        int start;
        int end;
        int pos;
    };

    bool comparator(Meeting m1, Meeting m2) {
        if (m1.end < m2.end)
            return true;
        else if (m1.end > m2.end)
            return false;
        else if (m1.pos < m2.pos)
            return true;
        return false;
    }

    int maxMeetings(int start[], int end[], int n) {
        Meeting meet[n];
        for (int i = 0; i < n; i++) {
            meet[i].start = start[i];
            meet[i].end = end[i];
        }

        sort(meet, meet + n, comparator);

        int result = 0;
        int limit = meet[0].end;
        result++;
        for (int i = 0; i < n; i++) {
            if (meet[i].start > limit) {
                limit = meet[i].end;
                result++;
            }
        }
        return result;
    }
};