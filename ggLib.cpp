// Test inject
#include <d3d9.h> //Needed header files
//#include <d3dx9core.h>
/*#include <WinUser.h>
#include <synchapi.h>
#include <utilapiset.h>
#include <processthreadsapi.h>*/

DWORD __stdcall KeyboardHook(void*)
{
	while (1)
	{
		if(GetAsyncKeyState(VK_F1))
		{
			Beep(500, 200);
		}
		Sleep(100);
	}
}



int __stdcall DllMain(HINSTANCE hInst, DWORD  ul_reason_for_call, void* lpReserved)
{
        switch (ul_reason_for_call)    
        {
        case DLL_PROCESS_ATTACH: //if we are attached into the game's process
			CreateThread(0, 0, &KeyboardHook, 0, 0, 0);//start hotkeys thread
        }
        return 1;
}