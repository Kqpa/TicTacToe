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
  
## Build
  
</div>

It's possible to build this program by using Visual Studio. Open the [`.sln`](https://github.com/Kqpa/TicTacToe/blob/master/TicTacToe.sln) file and run the program. If you're using a different version of Visual Studio, go to `Project > Properties > Platform Toolest` & set the version to 2022. If you don't have Visual Studio installed, you can still build the program by using [`g++`](https://gcc.gnu.org/). You'll have to change `system("cls")` to `system("clear)` on lines [`13`](https://github.com/Kqpa/TicTacToe/blob/master/TicTacToe/Source.cpp#L13) & [`100`](https://github.com/Kqpa/TicTacToe/blob/master/TicTacToe/Source.cpp#L100) before running the commands below.

```sh
git clone https://github.com/Kqpa/TicTacToe
cd ./TicTacToe/TicTacToe/
g++ Source.cpp -o TicTacToe && ./TicTacToe # Compiles & Executes TicTacToe
```
