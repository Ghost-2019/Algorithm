class Solution {
public:
    /**
     * AC: 
     * Runtime: 8 ms, faster than 93.95% of C++ online submissions for Search a 2D Matrix.
     * Memory Usage: 9.7 MB, less than 100.00% of C++ online submissions for Search a 2D Matrix.
     * ע������Ŀӣ����� matrix Ϊ�� vector�� ����Ϊ ��[[]]�� (��1����0)��������������index �������������
     * ���Ƶ�����ע����Ŀ�Ƿ��Ѹ����ǿգ��ȵ���������������һ�δ����ύ���Ǵ����ķ�ʱ���ò���ʧ��
     *
     */ 
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        int row = matrix.size();  // ����
        int col = matrix[0].size(); // ����
        int i = 0;
       

        // �ҵ�������
        while(!(target >= matrix[i][0] && target <= matrix[i][col - 1])) {
          i++;
          if(i > row - 1) // �����ж�������
            return false;
        }

        int left = 0;
        int right = col - 1;
        int mid = left + (right - left) / 2;
        if(matrix[i][mid] == target)
                return true;
        while(left <= right) {
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
