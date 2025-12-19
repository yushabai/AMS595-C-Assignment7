#include <iostream>
#include <vector>
using namespace std;

/*
====================================================
1. Conditional Statements
Translate MATLAB switch-case into C++
====================================================
*/
void conditional_statement() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    switch (n) {
        case -1:
            cout << "negative one" << endl;
            break;
        case 0:
            cout << "zero" << endl;
            break;
        case 1:
            cout << "positive one" << endl;
            break;
        default:
            cout << "other value" << endl;
    }
}

/*
====================================================
2. Print a vector of integers
====================================================
*/
void print_vector(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

/*
====================================================
3. Fibonacci sequence (while loop)
Print all Fibonacci numbers not exceeding 4,000,000
====================================================
*/
void fibonacci() {
    int a = 1, b = 2;

    while (a <= 4000000) {
        cout << a << " ";
        int next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
}

/*
====================================================
4.1 Check if a number is prime
====================================================
*/
bool isprime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

void test_isprime() {
    cout << "isprime(2) = " << isprime(2) << endl;
    cout << "isprime(10) = " << isprime(10) << endl;
    cout << "isprime(17) = " << isprime(17) << endl;
}

/*
====================================================
4.2 Factorize (find all factors)
====================================================
*/
vector<int> factorize(int n) {
    vector<int> answer;

    for (int i = 1; i <= n; i++) {
        if (n % i == 0)
            answer.push_back(i);
    }
    return answer;
}

void test_factorize() {
    print_vector(factorize(2));
    print_vector(factorize(72));
    print_vector(factorize(196));
}

/*
====================================================
4.3 Prime Factorization
====================================================
*/
vector<int> prime_factorize(int n) {
    vector<int> answer;

    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            answer.push_back(i);
            n /= i;
        }
    }
    return answer;
}

void test_prime_factorize() {
    print_vector(prime_factorize(2));
    print_vector(prime_factorize(72));
    print_vector(prime_factorize(196));
}

/*
====================================================
5. Pascal's Triangle (Iteration, no combinatorics)
====================================================
*/
void pascal_triangle(int n) {
    vector<vector<int>> triangle;

    for (int i = 0; i < n; i++) {
        vector<int> row(i + 1, 1);

        for (int j = 1; j < i; j++) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }

        triangle.push_back(row);
    }

    for (auto row : triangle) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

/*
====================================================
Main Function
====================================================
*/
int main() {
    cout << "===== Conditional Statement =====" << endl;
    conditional_statement();

    cout << "\n===== Fibonacci Sequence =====" << endl;
    fibonacci();

    cout << "\n===== Test isprime =====" << endl;
    test_isprime();

    cout << "\n===== Test factorize =====" << endl;
    test_factorize();

    cout << "\n===== Test prime factorize =====" << endl;
    test_prime_factorize();

    cout << "\n===== Pascal Triangle (n = 6) =====" << endl;
    pascal_triangle(6);

    return 0;
}
