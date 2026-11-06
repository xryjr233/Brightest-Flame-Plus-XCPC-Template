#import "../template.typ": *
#show: styled

=== 拓展欧拉定理
$
  a^b = cases(
      a^(b mod phi(m))\, &gcd(a, m) = 1\,,
      a^b\, &gcd(a, m) != 1\, b < phi(m)\,,
      a^(b mod phi(m) + phi(m))\, space &gcd(a, m) != -1\, b >= phi(m) \.,
    )
  space (mod m)
$

=== 扩展欧几里得
得到的解满足 $-b<x<b,-a<y<=a$。

#source("math/number-theory/exgcd.cpp");

=== 扩展中国剩余定理
#source("math/number-theory/excrt.cpp");

=== 二次剩余
#source("math/number-theory/二次剩余.cpp")

=== 原根（无）

=== 离散对数

$O(P^(3/4))-O(log P)$

#source("math/number-theory/dlog.cpp")

=== 连分数（无）

=== 数论分块
#usage 可以 $O(1)$ 计算 $sum_(i=l)^r f(i)$，则可以 $O(sqrt(n))$ 计算 $sum_(i=1)^n f(i) g(floor(n/i))$。

#caution 注意一些 $i=0$ 的情况。

#source("math/number-theory/数论分块.cpp")

=== 类欧几里得
$sum_(i=0)^n floor((a i+b)/c)$

#source("math/number-theory/类欧几里得.cpp")

=== 万能欧几里得
#source("math/number-theory/万能欧几里得.cpp")

=== 杜教筛（无）

=== Powerful Number 筛（无）

=== Min_25 筛

求积性函数 $f(i)$ 的前缀和，要求 $f(i)$ 在质数处的值为多个完全积性函数的和，且在质数幂处的值可求。

$
  sum_(i=1)^(n)f(i)=F_(1)(n)+1
$

$
  F_(k)(n)=P(k,n)+sum_(k=i)^(p_(i)^2<=n)sum_(c=1)^(p_(i)^(c+1)<=n) f(p_(i)^c)F_(i+1)(floor(n/(p_(i)^c)))+f(p_(i)^(c+1))
$

$
  P(k,n)=F_(\p\r\i\m\e)(n)-F_(\p\r\i\m\e)(p_(k-1))
$

#source("math/number-theory/min25.cpp")