#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <deque>
#include <queue>
#include <sstream>
#include <chrono>
#include <stack>
#include <algorithm>
#include <thread>
using namespace std;

class ATM {
public:
    ATM() {
        banknotes.resize(5, 0);
    }

    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; i++)
        {
            banknotes[i] += banknotesCount[i];
        }

    }

    void print() {
        for (auto i : banknotes)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    vector<int> withdraw(int amount) {
        vector<int> result = { 0,0,0,0,0 };
        auto temp = banknotes;
        for (int i = 4; i != -1; i--)
        {
            if (values[i] <= amount)
            {
                while (amount >= values[i] && temp[i] != 0)
                {
                    amount -= values[i];
                    temp[i]--;
                    result[i]++;
                }
                if (amount == 0) { banknotes = temp; return result; }
            }
        }
        return { -1 };
    }
private:
    vector<int> banknotes;
    vector<int> values = { 20,50,100,200,500 };
};
class Solution
{
public:
    int binary_search(vector<int>& v, int item)
    {
        int start = 0;
        int finish = v.size() - 1;
        while (finish >= start)
        {
            int mid = (finish + start) / 2;
            if (v[mid] == item)
            {
                return mid;
            }
            else if (v[mid]>item)
            {
                finish = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return -1;
    }

    int lengthOfLongestSubstring(string s) {
        if (s == "")return 0;
        int result = 1;
        for (int i = 0; i < s.length(); i++)
        {
            set<char> charSet;
            int j = i;
            while (1)
            {
                if (!charSet.insert(s[j]).second)
                {
                    if (result < charSet.size())result = charSet.size();
                    break;
                }
                if (j == s.length() - 1)break;
                j++;
            }
        }
        return result;
    }
    vector<int> commonElements(vector<int>& first, vector<int>& second)
    {
        vector<int> result;
        for (int i : first)
        {
            for (int& j : second)
            {
                if (i == j)
                {
                    result.push_back(j);
                    j = -1;
                }
            }
        }
        return result;
    }
    string RLE(string& str)
    {
        string result = "";
        char symb = str[0];
        int count = 0;
        for (int i = 0; i < str.length() + 1; i++)
        {
            if (i != str.length() && str[i] == symb)
            {
                count++;
            }
            else
            {
                result += symb;
                result += to_string(count);
                count = 1;
                symb = str[i];

            }
        }
        return result;
    }
    int fuctorial(int num)
    {
        if (num == 1)return 1;
        else
        {
            return num * fuctorial(num - 1);
        }

    }
    int recSum(vector<int>& v)
    {
        if (v.empty())return 0;
        else
        {
            int first = v.front();
            v.erase(v.begin());
            return first + recSum(v);
        }

    }
    void qSort(vector<int>& v)
    {
        if (v.size() < 2)return;
    }
    string intervals(vector<int>& v)
    {
        int first = v[0];
        string result = "";
        for (int i = 0; i < v.size() - 1; i++)
        {
            if (v[i + 1] > (v[i] + 1))
            {
                if (v[i] != first)
                {
                    result += (to_string(first) + "-" + to_string(v[i]) + ",");
                }
                else { result += to_string(v[i]) + ","; }
                first = v[i + 1];
            }
        }
        if (v[v.size() - 1] == first) { result += to_string(first); }
        else { result += (to_string(first) + "-" + to_string(v[v.size() - 1])); }
        return result;
    }
    vector<vector<string>> group(vector<string>& v)
    {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mp;
        for (auto i : v)
        {
            auto item = i;
            sort(i.begin(), i.end());
            mp[i].push_back(item);
        }

        for (auto i : mp)
        {
            vector<string> temp;
            for (auto j : i.second)
            {
                temp.push_back(j);
            }
            result.push_back(temp);
        }
        return result;
    }

    bool is_vertical_symmetry(unordered_map<int, int>& mp)
    {
        int xmax = INT_MIN;
        int xmin = INT_MAX;
        for (auto i : mp)
        {
            if (i.first < xmin) { xmin = i.first; }
            if (i.first > xmax) { xmax = i.first; }
        }
        int avgX = (xmax - xmin) / 2;
        for (auto i : mp)
        {
            auto curr = i;
            mp.erase(i.first);
            if (curr.first < avgX)
            {
                auto temp = mp.find(avgX - curr.first + avgX);
                if (temp == mp.end() || temp->second != curr.second) { return false; }
                mp.erase(temp);
            }
            else
            {
                auto temp = mp.find(curr.first - avgX - avgX);
                if (temp == mp.end() || temp->second != curr.second) { return false; }
                mp.erase(temp);
            }
        }
        return true;
    }
    bool isPalindrome(string s)
    {
        int i = 0;
        int j = s.length() - 1;
        while (j > i)
        {
            if (s[i] != s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string result = "";
        for (int i = 0; i < s.length(); i++)
        {

            for (int j = 1; j < s.length() - i + 1; j++)
            {
                string substr = s.substr(i, j);
                if (isPalindrome(substr))
                {
                    if (substr.length() > result.length())
                    {
                        result = substr;
                    }
                }
            }
        }
        return result;
    }
    int longestOneRov(vector<int>& v)
    {
        int result = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == 1)
            {
                int count = 0;
                while (i != v.size() && v[i] != 0)
                {
                    count++; i++;
                }
                if (count > result) {
                    result = count;
                }

            }
        }
        return result;
    }
    bool isValidAnagram(string& s1, string& s2)
    {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2 ? true : false;
    }
    void generate(string s, int open, int close, int n, vector<string>& ans) {
        if (s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }
        if (open < n) {
            generate(s + '(', open + 1, close, n, ans);
        }
        if (close < open) {
            generate(s + ')', open, close + 1, n, ans);
        }
    }

    int max_ones(vector<int>& nums) {
        int maxSet = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                int count = 0;
                while (i != nums.size() && nums[i] != 0)
                {
                    count++;
                    i++;
                }
                if (count > maxSet) { maxSet = count; }
            }
        }
        for (int i = 1; i < nums.size() - 1; i++)
        {
            if (nums[i] == 0 && nums[i + 1] == 1 && nums[i - 1] == 1)
            {
                int count = 0;
                int j = i - 1;
                while (j != -1 && nums[j] != 0)
                {
                    j--;
                    count++;
                }
                int k = i + 1;
                while (k != nums.size() && nums[k] != 0)
                {
                    k++;
                    count++;
                }
                if (count > maxSet) { maxSet = count; }
            }
        }
        if (maxSet == nums.size())return maxSet - 1;
        return maxSet;
    }
    int lengthOfLastWord(string s) {
        int result = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                while (i >= 0 && s[i] != ' ') {
                    result++;
                    i--;
                }
                break;
            }
        }
        return result;
    }
    void printWords(string s) {
        string result = "";
        vector<string> words;
        int first = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != ' ')
            {
                cout << "enter i:" << i << endl;
                first = i;
                while (i != s.length() && s[i] != ' ')
                {
                    i++;
                }
                words.push_back(s.substr(first, i - first));
                cout << "pushback i:" << i << endl;
            }
        }
        for (auto i : words)
        {
            cout << "*" << i << "*" << endl;
        }


    }

    bool isLetter(char sign)
    {
        if ((sign >= 'a' && sign <= 'z') || (sign >= 'A' && sign <= 'Z'))
        {
            return true;
        }
        return false;
    }

    bool isPalindromeSent(string s) {
        string str = "";
        for (auto i : s)
        {
            if (isLetter(i)) { str += i; }
        }
        cout << str << endl;
        int i = 0;
        int j = s.length() - 1;
        while (i < j)
        {
            if (!(str[j] == str[i] || str[j] == str[i] + 32 || str[j] == str[i] - 32)) { cout << s[j] << "!=" << s[i] << endl; return false; }
            i++;
            j--;
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        multiset<string> wordsSet;
        vector<int> result = {};
        int symbNum = 0;
        for (auto i : words)
        {
            wordsSet.insert(i);
            symbNum += i.length();
        }
        for (int i = 0; i + symbNum < s.length(); i++)
        {
            string tempStr = s.substr(i, symbNum);
            multiset<string> tempSet;
            for (int j = 0; j < tempStr.length(); j += words[0].length())
            {
                tempSet.insert(tempStr.substr(j, words[0].length()));
            }
            if (tempSet == wordsSet) { result.push_back(i); }
            tempSet.clear();
        }

        return result;
    }
    void stringSum()
    {
        int num;
        string str1, str2;
        cout << "Введите число: ";
        cin >> num;
        cout << "Введите первую строку: ";
        cin.ignore(); // очистка буфера после считывания числа
        getline(cin, str1);
        cout << "Введите вторую строку: ";
        getline(cin, str2);
        cout << "Вы ввели число: " << num << ", строки: " << str1 << " и " << str2 << endl;
        string result = "";
        for (int i = 0; i < num; i++)
        {
            result += str1[i];
            result += str2[i];
        }
        cout << result << std::endl;
    }
    void getVect()
    {
        int n;
        cin >> n;
        cin.ignore();
        string input;
        vector<int> nums;
        cout << "Введите строку с числами: ";
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        cout << "Введенные числа: ";
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> mp;
        for (int i = 0; i < strs.size(); i++)
        {
            auto temp = strs[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(i);
        }
        vector<vector<string>> result;
        result.resize(mp.size());
        int count = 0;
        for (auto i : mp)
        {
            for (auto j : i.second)
            {
                result[count].push_back(strs[j]);
            }
            count++;
        }
        return result;
    }
    bool stringIntersection(string base, string sub)
    {
        unordered_map<char, int> mpBase;
        unordered_map<char, int> mpSub;
        for (auto i : base)
        {
            if (mpBase.find(i) == mpBase.end()) {
                mpBase[i] = 1;
            }
            else { mpBase[i]++; }
        }
        for (auto i : sub)
        {
            if (mpSub.find(i) == mpSub.end()) {
                mpSub[i] = 1;
            }
            else { mpSub[i]++; }
        }
        for (auto i : mpSub)
        {
            if (mpBase.find(i.first) == mpBase.end()) { return false; }
            else { if (mpBase[i.first] < i.second) { return false; } }
        }
        return true;
    }
    void greed() {
        int n;
        cin >> n;
        int val;
        vector<vector<int>> v;
        for (int i = 0; i < n; i++)
        {
            int first;
            int second;
            cin >> first >> second;
            vector<int> temp;
            temp.push_back(first);
            temp.push_back(second);
            v.push_back(temp);
        }
        int count = 1;
        while (!v.empty())
        {
            int bestPos;
            int minFinish = 1000;
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i][2] < minFinish) { minFinish = v[i][2]; bestPos = i; }
            }
            v.erase(v.begin() + bestPos);
            for (int i = v.size() - 1; i >= 0; i--)
            {
                if (v[i][1] >= minFinish)
                {
                    v.erase(v.begin() + i);
                }
            }
            count++;
        }

        cout << count << std::endl;
    }
    vector<int> findAnagrams(string s, string p) {
        sort(p.begin(), p.end());
        vector<int> result;
        int pSize = p.length();
        for (int i = 0; i <= s.length() - pSize; i++)
        {
            string substr = s.substr(i, pSize);
            sort(substr.begin(), substr.end());
            if (substr == p)result.push_back(i);
        }
        return result;
    }
    string compressString(string str)
    {
        if (str.length() < 2)return str;
        string result = "";
        char prev = str[0];
        int count = 1;
        for (int i = 1; i < str.length(); i++)
        {
            if (prev != str[i])
            {
                if (count < 2)
                {
                    result += prev;
                }
                else
                {
                    result += prev;
                    result += to_string(count);
                }
                prev = str[i];
                count = 1;
            }
            else { count++; }
        }
        if (count < 2)
        {
            result += prev;
        }
        else
        {
            result += prev;
            result += to_string(count);
        }
        return result;
    }
    string getIntervals(vector<int> input)
    {
        string result = "";
        if (input.size() == 1) { result += to_string(input[0]); return result; }
        sort(input.begin(), input.end());//1 2 3 |5| 8 9
        int start = input[0];
        for (int i = 1; i < input.size(); i++)
        {
            if (input[i] != input[i - 1] + 1)
            {
                if (start == input[i - 1]) { result += to_string(input[i - 1]); result += ","; }
                else { result += to_string(start); result += "-"; result += to_string(input[i - 1]); result += ","; }
                start = input[i];
            }
        }
        if (start == input[input.size() - 1]) { result += to_string(input[input.size() - 1]); }
        else { result += to_string(start); result += "-"; result += to_string(input[input.size() - 1]); }
        return result;
    }
    void moveZeroes(vector<int>& input)
    {
        int zeroCount = 0;
        for (int i = 0; i < input.size(); i++)
        {
            if (input[i] == 0) { zeroCount++; }
            else { input[i - zeroCount] = input[i]; }
        }
        for (int i = input.size() - 1; i != input.size() - 1 - zeroCount; i--)
        {
            input[i] = 0;
        }

    }
    int compress(vector<char>& chars) {
        vector<char> resVect;
        int result = 0;
        int startGroupInd = 0;
        for (int i = 1; i <= chars.size(); i++)
        {
            if (i == chars.size() || chars[i] != chars[startGroupInd])
            {
                if (i == startGroupInd + 1)
                {
                    resVect.push_back(chars[startGroupInd]);
                    result += 1;
                }
                else
                {
                    resVect.push_back(chars[startGroupInd]);
                    result += 1;
                    string repet = to_string(i - startGroupInd);
                    for (auto y : repet)
                    {
                        result += 1;
                        resVect.push_back(y);
                    }
                }
                startGroupInd = i;
            }
        }
        chars = resVect;
        return result;
    }
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;
        int i = 0;
        int j = 0;
        while (i != firstList.size() && j != secondList.size())
        {
            int low = max(firstList[i][0], secondList[j][0]);
            int high = min(firstList[i][1], secondList[j][1]);
            if (low <= high)
            {
                result.push_back({ low,high });
            }
            if (firstList[i][1] > secondList[i][1]) { j++; }
            else i++;

        }
        return result;
    }
    int fuck(int num)
    {
        if (num == 1)return 1;
        else return(num * fuck(num - 1));
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int right = matrix[0].size() - 1;
        int left = 0;
        int high = 0;
        int down = matrix.size() - 1;
        while (right >= left || high <= down)
        {
            for (int i = left; i <= right; i++) // ->
            {
                result.push_back(matrix[high][i]);
            }
            high++;
            for (int i = high; i <= down; i++)// \/
            {
                result.push_back(matrix[i][right]);
            }
            right--;
            for (int i = right; i >= left; i--)
            {
                result.push_back(matrix[down][i]);
            }
            down--;
            for (int i = down; i >= high; i--)
            {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
        cout << " right: " << right << " left: " << left << " high: " << high << " down: " << down<<endl;
        return result;
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> result;
        if (k > arr.size())return result; // 1 3 6 8 10   k=3, x=9
        result.resize(k);
        int _NextPos = -1;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] >= x) { _NextPos = i; break; }
        }
        if (_NextPos == -1)
        {
            int j = k - 1;
            for (int i = arr.size() - 1; i >= arr.size() - k; i--)
            {
                result[j] = arr[i];
                j--;
            }
            return result;
        }
        if (_NextPos == 0)
        {
            for (int i = 0; i < k; i++)
            {
                result[i] = arr[i];
            }
            return result;
        }
        int r = _NextPos;
        int l = r - 1;
        while (r - l < k - 1)
        {
            if (r == arr.size() - 1)
            {
                l--;
            }
            else if (l == 0)
            {
                r++;
            }
            else
            {
                if (arr[r] - x > x - arr[l])
                {
                    l--;
                }
                else r++;
            }
        }
        for (int i = l, j = 0; i <= r; i++, j++)
        {
            result[j] = arr[i];
        }
        return result;
    }
    /*struct Point {
        Point(int _y, int _x):y(_y),x(_x){}
        int y;
        int x;
    };*/
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    result++;
                    stack<Point> st;
                    Point p(i, j);
                    st.push(p);
                    while (!st.empty())
                    {
                        auto temp = st.top();
                        st.pop();
                        grid[temp.y][temp.x] = 0;

                        if (temp.x != grid[temp.y].size() - 1 && grid[temp.y][temp.x + 1] == '1')//right
                        {
                            st.push({ temp.y,temp.x + 1 });
                        }
                        if (temp.x != 0 && grid[temp.y][temp.x - 1] == '1')//left
                        {
                            st.push({ temp.y,temp.x - 1 });
                        }
                        if (temp.y != 0 && grid[temp.y - 1][temp.x] == '1')//up
                        {
                            st.push({ temp.y - 1,temp.x });
                        }
                        if (temp.y != grid.size() - 1 && grid[temp.y + 1][temp.x] == '1')//down
                        {
                            st.push({ temp.y + 1,temp.x });
                        }
                    }
                }
            }
        }
        return result;
    }

    bool symetricLine(vector<vector<int>>& v)//{{0,-2},{1,-2},{3,1},{-2,1}};
    {
        const int inf = 1 << 30;
        int minX = inf, maxX = -inf;
        set<pair<int, int>> st;
        for (auto i : v)
        {
            minX = min(minX, i[0]);
            maxX = max(maxX, i[0]);
            st.insert({ i[0],i[1] });
        }
        for (auto i : v)
        {
            if (!st.count({ minX+ maxX-i[0],i[1] }))return false;
        }
        return true;

    }

    vector<int> shortestToChar(string s, char c) {
        vector<int> positions;
        vector<int> result;
        result.resize(s.length());
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == c)
            {
                positions.push_back(i);
            }
        }
        int prevInd = 0;
        int nextInd = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (i == positions[nextInd])
            {
                if (nextInd != positions[positions.size() - 1])
                {
                    prevInd = nextInd;
                    nextInd++;
                }
            }
            result[i] = min(abs(positions[prevInd] - i), abs(positions[nextInd] - i));
        }

        return result;

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int val = image[sr][sc];
        queue<vector<int>> q;//{y,x}
        q.push({ sr,sc });
        while (!q.empty())
        {
            auto temp = q.front();
            q.pop();
            image[temp[0]][temp[1]] = color;
            if (temp[0] != 0 && image[temp[0] - 1][temp[1]] == val)//верхнмй
            {
                q.push({ temp[0] - 1,temp[1] });
            }
            if (temp[0] != image.size() - 1 && image[temp[0] + 1][temp[1]] == val)//нижний
            {
                q.push({ temp[0] + 1,temp[1] });
            }
            if (temp[1] != 0 && image[temp[0]][temp[1] - 1] == val)//левый
            {
                q.push({ temp[0],temp[1] - 1 });
            }
            if (temp[1] != image[0].size() - 1 && image[temp[0]][temp[1] + 1] == val)//правый
            {
                q.push({ temp[0],temp[1] + 1 });
            }

        }
        return image;
    }
    bool oneDistanceApart(string s1, string s2)
    {
        if (s1.length() == s2.length())//replace  "annmj" 
        {                                       //"annmm"
            bool replased = false;
            for (int i = 0; i < s1.length(); i++)
            {
                if (s1[i] != s2[i])
                {
                    if (replased) { return false; }
                    else { replased = true; }
                }
            }
            return true;

        }
        else if (s1.length() == s2.length() - 1)//insert
        {
            bool inserted = false;
            for (int i = 0; i < s1.length(); i++)
            {
                if (s1[i] != s2[i])
                {
                    s1.insert(i,1, s2[i]);
                    if (s1 == s2) { return true; }
                    else return false;
                }
            }
        }
        else if (s1.length() == s2.length() + 1)//delete
        {
            for (int i = 0; i < s1.length(); i++)
            {
                if (s1[i] != s2[i])
                {
                    s1.erase(i, 1);
                    if (s1 == s2) { return true; }
                    else return false;
                }
            }
        }
        else return false;
    }
    int flipZero(vector<int> v)
    {
        int result = 0;
        int currOnes = 0;
        for (int i = 0; i <= v.size(); i++)
        {
            if (i== v.size() || v[i] == 0)
            {
                result = max(result, currOnes); currOnes = 0;
            }
            else currOnes++;
        }
        if (result < v.size()) { result++; }
        if (result == 0) { return 1; }
        for (int i = 1; i < v.size()-1; i++)
        {
            if (v[i] == 0 && v[i - 1] == 1 && v[i + 1] == 1)
            {
                int count = 0;
                int r = i + 1;
                while (r != v.size() && v[r] != 0)
                {
                    count++;
                    r++;
                }
                int l = i - 1;
                while (l != -1 && v[l] != 0)
                {
                    count++;
                    l--;
                }
                result = max(result, count+1);
            }
        }
        return result;
    }
    string H4(string str)
    {
        string result = "";
        if (str.size() <= 1)return str;
        int groupStart = 0;
        for (int i = 1; i <= str.size(); i++)
        {
            if (i == str.size() || str[i] != str[groupStart])
            {

                if (i - groupStart == 1)
                {
                    result += str[groupStart];
                }
                else
                {
                    result += str[groupStart];
                    result += to_string(i - groupStart);
                }
                groupStart = i;
            }
        }
        return result;
    }
    string H5(vector<int>& v)
    {
        string result = "";
        int start = 0;
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] != v[i - 1] + 1)
            {
                string temp = "";
                if (start == i - 1)
                {
                    temp += to_string(v[start]);
                    temp += ",";
                }
                else
                {
                    temp += to_string(v[start]);
                    temp += "->";
                    temp += to_string(v[i-1]);
                    temp += ",";
                }
                result += temp;
                start = i;
            }
        }
        string temp = "";
        if (start == v.size() - 1)
        {
            temp += to_string(v[start]);
        }
        else
        {
            temp += to_string(v[start]);
            temp += "->";
            temp += to_string(v[v.size() - 1]);
        }
        result += temp;
        return result;
    }
    vector<int> sq(vector<int>& v)
    {
        vector<int> v1;
        v1.resize(v.size());
        int left = 0; 
        int right = v.size();
        int pos = right;
        while (right>=left)
        {
            if ((v[right] * v[right]) > (v[left] * v[left]))
            {
                v1[pos] = v[right] * v[right];
                right--;
            }
            else
            {
                v1[pos] = v[left] * v[left];
                left++;
            }
            pos--;
        }
        return v1;
    }
    void palindromString(string str)//jk lk j
    {
        int left = 0;
        int right = str.size() - 1;
        while (right > left)
        {
            if (str[left] == ' ')
            {
                left++;
                continue;
            }

            if (str[right] == ' ')
            {
                right--;
                continue;
            }

            if (str[right]!= str[left])
            {
                cout << "not palindrome" << endl;
                return;
            }
            else
            {
                right--;
                left++;
            }
        }
        cout << "is palindrome" << endl;
    }
    int longestSubarray(vector<int>& nums) {
        int maxOnes = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                int curr = 0;
                while (i != nums.size() && nums[i] != 0)
                {
                    curr++;
                    i++;
                }
                maxOnes = max(maxOnes, curr);
            }
        }
        if (maxOnes == nums.size())return maxOnes - 1;
        int maxAftDel = 0;
        for (int i = 1; i < nums.size() - 1; i++)
        {
            if (nums[i] == 0 && nums[i + 1] == 1 && nums[i - 1] == 1)
            {
                int j = i - 1;
                while (j != -1 && nums[j] != 0)
                {
                    cout << j << " ";
                    maxAftDel++;
                    j--;
                }
                cout << endl;
                j = i + 1;
                while (j != nums.size() && nums[j] != 0)
                {
                    cout << j << " ";
                    maxAftDel++;
                    j++;
                }
            }
        }
        cout << "maxAftDel" << maxAftDel << endl;
        return max(maxAftDel, maxOnes + 1);
    }
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.empty())return result;
        if (nums.size() == 1) { result.push_back(to_string(nums[0])); return result;}
        int start = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1] + 1)
            {
                string temp;
                if (start != i - 1)
                {
                    temp = to_string(nums[start]) + "->" + to_string(nums[i - 1]);
                    result.push_back(temp);
                }
                else
                {
                    result.push_back(to_string(nums[start]));
                }
                start = i;
            }

            
        }
        if (start != nums.size() - 1)
        {
            string temp = to_string(nums[start]) + "->" + to_string(nums[nums.size() - 1]);
            result.push_back(temp);
        }
        else
        {
            result.push_back(to_string(nums[start]));
        }
        return result;
    }

    int compresss(vector<char>& chars)
    {
        if (chars.size() == 1)return 1;
        int start = 0;
        int pos = 0;
        for (int i = 1; i <= chars.size(); i++)
        {
            if (i == chars.size() || chars[i] != chars[i - 1])
            {
                int len = i - start;
                start = i;
                char symb = chars[i - 1];
                chars[pos] == symb;
                pos++;

                string temp = to_string(len);
                for (auto j : temp)
                {
                    chars[pos] = j;
                    pos++;
                }

            }
        }
        return pos;
    }
    bool checkInclusion(string s1, string s2)
    {
        unordered_map<char, int> mp1, mp2;
        for (auto i : s1)
        {
            mp1[i]++;
        }
        int size = s1.length();
        int left = 0;
        int right = left + size - 1;
        for (int i = left; i <= right; i++)
        {
            mp2[s2[i]]++;
        }
        if (mp1 == mp2)return true;
        left++;
        right++;
        cout << "mp1:" << endl;

        for (auto i : mp1)
        {
            cout << i.first << " " << i.second << endl;
        }
        cout << endl;
        cout << "mp2:" << endl;
        for (auto i : mp2)
        {
            cout << i.first << " " << i.second << endl;
        }
        cout << endl;

        while (right < s2.size())
        {
            if (mp2[s2[left - 1]]!=1)
            {
                mp2[s2[left - 1]]--;
            }
            else
            {
                mp2.erase(s2[left - 1]);
            }
            mp2[s2[right]]++;
            if (mp1 == mp2)return true;
            right++;
            left++;

            for (auto i : mp2)
            {
                cout << i.first << " " << i.second << endl;
            }
            cout << endl;
        }
        return false;
    }
    vector<int> findAnagramss(string s, string p)
    {
        vector<int> result;
        if (s.length() < p.length())return result;
        unordered_map<char, int> smp;
        unordered_map<char, int> pmp;
        for (auto i : p)
        {
            pmp[i]++;
        }
        for (int i = 0; i < p.length(); i++)
        {
            smp[s[i]]++;
        }

        if (smp == pmp) { result.push_back(0); }
        int next = p.length();
        while (next != s.length())
        {
            smp[s[next]]++;
            if (smp[s[next - p.length()]] == 1)
            {
                smp.erase(s[next - p.length()]);
            }
            else
            {
                smp[s[next - p.length()]]--;
            }
            next++;
            if (smp == pmp)
            {
                result.push_back(next - p.length());
            }

        }
        return result;
    }
    bool symetricLine2(vector<vector<int>>& v)//{{0,-2},{1,-2},{3,1},{-2,1}};
    {
        const int inf = 1 << 30;
        int minX = inf, maxX = -inf;
        set<pair<int, int>> st;
        for (auto i : v)
        {
            minX = min(minX, i[0]);
            maxX = max(maxX, i[0]);
            st.insert({ i[0],i[1] });
        }
        for (auto i : v)
        {
            if (!st.count({ minX + maxX - i[0],i[1] }))return false;
        }
        return true;
        
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
            if (it == res.end()) res.push_back(nums[i]);
            else *it = nums[i];
        }
        return res.size();
    }
    int maxDistToClosest(vector<int>& seats) {
        int firTaken, lastTaken;
        for (int i = 0; i < seats.size(); i++)
        {
            if (seats[i] == 1)
            {
                firTaken = i;
                break;
            }
        }
        for (int i = seats.size() - 1; i != -1; i--)
        {
            if (seats[i] == 1)
            {
                lastTaken = i;
                break;
            }
        }
        int betw = 0;
        for (int i = firTaken; i <= lastTaken; i++)
        {
            if (seats[i] == 0)
            {
                int temp = 0;
                while (seats[i] != 1)
                {
                    temp++;
                    i++;
                }
                betw = max(betw, temp);
            }
        }
        cout << "betw " << betw << endl;
        cout << "firTaken " << firTaken << endl;
        cout << "lastTaken " << lastTaken << endl;
        if (betw % 2 == 0) {
            betw /= 2;
        }
        else
        {
            betw /= 2;
            betw++;
        }
        return max(betw, max(firTaken, lastTaken));
    }

    int longestSubarray1(vector<int>& nums) {
        int maxCons = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                int temp = 0;
                while (i!= nums.size() && nums[i] == 1)
                {
                    temp++;
                    i++;
                }
                maxCons = max(maxCons, temp);
            }
        }
        int maxAftDel = 0;

        for (int i = 1; i < nums.size() - 1; i++)
        {
            if (nums[i] == 0 && nums[i + 1] == 1 && nums[i - 1] == 1)
            {
                int count = 0;
                int right = i + 1;
                while (right != nums.size() && nums[right] != 0)
                {
                    right++;
                    count++;
                }
                int left = i - 1;
                while (left != -1 && nums[left] != 0)
                {
                    left--;
                    count++;
                }
                maxAftDel = max(maxAftDel, count);
            }
        }
        if (maxCons == nums.size())return maxCons - 1;
        return max(maxCons, maxAftDel);
    }

    void T2(vector<int>& nums)
    {
        int zeroes = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                zeroes++;
            }
            else
            {
                nums[i - zeroes] = nums[i];
            }
        }
        for (int i = nums.size() - zeroes; i < nums.size(); i++)
        {
            nums[i] = 0;
        }
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result = { 0,0 };
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = mp.find(target - nums[i]);
            if (it != mp.end())
            {
                cout << "log";
                result[0] = mp.find(target - nums[i])->second;
                result[1] = i;
                return result;
            }
            mp[nums[i]] = i;
        }
        for (auto i : mp)
        {
            cout << i.first << " " << i.second << endl;
        }
        return result;
    }
    int T1(string str, int k)
    {
        if (k == 0 || str.length() == 0)return 0;
        if (str.length() <= k)return str.length();
        unordered_map<char, int> mp;
        for (int i = 0; i < str.length(); i++)
        {

        }
    }

    int T3(vector<int> nums)
    {
        int maxConsOnes = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                int temp = 0;
                while (i != nums.size() && nums[i] == 1)
                {
                    i++;
                    temp++;
                }
                maxConsOnes = max(maxConsOnes, temp);
            }
        }
        if (maxConsOnes == nums.size())return maxConsOnes - 1;
        if (maxConsOnes == 0)return 0;

        int maxOnesAfterDelZero = 0;
        for (int i = 1; i < nums.size()-1; i++)
        {
            if (nums[i] == 0 && nums[i + 1] == 1 && nums[i - 1] == 1)
            {
                int temp = 0;
                int left = i - 1;
                int right = i + 1;
                while (left != -1 && nums[left] == 1)
                {
                    temp++;
                    left--;
                }
                while (right != nums.size() && nums[right] == 1)
                {
                    temp++;
                    right++;
                }
                maxOnesAfterDelZero = max(maxOnesAfterDelZero, temp);
            }
        }
        return max(maxOnesAfterDelZero, maxConsOnes);

    }
    vector<int> findkClosestElements(vector<int>& A, int k, int x)
    {
        if (k > A.size())return {};
        if (k == A.size())return A;

        int targetSum = x * k;
        int sum = 0;
        int left = 0;

        for (int i = 0; i < k; i++)
        {
            sum += A[i];
        }
        
        int dev = abs(sum - targetSum);

        for (int i = k; i < A.size(); i++)
        {
            sum += A[i];
            sum -= A[i] - k;
            if (abs(sum - targetSum) < dev)
            {
                dev = abs(sum - targetSum);
                left = i - k + 1;
            }
        }

        return std::vector<int>(A.begin() + left, A.begin() + left + k);
    }
    vector<int> C1(vector<int> v1, vector<int> v2)
    {
        vector<int> result;
        unordered_map<int, int> mp;

        for (auto i : v1)
        {
            mp[i]++;
        }
        for (auto i : v2)
        {
            if (mp.find(i) != mp.end())
            {
                if (mp[i] != 0)
                {
                    mp[i]--;
                    result.push_back(i);
                }
            }
        }
        return result;
    }
    string C2(string str)
    {
        string result = "";
        int startPos = 0;
        for (int i = 1; i < str.length(); i++)
        {
            if (str[i] != str[i - 1])
            {
                result += str[startPos];
                result += to_string(i - startPos);
                startPos = i;
            }
        }
        return result;
    }
    int guestsNum(vector<vector<int>> v)
    {
        map<int, pair<int, int>> mp;
        for (int i = 0; i < v.size(); i++)
        {
            int dayComing = v[i][0];
            int dayLeft = v[i][1];

            if (mp.find(dayComing) == mp.end())
            {
                mp[dayComing] = { 1,0 };
            }
            else
            {
                mp[dayComing].first += 1;
            }

            if (mp.find(dayLeft) == mp.end())
            {
                mp[dayLeft] = { 0,1 };
            }
            else
            {
                mp[dayLeft].second += 1;
            }
        }
        int result = 0;
        int guests = 0;
        for (auto i : mp)
        {
            guests -= i.second.second;
            guests += i.second.first;
            result = max(result, guests);
        }
        return result;
    }

    vector<vector<int>> merge(vector < vector<int>> v)
    {
        vector < vector<int>> result;
        std::sort(v.begin(), v.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0]; });

        int start = v[0][0];
        int finish = v[0][1];

        for (int i = 1; i < v.size(); i++)
        {
            if (v[i][0] > finish + 1)
            {
                result.push_back({ start,finish });
                start = v[i][0];
                finish = v[i][1];
            }
            else
            {
                finish = max(finish, v[i][1]);
            }
        }
        result.push_back({ start,finish });
        return result;
    }

    bool line(vector<vector<int>> v)//{{0,-2},{1,-2},{3,1},{-2,1}};
    {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        set<pair<int, int>> st;
        for (auto i : v)
        {
            mini = min(mini, i[0]);
            maxi = max(maxi, i[0]);
            st.insert({ i[0],i[1] });
        }
        for (auto i : v)
        {
            if (!st.count({maxi+mini-i[0],i[1]}))return false;
        }
        return true;
    }


    bool twoString(string str1, string str2)
    {
        if (str1.length() == str2.length())
        {
            int unrepCount = 0;
            for (int i = 0; i < str1.length(); i++)
            {
                if (str1[i] != str2[i])
                {
                    unrepCount++;
                }
            }
            if (unrepCount <= 1)return true;
        }
        else if (str1.length() - str2.length() == 1)
        {
            for (int i = 0; i < str1.length(); i++)
            {
                if (str1[i] != str2[i])
                {
                    int j = i + 1;
                    while (i != str2.length())
                    {
                        if (str1[j] != str2[i])
                        {
                            return false;
                        }
                        j++;
                        i++;
                    }

                }
            }
            
            return true;
        }
        return false;
    }


    vector<pair<int, int>> mergeRanges(vector<pair<int, int>> input)
    {
        vector<pair<int, int>> result;
        if (input.size() == 1)return input;
        std::sort(input.begin(), input.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first; });
        int first = input[0].first;
        int last = input[1].second;
        for (int i = 1; i < input.size(); i++)
        {
            if (input[i].first <= last)
            {
                last = max(input[i].second, last);
            }
            else
            {
                result.push_back({ first, last });
                first = input[i].first;
                last = input[i].second;
            }
            
        }
        result.push_back({ first, last });
        return result;

    }
    int ksubstr(string s, int k)
    {
        int result = 0;
        unordered_map<char, int> mp;
        int start = 0;
        for (int i = 0; i < s.length(); i++)
        {
            mp[s[i]]++;
            if (mp.size() > k)
            {
                result = max(result, i - start);
                while (mp.size() > k)
                {
                    if (mp[s[start]] == 1)
                    {
                        mp.erase(s[start]);
                    }
                    else
                    {
                        mp[s[start]]--;
                    }
                    start++;
                }
            }
        }
        result = max(result, int(s.length() - start));
            return result;
    }

    vector<int> intersect(vector<int> v1, vector<int> v2)
    {
        vector<int> result;
        unordered_map<int, int>mp;
        for (auto i : v1)
        {
            mp[i]++;
        }
        for (auto i : v2)
        {
            if (mp.find(i) != mp.end())
            {
                if (mp[i] != 0)
                {
                    result.push_back(i);
                    mp[i]--;
                }
            }
        }
        return result;
    }
    string merge(vector<int> v)
    {
        string result = "";
        sort(v.begin(), v.end());
        int start = 0;
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] != v[i - 1] + 1)
            {
                if (i - 1 == start)
                {
                    result += to_string(v[start])+",";
                }
                else
                {
                    result += to_string(v[start]) + "-" + to_string(v[i - 1])+",";
                }
                start = i;
            }
        }
        if (v.size() - 1 == start)
        {
            result += to_string(v[start]);
        }
        else
        {
            result += to_string(v[start]) + "-" + to_string(v[v.size() - 1]);
        }
        return result;
    }


    vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals)
    {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) 
            {
            return a[0] < b[0];
            });
        int start = intervals[0][0];
        int finish = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= finish)
            {
                finish = max(finish, intervals[i][1]);
            }
            else
            {
                result.push_back({ start,finish });
                start = intervals[i][0];
                finish = intervals[i][1];
            }
        }
        result.push_back({ start,finish });
        return result;
    }
    vector<int> moveZe(vector<int> v)
    {
        int pos = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] != 0)
            {
                int temp = v[i];
                v[i] = 0;
                v[pos] = temp;
                pos++;
            }
        }
        return v;
    }

    int consOnes(vector<int> v)
    {
        int maxCons = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == 1)
            {
                int temp = 0;
                while (i != v.size() && v[i] != 0)
                {
                    temp++;
                    i++;
                }
                maxCons = max(maxCons, temp);
            }
        }
        if (maxCons == v.size())return maxCons - 1;
        if (maxCons == 0)return 0;

        int maxAftDel = 0;
        for (int i = 1; i < v.size() - 1; i++)
        {
            if (v[i] == 0 && v[i - 1] == 1 && v[i + 1] == 1)
            {
                int temp = 0;
                int left = i - 1;
                int right = i + 1;
                while (right != v.size() && v[right] != 0)
                {
                    temp++;
                    right++;
                }

                while (left != -1 && v[left] != 0)
                {
                    temp++;
                    left--;
                }
                maxAftDel = max(maxAftDel, temp);
            }
        }

        return max(maxAftDel, maxCons);
    }

    vector<int> kClosest(vector<int> v, int index, int k)
    {
        vector<int> result = { v[index] };
        k--;
        if (k == v.size())return v;
        if (k > v.size())return {};

        if (index == 0)
        {
            result.insert(result.begin(), v.begin(), v.begin() + k);
            return result;
        }

        if (index == v.size() - 1)
        {
            result.insert(result.begin(), v.end() - k, v.end());
            return result;
        }
       
        int left = index - 1;
        int right = index + 1;
            while (k > 0)
            {


                if (left == -1)
                {
                    result.push_back(v[right]);
                    right++;
                    k--;
                }
                else if (right == v.size())
                {
                    result.push_back(v[left]);
                    left--;
                    k--;
                }
                else
                {
                    if (abs(v[index] - v[right]) > abs(v[index] - v[left]))
                    {
                        result.push_back(v[left]);
                        left--;
                        k--;
                    }
                    else
                    {
                        result.push_back(v[right]);
                        right++;
                        k--;
                    }
                }
            }
        return result;
    }
    void blinking(vector<int>& leds, int row)
    {
        for (int i = 0; i < row; i++)
        {
            leds[i] = 1;
        }
        int l = leds.size() - 1;
        int r = row - 1;

        while (1)
        {
            for (auto i : leds)
            {
                cout << i << " ";
            }
            cout << endl;
            this_thread::sleep_for(std::chrono::milliseconds(1000));



            l++;
            r++;
            if (l == leds.size())
            {
                l = 0;
            }
            if (r == leds.size())
            {
                r = 0;
            }
            leds[r] = 1;
            leds[l] = 0;


        }
    }


    struct Point {
        Point(int _y, int _x) :y(_y), x(_x) {}
        int y;
        int x;
    };
    int vostray(vector<vector<int>> &ocean)
    {
        int result = 0;
        for (int i = 0; i < ocean.size(); i++)
        {
            for (int j = 0; j < ocean[i].size(); j++)
            {
                if (ocean[i][j] == 1)
                {
                    int tempRes = 0;
                    stack<Point> st;
                    Point point(i,j);
                    ocean[point.y][point.x] = 0;
                    st.push(point);
                    while (!st.empty())
                    {
                        tempRes++;
                        Point temp = st.top();
                        st.pop();
                        if (temp.x != ocean[i].size() - 1 && ocean[temp.y][temp.x+1] == 1)//right
                        {
                            st.push({temp.y,temp.x+1});
                            ocean[temp.y][temp.x+1] = 0;
                        }
                        if (temp.x != 0 && ocean[temp.y][temp.x - 1] == 1)//left
                        {
                            st.push({ temp.y,temp.x - 1 });
                            ocean[temp.y][temp.x-1] = 0;
                        }
                        if (temp.y != 0 && ocean[temp.y-1][temp.x] == 1)//up
                        {
                            st.push({ temp.y-1,temp.x});
                            ocean[temp.y-1][temp.x] = 0;
                        }
                        if (temp.y != ocean.size()-1 && ocean[temp.y + 1][temp.x] == 1)//down
                        {
                            st.push({ temp.y + 1,temp.x });
                            ocean[temp.y+1][temp.x] = 0;
                        }
                    }
                    result = max(result, tempRes);

                }
            }
        }
        return result;
    }
    int maxGuests(vector<pair<int, int>> g)
    {
        map<int, pair<int, int>> mp;  
            for (int i = 0; i < g.size(); i++)
            {
                mp[g[i].first].first++;
                mp[g[i].second].second++;
            }
        int res = 0;
        int sum = 0;
        for (auto i : mp)
        {
            sum -= i.second.second;
            sum += i.second.first;
            res = max(res, sum);
        }
        return res;
    }
    vector<int> kCl(vector<int> v, int index, int k)
    {
        vector<int> result;
        result.resize(k);
        if (v.size() < k)return {};
        if (index == 0)
        {
            for (int i = 0; i < k; i++)
            {
                result[i] = v[i];
            }
            return result;
        }
        if (index == v.size() - 1)
        {
            int pos = 0;
            for (int i = v.size() - k; i < v.size(); i++)
            {
                result[pos] = v[i];
                pos++;
            }
            return result;
        }
        int r = index + 1;
        int l = index - 1;
        result[0] = v[index];
        int pos = 1;
        k--;
        while (k != 0)
        {
            if (r == v.size())
            {
                result[pos] = v[l];
                l--;
            }
            else if (l == -1)
            {
                result[pos] = v[r];
                r++;
            }
            else
            {
                if (abs(v[r] - v[index]) > abs(v[l] - v[index]))
                {
                    result[pos] = v[l];
                    l--;
                }
                else
                {
                    result[pos] = v[r];
                    r++;
                }
            }
            pos++;
            k--;
        }
        return result;
    }
    int maxSubstr(string s, int k)
    {
        int result = 0;
        unordered_map<char, int> mp;
        int start = 0;
        for (int i = 0; i < s.length(); i++)
        {
            mp[s[i]]++;
            if (mp.size() > k)
            {
                result = max(result, i - start);
                while (mp.size() > k)
                {
                    mp[s[start]]--;
                    if (mp[s[start]] == 0)
                    {
                        mp.erase(s[start]);
                    }
                    start++;
                }
            }
        }
        result = max(result, int(s.length() - start));
        return result;
    }
    int findLHS(vector<int> nums)
    {
        int result = 0;
        unordered_map<int, int> mp;

        for (int i = 0 ; i < nums.size(); i++)
        {
            mp[nums[i]]++;
            result = max(result, max(mp[i] + mp[i - 1], mp[i] + mp[i + 1]));
        }
        cout << mp.size() << endl;
       
        if (mp.size() == 1)return 0;
        return result;
    }
    std::optional<int> findBitInclusion(string big, string small)
    {
        int windSize = small.length();
        for (int i = 0; i < big.length()- windSize+1; i++)
        {
            string temp = big.substr(i, windSize);
                cout << temp << endl;
                if (temp == small)return i;
        }
        return std::nullopt;
    }
};

