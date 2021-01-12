#include <console/console.h>

namespace Console
{
    void Update()
    {
        
        //mouse_event(MOUSEEVENTF_MIDDLEUP, 5000, 5000, 0, 0);
        ReadConsoleInput(hin, &InputRecord, 1, &Events); 
    }
}