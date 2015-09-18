#define VK_OEM_PLUS	0xBB
#define VK_OEM_COMMA	0xBC
#define VK_OEM_MINUS	0xBD
#define VK_OEM_PERIOD	0xBE    
      
        bool TAB_KEY_RESET                      = true;
        bool KEY_V_IS_RESET                     = true;
        bool KEY_C_IS_RESET                     = true;

        bool VK_PRIOR_KeyIsReset                = true;
        bool VK_NEXT_KeyIsReset                 = true;

        bool aKeyIsReset                        = true;            
        bool bKeyIsReset                        = true;         
        bool cKeyIsReset                        = true;    
        bool dKeyIsReset                        = true;            
        bool eKeyIsReset                        = true;         
        bool fKeyIsReset                        = true;           
        bool gKeyIsReset                        = true;         
        bool hKeyIsReset                        = true;         
        bool iKeyIsReset                        = true;  
        bool jKeyIsReset                        = true; 
        bool kKeyIsReset                        = true;        
        bool lKeyIsReset                        = true;         
        bool mKeyIsReset                        = true;         
        bool nKeyIsReset                        = true;        
        bool oKeyIsReset                        = true;          
        bool pKeyIsReset                        = true;        
        bool qKeyIsReset                        = true;        
        bool rKeyIsReset                        = true;        
        bool sKeyIsReset                        = true;        
        bool tKeyIsReset                        = true;        
        bool uKeyIsReset                        = true;          
        bool vKeyIsReset                        = true;       
        bool wKeyIsReset                        = true;         
        bool xKeyIsReset                        = true;                
        bool yKeyIsReset                        = true;         
        bool zKeyIsReset                        = true;          
        
        bool homeKeyIsReset                     = true;            
        bool endKeyIsReset                      = true;
        
        bool VK_OEM_COMMA_KeyIsReset            = true;            
        bool VK_OEM_PERIOD_KeyIsReset           = true;    
        
        
        bool numpad_1_isReset                   = true;                                 
        
        bool spaceBarIsPressed                  = false;
        
        //======================================================================
 
        static bool  leftMouseButton;
        static bool  rightMouseButton;
        static bool  middleMouseButton;

#if !defined(WIN32_LEAN_AND_MEAN)
#define WIN32_LEAN_AND_MEAN
#endif


#include <windows.h>
#include <cmath>
#include <sstream>
#include <stdexcept>
#include <string>

#if defined(_DEBUG)
#include <crtdbg.h>
#endif



#include <windows.h>
#include <GL/gl.h>


//_______________________________________________OLD______________________________________________________________//
//_______________________________________________OLD______________________________________________________________//
//_______________________________________________OLD______________________________________________________________//
//_______________________________________________OLD______________________________________________________________//

//_______________________________________________NEW______________________________________________________________//
//_______________________________________________NEW______________________________________________________________//
//_______________________________________________NEW______________________________________________________________//
//_______________________________________________NEW______________________________________________________________//


#define CAMERA_FOVY  45.0f
#define CAMERA_ZFAR  10.0f
#define CAMERA_ZNEAR 0.1f

#define MOUSE_ORBIT_SPEED 0.30f     // 0 = SLOWEST, 1 = FASTEST
#define MOUSE_DOLLY_SPEED 0.02f     // same as above...but much more sensitive
#define MOUSE_TRACK_SPEED 0.005f    // same as above...but much more sensitive





HWND                g_hWnd;
HDC                 g_hDC;
HGLRC               g_hRC;
HINSTANCE           g_hInstance;
int                 g_windowWidth;
int                 g_windowHeight;
bool                g_isFullScreen;
bool                g_hasFocus;


//-----------------------------------------------------------------------------
// Functions Prototypes.
//-----------------------------------------------------------------------------

void    Cleanup();
void    CleanupApp();
HWND    CreateAppWindow(const WNDCLASSEX &wcl, const char *pszTitle);
void    DrawFrame();


void    Init();

void    InitGL();

void    Log(const char *pszMessage);
void    ProcessMouseInput(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

void    ToggleFullScreen();


LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);









