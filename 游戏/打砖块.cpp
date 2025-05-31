#include <windows.h>   // 用于创建窗口、绘图、处理消息等（图形界面游戏的核心）
#include <wchar.h>     // 用于宽字符（wchar_t）相关操作，支持中文或特殊字符显示
#include <ctime>       // 时间相关函数，如计时、获取当前时间、随机数种子
#include <cstdlib>     // 标准库，包含随机数生成（rand, srand）、内存分配等

bool bricks[3] = {true, true, true}; // 3块砖，true表示存在
int ball_x = 300, ball_y = 400;
int ball_dx = 5, ball_dy = -5;
int ball_r = 20; // 初始值，后续会根据窗口大小动态调整
int w;
int h;
int pad_x;
int pad_y;
int pad_w;
int pad_h;
int brick_w;
int brick_h;
bool game_over = false;

LRESULT CALLBACK WndProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam){
    switch(msg){
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            // 创建内存DC和兼容位图
            HDC memDC = CreateCompatibleDC(hdc);
            RECT clientRect;
            GetClientRect(hwnd, &clientRect);
            int width = clientRect.right - clientRect.left;
            int height = clientRect.bottom - clientRect.top;
            w = width;
            h = height;
            // 计算挡板和砖块的尺寸和位置
            pad_w = w / 6;
            pad_h = h / 30;
            pad_y = h - pad_h * 3;
            brick_w = w / 8;
            brick_h = h / 20;
            HBITMAP memBitmap = CreateCompatibleBitmap(hdc, width, height);
            HBITMAP oldBitmap = (HBITMAP)SelectObject(memDC, memBitmap);

            // 用黑色清空背景
            HBRUSH hBrush = (HBRUSH)GetStockObject(BLACK_BRUSH);
            FillRect(memDC, &clientRect, hBrush);

            // 下面所有绘图都用 memDC 替代 hdc
            // ... 你的挡板、球、砖块绘制代码 ...
            // 例如：
            // FillRect(memDC, &padRect, padBrush);
            // Rectangle(memDC, ...);
            // ...

            // 画挡板（实心）
            HBRUSH padBrush = CreateSolidBrush(RGB(255,255,255));
            RECT padRect = {pad_x, pad_y, pad_x + pad_w, pad_y + pad_h};
            FillRect(memDC, &padRect, padBrush);
            DeleteObject(padBrush);

            // 画球（正方形，黄色，防止闪烁）
            int ball_size = ball_r;
            HBRUSH ballBrush = CreateSolidBrush(RGB(255,255,255));
            HBRUSH oldBrush = (HBRUSH)SelectObject(memDC, ballBrush);
            Rectangle(memDC, ball_x, ball_y, ball_x + ball_size, ball_y + ball_size);
            SelectObject(memDC, oldBrush);
            DeleteObject(ballBrush);

            // 画砖块（实心）
            HBRUSH brickBrush = CreateSolidBrush(RGB(255,255,255));
            for (int i = 0; i < 3; ++i) {
                if (bricks[i]) {
                    int bx = w / 8 + i * (brick_w + w / 20);
                    int by = h / 10;
                    RECT brickRect = {bx, by, bx + brick_w, by + brick_h};
                    FillRect(memDC, &brickRect, brickBrush);
                }
            }
            DeleteObject(brickBrush);
            // 计算挡板位置
            // 一次性拷贝到屏幕
            BitBlt(hdc, 0, 0, width, height, memDC, 0, 0, SRCCOPY);

            // 清理
            SelectObject(memDC, oldBitmap);
            DeleteObject(memBitmap);
            DeleteDC(memDC);

            EndPaint(hwnd, &ps);
            break;
        }
        case WM_SIZING: {
            RECT* rect = (RECT*)lParam;
            int width = rect->right - rect->left;
            int height = rect->bottom - rect->top;
            float ratio = 4.0f / 3.0f; // 4:3比例
            if (width / (float)height > ratio) {
                width = (int)(height * ratio);
                rect->right = rect->left + width;
            } else {
                height = (int)(width / ratio);
                rect->bottom = rect->top + height;
            }
            break;
        }
        case WM_TIMER: {
            ball_x += ball_dx;
            ball_y += ball_dy;

            if(!game_over && ball_y + ball_r > h){
                game_over = true; // 游戏结束
                MessageBoxW(hwnd, L"Game over!", L"warning", MB_OK);
                KillTimer(hwnd, 1);
                DestroyWindow(hwnd);
                return 0;
            }

            if(ball_x < ball_r || ball_x > w - ball_r) ball_dx = -ball_dx;
            if(ball_y < ball_r || ball_y > h - ball_r) ball_dy = -ball_dy;
            //检测挡板碰撞
            if(ball_y + ball_r >= pad_y && ball_y + ball_r <= pad_y + pad_h && ball_x + ball_r >= pad_x && ball_x <= pad_x + pad_w){
                ball_dy = -abs(-ball_dy); // 反弹
            }
            // 检测砖块碰撞
            for (int i = 0; i < 3; ++i) {
                if (bricks[i]) {
                    int bx = w / 8 + i * (brick_w + w / 20);
                    int by = h / 10;
                    if (ball_x + ball_r >= bx && ball_x <= bx + brick_w &&
                        ball_y + ball_r >= by && ball_y <= by + brick_h) {
                        bricks[i] = false; // 碰撞，砖块消失
                        ball_dy = -ball_dy; // 反弹
                    }
                }
            
            }
            InvalidateRect(hwnd, NULL, FALSE);
            break;
        }
        case WM_KEYDOWN: {
            switch(wParam){
                case VK_LEFT:
                    pad_x -= 20;
                    if (pad_x < 0) pad_x = 0;
                    InvalidateRect(hwnd, NULL, FALSE);
                    break;
                case VK_RIGHT:
                    pad_x += 20;
                    if (pad_x + pad_w > w) pad_x = w - pad_w;
                    InvalidateRect(hwnd, NULL, FALSE);
                    break;
            }
            break;
        }
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASSW wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"MyGameWindow";
    wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    RegisterClassW(&wc);
    HWND hwnd = CreateWindowW(
        L"MyGameWindow",
        L"Brick-breaking game",
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
        NULL, NULL, hInstance, NULL);
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    pad_w = 800 / 6;
    pad_x = 800 / 2 - pad_w / 2;
    SetTimer(hwnd, 1, 16, NULL);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}