#include <iostream>
// for GMP big integers beyond the range of long long replace the type with bigInteger
// #include <gmpxx.h> 
// using bigInteger =  mpz_class;
#include <vector>
using namespace std;
typedef long long ll;


struct Triple {
    ll d, x, y;
    Triple(ll D, ll X, ll Y) : d(D), x(X), y(Y) {}
    Triple() {}

    void display() {
        cout << "d, x, y: " << d << " " << x << " " << y << '\n';
    }
};

Triple extendedGCD(ll a, ll b) {
    Triple aux;
    if (b == 0)
        return Triple(a, 1, 0);
    else
        aux = extendedGCD(b, a % b);
    return Triple(aux.d, aux.y, aux.x - (a / b) * aux.y);
}

ll inverse(ll a, ll n) {
    Triple egcd = extendedGCD(a, n);
    if (egcd.d != 1)
        return -1; // no inverse exists in this ring
    return (egcd.x % n + n) % n; 
}

ll crt(vector<ll>& a, vector<ll>& n, int k) {
    ll N = 1;
    for (int i = 0; i < k; ++i) {
        N *= n[i];
    }
    vector<ll> b(k);
    for (int i = 0; i < k; ++i) {
        ll aux = N / n[i];
        b[i] = inverse(aux, n[i]);
    }
    vector<ll> y(k);
    for (int i = 0; i < k; ++i) {
        ll aux = N / n[i];
        y[i] = b[i] * aux;
    }
    ll result = 0;
    for (int i = 0; i < k; ++i) {
        result += a[i] * y[i];
    }
    return result % N;
}

int main() {
    int k;
    cin >> k;

    vector<ll> a(k), n(k);
    for (int i = 0; i < k; ++i) {
        // filling the remainders array
        cin >> a[i];
    }

    for (int i = 0; i < k; ++i) {
        // filling the moduli array
        cin >> n[i];
    }

    ll result = crt(a, n, k) << endl;
    cout << "result: " << result << endl;

    return 0;
}
