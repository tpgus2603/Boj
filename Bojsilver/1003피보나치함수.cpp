//#include<iostream>
//
//using namespace std;
//int one = 0;
//int zero = 0;
//int fibonacci(int n) {
//    if (n == 0) {
//        zero++;
//        return 0;
//    }
//    else if (n == 1) {
//        one++;
//        return 1;
//    }
//    else {
//        return fibonacci(n-1) + fibonacci(n-2);
//    }
//}
//
//int main()
//{
//    ios::sync_with_stdio(0); cin.tie(0);
//    int fibo[41][2];
//    fibo[0][1] = 0;
//    fibo[0][0] = 1;
//    fibo[1][0] = 0;
//    fibo[1][1] = 1;
//    fibo[2][0] = 1;
//    fibo[2][1] = 1;
//    int testn;
//    cin >> testn;
//    for (int i = 3; i <= 40; i++)
//    {
//        fibo[i][0] = fibo[i - 1][0] + fibo[i - 2][0];
//        fibo[i][1] = fibo[i - 1][1] + fibo[i - 2][1];
//    }
//    for (int i = 0; i < testn; i++)
//    {
//        int n;
//        cin >> n;
//        cout << fibo[n][0] << ' ' << fibo[n][1]<<'\n';
//    }
//
//
//
//}