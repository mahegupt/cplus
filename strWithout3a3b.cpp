#include<iostream>
using namespace std;


class StrWithout3A3B {
    public:
        string strWithout3a3b(int a, int b) {
            string result="";
            //3 cases to handle.
            while(a>0 || b>0)
            if (a>b) {
                if (a>2) {
                    result += "aa";
                    a -= 2;
                } else if (a>0) {
                    result += "a";
                    a -= 1;
                }
                if (b>0) {
                    result += "b";
                    b -= 1;
                }
            } else if (b>a) {
                if (b>2) {
                    result += "bb";
                    b -= 2;
                } else  if (b > 0) {
                    result += "b";
                    b -= 1;
                }
                if (a>0) {
                    result += "a";
                    a -= 1;
                }

            } else {
                if (a>0) {
                    result += "a";
                    a -= 1;
                }
                if (b>0) {
                    result += "b";
                    b -= 1;
                }            
            }
            return result;
        }
};

int main() {
    StrWithout3A3B S;
    cout << S.strWithout3a3b(3,3) << endl;
    cout << S.strWithout3a3b(13,3) << endl;
    cout << S.strWithout3a3b(3,8) << endl;
    return 0;
}