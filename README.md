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

It's possible to build this program using Visual Studio, open the `TicTacToe.sln` file and run the program. If you're using a different version of Visual Studio, go to `Project > Properties > Platform Toolest` and set the version to 2022. 

If you don't have Visual Studio installed, you can build the program using [`g++`](https://gcc.gnu.org/). Run the commands below:

```sh
git clone https://github.com/Kqpa/TicTacToe

cd ./TicTacToe/TicTacToe/

# G++ uses system("clear") instead of system("cls")
sed 's/system("cls")/system("clear")/g' Source.cpp

g++ Source.cpp -o TicTacToe && ./TicTacToe
 ```
