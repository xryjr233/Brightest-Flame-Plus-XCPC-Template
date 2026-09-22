#import "../template.typ": *
#show: styled

== 简单数据结构

=== 可删堆
#source("ds/简单数据结构/可删堆.cpp")

=== 哈希表

== 线段树

=== 线段树上二分
#desc 线段树的每个位置上存一个每次查询区间 $[l,r]$ 的连续前缀/后缀有多少个数 $<= x$。（注意如果查询 $>=$ 则应记录 `min`。）

#source("ds/线段树/线段树上二分.cpp")

=== 标记永久化

=== zkw 线段树

=== Segtree Beats!

=== 主席树

== 李超树

== 划分树

== 平衡树

=== 非旋 Treap

=== WBLT

== 树套树

== K-D Tree
#source("ds/动态KDT.cpp")

== Link Cut Tree
#source("ds/LCT.cpp")

== 全局平衡二叉树

== Top Tree

== 析合树

== 珂朵莉树

== 分块

== 莫队

#source("ds/莫队.cpp")

== $O(n)-O(1)$ RMQ

#source("ds/ono1rmq.cpp")