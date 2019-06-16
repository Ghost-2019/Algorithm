class Solution {
public:
	int longestValidParentheses(string s) {
		int n = s.length(), maxL = 0;
		stack<int> st;
		// st ������ֻʣ�� ȥ������ �����ڳɶ�������ϡ�������С������͡�������pos
		for (int i = 0; i < n; i++) {
			if (s[i] == '(')
				st.push(i);
			else {
				if (!st.empty()) {
					if (s[st.top()] == '(')
						st.pop();
					else
						st.push(i);
				}
				else {
					st.push(i);
				}
			}
		}
		if (st.empty())	// ȫ�����ѳɶ�
			maxL = n;
		else {
			int r = n, q = 0;
			while (!st.empty()) {
				q = st.top();
				st.pop();
				maxL = max(maxL, r - q - 1);
				r = q;
			}
			maxL = max(maxL, r);
		}
		return maxL;
	}

};