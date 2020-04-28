#include <iostream>
#include <vector>

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
    if (condition) {
        log("test succeed");
    } else {
        log("test fail", message);
    }
}

int
find(const string &s1, char s2) {
    // 返回 s2 在 s1 中的下标, 从 0 开始, 如果不存在则返回 -1
    size_t i = 0;
    int index = -1;
    while (i < s1.size()) {
        if (s2 == s1[i]) {
            index = i;
            break;
        }
        i = i + 1;
    }
    return index;
}

void
testFind() {
    ensure(find("hello", 'a') == -1, "find 1");
    ensure(find("hello", 'e') == 1, "find 2");
    ensure(find("hello", 'l') == 2, "find 3");
}

string
lowercase(const string &s) {
    // 这里是两个字符串, 包含了大写字母和小写字母
    // 用 const 修饰是因为它们并不会被修改
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // 初始化一个空字符串
    string result = "";
    size_t i = 0;
    while (i < s.size()) {
        // 注意, 这个 find 已经帮你实现了
        int index = find(upper, s[i]);
        // 字符串可以用加号拼接, 不明白可以 log 一下
        result += lower[index];
        i += 1;
    }
    return result;
}

void
testLowercase() {
    ensure(lowercase("HELLO") == "hello", "lowercase 1");
    ensure(lowercase("GUA") == "gua", "lowercase 2");
}

string
uppercase(const string &s) {
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string result = "";
    size_t i = 0;
    while (i < s.size()) {
        int index = find(lower, s[i]);
        result += upper[index];
        i += 1;
    }
    return result;
}

void
testUppercase() {
    ensure(uppercase("hello") == "HELLO", "uppercase 1");
    ensure(uppercase("gua") == "GUA", "uppercase 2");
}

string
lowercase1(const string &s) {
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string result = "";
    size_t i = 0;
    while (i < s.size()) {
        int index = find(upper, s[i]);
        if (index == -1) {
            result += s[i];
        } else {
            result += lower[index];
        }
        i += 1;
    }
    return result;
}

void
testLowercase1() {
    ensure(lowercase1("heLLo") == "hello", "lowercase1 1");
    ensure(lowercase1("gua") == "gua", "lowercase1 2");
    ensure(lowercase1("GW") == "gw", "lowercase1 3");
}

string
uppercase1(const string &s) {
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string result = "";
    size_t i = 0;
    while (i < s.size()) {
        int index = find(lower, s[i]);
        if (index == -1) {
            result += s[i];
        } else {
            result += upper[index];
        }
        i += 1;
    }
    return result;
}

void
testUppercase1() {
    ensure(uppercase1("helLo") == "HELLO", "uppercase1 1");
    ensure(uppercase1("gUA") == "GUA", "uppercase1 2");
}

string
encode1(const string &s) {
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    string result = "";
    size_t i = 0;
    while (i < s.size()) {
        int index = find(lower, s[i]);
        int n = index + 1;
        if (n < lower.size()) {
            result += lower[n];
        } else {
            result += lower[0];
        }
        i += 1;
    }
    // log(result);
    return result;
}

void
testEncode1() {
    ensure(encode1("afz") == "bga", "encode1 1");
    ensure(encode1("gw") == "hx", "encode1 2");
}

string
decode1(const string &s) {
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    string result = "";
    size_t i = 0;
    while (i < s.size()) {
        int index = find(lower, s[i]);
        int n = index - 1;
        if (n < 0) {
            result += "z";
        } else {
            result += lower[n];
        }
        i += 1;
    }
    // log(result);
    return result;
}

void
testDecode1() {
    ensure(decode1("bga") == "afz", "decode1 1");
    ensure(decode1("hx") == "gw", "decode1 2");
}

string
encode2(const string &s, int shift) {
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    string result = "";
    size_t i = 0;
    while (i < s.size()) {
        int index = find(lower, s[i]);
        int n = index + shift;
        if (n < lower.size()) {
            result += lower[n];
        } else {
            int m = n - 26;
            result += lower[m];
        }
        i += 1;
    }
    // log(result);
    return result;
}

void
testEncode2() {
    ensure(encode2("afz", 2) == "chb", "encode2 1");
    ensure(encode2("gw", 3) == "jz", "encode2 2");
}

string
decode2(const string &s, int shift) {
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    string result = "";
    size_t i = 0;
    while (i < s.size()) {
        int index = find(lower, s[i]);
        int n = index - shift;
        if (n < 0) {
            int m = n + 26;
            result += lower[m];
        } else {
            result += lower[n];
        }
        i += 1;
    }
    // log(result);
    return result;
}

void
testDecode2() {
    ensure(decode2("chb", 2) == "afz", "decode2 1");
    ensure(decode2("jz", 3) == "gw", "decode2 2");
}

string
encode3(const string &s, int shift) {
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    string result = "";
    size_t i = 0;
    while (i < s.size()) {
        int index = find(lower, s[i]);
        if (index == -1) {
            result += s[i];
        } else {
            int n = index + shift;
            if (n < lower.size()) {
                result += lower[n];
            } else {
                int m = n - 26;
                result += lower[m];
            }
        }
        i += 1;
    }
    // log(result);
    return result;
}

void
testEncode3() {
    ensure(encode3("a fz", 2) == "c hb", "encode3 1");
    ensure(encode3("g#w", 3) == "j#z", "encode3 2");
}

string
decode3(const string &s, int shift) {
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    string result = "";
    size_t i = 0;
    while (i < s.size()) {
        int index = find(lower, s[i]);
        if (index == -1) {
            result += s[i];
        } else {
            int n = index - shift;
            if (n < 0) {
                int m = n + 26;
                result += lower[m];
            } else {
                result += lower[n];
            }
        }
        i += 1;
    }
    // log(result);
    return result;
}

void
testDecode3() {
    ensure(decode3("ch#b", 2) == "af#z", "decode3 1");
    ensure(decode3("j z", 3) == "g w", "decode3 2");
}

void
decode4() {
    const string code = "VRPHWLPHV L ZDQW WR FKDW ZLWK BRX,EXW L KDYH QR UHDVRQ WR FKDW ZLWK BRX";
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    string lowercode = lowercase1(code);
    size_t i = 0;
    while(i < 26) {
        i += 1;
        string message = decode3(lowercode, i);
        log(message);
    }
}

void
test() {
    // testFind();
    // testLowercase();
    // testUppercase();
    // testLowercase1();
    // testUppercase1();
    // testEncode1();
    // testDecode1();
    // testEncode2();
    // testDecode2();
    // testEncode3();
    // testDecode3();
    decode4();
}

int main(int argc, const char *argv[])
{
   test();
   
   return 0;
}