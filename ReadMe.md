## 一.项目概述

本项目是一个基于 C++ 语言和 EasyX 图形库开发的俄罗斯方块游戏。游戏实现了俄罗斯方块的基本功能，包括方块的下落、左右移动、旋转，消除满行，计分，保存最高分等功能，并且具备多关卡难度。

## 二.项目结构

项目主要包含以下文件：

1. **Block.h**：定义了方块类`Block`的接口。
2. **Block.cpp**：实现了方块类`Block`的具体功能。
3. **Tetris.h**：定义了游戏类`Tetris`的接口。
4. **Tetris.cpp**：实现了游戏类`Tetris`的具体功能。
5. **main.cpp**：程序的入口文件，负责创建游戏对象并启动游戏。

## 三.类设计

### 1.Point结构体

```cpp
struct Point{
    int row;
    int col;
};
```

- 功能：表示二维平面上的一个点，用于描述方块的位置。
- 成员变量：
  -   row : 点所在的行。
  -   col : 点所在的列。

### 2.Block类

```cpp
class Block
{
public:
    Block();
    void drop();
    void moveLeftRight(int offset);
    void rotate();
    void draw(int leftMargin, int topMargin);
    static IMAGE** getImages();
    Block& operator=(const Block& other);
    bool blockInMap(const vector<vector<int>>& map);
    void solidify(vector<vector<int>>& map);
    int getBlockType();

private:
    int blockType;
    Point smallBlocks[4];
    IMAGE* img;
    static IMAGE* imgs[7];
    static int size;
};
```

- **功能**：表示游戏中的方块，负责方块的创建、移动、旋转、绘制等操作。
- 成员变量:
  - `blockType`：方块的类型。
  - `smallBlocks[4]`：方块的四个小方块的位置。
  - `img`：方块的图像。
  - `imgs[7]`：静态数组，存储所有类型方块的图像。
  - `size`：方块的大小。
- 成员函数:
  - `Block()`：构造函数，初始化方块的类型和位置。
  - `drop()`：方块下落。
  - `moveLeftRight(int offset)`：方块左右移动。
  - `rotate()`：方块旋转。
  - `draw(int leftMargin, int topMargin)`：绘制方块。
  - `getImages()`：获取所有类型方块的图像数组。
  - `operator=(const Block& other)`：赋值运算符重载。
  - `blockInMap(const vector<vector<int>>& map)`：判断方块是否在地图内。
  - `solidify(vector<vector<int>>& map)`：将方块固定到地图上。
  - `getBlockType()`：获取方块的类型

### 3.Tetris类

```cpp
class Tetris
{
public:
    Tetris(int rows, int cols, int left, int top, int blockSize);
    void init();
    void play();

private:
    void keyEvent();
    void updateWindow();
    int getDelay();
    void drop();
    void clearLine();
    void moveLeftRight(int offset);
    void rotate();
    void drawScore();
    void checkOver();
    void saveScore();
    void displayOver();

    int delay;
    bool update;
    vector<vector<int>> map;
    int rows;
    int cols;
    int leftMargin;
    int topMargin;
    int blockSize;
    IMAGE imgBg;
    Block* curBlock;
    Block* nextBlock;
    Block bakBlock;
    int score;
    int highestScore;
    int level;
    int lineCount;
    bool gameOver;
    IMAGE imgOver;
    IMAGE imgWin;
};
```

- **功能**：表示整个游戏，负责游戏的初始化、运行、处理用户输入、更新界面等操作。
- 成员变量：
  - `delay`：方块下落的延迟时间。
  - `update`：是否需要更新窗口。
  - `map`：游戏地图。
  - `rows`：地图的行数。
  - `cols`：地图的列数。
  - `leftMargin`：地图的左边界。
  - `topMargin`：地图的上边界。
  - `blockSize`：方块的大小。
  - `imgBg`：游戏背景图像。
  - `curBlock`：当前方块。
  - `nextBlock`：下一个方块。
  - `bakBlock`：备份方块。
  - `score`：当前得分。
  - `highestScore`：最高分。
  - `level`：当前关卡。
  - `lineCount`：当前消除的行数。
  - `gameOver`：游戏是否结束。
  - `imgOver`：游戏失败图像。
  - `imgWin`：游戏胜利图像。
- 成员函数：
  - `Tetris(int rows, int cols, int left, int top, int blockSize)`：构造函数，初始化游戏的基本参数。
  - `init()`：初始化游戏，包括加载图像、初始化地图、读取最高分等。
  - `play()`：开始游戏，进入游戏主循环。
  - `keyEvent()`：处理用户的键盘输入。
  - `updateWindow()`：更新游戏窗口，绘制地图、方块和得分等信息。
  - `getDelay()`：获取方块下落的延迟时间。
  - `drop()`：方块下落，处理方块固定和更新当前方块等操作。
  - `clearLine()`：消除满行，更新得分和关卡等信息。
  - `moveLeftRight(int offset)`：方块左右移动。
  - `rotate()`：方块旋转。
  - `drawScore()`：绘制得分、消除行数、当前关卡和最高分等信息。
  - `checkOver()`：检查游戏是否结束。
  - `saveScore()`：保存最高分。
  - `displayOver()`：显示游戏结束界面，根据结果显示胜利或失败图像。

## 四、游戏流程

1. **初始化**：在`Tetris`类的构造函数中初始化游戏的基本参数，如地图的行数、列数、边界等。在`init()`函数中进行更详细的初始化操作，包括加载图像、初始化地图、读取最高分等。
2. **开始游戏**：在`play()`函数中进入游戏主循环，不断处理用户的键盘输入，更新方块的位置，检查是否需要消除满行，更新得分和关卡等信息。
3. **用户输入处理**：在`keyEvent()`函数中处理用户的键盘输入，根据输入对方块进行移动、旋转或加速下落等操作。
4. **方块下落**：在`drop()`函数中处理方块的下落，当方块无法继续下落时，将其固定到地图上，并更新当前方块为下一个方块。
5. **消除满行**：在`clearLine()`函数中检查是否有满行，如果有则消除满行，更新得分和关卡等信息。
6. **游戏结束检查**：在`checkOver()`函数中检查游戏是否结束，如果当前方块无法放置在地图上，则游戏结束。
7. **保存最高分**：在`saveScore()`函数中保存当前得分，如果当前得分高于最高分，则更新最高分。
8. **显示游戏结束界面**：在`displayOver()`函数中根据游戏结果显示胜利或失败图像。

## 五、技术细节

### 1. 图形库

本项目使用了 EasyX 图形库，用于实现游戏的图形界面，包括绘制背景图像、方块和得分等信息。

### 2. 随机数生成

在`Block`类的构造函数中使用`rand()`函数生成随机数，用于随机选择方块的类型。

### 3. 文件操作

在`Tetris`类的`init()`函数中使用`ifstream`读取保存最高分的文件，在`saveScore()`函数中使用`ofstream`将最高分保存到文件中。

### 4. 音乐播放

使用`mciSendString`函数播放背景音乐和音效，如方块消除音效、游戏失败音效等。

## 六、注意事项

1. 项目依赖 EasyX 图形库，需要在编译环境中正确配置该库。
2. 项目中使用的图像和音频文件需要放在正确的路径下，否则会导致加载失败。
3. 项目中的最高分保存文件`recorder.txt`需要有读写权限。
