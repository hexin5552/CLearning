# 贪吃蛇小游戏（C语言 · Windows控制台版）
> 项目名称：Snake Game
> 开发环境：MinGW / GCC，Windows平台（依赖 `windows.h`、`conio.h`）
> 作者：Hexin
> 版本：v1.0

## 📖 项目简介
基于C语言开发的控制台贪吃蛇游戏，使用Windows控制台API实现光标定位绘图；支持WSAD方向控制、撞墙/撞自身判定、吃食物变长、分数统计、随分数提升加速、围墙边框等功能。
> ⚠️ 注意：本项目仅支持 **Windows系统**，Linux/Mac没有 `conio.h`、`windows.h` 相关接口，无法直接编译运行。

## 🧱 数据结构设计
### 1. 坐标结构体（单节蛇身体单元）
```c
struct BODY {
    int x;
    int y;
};
```
用来存储每一节蛇身、食物的平面坐标。

### 2. 蛇对象结构体
```c
struct SNACK {
    struct BODY body[WIDTH * HIGH];  // 蛇身数组，最大不超过地图格子总数
    int size;                        // 当前蛇的长度
};
```
- `body[]`：数组保存每一节身体的xy坐标
- `size`：蛇当前身体节数

### 3. 食物对象结构体
```c
struct FOOD {
    int x;
    int y;
};
```
保存食物在地图上的坐标。

### 全局变量说明
```c
int key_x, key_y;   // 移动方向增量：w/s/a/d 控制
int score = 0;      // 游戏得分
struct SNACK snake; // 蛇实例
struct FOOD food;   // 食物实例
```

## 📌 宏定义（地图尺寸）
```c
#define WIDTH 60    // 地图宽度（X方向格子数）
#define HIGH 20     // 地图高度（Y方向格子数）
```
> 地图四周会生成围墙，蛇的有效活动区域：`1 ≤ x ≤ WIDTH-2`，`1 ≤ y ≤ HIGH-2`

## 🧩 函数清单与功能说明
| 函数 | 功能描述 |
| ---- | ---- |
| `void initSnake(void)` | 初始化蛇：出生在地图中心，初始长度为2，蛇头向右 |
| `void initFood(void)` | 随机生成食物坐标，食物不会生成在围墙、蛇身上 |
| `void initWall(void)` | 绘制地图围墙，使用 `#` 作为围墙字符 |
| `void initUI(void)` | 画面渲染入口：先绘制围墙 → 绘制蛇 → 绘制食物，隐藏控制台光标 |
| `void playGame(void)` | 游戏主循环，处理输入、碰撞判定、蛇移动、速度控制 |

## 🎮 游戏核心控制流程
### 1. 方向控制规则
WSAD 控制移动方向，**禁止直接反向掉头（防止自杀）**
- `w`：向上，方向增量 `(0, -1)`
- `s`：向下，方向增量 `(0, +1)`
- `a`：向左，方向增量 `(-1, 0)`
- `d`：向右，方向增量 `(+1, 0)`

> 输入使用 `kbhit()` + `getch()`：非阻塞读取按键，按键不会在控制台回显。

### 2. 碰撞判定逻辑
#### （1）蛇头撞墙壁判定
围墙占用 `x=0`、`x=WIDTH-1`、`y=0`、`y=HIGH-1`
```c
// 合法条件，不满足则游戏结束
snake.body[0].x > 0 && snake.body[0].x < WIDTH - 1 &&
snake.body[0].y > 0 && snake.body[0].y < HIGH - 1
```

#### （2）蛇头撞击自身判定
遍历蛇身所有节点，判断蛇头坐标是否和任意一节身体重合：
```c
for (size_t i = 1; i < snake.size; i++)
{
    if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y)
    {
        // 撞到自己，游戏结束
        return;
    }
}
```

#### （3）蛇头吃到食物判定
当蛇头坐标与食物坐标一致：
1. 蛇身长度 `snake.size++`
2. 分数 `score += 1`
3. 重新生成新食物（避开墙体和蛇身）
4. 移动速度加快（Sleep休眠时间缩短）

### 3. 蛇移动逻辑（跟随算法）
从蛇尾向前遍历，**后一节身体坐标 = 前一节身体旧坐标**，最后单独更新蛇头坐标：
```c
for (size_t i = snake.size - 1; i > 0; i--)
{
    snake.body[i].x = snake.body[i - 1].x;
    snake.body[i].y = snake.body[i - 1].y;
}
// 更新蛇头
snake.body[0].x += key_x;
snake.body[0].y += key_y;
```
> 实现效果：蛇整体自动持续向前移动，按键只修改方向向量，不直接移动蛇。

## 🖼️ 图形渲染原理
Windows控制台API：`SetConsoleCursorPosition()`
- `COORD` 结构体：存放光标X、Y坐标
- 每次渲染前 `system("cls")` 清屏，重新绘制围墙、蛇、食物
- 蛇头字符：`@`，蛇身字符：`*`，食物字符：`$`，围墙字符：`#`
- 隐藏控制台闪烁光标，优化画面观感

## 📊 分数与加速机制
1. 初始分数：`score = 0`
2. 每吃掉1个食物，分数+1
3. 基础延时 `Sleep(350)`；分数越高，Sleep延时越小，蛇移动速度越快
4. 拓展预留：可增加分数排行榜文件读写功能（将分数保存到本地txt）

## 🛠️ 编译&运行教程
### 编译命令（MinGW gcc）
```bash
gcc main.c snake.c -o snake.exe
```
### 运行
```bash
./snake.exe
```
> 编译成功后，在Windows终端打开exe即可游玩。

## 📂 项目文件结构
```
Snake/
├── main.c       // 程序入口，main函数
├── snake.c      // 所有功能函数实现
├── snake.h      // 头文件：宏定义、结构体、extern声明、函数声明
└── README.md    // 项目说明文档（本文档）
```

## ✨ 功能清单
- ✅ 围墙地图边界
- ✅ WSAD方向控制，禁止反向掉头
- ✅ 撞墙、撞自身死亡判定
- ✅ 吃食物变长、加分
- ✅ 分数越高，速度越快
- ✅ 控制台光标定位绘图，无多余字符
- ✅ 隐藏控制台光标，优化视觉
- ⏳ 待拓展：本地分数排行榜读写（txt存储）

## 📝 已知限制 & 待优化点
1. 仅Windows平台可用，Linux/macOS缺少 `windows.h`、`conio.h`
2. `system("cls")` 全屏清屏会产生画面闪烁；进阶方案：局部光标覆盖绘制，不整体清屏
3. 排行榜功能仅预留设计，当前版本未实现文件读写
4. 没有游戏结束弹窗，碰撞后直接退出程序

## 📜 开源声明
本项目仅供C语言学习练习使用，自由修改、学习、二次分发。

---