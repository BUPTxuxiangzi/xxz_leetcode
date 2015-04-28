/*问题描述
Given an array of strings, return all groups of strings that are anagrams.
Note: All inputs will be in lower-case.
*/


/*分析：
    首先简单介绍一下Anagram（回文构词法）。Anagrams是指由颠倒字母顺序组成的单词，
    比如“dormitory”颠倒字母顺序会变成“dirty room”，“tea”会变成“eat”。
    回文构词法有一个特点：单词里的字母的种类和数目没有改变，只是改变了字母的排列顺序。
*/

/*解法1：hash表法 （不是自己做的，抄来的）

思路：注意到回文构词法一个特点是单词中字母的种类和数目没有改变，只是改变了字母的排列顺序。
    所以，可以将各个string中的字母先进行排序，以生成一个关键字，值为可以生成它的所有string的
    一个组合， 因为值是一个组合，所以用vector<string>来存储。

步骤：
1>先将vector中的一个string建立哈希
        在建立哈希的时候应注意，先将string标准化，即将string中各元素按照字典顺序重新排列，
        得到“键”
2>将这个string加入到“键”对应的值（一个vector）中去
3>重复上述步骤，直到所有的string处理完毕。这样，就生成了一个哈希表。

4>哈希表的“值”是一个vector,如果它的size大于1，那么证明了这一组词属于回文构词法构造的词

Status: Accepted
Runtime: 50 ms
 */
//应好好理解
class Solution
{
public:
    vector<string> anagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string> > group;
        for (const auto &s : strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            group[key].push_back(s);
        }
            
        vector<string> result;
        for (auto it=group.cbegin(); it!=group.cend(); ++it)
        {
            //it所指向的是一个pair类型，it->first对应着“键”，it->second对应着值
            if(it->second.size()>1)
            {
                result.insert(result.end(), it->second.begin(), it->second.end());
            }
        }
        return result;
    }
};