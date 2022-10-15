#include <complex>
#include <vector>
#include <iostream>
using namespace std;
using cd_t = complex<long double>;

cd_t e_pow_2pi_i_by_m(int m)
{
    return cd_t(cos(2.0 * M_PI / m), sin(2.0 * M_PI / m));
}

int bitReverse(int x, int log2n)
{
    int n = 0;
    for (int i = 0; i < log2n; ++i)
    {
        n <<= 1;
        n |= (x & 1);
        x >>= 1;
    }
    return n;
}

vector<cd_t> fft(const vector<cd_t> &a)
{
    // code
    int n = a.size();

    if (n == 1) return a;

    cd_t wn = e_pow_2pi_i_by_m(n);
    cd_t w(1,0);

    vector<cd_t> a0, a1;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) a0.push_back(a[i]);
        else a1.push_back(a[i]);
    }

    vector<cd_t> y0 = fft(a0);
    vector<cd_t> y1 = fft(a1);

    vector<cd_t> y(n);
    cd_t yk, yk_plus_n_by_2, w_times_yk;
    for (int k = 0; k <= n / 2 - 1; ++k) {
        w_times_yk = w * y1[k];
        yk = y0[k] + w_times_yk;
        yk_plus_n_by_2 = y0[k] - w_times_yk;

        y[k] = yk;
        y[n / 2 + k] = yk_plus_n_by_2;
        w = w * wn;
    }
    return y;
}

int main()
{
    int N;
    cin >> N;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
    }

    vector<cd_t> complex_a;
    for (auto i : a)
    {
        complex_a.push_back(cd_t(i, 0));
    }

    vector<cd_t> ans = fft(complex_a);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << "\n";
}