int main(int argc, char* argv[])
{
   /*vector<vector<int>> ocean =
    {
        {0,1,1,0,0,1,0,0,0,1},
        {0,0,0,0,0,1,1,0,0,0},
        {0,0,0,0,0,0,1,0,0,0},
        {0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,1,0,0,0},
        {0,0,0,0,0,0,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,1,1,0,0,0,0,0,0},
        {0,0,1,1,0,0,0,0,0,0},
        {0,0,1,1,1,0,0,0,0,0},
    };*/
    // 0 0 0
    // 0 0 0
    // 0 0 0
    Solution sol;
    auto res = sol.findBitInclusion("00110101", "0101");
    if (res.has_value()) {
        std::cout << "Inclusion on : " << res.value() <<" pos" << std::endl;
    }
    else {
        std::cout << "Nothing include" << std::endl;
    }
    vector<string> tokens = {
        "Ukfjs619rnuflcDaLKrjxvE01BUU0X4O",
        "bheLpmPEf3H4eoeZFf90ZyEAeKZPBfh9",
        "3m3sPlkOu7JtUktKmTlCi7C1CHPvH1OA",
        "DYtN5Aabw36VtCV3UBsajpHgu7EipYOw",
        "lr4up8X1UmjwAaiMv8PzXZtaipqkUlQq",
        "AyljT4ctOls9GtXKC6t9wPRP8NSMD6y0",
        "3DLGTbeh4SLLZ5VeiCOPZeUBTP3XbgEE4"
    };
    for (auto& token : tokens)
    {
        cout << token.length() << endl;
    }
    
    //cout << sol.findBitInclusion("10111011010001101111011110010", "1100100") << endl;
}