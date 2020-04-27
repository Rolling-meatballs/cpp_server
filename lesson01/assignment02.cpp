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

float
sum(vector<float> &array) {
    // Seting a s to store array sum
    float s = 0;
    // The return value of .size() is size_t
    // so the i is size_t (same as int)
    size_t i = 0;
    // array.size() give a measurement of vector
    while (i < array.size()) {
        float n = array[i];
        s = s + n;
        i = i + 1;
    }
    return s;
}

void
ensure(bool condition, const string &message) {
    if (condition) {
        log("test succeed");
    } else {
        log(message);
    }
}

bool
floatEqual(float a, float b) {
    auto delta = 0.00001;
    return a - b < delta && b - a < delta;
}

void
testSum(void) {
    vector<float> v1 = {1, 2, 3, 4};
    float s1 = sum(v1);
    ensure(floatEqual(s1, 10), "sum test error 1");
    vector<float> v2 = {1, 2, 3, 4, 5, 6};
    float s2 = sum(v2);
    ensure(floatEqual(s2, 21), "sum test error 2");
}

float
product(vector<float> &array) {
    float s = 1;
    size_t i = 0;
    while (i < array.size()) {
        float n = array[i];
        s = s * n;
        // log(s);
        i = i + 1;
    }
    return s;
}

void
testProduct(void) {
    vector<float> v1 = {1, 2, 3, 4};
    float s1 = product(v1);
    ensure(floatEqual(s1, 24), "sum test error 3");
    vector<float> v2 = {1, 2, 3, 4, 5, 6};
    float s2 = product(v2);
    ensure(floatEqual(s2, 720), "sum test error 4");
}

float
abs1(float n) {
    if (n < 0) {
        n = - n;
    }
    return n;
}

void
testabs1(void) {
    //float v1 = -5;
    float s1 = abs1(-5);
    ensure(floatEqual(s1, 5), "sum test error 5");
    float v2 = 10;
    float s2 = abs1(v2);
    ensure(floatEqual(s2, 10), "sum test error 6");
}

float
average(vector<float> &array) {
    float s = sum(array);
    float n = array.size();
    float aver = s / n;
    return aver;
}

void
testAverage(void) {
    vector<float> v1 = {1, 2, 3, 4, 5};
    float s1 = average(v1);
    ensure(floatEqual(s1, 3), "sum test error 3");
    vector<float> v2 = {1, 2, 3, 4, 5, 6, 7};
    float s2 = average(v2);
    ensure(floatEqual(s2, 4), "sum test error 4");
}

float
min1(vector<float> &array) {
    float min = array[0];
    size_t i = 1;
    while(i < array.size()) {
        float n = array[i];
        if(n < min) {
            min = n;
        }
        i = i + 1;
    }
    return min;
}

void
testMin1(void) {
    vector<float> v1 = {6, 3, 8, 4, 5};
    float s1 = min1(v1);
    ensure(floatEqual(s1, 3), "sum test error 3");
    vector<float> v2 = {1, 2, 3, 4, 5, 6, 7};
    float s2 = min1(v2);
    ensure(floatEqual(s2, 1), "sum test error 4");
}

int
sum1(int n) {
    int s = 0;
    size_t i = 1;
    while (i < n + 1) {
        if (i % 2 == 0) {
            s = s - i;
        } else {
            s = s + i;
        }
        i = i + 1;
    }
    // log(s);
    return s;
}

void
testSum1(void) {
    float s1 = sum1(5);
    ensure(floatEqual(s1, 3), "sum test error 3");
    float s2 = sum1(7);
    ensure(floatEqual(s2, 4), "sum test error 4");
}

int
sum2(int n) {
    int s = 1;
    size_t i = 2;
    while (i < n + 1) {
        if (i % 2 == 0) {
            s = s + i;
        } else {
            s = s - i;
        }
        i = i + 1;
        // log(s);
    }
    return s;
}

void
testSum2(void) {
    float s1 = sum2(5);
    ensure(floatEqual(s1, -1), "sum test error 3");
    float s2 = sum2(8);
    ensure(floatEqual(s2, 6), "sum test error 4");
}

int
fac1(int n) {
    int s = 1;
    size_t i = 1;
    while (i < n + 1) {
        s = s * i;
        i = i + 1;
        // log(s);
    }
    return s;
}

void
testFac1(void) {
    float s1 = fac1(5);
    ensure(floatEqual(s1, 120), "sum test error 3");
    float s2 = fac1(8);
    ensure(floatEqual(s2, 40320), "sum test error 4");
}

void
test() {
    //testSum();
    //testProduct();
    // testabs1();
    // testAverage();
    // testMin1();
    // testSum1();
    // testSum2();
    testFac1();
}

int main(int argc, const char *argv[])
{
   test();
   
   return 0;
}