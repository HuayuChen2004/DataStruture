#include<iostream> 
#include<vector> 
#include<algorithm> 
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        mergedIntervals.push_back(intervals[0]);
        int numInterval = intervals.size();
        for (int i=1;i<numInterval;i++){
            // cout << "intervals[" << i << "]: [" << intervals[i][0] << "," << intervals[i][1] << "]" << endl;
            mergeInterval(mergedIntervals, intervals[i]);
            // cout << "After merging interval " << i << ":" << endl;
            // for (const auto& mergedInterval:mergedIntervals){
            //     cout<<'['<<mergedInterval[0]<<','<<mergedInterval[1]<<']'<<endl;
            // }
        }
        return mergedIntervals;
    }
private:
    void mergeInterval(vector<vector<int>>& mergedIntervals, vector<int>& interval){
        // cout << "interval: [" << interval[0] << "," << interval[1] << "]" << endl;
        for (int i=0;i<mergedIntervals.size();i++){
            // cout << "mergedIntervals[" << i << "]: [" << mergedIntervals[i][0] << "," << mergedIntervals[i][1] << "]" << endl;
            if (mergedIntervals[i][0]<=interval[0]&& interval[0]<=mergedIntervals[i][1]) {
                interval[0]=mergedIntervals[i][0];
                // cout << "interval: [" << interval[0] << "," << interval[1] << "]" << endl;
            }
            // cout << "mergedIntervals[" << i << "]: [" << mergedIntervals[i][0] << "," << mergedIntervals[i][1] << "]" << endl;
            // cout << "interval[1]: " << interval[1] << endl;
            if (mergedIntervals[i][0]<=interval[1]&& interval[1]<=mergedIntervals[i][1]) {
                interval[1]=mergedIntervals[i][1];
                // cout << "interval: [" << interval[0] << "," << interval[1] << "]" << endl;
            }
        }
        // cout << "interval: [" << interval[0] << "," << interval[1] << "]" << endl;
        // cout << "checking point 1" << endl;
        // cout << "mergedIntervals.size(): " << mergedIntervals.size() << endl;
        for (auto it = mergedIntervals.begin(); it != mergedIntervals.end(); ) {
            if (interval[0] <= it->at(0) && interval[1] >= it->at(1)) {
                // 如果 interval 完全包含 *it，则删除 *it
                it = mergedIntervals.erase(it);
            } else {
                ++it;
            }
        }

        // cout << "checking point 2" << endl;
        // cout << "interval: [" << interval[0] << "," << interval[1] << "]" << endl;
        mergedIntervals.push_back(interval);
    }
};

int main(){
    vector<vector<int>> intervals={{2,3},{4,5},{6,7},{8,9},{1,10}};
    Solution sol;
    vector<vector<int>> mergedIntervals=sol.merge(intervals);
    for (const auto& mergedInterval:mergedIntervals){
        cout<<'['<<mergedInterval[0]<<','<<mergedInterval[1]<<']'<<endl;
    }
    return 0;
}