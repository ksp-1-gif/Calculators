#include <windows.h>
#include <wchar.h>

HWND hDisplay;
LRESULT CALLBACK WndProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam){
    switch(msg){
        case WM_CREATE:
        CreateWindowW(
            L"STATIC",
            L"",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            10, 10, 230, 30,
            hwnd,
            (HMENU)0,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);
        
        CreateWindowW(
            L"BUTTON",
            L"C",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            10, 60, 30, 30,
            hwnd,
            (HMENU)1,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);
        
        CreateWindowW(
            L"BUTTON",
            L"C#",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            50, 60, 30, 30,
            hwnd,
            (HMENU)2,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);
        
        CreateWindowW(
            L"BUTTON",
            L"D",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            90, 60, 30, 30,
            hwnd,
            (HMENU)3,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);

        CreateWindowW(
            L"BUTTON",
            L"D#",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            130, 60, 30, 30,
            hwnd,
            (HMENU)4,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);

        CreateWindowW(
            L"BUTTON",
            L"E",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            170, 60, 30, 30,
            hwnd,
            (HMENU)5,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);

        CreateWindowW(
            L"BUTTON",
            L"F",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            210, 60, 30, 30,
            hwnd,
            (HMENU)6,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);

        CreateWindowW(
            L"BUTTON",
            L"F#",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            10, 110, 30, 30,
            hwnd,
            (HMENU)7,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);

        CreateWindowW(
            L"BUTTON",
            L"G",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            50, 110, 30, 30,
            hwnd,
            (HMENU)8,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);

        CreateWindowW(
            L"BUTTON",
            L"G#",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            90, 110, 30, 30,
            hwnd,
            (HMENU)9,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);

        CreateWindowW(
            L"BUTTON",
            L"A",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            130, 110, 30, 30,
            hwnd,
            (HMENU)10,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);
        
        CreateWindowW(
            L"BUTTON",
            L"A#",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            170, 110, 30, 30,
            hwnd,
            (HMENU)11,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);

        CreateWindowW(
            L"BUTTON",
            L"B",
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            210, 110, 30, 30,
            hwnd,
            (HMENU)12,
            (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
            NULL);
        return 0;
        case WM_COMMAND:
        if(LOWORD(wParam) == 1){
            Beep(262,500); // C
        }else if(LOWORD(wParam) == 2){
            Beep(277,500); // C#
        }else if(LOWORD(wParam) == 3){
            Beep(294,500); // D
        }else if(LOWORD(wParam) == 4){
            Beep(311,500); // D#
        }else if(LOWORD(wParam) == 5){
            Beep(330,500); // E
        }else if(LOWORD(wParam) == 6){
            Beep(349,500); // F
        }else if(LOWORD(wParam) == 7){
            Beep(370,500); // F#
        }else if(LOWORD(wParam) == 8){
            Beep(392,500); // G
        }else if(LOWORD(wParam) == 9){
            Beep(415,500); // G#
        }else if(LOWORD(wParam) == 10){
            Beep(440,500); // A
        }else if(LOWORD(wParam) == 11){
            Beep(466,500); // A#
        }else if(LOWORD(wParam) == 12){
            Beep(494,500); // B
        }
        return 0;
        case WM_CLOSE:
            DestroyWindow(hwnd);
            return 0;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
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
        L"cardMusic", // 窗口标题
        WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_VISIBLE, // 只有标题栏、关闭和最小化按钮
        CW_USEDEFAULT, CW_USEDEFAULT, 250, 200, // 更适合按钮布局的窗口大小
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