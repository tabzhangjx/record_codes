//mouse.c - �������ļ�
#include <windows.h>
#include <stdio.h>

int main(int argc, char** argv)
{
	DWORD dwMode, dwOldMode;    /* ԭ����ģʽ����ģʽ */
	DWORD dwRead;    /* �Ѿ���ȡ�������¼��� */
	int mouse_pos; /* ���ڷ������λ�� */
	UINT count;        /* ����ѭ������ */
	INPUT_RECORD ir[128];    /* ����̨�����¼ */
	CONSOLE_CURSOR_INFO cci, cciOld;    /* �����ص����� */
	COORD co;    /* ����ƶ�ʱ�������� */
	HANDLE hStdIn = NULL, hStdOut = NULL; /* ��׼����������  */

	if (argc == 2 && argv[1][0] == '/' && argv[1][1] == '\?')
	{
		printf("����̨���֧�ֳ���\n\n"
			"ʹ�÷���:\n"
			"\t/\?\t�鿴����\n\n"
			"����ֵ����:\n"
			"\t%%ERRORLEVEL%% �� 16 λ������� X ����\n"
			"\t%%ERRORLEVEL%% �� 16 λ������� Y ����\n"
			"����:���� 65537, ���������·�ʽȡ�� X,Y\n"
			"\tset /a ret=%%errorlevel%%\n"
			"\tset /a \"x=%%ret%%>>16\"\n"
			"\tset /a \"y=%%ret%%&65535\"\n\n"
			"Ů������,QQ:191035066 @ ������֮��\n");
		return 0;
	}

	hStdIn = GetStdHandle(STD_INPUT_HANDLE);    /* ȡ������������ */
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	if (!GetConsoleMode(hStdIn, &dwOldMode))    /* ȡ�ÿ���̨ԭ����ģʽ */
	{
		fprintf(stderr, "GetConsoleMode ����:%d\n", GetLastError());
		goto _exit;
	}
	dwMode = dwOldMode | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(hStdIn, dwMode))    /* ��������¼� */
	{
		fprintf(stderr, "SetConsoleMode ����:%d\n", GetLastError());
		goto _exit;
	}

	GetConsoleCursorInfo(hStdOut, &cciOld);
	cci.bVisible = TRUE;    /* �ɼ� */
	cci.dwSize = 100;        /* ��״ */
	if (!SetConsoleCursorInfo(hStdOut, &cci))
	{
		fprintf(stderr, "SetConsoleCursorInfo ����:%d\n", GetLastError());
		goto _exit;
	}

	for (;;)    /* ѭ���ȴ��û��¼� */
	{
		if (!ReadConsoleInput(hStdIn, &ir[0], 128, &dwRead))
		{
			fprintf(stderr, "ReadConsoleInput ����:%d\n", GetLastError());
			goto _exit;
		}
		for (count = 0; count<dwRead; count++)
		{
			switch (ir[count].EventType)
			{
			case MOUSE_EVENT:
				switch (ir[count].Event.MouseEvent.dwEventFlags)
				{
				case 0:    /* ȡ����굥���¼� */
					if (ir[count].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
					{
						SetConsoleMode(hStdIn, dwOldMode);    /* ��ԭԭ�������� */
						SetConsoleCursorInfo(hStdOut, &cciOld);
						mouse_pos = ir[count].Event.MouseEvent.dwMousePosition.X;
						mouse_pos = mouse_pos << 16 | ir[count].Event.MouseEvent.dwMousePosition.Y;
						return mouse_pos;
					}
					break;
				case MOUSE_MOVED:    /* �������λ�� */
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


//::test_mouse.bat - �ű�����
//@echo off
//	:main
//	mouse.exe
//	set / a "ret=%errorlevel%,x=ret>>16,y=ret&65535"
//	title �����ʾ����, ������� = (%x%, %y%)
//	goto : main