int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
#if defined _DEBUG
    _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
    _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
#endif

    MSG msg = {0};
    WNDCLASSEX wcl = {0};

    wcl.cbSize = sizeof(wcl);
    wcl.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
    wcl.lpfnWndProc = WindowProc;
    wcl.cbClsExtra = 0;
    wcl.cbWndExtra = 0;
    wcl.hInstance = g_hInstance = hInstance;
    wcl.hIcon = LoadIcon(0, IDI_APPLICATION);
    wcl.hCursor = LoadCursor(0, IDC_ARROW);
    wcl.hbrBackground = 0;
    wcl.lpszMenuName = 0;
    wcl.lpszClassName = "GLWindowClass";
    wcl.hIconSm = 0;

    if (!RegisterClassEx(&wcl))
        return 0;

    g_hWnd = CreateAppWindow(wcl, 0);

    if (g_hWnd)
    {
       
		InitGL();
		ToggleFullScreen();


glDisable(GL_MULTISAMPLE_ARB);
           
           
           ShowWindow(g_hWnd, nShowCmd);
            UpdateWindow(g_hWnd);

            while (true)
            {
                while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
                {
                    if (msg.message == WM_QUIT)
                        break;

                    TranslateMessage(&msg);
                    DispatchMessage(&msg);
                }

                if (msg.message == WM_QUIT)
                    break;


                if (keys[VK_ESCAPE])
		        { 
                     msg.message = WM_QUIT ;
                }                                   
               
                if (g_hasFocus)
                {
                    RenderGL();
                    SwapBuffers(g_hDC);
                    ProcessKeyboard();
                }
                else
                {
                    WaitMessage();
                }
            }


        Cleanup();
        UnregisterClass(wcl.lpszClassName, hInstance);
    }

    return static_cast<int>(msg.wParam);
}






LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        //======================================================================================
        case WM_KEYDOWN:
		{
			keys[wParam] = TRUE;					// If So, Mark It As TRUE
            return 0;								// Jump Back
		}
        break;
        case WM_KEYUP:								// Has A Key Been Released?
		{
			keys[wParam] = FALSE;					// If So, Mark It As FALSE
			return 0;								// Jump Back
		}
		break;    
       //======================================================================================
    
    case WM_ACTIVATE:
        switch (wParam)
        {
        default:
            break;

        case WA_ACTIVE:
        case WA_CLICKACTIVE:
            g_hasFocus = true;
            break;

        case WA_INACTIVE:
            if (g_isFullScreen)
                ShowWindow(hWnd, SW_MINIMIZE);
            g_hasFocus = false;
            break;
        }
        break;

    case WM_CHAR:
        switch (static_cast<int>(wParam))
        {
        case VK_ESCAPE:
                PostMessage(hWnd, WM_CLOSE, 0, 0);
            break;


        
        default:
            break;
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_SIZE:
        g_windowWidth = static_cast<int>(LOWORD(lParam));
        g_windowHeight = static_cast<int>(HIWORD(lParam));
        break;

    case WM_SYSKEYDOWN:
        if (wParam == VK_RETURN)
            ToggleFullScreen();
        break;

    default:
        ProcessMouseInput(hWnd, msg, wParam, lParam);
        break;
    }

    return DefWindowProc(hWnd, msg, wParam, lParam);
}

void Cleanup()
{
    CleanupApp();

    if (g_hDC)
    {
        if (g_hRC)
        {
            wglMakeCurrent(g_hDC, 0);
            wglDeleteContext(g_hRC);
            g_hRC = 0;
        }

        ReleaseDC(g_hWnd, g_hDC);
        g_hDC = 0;
    }
}

void CleanupApp()
{



}

