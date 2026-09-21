#import "template.typ": *

#show: project.with(
  title: "Brightest Flame+'s Standard Library",
  authors: (
    "cmk666",
    "xryjr233",
    "ladicius",
  ),
  special_thanks: [
    Qingyu,
    Sulfox,
    fstqwq,
    Antileaf,
    memset0,
    add10k,
    and seniors from _Zhejiang University_.
  ],
  comment: [
    #v(0.5em)
    Update on 2026/6/21
  ],
)

= 基础
#include "basic/main.typ"

= 数据结构
#include "datastrure/main.typ"

= 树
#include "tree/main.typ"

= 图
#include "graph/main.typ"

= 数学
#include "math/main.typ"

= 字符串
#include "string/main.typ"

= 计算几何
#include "geometry/main.typ"

= 动态规划
#include "dp/main.typ"

= 杂项
#include "misc/main.typ"

= 标准库
#include "stl/main.typ"

= 附录
#include "appendix/main.typ"

#v(1fr)

\/\/ 测试高亮渲染

#source("_dev/test-len.cpp")
