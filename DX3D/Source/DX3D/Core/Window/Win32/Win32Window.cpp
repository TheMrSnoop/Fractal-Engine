#include <DX3D/Core/Window/Window.h>
#include <Windows.h>
#include <stdexcept>
#include <iostream>

static LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    switch (msg)
    {    
    case WM_CLOSE:
    {
        PostQuitMessage(0);
        break;
    }
    default:
        return DefWindowProc(hwnd, msg, wparam, lparam);
    }
    return 0;
}


dx3d::Window::Window(): Base()
{
    std::cout << "Window Code should be running now.";

    WNDCLASSEX wc{};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpszClassName = L"DX3DWindow";
    wc.lpfnWndProc = &WindowProcedure;
    auto windowClassId = RegisterClassEx(&wc);

    if (!windowClassId)
    {
        throw std::runtime_error("RegisterClassEx failed.");
    }

    RECT rc{ 0,0,1280,720};
    AdjustWindowRect(&rc, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, false);
    
    m_handle = CreateWindowEx(0, MAKEINTATOM(windowClassId), L"FRACTAL ENGINE", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, NULL, NULL);

    if (!m_handle)
    {
        throw std::runtime_error("CreateWindowEx Failed");
    }

    ShowWindow(static_cast<HWND>(m_handle), SW_SHOW);


}

dx3d::Window::~Window()
{
    DestroyWindow(static_cast<HWND>(m_handle));
}