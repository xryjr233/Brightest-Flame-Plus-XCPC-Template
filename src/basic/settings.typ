#import "../template.typ": *
#show: styled
#set heading(outlined: false)

=== 可以加的编译选项

- 检查越界和 UB：`-g -fsanitize=address,undefined`

=== Code Runner 设置

- 打开 `run in terminal`。

- 将快捷键 `code-runner.run` 设置为需要的。

- 设置 `code-runner.executorMap`：

```json
"cpp": "cd $dir && g++ -Wall -Wextra -Wconversion -Wshadow -O2 -std=c++17 -Dbfp $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt"
```

=== 编译运行脚本（linux 上没有 code runner 的时候用）

把下面代码放到 `~/.bashrc` 中（空格不能少）：

```bash
run() { f="${1%.cpp}"; shift; g++ -Wall -Wextra -Wconversion -Wshadow -O2 -std=c++17 -Dbfp  "$@" "$f.cpp" -o "$f" && "./$f"; }
```