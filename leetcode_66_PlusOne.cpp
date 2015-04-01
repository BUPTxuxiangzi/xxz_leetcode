/*问题描述
Plus One
Total Accepted: 41324 Total Submissions: 134070

Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
数组的低位存储数字的高位
*/

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
    int carry = 1;
	vector<int>::iterator iter = digits.end();
	int tmp = 0;
	do
	{
		iter--;
		tmp = *iter;
		(*iter) = (tmp + carry) % 10;
		carry = ( tmp + carry) / 10;
	
	} while (iter != digits.begin() );

	if (carry) //carry != 0
	{
		digits.insert(digits.begin(), carry);
	}
	return digits;
    }
};