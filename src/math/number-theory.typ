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

=== 原根

=== 离散对数

=== 连分数

=== 数论分块
#usage 可以 $O(1)$ 计算 $sum_(i=l)^r f(i)$，则可以 $O(sqrt(n))$ 计算 $sum_(i=1)^n f(i) g(floor(n/i))$。

#caution 注意一些 $i=0$ 的情况。

#source("math/number-theory/数论分块.cpp")

=== 类欧几里得
$sum_(i=0)^n floor((a i+b)/c)$

#source("math/number-theory/类欧几里得.cpp")

=== 万能欧几里得
#source("math/number-theory/万能欧几里得.cpp")