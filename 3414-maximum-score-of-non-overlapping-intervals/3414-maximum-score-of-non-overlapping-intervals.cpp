class Solution {
public:
    struct Node{
        long long score;
        vector<int> idxs;

        Node(){
            score = 0;
        }
    };

    int n;
    vector<int> nextIdx;
    vector<vector<Node>> t;

    int findNext(vector<vector<int>>& intervals, int r){
        int l = 0;
        int h = n - 1;
        int result = n;

        while(l <= h){
            int mid = l + (h - l) / 2;
            if(intervals[mid][0] > r){
                result = mid;
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return result;
    }

    Node solve(vector<vector<int>> &intervals, int i, int k){
        if(k == 0 || i >= n){
            return Node();
        }

        if(t[i][k].score != -1){
            return t[i][k];
        }

        Node skip = solve(intervals, i+1, k);

        long long weight = intervals[i][2];
        int idx = intervals[i][3];
        int j = nextIdx[i];

        Node temp = solve(intervals, j, k-1);

        Node take;
        take.score = temp.score + weight;
        take.idxs = temp.idxs;
        take.idxs.push_back(idx);

        sort(take.idxs.begin(), take.idxs.end());

        Node result;

        if(take.score > skip.score){
            result = take;
        }
        else if(take.score < skip.score){
            result = skip;
        }
        else{
            result = min(take.idxs, skip.idxs) == take.idxs ? take : skip;
        }

        t[i][k] = result;

        return result;

    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();

        for(int i =0;i<n;i++){
           intervals[i].push_back(i);
        }

        sort(intervals.begin(), intervals.end());

        nextIdx.resize(n);

        for(int i=0;i<n;i++){
            nextIdx[i] = findNext(intervals, intervals[i][1]);
        }

        t.assign(n, vector<Node>(5));

        for(int i=0;i<n;i++){
            for(int k=0;k<=4;k++){
                t[i][k].score = -1;
            }
        }
        return solve(intervals, 0, 4).idxs;
    }
};