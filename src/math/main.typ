#import "../template.typ": *
#show: styled

== 数论
#include "number-theory.typ"

== 数论筛法

=== 杜教筛

=== Powerful Number 筛

=== Min_25 筛

== 群论
#desc $X$ 为有限集 $A$ 到 $B$ 的映射；$X/G$ 表示作用在 $X$ 上产生的等价类集合。$c(g)$ 表示置换 $g$ 能拆分成的不相交的循环置换的数量。

==== Burnside 引理
#h(1fr) $display(abs(X"/"G) = 1 / abs(G) sum_(g in G) abs(X^g))$ #h(1fr)

==== Polya 定理
#h(1fr) $display(abs(X"/"G) = 1 / abs(G) sum_(g in G) abs(B)^(c(g)))$ #h(1fr)

== 线性代数

== 博弈论

== 概率论

== 组合数学

== 多项式与生成函数
#source("math/polynom/多项式.cpp", namespace: "ModulusOperations")

=== 多项式乘法
#source("math/polynom/多项式.cpp", namespace: "polynom_mul")

=== 多项式求逆
#source("math/polynom/多项式.cpp", namespace: "polynom_inv")

=== 多项式 $ln$
#source("math/polynom/多项式.cpp", namespace: "polynom_ln")

=== 多项式 $exp$
#source("math/polynom/多项式.cpp", namespace: "polynom_exp")

=== 多项式多点求值
#source("math/polynom/多点求值.cpp")

=== 多项式快速插值
#source("math/polynom/快速插值.cpp")

=== NTT（add10k）
#source("math/polynom/多项式-wh.cpp", namespace: "polynom")

=== 分治 NTT（add10k）
#source("math/polynom/多项式-wh.cpp", namespace: "DC_NTT")

== 集合幂级数
#source("math/setpoly/base.cpp")

=== 子集卷积
#source("math/setpoly/conv.cpp")

=== 除法&求逆
#source("math/setpoly/convinv.cpp")

=== exp

组合意义是：设 $f_S$ 表示 $S$ 集合的权值，令 $g=exp f$，则 $g_S$ 表示对 $S$ 任意划分，每种划分方案的权值乘积之和。

#source("math/setpoly/exp.cpp")

=== ln
#source("math/setpoly/ln.cpp")

=== 边双连通-连通 变换

$t r a n s(f,c,g r a p h)$ 表示每一条割边使代价额外 $times c$ 的变换，$g r a p h$ 是以 0-index 状压形式存储的图。逆变换令 $c<- -c$ 即可。

例如 $f_S$ 为 $S$ 的边双连通子图数，$g_S$ 为 $S$ 的连通子图数，则 $g=t r a n s(f,1,g r a p h),f=t r a n s(g,-1,g r a p h)$。

#source("math/setpoly/trans.cpp")

== 杂项

=== 杨氏矩阵

=== 二次剩余
#source("math/cipolla.cpp")