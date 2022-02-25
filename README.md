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

It's possible to build this program using Visual Studio, open the [`TicTacToe.sln`](/TicTacToe.sln) file and run the program. If you're using a different version of Visual Studio, go to `Project > Properties > Platform Toolest` and set the version to 2022. 

If you don't have Visual Studio installed, you can build the program using [`g++`](https://gcc.gnu.org/). Run the commands below:

```sh
git clone https://github.com/Kqpa/TicTacToe

cd ./TicTacToe/TicTacToe/

# GNU implementation of sed — use this if you're on GNU/Linux
sed -i 's/system("cls")/system("clear")/g' Source.cpp

# BSD implementation of sed — use this if you're on macOS or BSD
sed -i '' -e 's/system("cls")/system("clear")/g' Source.cpp

g++ Source.cpp -o TicTacToe && ./TicTacToe
```
 
If you see something like [this](https://cdn.discordapp.com/attachments/711225037738213446/944892974012198932/unknown.png) when you launch the program, that means that your terminal doesn't support colors. Replace the color macros in [`Core.hpp`](/TicTacToe/Core.hpp) with the code block below: 

```cpp
#define RESET   ""  /* "\033[0m"  */	/* Reset Color */

#define RED     ""  /* "\033[31m" */	/* Red */

#define GREEN   ""  /* "\033[32m" */	/* Green */
```
