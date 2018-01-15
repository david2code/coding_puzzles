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
vector<vector<string> > partition(string s)
{
    vector<vector<string> > result;
    vector<string> output;

    DFS(s, 0, output, result);
    return result;
}
int main()
{
    string s = "aab";
    vector<vector<string> > result;

    result = partition(s);
    cout << s << endl << result.size() << endl;
    for (int i = 0; i < result.size();i ++)
    {
        vector<string> output = result[i];
        for (int j = 0; j < output.size(); j++)
        {
            cout << output[j] << "  ";
        }

        cout << endl;
    }
	return 0;
}
