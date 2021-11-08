#include "iostream"
#include <map>
#include <string>


using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        map<char, int> src;
        map<int, bool> marks;
        int bulls = 0, cows = 0;
        for (int i = 0; i < secret.size(); ++i) {
            if(secret[i] == guess[i]){
                bulls ++;
                marks[i] = true;
            }else{
                src[secret[i]] ++;
            }
        }
        for (int i = 0; i < guess.size(); ++i) {
            if (marks[i]){
                continue;
            }
            if (src[guess[i]] > 0){
                src[guess[i]] --;
                cows ++;
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

int main(){
    Solution sol;
    string ans = sol.getHint("1807", "7810");
    cout << ans;
    return 0;
}