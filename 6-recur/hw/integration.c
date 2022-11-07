#include <math.h>
#include <stdio.h>

double integration(double a, double b, double error);
double cal(double x);
double simpson(double a, double b);

int coefficients[21] = {};
int p, n;

int main() {
  double a, b;
  double error = 1e-4;
  scanf("%d%d", &n, &p);
  for (int i = 0; i < n + 1; i++) {
    scanf("%d", &coefficients[i]);
  }
  scanf("%lf%lf", &a, &b);
  printf("%lf", integration(a, b, error));
  return 0;
}

double integration(double a, double b, double error) {
  // if (fabs(A) <= error) {
  //   return SL + SR + A;
  // } else {
  //   return integration(a, mid, p, error / 2, coefficients) +
  //          integration(mid, b, p, error / 2, coefficients);
  // }
  // while (fabs((simpson(a, a / 2 + b / 2) + simpson(b / 2 + a / 2, b) -
  //              simpson(a, b))) > error) {
  //
  // }
  double mid = (a + b) / 2;
  double S = simpson(a, b);
  double SL = simpson(a, mid);
  double SR = simpson(mid, b);
  if (fabs(SL + SR - S) <= error) {
    return SL + SR + (SL + SR - S) / 15;
  } else {
    return integration(a, mid, error / 2) + integration(mid, b, error / 2);
  }
}

double cal(double x) {
  double ans = 0;
  for (int i = 0; i <= n; i++) {
    ans += pow(x, i) * coefficients[i];
  }
  ans = pow(ans, p);
  return ans;
}

double simpson(double a, double b) {
  double ans;
  double A = 4 * cal((a + b) / 2);
  double B = cal(a);
  double C = cal(b);
  ans = (A + B + C) / 6 * (b - a);
  return ans;
}
