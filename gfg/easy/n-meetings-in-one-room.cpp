class Solution{
    public:
    struct Meeting{
        int start;
        int end;
        int pos;
    };

    bool comparator(Meeting m1, Meeting m2){
        if(m1.end<m2.end) return true;
        else if(m1.end>m2.end) return false;
        else if(m1.pos<m2.pos) return true;
        return false;
    )

    int maxMeetings(int start[], int end[], int n){
        Meeting meet[n];
        for(int i=0;i<n;i++){
            meet[i].start = start[i];
            meet[i].end = end[i];
        }

        sort(meet, meet+n, comparator);

        int result = 0;
        int limit = meet[0].end;
        result++;
        for(int i=0;i<n;i++){
            if(meet[i].start>limit){
                limit = meet[i].end;
                result++;
            }
        }
        return result;
   }
};