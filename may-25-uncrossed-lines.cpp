// https://leetcode.com/problems/uncrossed-lines/

int dp(int i, int j, vector<int>& A, vector<int>& B, int** dparr)
{
	if (dparr[i][j] >= 0) return dparr[i][j];
	if (i == A.size() - 1 && j == B.size() - 1)	dparr[i][j] = A[i] == B[j] ? 1 : 0;
	else if (i == A.size() - 1) dparr[i][j] = A[i] == B[j] ? 1 : dp(i, j + 1, A, B, dparr);
	else if (j == B.size() - 1) dparr[i][j] = A[i] == B[j] ? 1 : dp(i + 1, j, A, B, dparr);
	else if (A[i] == B[j]) dparr[i][j] = 1 + dp(i + 1, j + 1, A, B, dparr);
	else dparr[i][j] = max({ dp(i, j + 1, A, B, dparr), dp(i + 1, j, A, B, dparr)});
	return dparr[i][j];
}

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
		int** dparr = new int*[A.size()];
		for (int i = 0; i < A.size(); ++i)
		{
			dparr[i] = new int[B.size()];
			fill(dparr[i], dparr[i] + B.size(), -1);
		}			
		return dp(0, 0, A, B, dparr);
    }
};