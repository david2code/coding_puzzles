#include <iostream>
#include <vector>

using namespace std;

bool isPali(string s, int start, int end)
{
    while(start < end)
    {
        if (s[start] != s[end])
            return false;
        start ++;
        end --;
    }

    return true;
}

void DFS(string s, int start, vector<string>& output, vector<vector<string> >& result)
{
    if (start >= s.size())
    {
        result.push_back(output);
    }

    for (int i = start; i < s.size(); i++)
    {
        if (isPali(s, start, i))
        {
            output.push_back(s.substr(start, i + 1 - start));
            DFS(s, i + 1, output, result);
            output.pop_back();
        }
    }
}
int min_partition(string s)
{
    int size = s.size();
    int is_pali[size][size];
    int min_p[size];    


    for (int i = 0; i < size; i ++)
    {
        min_p[i] = size;
        for(int j = 0; j < size; j ++)
            is_pali[i][j] = 0;
    }

    min_p[0] = 1;

    for (int i = 1; i < size; i++)
    {
        //cout << i << endl;
        min_p[i] = min_p[i - 1] + 1;
        for (int j = 0; j < i; j++)
        {
            //cout << i << " " << j << endl;
            if (s[j] == s[i] && ((i - j) <= 2 || is_pali[j + 1][i - 1]))
            {
                is_pali[j][i] = 1;
                if (j == 0)
                    min_p[i] = 1;
                else
                    min_p[i] = min(min_p[i], min_p[j - 1] + 1);
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            cout << i << " " << j << "  " << is_pali[i][j] << endl;

        cout << endl;
        
    }
    
    return min_p[size - 1];
}
int main()
{
    string s = "cacaabbbaacc";

    int result = min_partition(s);
    cout << s << endl << result << endl;
	return 0;
}
