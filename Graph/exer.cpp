#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'findSchedules' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER workHours
 *  2. INTEGER dayHours
 *  3. STRING pattern
 */

int dh;
int len;
int n;
vector<vector<int>> ans;
void findarr (int cnt,int sum,vector<int> & arr)
{
  if(cnt==len&&sum==n)
  {
    ans.push_back(arr);
    return;
  }
  for(int i=0;i<9;i++)
  {
    arr.push_back(i);
    findarr(cnt+1,sum+i,arr);
    arr.pop_back();
  }
}


vector<string> findSchedules(int workHours, int dayHours, string pattern) {
  
  vector<string> sol;
  int sum=0;
  map<int,int> idx;
  int idxsize=0;
  for(int i=0;i<pattern.length();i++)
  {
    if(pattern[i]=='?')
    {
      idx[i]++;
      idxsize++;
      continue;
    }
    sum+=(pattern[i]-'0');
  }
  len=7-idxsize;
  n =workHours-sum; //구해야하는 시간합 
  dh=dayHours;
  vector<int> arr;
  cout<<len<<' '<<n<<'\n';
  findarr(0,0 ,arr);
  for(auto temp : ans)
  {
    string str;
    int k=0;
    for(int i=0;i<pattern.length();i++)
    {
      if(idx[i]>0)
        str+=temp[k++]+'0';
      else
        str+=pattern[i];
    }
    sol.push_back(str);
  }
  return sol;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string workHours_temp;
    getline(cin, workHours_temp);

    int workHours = stoi(ltrim(rtrim(workHours_temp)));

    string dayHours_temp;
    getline(cin, dayHours_temp);

    int dayHours = stoi(ltrim(rtrim(dayHours_temp)));

    string pattern;
    getline(cin, pattern);

    vector<string> result = findSchedules(workHours, dayHours, pattern);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
