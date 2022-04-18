<div align="center">

# TicTacToe

```cpp
|     |
1  |  2  |  3
_____|_____|_____
|     |
4  |  5  |  6
_____|_____|_____
|     |
7  |  8  |  9
|     |
```

</div>

## Building

You need `g++` in order to build this project. If you're using a ***NIX** (Linux, macOS, etc..) OS, you can install it from your package manager. If you're using Windows, you'll need to install `MinGW`. If you don't have `git`, you can download & extract the repository instead.

***NIX**:
Open your terminal & run the following command block
```sh
git clone https://github.com/Kqpa/TicTacToe && \
cd ./TicTacToe/src && \
g++ Source.cpp -std=c++11 -o TicTacToe.out && \
./TicTacToe.out
```

**Windows**:
Open PowerShell & run the following command block
```powershell
git clone 'https://github.com/Kqpa/TicTacToe' `
; if ($?) { cd .\TicTacToe\src } `
; if ($?) { g++ Source.cpp -std=c++11 -o TicTacToe.exe } `
; if ($?) { .\TicTacToe.exe }
```

## Troubleshooting

* [**Colors failing to load**](https://cdn.discordapp.com/attachments/711225037738213446/944892974012198932/unknown.png)

This occurs when you're running the program on a terminal that doesn't support ANSI escape codes. You can fix this by replacing the color macros on [`./include/Macros.hpp`](./include/Macros.hpp) with the following code block:


```cpp
#define RESET   ""  /* "\033[0m"  */	/* Reset Color */
#define RED     ""  /* "\033[31m" */	/* Red */
#define GREEN   ""  /* "\033[32m" */	/* Green */
```
