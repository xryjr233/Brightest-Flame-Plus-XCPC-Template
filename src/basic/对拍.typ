#import "../template.typ": *
#show: styled
#set heading(outlined: false)

=== Linux

- 使用：`chmod +x duipai.sh && ./duipai.sh`

```bash
#!/bin/bash
g++ A-gen.cpp -o A-gen && g++ A.cpp -o A && g++ A-bf.cpp -o A-bf || exit 1

for i in {1..100}; do
    ./A-gen > A-data.in
    ./A < A-data.in > A-out.out
    ./A-bf < A-data.in > A-ans.out
    if diff -q A-out.out A-ans.out > /dev/null; then
        echo "correct $i"
    else
        echo "wrong $i"
        exit 0
    fi
done
```

=== Windows

```bat
@echo off
g++ A-gen.cpp -o A-gen.exe || exit /b 1
g++ A.cpp -o A.exe || exit /b 1
g++ A-bf.cpp -o A-bf.exe || exit /b 1

for /l %%i in (1,1,100) do (
    A-gen.exe > A-data.in
    A.exe < A-data.in > A-out.out
    A-bf.exe < A-data.in > A-ans.out
    fc A-out.out A-ans.out > nul
    if errorlevel 1 (
        echo wrong %%i
        exit /b
    ) else (
        echo correct %%i
    )
)
```