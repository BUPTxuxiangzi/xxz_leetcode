/*问题描述
Valid Sudoku Total Accepted: 31207 Total Submissions: 114780

Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. 
Only the filled cells need to be validated. 
不必考虑九宫格是否能求解出来，只需要考虑填上的格子是有效的就可以
*/

/*解法1：暴力求解，直接循环
时间复杂度O(n^2)，空间复杂度为O(1)(其实是O(9))
runtimes:43ms
*/
class Solution
{
public:
    bool isValidSudoku(vector<vector<char> > &board)
    {
        //逐行判断
        for(int i=0; i!=9; ++i)
        {
            unordered_map<int, bool> imap;
            for(int j=0; j!=9; ++j)
            {
                imap[board[i][j]] = false;
            }
            for(int j=0; j!=9; ++j)
            {
                if(board[i][j] == '.')
                {
                    continue;
                }
                else
                {
                    if(imap[board[i][j]])//已经被访问过，证明是重复了
                        return false;//直接返回不是
                    else
                        imap[board[i][j]] = true;
                }
            }

        }//行

        //逐列判断
        for(int i=0; i!=9; ++i)
        {
            unordered_map<int, bool> imap;
            for(int j=0; j!=9; ++j)
            {
                imap[board[i][j]] = false;
            }
            for(int j=0; j!=9; ++j)
            {
                if(board[j][i] == '.')
                {
                    continue;
                }
                else
                {
                    if(imap[board[j][i]])//已经被访问过，证明是重复了
                        return false;//直接返回不是
                    else
                        imap[board[j][i]] = true;
                }
            }

        }//列

        for(int k=0; k!=3; ++k)
        {
            for(int l=0; l!=3; ++l)
            {
                unordered_map<int, bool> imap;
                for(int i = 3*k; i!=3+3*k; ++i)
                {
                    for(int j=3*l; j!=3+3*l; ++j)
                    {
                        imap[board[i][j]] = false;
                    }
                }

                for(int i=3*k; i!=3+3*k; ++i)
                {
                    for(int j=3*l; j!=3+3*l; ++j)
                    {
                        if(board[i][j] == '.')
                        {
                            continue;
                        }
                        else
                        {
                            if(imap[board[i][j]])//已经被访问过，证明是重复了
                                return false;//直接返回不是
                            else
                                imap[board[i][j]] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};

/*法2：不用哈希，写一个check函数，判断是某点是否被访问过
时间复杂度O(n^2),空间复杂度O(1) (其实是O(9))
runtime:18ms
*/
class Solution
{
public:
    bool check(char ch, bool used[9])  //改为inline的，时间反而变成了20ms
    {
        if('.' == ch)
        {
            return true;
        }

        if(used[ch - '1'])
        {
            return false;
        }
        used[ch - '1'] = true;
        return true;
    }
    bool isValidSudoku(vector<vector<char> > &board)
    {
        bool used[9];
        //行与列
        for(int i=0; i!=9; ++i)
        {
            //逐行对比
            for(int j=0; j!=9; ++j)
            {
                used[j] = false;
            }
            for(int j=0; j!=9; ++j)
            {
                if(!check(board[i][j], used))
                    return false;
            }

            //逐列对比
            for(int j=0; j!=9; ++j)
            {
                used[j] = false;
            }
            for(int j=0; j!=9; ++j)
            {
                if(!check(board[j][i], used))
                    return false;
            }
        }//行列结束

        //逐个小方格对比
        for(int k=0; k!=3; ++k)
        {
            for(int l=0; l!=3; ++l)
            {
                for(int i = 0; i!=9; ++i)
                {
                    used[i] = false;
                }

                for(int i=3*k; i!=3+3*k; ++i)
                {
                    for(int j=3*l; j!=3+3*l; ++j)
                    {
                        if(!check(board[i][j], used))
                            return false;
                    }
                }
            }
        }
        return true;
    }
};


/*法3：用fill函数代替for循环给used赋值
fill函数与fill_n函数讲解：

fill函数的作用是：将一个区间的元素都赋予val值。
函数参数：fill(first,last,val);
//first为容器的首迭代器，last为容器的末迭代器，val为将要替换的值。

fill_n函数的作用是：给你一个起始点，然后再给你一个数值count和val。
把从起始点开始依次赋予count个元素val的值。
注意： 不能在没有元素的空容器上调用fill_n函数

runtime：21ms
*/
class Solution
{
public:
    bool check(char ch, bool used[9])
    {
        if('.' == ch)
        {
            return true;
        }

        if(used[ch - '1'])
        {
            return false;
        }
        used[ch - '1'] = true;
        return true;
    }
    bool isValidSudoku(vector<vector<char> > &board)
    {
        bool used[9];
        //行与列
        for(int i=0; i!=9; ++i)
        {
            //逐行对比
            fill(used, used+9, false);
            for(int j=0; j!=9; ++j)
            {
                if(!check(board[i][j], used))
                    return false;
            }

            //逐列对比
            fill(used, used+9, false);
            for(int j=0; j!=9; ++j)
            {
                if(!check(board[j][i], used))
                    return false;
            }
        }//行列结束

        //逐个小方格对比
        for(int k=0; k!=3; ++k)
        {
            for(int l=0; l!=3; ++l)
            {
                fill(used, used+9, false);
                for(int i=3*k; i!=3+3*k; ++i)
                {
                    for(int j=3*l; j!=3+3*l; ++j)
                    {
                        if(!check(board[i][j], used))
                            return false;
                    }
                }
            }
        }
        return true;
    }
};