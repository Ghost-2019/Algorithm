class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();	// ����
        int col = matrix[0].size();	// ����
        int i = 0;

        // �ҵ�������
        while(!(target >= matrix[i][0] && target <= matrix[i][col])) {
        	i++;
        	if(i > row - 1)	// �����ж�������
        		return false;
        }

       	int left = 0;
       	int right = col - 1;
       	int mid = left + (right - left) / 2;
        if(matrix[i][mid] == target)
                return true;
       	while(left != right) {
         		if(matrix[i][mid] == target)
         			  return true;
         		else if(matrix[i][mid] > target) {
           			right = mid - 1;
           			mid = left + (right - left) / 2;
         		} else if(matrix[i][mid] < target) {
         			  left = mid + 1;
         			  mid = left + (right - left) / 2;
         		}
       	}
        return false;
    }
};
