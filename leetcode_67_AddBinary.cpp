/*问题描述
Add Binary Total Accepted: 38333 Total Submissions: 154262

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100". 
 */

/*解法1：直接求解
Status: Accepted
Runtime: 8 ms
 */
class Solution {
public:
	string addBinary(string a, string b) {
		int alen = a.size(), blen = b.size();
		int carry = 0;
		int tmp;
		string result;
		int i, j;
		for (i = alen - 1, j = blen - 1; i != -1 && j != -1; --i, --j)
		{
			tmp = a[i] - '0' + b[j] - '0' + carry;
			carry = tmp / 2;
			result.push_back(tmp % 2);
		}
		while (i != -1)
		{
			tmp = a[i--] - '0' + carry;
			carry = tmp / 2;
			result.push_back(tmp % 2);
		}
		while (j != -1)
		{
			tmp = b[j--] - '0' + carry;
			carry = tmp / 2;
			result.push_back(tmp % 2);
		}
		if (carry)
			result.push_back(carry);

		string res;
		int slen = result.size();
		for (int i = slen - 1; i != -1; --i)
		{
			res.push_back(result[i] + '0');
		}
		return res;
	}
};