#import "../template.typ": *
#show: styled

== 代码模板

#source("basic/template.cpp")

#[
  #set heading(outlined: false)

  === 随机数
  #source("basic/random.hpp")

  === 手动开编译选项
  #source("basic/编译选项.hpp")

  === 读入优化
  #source("basic/读入优化.hpp")
]

== 准备配置

#include "settings.typ"

== 热身赛准备

- 测试 C++ 标准：C++17 `for (auto [x, y] : a)`；C++14 `[](auto x, auto y){}`；C++11 `auto`。
- 测试 submit 脚本能否正常使用，交错题目是否有提示。

== 对拍脚本

#include "对拍.typ"