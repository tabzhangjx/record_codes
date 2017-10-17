//mouse.c - 主程序文件
#include <windows.h>
#include <stdio.h>

int main(int argc, char** argv)
{
	DWORD dwMode, dwOldMode;    /* 原来的模式与新模式 */
	DWORD dwRead;    /* 已经读取的输入事件数 */
	int mouse_pos; /* 用于返回鼠标位置 */
	UINT count;        /* 用于循环控制 */
	INPUT_RECORD ir[128];    /* 控制台输入记录 */
	CONSOLE_CURSOR_INFO cci, cciOld;    /* 鼠标相关的设置 */
	COORD co;    /* 鼠标移动时更新坐标 */
	HANDLE hStdIn = NULL, hStdOut = NULL; /* 标准输入输出句柄  */

	if (argc == 2 && argv[1][0] == '/' && argv[1][1] == '\?')
	{
		printf("控制台鼠标支持程序\n\n"
			"使用方法:\n"
			"\t/\?\t查看帮助\n\n"
			"返回值处理:\n"
			"\t%%ERRORLEVEL%% 高 16 位包含鼠标 X 坐标\n"
			"\t%%ERRORLEVEL%% 低 16 位包含鼠标 Y 坐标\n"
			"比如:返回 65537, 可以用如下方式取得 X,Y\n"
			"\tset /a ret=%%errorlevel%%\n"
			"\tset /a \"x=%%ret%%>>16\"\n"
			"\tset /a \"y=%%ret%%&65535\"\n\n"
			"女孩不哭,QQ:191035066 @ 批处理之家\n");
		return 0;
	}

	hStdIn = GetStdHandle(STD_INPUT_HANDLE);    /* 取得输入输出句柄 */
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	if (!GetConsoleMode(hStdIn, &dwOldMode))    /* 取得控制台原来的模式 */
	{
		fprintf(stderr, "GetConsoleMode 错误:%d\n", GetLastError());
		goto _exit;
	}
	dwMode = dwOldMode | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(hStdIn, dwMode))    /* 开启鼠标事件 */
	{
		fprintf(stderr, "SetConsoleMode 错误:%d\n", GetLastError());
		goto _exit;
	}

	GetConsoleCursorInfo(hStdOut, &cciOld);
	cci.bVisible = TRUE;    /* 可见 */
	cci.dwSize = 100;        /* 块状 */
	if (!SetConsoleCursorInfo(hStdOut, &cci))
	{
		fprintf(stderr, "SetConsoleCursorInfo 错误:%d\n", GetLastError());
		goto _exit;
	}

	for (;;)    /* 循环等待用户事件 */
	{
		if (!ReadConsoleInput(hStdIn, &ir[0], 128, &dwRead))
		{
			fprintf(stderr, "ReadConsoleInput 错误:%d\n", GetLastError());
			goto _exit;
		}
		for (count = 0; count<dwRead; count++)
		{
			switch (ir[count].EventType)
			{
			case MOUSE_EVENT:
				switch (ir[count].Event.MouseEvent.dwEventFlags)
				{
				case 0:    /* 取得鼠标单击事件 */
					if (ir[count].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
					{
						SetConsoleMode(hStdIn, dwOldMode);    /* 还原原来的设置 */
						SetConsoleCursorInfo(hStdOut, &cciOld);
						mouse_pos = ir[count].Event.MouseEvent.dwMousePosition.X;
						mouse_pos = mouse_pos << 16 | ir[count].Event.MouseEvent.dwMousePosition.Y;
						return mouse_pos;
					}
					break;
				case MOUSE_MOVED:    /* 更新鼠标位置 */
					co.X = ir[count].Event.MouseEvent.dwMousePosition.X;
					co.Y = ir[count].Event.MouseEvent.dwMousePosition.Y;
					SetConsoleCursorPosition(hStdOut, co);
					break;
				}
				break;
			default:
				break;
			}
		}
	}
_exit:
	return 1;
}


//::test_mouse.bat - 脚本程序
//@echo off
//	:main
//	mouse.exe
//	set / a "ret=%errorlevel%,x=ret>>16,y=ret&65535"
//	title 鼠标演示程序, 鼠标坐标 = (%x%, %y%)
//	goto : main
