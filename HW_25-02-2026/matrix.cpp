//UID:24BCS10773

//1.Multiply 2 matrices GFG
class Solution {
  public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {\
    int n=mat1.size();
        vector<vector<int>>mat3(n,vector<int>(n,0));
        
        for(int i=0;i<mat1.size();i++){
            for(int j=0;j<mat2.size();j++){
                for(int k=0;k<n;k++){
                    mat3[i][j]+=mat1[i][k]*mat2[k][j];
                }
            }
        }
        return mat3;
        
    }
};

//Multiply 2 matrices using Recurrence Relation (Divide & Conquer (T(n) = 8T(n/2) + O(n²)))

#include <bits/stdc++.h>
using namespace std;

class MatrixMultiplyDC {
public:
    vector<vector<int>> multiplyMatrices(vector<vector<int>>& A,
                                          vector<vector<int>>& B) {
        int size = A.size();
        return solve(A, B, 0, 0, 0, 0, size);
    }

private:
    vector<vector<int>> solve(vector<vector<int>>& A,
                              vector<vector<int>>& B,
                              int rA, int cA,
                              int rB, int cB,
                              int n) {

        vector<vector<int>> result(n, vector<int>(n, 0));

        if (n == 1) {
            result[0][0] = A[rA][cA] * B[rB][cB];
            return result;
        }

        int mid = n / 2;

        auto M1 = solve(A, B, rA, cA, rB, cB, mid);
        auto M2 = solve(A, B, rA, cA + mid, rB + mid, cB, mid);

        auto M3 = solve(A, B, rA, cA, rB, cB + mid, mid);
        auto M4 = solve(A, B, rA, cA + mid, rB + mid, cB + mid, mid);

        auto M5 = solve(A, B, rA + mid, cA, rB, cB, mid);
        auto M6 = solve(A, B, rA + mid, cA + mid, rB + mid, cB, mid);
      
        auto M7 = solve(A, B, rA + mid, cA, rB, cB + mid, mid);
        auto M8 = solve(A, B, rA + mid, cA + mid, rB + mid, cB + mid, mid);
      
        for (int i = 0; i < mid; i++) {
            for (int j = 0; j < mid; j++) {
                result[i][j] = M1[i][j] + M2[i][j];
                result[i][j + mid] = M3[i][j] + M4[i][j];
                result[i + mid][j] = M5[i][j] + M6[i][j];
                result[i + mid][j + mid] = M7[i][j] + M8[i][j];
            }
        }
        return result;
    }
};
