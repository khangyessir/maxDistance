#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    bool ballCheck(const std::vector<int>& position, int m, int x){
        int n = position.size();
        int start = -1e9;
        int count = 0;
        for(int i=0; i<n; ++i){
            if(position[i] - start >= x){
                start = position[i];
                ++count;
            }
        }
        return count >= m;
    }
public:
    int maxDistance(vector<int>& position, int m){
        int n = position.size();
        sort(position.begin(), position.end());
        int left = 0;
        int right = position[n-1] - position[0];
        int result = 0;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(ballCheck(position, m, mid)){
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};

//Example
int main(){
    Solution sol;
    vector<int> position = {5,4,3,2,1,1000000000};
    int m = 2;
    cout << sol.maxDistance(position, m) << endl;
    return 0;
}
