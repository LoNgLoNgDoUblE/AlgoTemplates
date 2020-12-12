/**
 * Author: Mattias de Zalenski, Per Austrin, Lukas Polacek
 * Date: 2003-02-16
 * Description: Chinese Remainder Theorem.
 *
 * \texttt{chinese(a, m, b, n)} returns a number $x$, such that
 * $x\equiv a \pmod m$ and $x\equiv b \pmod n$. For not
 * coprime $n, m$, use \texttt{chinese\_common}. Note that all numbers must be less than
 * $2^{31}$ if you have Z = unsigned long long.
 * Status: Works
 * Time: $\log(m + n)$
 */

template<typename T> T chinese(T a, T m, T b, T n) {
	T x, y; extgcd(m, n, x, y);
	T ret = a * (y + m) % m * n + b * (x + n) % n * m;
	if (ret >= m * n) ret -= m * n;
	return ret;
}

template<typnemae T> T chinese_common(T a, T m, T b, T n) {
	T d = gcd(m, n);
	if (((b -= a) %= n) < 0) b += n;
	if (b % d) return -1; // No solution
	return d * chinese(Z(0), m/d, b/d, n/d) + a;
}
