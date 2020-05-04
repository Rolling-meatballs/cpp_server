#include <vector>
#include <iostream>
#include <string>

using namespace std;


template<class T>
void
_print(T arg) {
    cout << arg << " ";
}

template<class... Args>
void
log(Args... args) {
    int arr[] = { (_print(args), 0)... };
    cout << endl;
}

void
ensure(bool condition, const string &message) {
    // 在条件不成立的时候, 输出 message
    if (not condition) {
        log("*** 测试失败: ", message);
    } else {
        log("||| 测试成功");
    }
}

string nChar(int n) {
    char fillchar = '0';
    string r = "";
    int i = 0;
    while(i < n) {
        r += fillchar;
        i += 1;
    }
    return r;
}

string
zfill(int n, int width) {
    string n_str = to_string(n);
    int n_amount = string(n_str).length();
    int replenish = width - n_amount;
    string zero_str = nChar(replenish);
    string end_str = zero_str + n_str;
    return end_str;
}

void
testZfill() {
    ensure(zfill(1, 4) == "0001", "zfill 测试 1");
    ensure(zfill(23, 4) == "0023", "zfill 测试 2");
    ensure(zfill(12345, 4) == "12345", "zfill 测试 3");
    ensure(zfill(169, 5) == "00169", "zfill 测试 4");
}

string nChar_2(int n, char &fillchar) {
    string r = "";
    int i = 0;
    while(i < n) {
        r += fillchar;
        i += 1;
    }
    return r;
}

string
rjust(const string &s, int width, char fillchar=' ') {
    int n_amount = string(s).length();
    int replenish = width - n_amount;
    string end_str = " "
    if (replenish > 0) {
        string rep_str = nChar_2(replenish, fillchar);
        end_str = rep_str + s;
    } else {
        end_str = s;
    }
    return end_str;
}

void
testRjust() {
    ensure(rjust("gua", 5) == "  gua", "rjust 测试 1");
    ensure(rjust("guagua", 5) == "guagua", "rjust 测试 2");
    ensure(rjust("gua", 5, '*') == "**gua", "rjust 测试 3");
}

void
test() {
    // testZfill();
    testRjust();
    // testLjust();
    // 剩下的测试函数调用需要你自行补足
}

int
main(int argc, const char *argv[]) {
    test();

    return 0;
}
