#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

vector<int> primeNumber(int n) {
    vector<int> prime;
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            prime.push_back(i);
        }
        for (int j = 0; j<prime.size() && i*prime[j]<=n; j++) {
            isPrime[i * prime[j]] = false;
            if (i % prime[j] == 0) {
                break;
            }
        }

    }
    return prime;
}

class BitMap {
private:
    vector<char> bits;
    int size;
public:
    BitMap(int size) {this->size = size; bits.resize((size + 7) >> 3);}
    void set(int pos) {bits[pos >> 3] |= (0x80 >> (pos & 0x07));}
    bool get(int pos) {return bits[pos >> 3] & (0x80 >> (pos & 0x07));}
    void clear(int pos) {bits[pos >> 3] &= ~(0x80 >> (pos & 0x07));}
};

vector<int> primeNumber2(int n, int& count) {
    vector<int> prime;
    BitMap isPrime(n + 1);
    for (int i = 0; i <= n; i++) {
        isPrime.set(i);
    }
    isPrime.clear(0);
    isPrime.clear(1);
    for (int i = 2; i <= n; i++) {
        if (isPrime.get(i)) {
            prime.push_back(i);
        }
        for (int j = 0; j < prime.size() && i * prime[j] <= n; j++) {
            isPrime.clear(i * prime[j]);
            count++;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
    return prime;
}



int main() {
    int n = 100000000;
    int count = 0;
    auto start = chrono::high_resolution_clock::now();
    vector<int> prime = primeNumber2(n, count);
    // for (int i = 0; i < prime.size(); i++) {
    //     cout << prime[i] << " ";
    // }
    cout << "n: " << n << endl;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration<double>(end - start);
    cout << "time: " << duration.count() << " seconds" << endl;
    cout << "count: " << count << endl;
    
    return 0;
}