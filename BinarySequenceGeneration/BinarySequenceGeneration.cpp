#include <bits/stdc++.h>
using namespace std;

void generate_binary_sequences(int n, string sequence = "", int i = 0) {
    if (i == n) {
        cout << sequence << endl;
        return;
    }
    generate_binary_sequences(n, sequence + "0", i + 1);
    generate_binary_sequences(n, sequence + "1", i + 1);
}

int main() {
    int n;
    cin >> n;
    generate_binary_sequences(n);
    return 0;
}
