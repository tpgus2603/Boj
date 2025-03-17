#include<bits/stdc++.h>

using namespace std;

// 절댓값 문자열 비교: 반환값이 1이면 a > b, 0이면 a == b, -1이면 a < b
int compareAbs(const string &a, const string &b) {
    if(a.size() > b.size()) return 1;
    if(a.size() < b.size()) return -1;
    if(a == b) return 0;
    return (a > b) ? 1 : -1;
}

// 두 절댓값 문자열 덧셈
string addAbs(const string &a, const string &b) {
    int i = a.size() - 1, j = b.size() - 1;
    int carry = 0;
    string result;
    while(i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if(i >= 0) sum += a[i--] - '0';
        if(j >= 0) sum += b[j--] - '0';
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
    }
    reverse(result.begin(), result.end());
    // 불필요한 0 제거
    size_t pos = result.find_first_not_of('0');
    if(pos != string::npos)
        return result.substr(pos);
    return "0";
}

// 두 절댓값 문자열 뺄셈: a >= b라는 가정하에 a - b 계산
string subtractAbs(const string &a, const string &b) {
    int i = a.size() - 1, j = b.size() - 1;
    int carry = 0;
    string result;
    while(i >= 0) {
        int diff = (a[i] - '0') - carry;
        if(j >= 0) diff -= (b[j] - '0');
        if(diff < 0) {
            diff += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        result.push_back(diff + '0');
        i--; j--;
    }
    reverse(result.begin(), result.end());
    // 앞에 붙은 불필요한 0 제거
    size_t pos = result.find_first_not_of('0');
    if(pos != string::npos)
        return result.substr(pos);
    return "0";
}

// 두 절댓값 문자열 곱셈
string multiplyAbs(const string &a, const string &b) {
    int n = a.size(), m = b.size();
    vector<int> result(n + m, 0);
    
    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            int prod = (a[i]-'0') * (b[j]-'0');
            int sum = result[i+j+1] + prod;
            result[i+j+1] = sum % 10;
            result[i+j] += sum / 10;
        }
    }
    
    string res;
    for(int num : result) {
        if(!(res.empty() && num == 0)) {
            res.push_back(num + '0');
        }
    }
    return res.empty() ? "0" : res;
}

// 부호 있는 덧셈: A와 B는 부호가 붙은 문자열 (ex. "-123", "456")
string addBig(const string &A, const string &B) {
    // 부호 및 절댓값 분리
    bool negA = (A[0] == '-');
    bool negB = (B[0] == '-');
    string a = negA ? A.substr(1) : A;
    string b = negB ? B.substr(1) : B;
    
    // 두 숫자의 부호가 같으면 절댓값 덧셈 후 부호 부여
    if(negA == negB) {
        string sum = addAbs(a, b);
        return (negA && sum != "0") ? "-" + sum : sum;
    } else {
        // 부호가 다르면, 큰 절댓값에서 작은 절댓값을 뺀다.
        int cmp = compareAbs(a, b);
        if(cmp == 0)
            return "0";
        if(cmp > 0) {
            string diff = subtractAbs(a, b);
            return negA ? "-" + diff : diff;
        } else {
            string diff = subtractAbs(b, a);
            return negB ? "-" + diff : diff;
        }
    }
}

// 부호 있는 뺄셈: A - B = A + (-B)
string subtractBig(const string &A, const string &B) {
    // B의 부호를 반대로 하여 덧셈 수행
    string negB = (B[0] == '-') ? B.substr(1) : "-" + B;
    return addBig(A, negB);
}

// 부호 있는 곱셈
string multiplyBig(const string &A, const string &B) {
    bool negA = (A[0] == '-');
    bool negB = (B[0] == '-');
    string a = negA ? A.substr(1) : A;
    string b = negB ? B.substr(1) : B;
    
    string prod = multiplyAbs(a, b);
    // 결과가 "0"이면 부호 제거
    if(prod == "0")
        return "0";
    // 두 부호가 다르면 결과는 음수
    if(negA ^ negB)
        return "-" + prod;
    else
        return prod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string A, B;
    cin>>A>>B;
    
    cout << addBig(A, B) << "\n";
    cout << subtractBig(A, B) << "\n";
    cout << multiplyBig(A, B) << "\n";
    
    return 0;
}