HWND CreateAppWindow(const WNDCLASSEX &wcl, const char *pszTitle)
{
    // Create a window that is centered on the desktop. It's exactly 1/4 the
    // size of the desktop. Don't allow it to be resized.

    DWORD wndExStyle = WS_EX_OVERLAPPEDWINDOW;
    DWORD wndStyle   = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;

    HWND hWnd = CreateWindowEx(wndExStyle, wcl.lpszClassName, pszTitle, wndStyle, 0, 0, 0, 0, 0, 0, wcl.hInstance, 0);

    if (hWnd)
    {
        viewWidth = GetSystemMetrics(SM_CXSCREEN);
        viewHeight = GetSystemMetrics(SM_CYSCREEN);
        
        
        int halfScreenWidth = (int)viewWidth / 2;
        int halfScreenHeight = (int)viewHeight / 2;
        int left = ((int)viewWidth - halfScreenWidth) / 2;
        int top = ((int)viewHeight - halfScreenHeight) / 2;
        RECT rc = {0};

        SetRect(&rc, 0, 0, (int)viewWidth, (int)viewHeight);
        AdjustWindowRectEx(&rc, wndStyle, FALSE, wndExStyle);
        MoveWindow(hWnd, rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top, TRUE);

        GetClientRect(hWnd, &rc);
        g_windowWidth = rc.right - rc.left;
        g_windowHeight = rc.bottom - rc.top;
    }

    return hWnd;
}





void ProcessMouseInput(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    // Use the left mouse button to track the camera.
    // Use the middle mouse button to dolly the camera.
    // Use the right mouse button to orbit the camera.

    enum CameraMode {CAMERA_NONE, CAMERA_TRACK, CAMERA_DOLLY, CAMERA_ORBIT};

    static CameraMode cameraMode = CAMERA_NONE;
    static POINT ptMousePrev = {0};
    static POINT ptMouseCurrent = {0};
    static int mouseButtonsDown = 0;
    static float dx = 0.0f;
    static float dy = 0.0f;

    switch (msg)
    {
    case WM_LBUTTONDOWN:
        
        leftMouseButton     = true;

        SetCapture(hWnd);
        ptMousePrev.x = static_cast<int>(static_cast<short>(LOWORD(lParam)));
        ptMousePrev.y = static_cast<int>(static_cast<short>(HIWORD(lParam)));
        ClientToScreen(hWnd, &ptMousePrev);
        break;

    case WM_RBUTTONDOWN:

        rightMouseButton    = true;

        SetCapture(hWnd);
        ptMousePrev.x = static_cast<int>(static_cast<short>(LOWORD(lParam)));
        ptMousePrev.y = static_cast<int>(static_cast<short>(HIWORD(lParam)));
        ClientToScreen(hWnd, &ptMousePrev);
        break;

    case WM_MBUTTONDOWN:
        
        middleMouseButton   = true;
        
        SetCapture(hWnd);
        ptMousePrev.x = static_cast<int>(static_cast<short>(LOWORD(lParam)));
        ptMousePrev.y = static_cast<int>(static_cast<short>(HIWORD(lParam)));
        ClientToScreen(hWnd, &ptMousePrev);
        break;

    case WM_MOUSEMOVE:
        ptMouseCurrent.x = static_cast<int>(static_cast<short>(LOWORD(lParam)));
        ptMouseCurrent.y = static_cast<int>(static_cast<short>(HIWORD(lParam)));
        ClientToScreen(hWnd, &ptMouseCurrent);
        //=====================================================================================            
            ptMouseCurrent.x = LOWORD (lParam);
			ptMouseCurrent.y = HIWORD (lParam);
        //=====================================================================================
			
            if( rightMouseButton )
			{
            
            }
            //-------------------------------------------------------------------------------------
			if( middleMouseButton && !keys[VK_CONTROL]  && !keys[VK_SHIFT])
			{
                  Pass_MIDDLE_Mouse[1] -= (ptMouseCurrent.x - ptMousePrev.x)   * .3;
                  Pass_MIDDLE_Mouse[0] += (ptMouseCurrent.y - ptMousePrev.y)   * .3;
            }
            //-------------------------------------------------------------------------------------
			if( middleMouseButton && keys[VK_CONTROL])
			{
                  Pass_MIDDLE_CONTROL_Mouse += (ptMouseCurrent.y - ptMousePrev.y)   * .05;
            }                   
            //-------------------------------------------------------------------------------------
			if( middleMouseButton && keys[VK_SHIFT])
			{
                  Pass_MIDDLE_SHIFT_Mouse[0] += (ptMouseCurrent.x - ptMousePrev.x)   * .01;
                  Pass_MIDDLE_SHIFT_Mouse[1] -= (ptMouseCurrent.y - ptMousePrev.y)   * .01;
            }
            //-------------------------------------------------------------------------------------        
        
            //-------------------------------------------------------------------------------------
			if( leftMouseButton && !keys[VK_CONTROL]  && !keys[VK_SHIFT])
			{
                  Pass_MIDDLE_Mouse[1] -= (ptMouseCurrent.x - ptMousePrev.x)   * .3;
                  Pass_MIDDLE_Mouse[0] += (ptMouseCurrent.y - ptMousePrev.y)   * .3;
            }
            //-------------------------------------------------------------------------------------
			if( leftMouseButton && keys[VK_CONTROL])
			{
                  Pass_MIDDLE_CONTROL_Mouse += (ptMouseCurrent.y - ptMousePrev.y)   * .01;
            }                   
            //-------------------------------------------------------------------------------------
			if( leftMouseButton && keys[VK_SHIFT])
			{
                  Pass_MIDDLE_SHIFT_Mouse[0] += (ptMouseCurrent.x - ptMousePrev.x)   * .01;
                  Pass_MIDDLE_SHIFT_Mouse[1] -= (ptMouseCurrent.y - ptMousePrev.y)   * .01;
            }
            //-------------------------------------------------------------------------------------          
        
        
        
        //=====================================================================================        
            ptMousePrev.x = ptMouseCurrent.x;
            ptMousePrev.y = ptMouseCurrent.y;          
        //=====================================================================================
        break;


    case WM_LBUTTONUP:
        
        leftMouseButton     = false;
        break;
    
    case WM_RBUTTONUP:
        rightMouseButton     = false;
        break;
    
    case WM_MBUTTONUP:
        middleMouseButton     = false;
        break;

    default:
        break;
    }
}



