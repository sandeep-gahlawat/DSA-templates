#include<bits/stdc++.h>
using namespace std;


// Intuition:
// Assume B[i][j] = A[i] | A[i+1] | ... | A[j]
// Hash set cur stores all wise B[0][i], B[1][i], B[2][i], B[i][i].

// When we handle the A[i+1], we want to update cur
// So we need operate bitwise OR on all elements in cur.
// Also we need to add A[i+1] to cur.

// In each turn, we add all elements in cur to res.


// Complexity:
// Time O(30N)

// Normally this part is easy.
// But for this problem, time complexity matters a lot.

// The solution is straight forward,
// while you may worry about the time complexity up to O(N^2)
// However, it's not the fact.
// This solution has only O(30N)

// The reason is that, B[0][i] >= B[1][i] >= ... >= B[i][i].
// B[0][i] covers all bits of B[1][i]
// B[1][i] covers all bits of B[2][i]
// ....

// There are at most 30 bits for a positive number 0 <= A[i] <= 10^9.
// So there are at most 30 different values for B[0][i], B[1][i], B[2][i], ..., B[i][i].
// Finally cur.size() <= 30 and res.size() <= 30 * A.length()

// In a worst case, A = {1,2,4,8,16,..., 2 ^ 29}
// And all B[i][j] are different and res.size() == 30 * A.length()





int subarrayBitwiseORs(vector<int> A) {
        unordered_set<int> res, cur, cur2;
        for (int i: A) {
            cur2 = {i};

            //adding i arr[i] to all the previos values B[0][i-1] | arr[i]
           //{
//                curr_set contains all the value
//                 arr[0]|arr[1]|arr[2].....|arr[i]
//                        arr[1]|arr[2]|....|arr[i]
//                  .
//                  .
//                  .
//                                           arr[i]                     
           //}
            for (int j: cur) cur2.insert(i|j);

            // means maximun 30 values can be present in curr_set for every i
            for (int j: cur = cur2) res.insert(j);
        }
        return res.size();
    }