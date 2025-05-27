#include <windows.h>
#include <wchar.h>

int num1;
char op;
int num2;
bool next = false;
int digitnumber = 0;
HWND hDisplay;
// 窗口过程函数（处理交互事件）
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
        case WM_CREATE:
        // 创建按钮控件（支持 Unicode）
        CreateWindowW(
            L"BUTTON",          // 预定义类名
            L"1",          // 按钮文本
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            10, 60, 30, 30,    // 位置和尺寸
            hwnd,               // 父窗口
            (HMENU)1,           // 控件ID
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);
            
            CreateWindowW(
            L"BUTTON",          // 预定义类名
            L"2",          // 按钮文本
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            50, 60, 30, 30,    // 位置和尺寸
            hwnd,               // 父窗口
            (HMENU)2,           // 控件ID
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);

             CreateWindowW(
            L"BUTTON",          // 预定义类名
            L"3",          // 按钮文本
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            90, 60, 30, 30,    // 位置和尺寸
            hwnd,               // 父窗口
            (HMENU)3,           // 控件ID
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);
             
            CreateWindowW(
            L"BUTTON",          // 预定义类名
            L"4",          // 按钮文本
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            10, 110, 30, 30,    // 位置和尺寸
            hwnd,               // 父窗口
            (HMENU)4,           // 控件ID
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);

            CreateWindowW(
            L"BUTTON",          // 预定义类名
            L"5",          // 按钮文本
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            50, 110, 30, 30,    // 位置和尺寸
            hwnd,               // 父窗口
            (HMENU)5,           // 控件ID
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);

            CreateWindowW(
            L"BUTTON",          // 预定义类名
            L"6",          // 按钮文本
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            90, 110, 30, 30,    // 位置和尺寸
            hwnd,               // 父窗口
            (HMENU)6,           // 控件ID
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);

            CreateWindowW(
            L"BUTTON",          // 预定义类名
            L"7",          // 按钮文本
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            10, 160, 30, 30,    // 位置和尺寸
            hwnd,               // 父窗口
            (HMENU)7,           // 控件ID
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);

            CreateWindowW(
            L"BUTTON",          // 预定义类名
            L"8",          // 按钮文本
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            50, 160, 30, 30,    // 位置和尺寸
            hwnd,               // 父窗口
            (HMENU)8,           // 控件ID
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);

            CreateWindowW(
            L"BUTTON",          // 预定义类名
            L"9",          // 按钮文本
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            90, 160, 30, 30,    // 位置和尺寸
            hwnd,               // 父窗口
            (HMENU)9,           // 控件ID
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);

            CreateWindowW(
            L"BUTTON",          // 预定义类名
            L"0",          // 按钮文本
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            50, 210, 30, 30,    // 位置和尺寸
            hwnd,               // 父窗口
            (HMENU)0,           // 控件ID
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);

            CreateWindowW(
            L"BUTTON",          // 预定义类名
            L"+",          // 按钮文本
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            130, 60, 30, 30,    // 位置和尺寸
            hwnd,               // 父窗口
            (HMENU)10,           // 控件ID
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);

            CreateWindowW(
            L"BUTTON",          // 预定义类名
            L"-",          // 按钮文本
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            130, 110, 30, 30,    // 位置和尺寸
            hwnd,               // 父窗口
            (HMENU)11,           // 控件ID
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);
            
            CreateWindowW(
            L"BUTTON",          // 预定义类名
            L"*",          // 按钮文本
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            130, 160, 30, 30,    // 位置和尺寸
            hwnd,               // 父窗口
            (HMENU)12,           // 控件ID
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);

            CreateWindowW(
            L"BUTTON",          // 预定义类名
            L"/",          // 按钮文本
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            130, 210, 30, 30,    // 位置和尺寸
            hwnd,               // 父窗口
            (HMENU)13,           // 控件ID
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);

            CreateWindowW(
            L"BUTTON",          // 预定义类名
            L"=",          // 按钮文本
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            90, 210, 30, 30,    // 位置和尺寸
            hwnd,               // 父窗口
            (HMENU)14,           // 控件ID
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);

            CreateWindowW(
            L"BUTTON",          // 预定义类名
            L"<-",          // 按钮文本
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            10, 210, 30, 30,    // 位置和尺寸
            hwnd,               // 父窗口
            (HMENU)15,           // 控件ID
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);

            hDisplay = CreateWindowW(
            L"STATIC",
            L"0",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            10, 10, 160, 30,
            hwnd,
            (HMENU)16, // 控件ID随便给
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);
        return 0;

    case WM_COMMAND:
        // 处理按钮点击事件
        if(next == false){
            if(LOWORD(wParam) >= 0 && LOWORD(wParam) <= 9) // 多位数字输入
            {
                num1 = num1 * 10 + LOWORD(wParam);
                wchar_t buf[16];
                swprintf(buf, L"%d", num1);
                SetWindowTextW(hDisplay, buf); // 显示num1
            }else if(LOWORD(wParam) == 10) // +
            {
                op = '+';
                next = true;
                num2 = 0; // 切换输入第二个数时清零
            }else if(LOWORD(wParam) == 11) // -
            {
                op = '-';
                next = true;
                num2 = 0;
            }else if(LOWORD(wParam) == 12) // *
            {
                op = '*';
                next = true;
                num2 = 0;
            }else if(LOWORD(wParam) == 13) // /
            {
                op = '/';
                next = true;
                num2 = 0;
            }else if(LOWORD(wParam) == 14) // =
            {
                int result = 0;
                if(next == true) {
                    if(op == '+') result = num1 + num2;
                    else if(op == '-') result = num1 - num2;
                    else if(op == '*') result = num1 * num2;
                    else if(op == '/' && num2 != 0) result = num1 / num2;
                    else result = 0;
                    num1 = result;
                    num2 = 0;
                    op = 0;
                    next = false;
                } else {
                    result = num1;
                }
                wchar_t buf[16];
                swprintf(buf, L"%d", result);
                SetWindowTextW(hDisplay, buf);
            }else if(LOWORD(wParam) == 15) // <-
            {
                num1 = (int)num1 / 10; // 删除最后一位数字
                wchar_t buf[16];
                swprintf(buf, L"%d", num1);
                SetWindowTextW(hDisplay, buf); // 显示num1
            }
        }else if(next == true){
            if(LOWORD(wParam) >= 0 && LOWORD(wParam) <= 9) // 多位数字输入
            {
                num2 = num2 * 10 + LOWORD(wParam);
                wchar_t buf[16];
                swprintf(buf, L"%d", num2);
                SetWindowTextW(hDisplay, buf); // 显示num2
            }else if(LOWORD(wParam) == 14) // =
            {
                int result = 0;
                if(op == '+') result = num1 + num2;
                else if(op == '-') result = num1 - num2;
                else if(op == '*') result = num1 * num2;
                else if(op == '/' && num2 != 0) result = num1 / num2;
                else result = 0;
                num1 = result;
                num2 = 0;
                op = 0;
                next = false;
                wchar_t buf[16];
                swprintf(buf, L"%d", result);
                SetWindowTextW(hDisplay, buf);
            }else if(LOWORD(wParam) == 15) // <-
            {
                num1 = (int)num1 / 10; // 删除最后一位数字
                wchar_t buf[16];
                swprintf(buf, L"%d", num1);
                SetWindowTextW(hDisplay, buf); // 显示num1
            }
        }
        return 0;

    case WM_CLOSE:
        DestroyWindow(hwnd);
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

// 修改入口函数为WinMain，参数类型改为LPSTR
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // 注册窗口类
    const wchar_t CLASS_NAME[] = L"InteractiveWindow";

    WNDCLASSW wc = {};
    wc.lpfnWndProc   = WndProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);

    RegisterClassW(&wc);

    // 创建窗口
     HWND hwnd = CreateWindowExW(
        0,
        CLASS_NAME,
        L"Calculator",
        WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_VISIBLE, // 只有标题栏、关闭和最小化按钮
        CW_USEDEFAULT, CW_USEDEFAULT, 180, 300, // 更适合按钮布局的窗口大小
        NULL, NULL, hInstance, NULL);

    if(hwnd == NULL) return 0;

    // 消息循环
    MSG msg;
    while(GetMessageW(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    return 0;
}