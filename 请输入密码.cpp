#include <windows.h>
#include <wchar.h>

int num1;
int lock = 114514;

HWND hDisplay;
// 窗口过程函数（处理交互事件）
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg){
        case WM_CREATE:
        CreateWindowW(
            L"BUTTON",
            L"1",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            10, 60, 30, 30,
            (HWND)hwnd,
            (HMENU)1,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);

        CreateWindowW(
            L"BUTTON",
            L"2",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            50, 60, 30, 30,
            (HWND)hwnd,
            (HMENU)2,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);

        CreateWindowW(
            L"BUTTON",
            L"3",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            90, 60, 30, 30,
            (HWND)hwnd,
            (HMENU)3,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);

            CreateWindowW(
            L"BUTTON",
            L"4",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            10, 110, 30, 30,
            (HWND)hwnd,
            (HMENU)4,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);

            CreateWindowW(
            L"BUTTON",
            L"5",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            50, 110, 30, 30,
            (HWND)hwnd,
            (HMENU)5,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);

            CreateWindowW(
            L"BUTTON",
            L"6",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            90, 110, 30, 30,
            (HWND)hwnd,
            (HMENU)6,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);

            CreateWindowW(
            L"BUTTON",
            L"7",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            10, 160, 30, 30,
            (HWND)hwnd,
            (HMENU)7,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);

            CreateWindowW(
            L"BUTTON",
            L"8",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            50, 160, 30, 30,
            (HWND)hwnd,
            (HMENU)8,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);

            CreateWindowW(
            L"BUTTON",
            L"9",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            90, 160, 30, 30,
            (HWND)hwnd,
            (HMENU)9,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);

            CreateWindowW(
            L"BUTTON",
            L"0",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            50, 210, 30, 30,
            (HWND)hwnd,
            (HMENU)0,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);

            hDisplay = CreateWindowW(
            L"STATIC",
            L"",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            10, 10, 110, 30,
            (HWND)hwnd,
            (HMENU)10,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);
            
            CreateWindowW(
            L"BUTTON",
            L"↵",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            90, 210, 30, 30,
            (HWND)hwnd,
            (HMENU)11,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);

            CreateWindowW(
            L"BUTTON",
            L"#",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            10, 210, 30, 30,
            (HWND)hwnd,
            (HMENU)12,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);

            return 0;

        case WM_COMMAND:
            if(LOWORD(wParam) >= 0 && LOWORD(wParam) <= 9)
            {
                num1 = num1 * 10 + LOWORD(wParam);
                wchar_t buf[16];
                swprintf(buf, L"%d", num1);
                SetWindowTextW(hDisplay, buf);
            }else if(LOWORD(wParam) == 11) // ↵
            {
                if(num1 == lock) // 假设密码是a
                {
                    MessageBoxW(hwnd, L"密码正确！", L"提示", MB_OK);
                    DestroyWindow(hwnd);
                    return 0;
                }else if(num1 == 0){
                    MessageBoxW(hwnd, L"请输入密码！", L"提示", MB_OK);
                }else
                {
                    MessageBoxW(hwnd, L"密码错误！", L"提示", MB_OK);
                }
            }else if(LOWORD(wParam) == 12) // #
            {
                num1 = num1 / 10; // 删除最后一位数字
                wchar_t buf[16];
                swprintf(buf ,L"%d", num1);
                SetWindowTextW(hDisplay, buf);
            }
            break; //防止贯穿到 WM_CLOSE

        case WM_CLOSE:
            DestroyWindow(hwnd);
            return 0;
        
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam); // 保证有返回值
}
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
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
        L"Password lock",
        WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_VISIBLE, // 只有标题栏、关闭和最小化按钮
        CW_USEDEFAULT, CW_USEDEFAULT, 110, 300, // 更适合按钮布局的窗口大小
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
