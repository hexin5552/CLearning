# CLearning

《C Primer Plus》练习代码库

## 📘 项目简介

本仓库是我在学习经典教材 **《C Primer Plus》** 过程中编写的练习代码。目前进度为 **第 11 章**（字符串和字符串函数），后续会持续更新。所有代码均经过实际编译运行，确保可正常执行。

## 🛠️ 开发环境

- **IDE**：JetBrains CLion（因此仓库中包含 `.idea` 等 IDE 配置文件）
- **编译器**：MinGW / GCC（取决于平台）
- **操作系统**：Windows / Linux / macOS 均可

> ⚠️ 注意：由于未添加 `.gitignore`，IDE 的配置文件和编译中间文件被一并上传。建议 Fork 或克隆后自行添加 `.gitignore`，避免不必要的文件干扰。

## 📂 目录结构
```
CLearning/
├── 第1-10章/ # 各章节练习代码（按章组织）
├── 第11章/ # 当前学习章节
├── ysyx/ # “一生一芯”项目实践（番茄钟）
│ └── README.md # 该项目详细说明
└── README.md # 本文件
```
## 🍅 ysyx —— 番茄钟实践项目

`ysyx/` 目录是我参与 **“一生一芯”项目组** 的阶段性实践作品，实现了一个**命令行番茄钟计时器**。

- **功能**：遵循番茄工作法（25分钟工作 + 5分钟休息），可自定义时长。
- **平台要求**：**Linux** 环境下原生运行（依赖标准终端和信号处理）。
- **Windows 用户**：需安装兼容环境（如 MinGW + cmd 或 WSL），或使用 Cygwin 等模拟层。

具体使用方法和实现细节，请参阅 `ysyx/README.md`。

## 🚀 如何运行

1. 克隆本仓库：
   ```bash
   git clone https://github.com/hexin5552/CLearning.git
