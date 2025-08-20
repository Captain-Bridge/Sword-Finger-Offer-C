#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty()) return false;
        int length = sequence.size();
        if(length == 1) return true;        
        int root = sequence[length-1];


        int index = 0;
        for(; index < length-1; index++){
            if(sequence[index]>root) break;
        }

        int seperate = index;
        for(;index<length-1;index++){
            if (sequence[index]<root) {
                return false;
            }
        }

        vector<int> leftSeq;
        for(int i = 0; i < seperate; i++)   leftSeq.push_back(sequence[i]);
        vector<int> rightSeq;
        for(int i = seperate; i < length-1; i++)   rightSeq.push_back(sequence[i]);

        if (leftSeq.empty()) {
            return VerifySquenceOfBST(rightSeq);
        }else if (rightSeq.empty()) {
            return VerifySquenceOfBST(leftSeq);
        }else {
        return (VerifySquenceOfBST(leftSeq) && VerifySquenceOfBST(rightSeq));        
        }
    }
};