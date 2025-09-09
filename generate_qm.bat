@echo off
setlocal

REM 设置Qt路径
set QT_PATH=D:\Qt\Qt5.15.17\5.15.17\msvc2015_64\bin
set LRELEASE=%QT_PATH%\lrelease.exe

REM 检查lrelease工具是否存在
if not exist "%LRELEASE%" (
    echo 错误: 找不到lrelease工具: %LRELEASE%
    echo 请检查Qt路径是否正确
    pause
    exit /b 1
)

REM 检查translations目录是否存在
if not exist "translations" (
    echo 错误: 找不到translations目录
    pause
    exit /b 1
)

REM 检查ts文件是否存在
if not exist "translations\zh_CN.ts" (
    echo 错误: 找不到translations\zh_CN.ts文件
    echo 请先运行generate_ts.bat生成ts文件
    pause
    exit /b 1
)

echo 正在使用Qt Linguist工具将ts文件编译为qm文件...

REM 使用lrelease工具将ts文件编译为qm文件
"%LRELEASE%" translations\zh_CN.ts -qm translations\zh_CN.qm

if %ERRORLEVEL% EQU 0 (
    echo 成功生成qm文件: translations\zh_CN.qm
) else (
    echo 生成qm文件时出错
    pause
    exit /b 1
)

echo.
echo 脚本执行完成
pause