void ToggleFullScreen()
{
    static DWORD savedExStyle;
    static DWORD savedStyle;
    static RECT rcSaved;

    g_isFullScreen = !g_isFullScreen;

    if (g_isFullScreen)
    {
        // Moving to full screen mode.

        savedExStyle = GetWindowLong(g_hWnd, GWL_EXSTYLE);
        savedStyle = GetWindowLong(g_hWnd, GWL_STYLE);
        GetWindowRect(g_hWnd, &rcSaved);

        SetWindowLong(g_hWnd, GWL_EXSTYLE, 0);
        SetWindowLong(g_hWnd, GWL_STYLE, WS_POPUP | WS_CLIPCHILDREN | WS_CLIPSIBLINGS);
        SetWindowPos(g_hWnd, HWND_TOPMOST, 0, 0, 0, 0,
            SWP_NOMOVE | SWP_NOSIZE | SWP_FRAMECHANGED | SWP_SHOWWINDOW);

        g_windowWidth = GetSystemMetrics(SM_CXSCREEN);
        g_windowHeight = GetSystemMetrics(SM_CYSCREEN);

        SetWindowPos(g_hWnd, HWND_TOPMOST, 0, 0,
            g_windowWidth, g_windowHeight, SWP_SHOWWINDOW);
    }
    else
    {
        // Moving back to windowed mode.

        SetWindowLong(g_hWnd, GWL_EXSTYLE, savedExStyle);
        SetWindowLong(g_hWnd, GWL_STYLE, savedStyle);
        SetWindowPos(g_hWnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_FRAMECHANGED | SWP_SHOWWINDOW);

        g_windowWidth = rcSaved.right - rcSaved.left;
        g_windowHeight = rcSaved.bottom - rcSaved.top;

        SetWindowPos(g_hWnd, HWND_NOTOPMOST, rcSaved.left, rcSaved.top, g_windowWidth, g_windowHeight, SWP_SHOWWINDOW);
    }
}

