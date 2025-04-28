#include <windows.h>
#include <iostream>

/*-------------------------------------
p100 Windows callback
--------------------------------------*/
BOOL CALLBACK 
enum_win_proc(HWND hwnd, LPARAM lParam) 
{
    DWORD affinity = 0;

    if (GetWindowDisplayAffinity(hwnd, &affinity)) 
    {
        if (affinity == WDA_EXCLUDEFROMCAPTURE || affinity == WDA_MONITOR) 
        {
            printf("[Clueless] HWND: %p, possible cluely\n", hwnd);

            if (SetWindowDisplayAffinity(hwnd, WDA_NONE)) 
            {
                printf("[Clueless] Reset affiniity to WDA_NONE\n");
            }
            else 
            {
                printf("[Clueless] HWND: %p, has potential hook!: Error: %d\n", 
                    hwnd, GetLastError());
            }
        }
    }

    return TRUE;
}

/*-----------------------
Run p100 detection.
------------------------*/
int main(void) 
{
    printf("[Clueless] Revealing all hidden windows\n");

    EnumWindows(enum_win_proc, 0);
   
    system("pause");

    return 0;
}
