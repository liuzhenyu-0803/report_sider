@echo off
setlocal

REM 设置Qt路径
set QT_PATH=D:\Qt\Qt5.15.17\5.15.17\msvc2015_64\bin
set LUPDATE=%QT_PATH%\lupdate.exe

REM 检查lupdate工具是否存在
if not exist "%LUPDATE%" (
    echo 错误: 找不到lupdate工具: %LUPDATE%
    echo 请检查Qt路径是否正确
    pause
    exit /b 1
)

REM 检查src目录是否存在
if not exist "src" (
    echo 错误: 找不到src目录
    pause
    exit /b 1
)

REM 创建translations目录（如果不存在）
if not exist "translations" (
    echo 创建translations目录...
    mkdir translations
)

echo 正在使用Qt Linguist工具为src目录下的代码生成ts文件...

REM 使用lupdate工具扫描src目录并生成ts文件
"%LUPDATE%" -recursive src -ts translations\zh_CN.ts

if %ERRORLEVEL% EQU 0 (
    echo 成功生成ts文件: translations\zh_CN.ts
) else (
    echo 生成ts文件时出错
    pause
    exit /b 1
)

echo.
echo 脚本执行完成
pause