#include <windows.h>
#include "WarhammerBattleGUI.h"
#include "WindowComponents.h"
#include "UnitCollection.h"
//
//const char g_szClassName[] = "myWindowClass";
//
//BOOL CALLBACK AboutDlgProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
//{
//	switch (Message)
//	{
//	case WM_INITDIALOG:
//
//		return TRUE;
//	case WM_COMMAND:
//		switch (LOWORD(wParam))
//		{
//		case IDOK:
//			EndDialog(hwnd, IDOK);
//			break;
//		case IDCANCEL:
//			EndDialog(hwnd, IDCANCEL);
//			break;
//		}
//		break;
//	default:
//		return FALSE;
//	}
//	return TRUE;
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
//{
//	switch (msg)
//	{
//	case WM_COMMAND:
//		switch (LOWORD(wParam))
//		{
//		case ID_FILE_NEW:
//		{
//			int ret = DialogBox(GetModuleHandle(NULL),
//				MAKEINTRESOURCE(IDD_DIALOG1), hwnd, AboutDlgProc);
//			if (ret == IDOK) {
//				MessageBox(hwnd, "Dialog exited with IDOK.", "Notice",
//					MB_OK | MB_ICONINFORMATION);
//			}
//			else if (ret == IDCANCEL) {
//				MessageBox(hwnd, "Dialog exited with IDCANCEL.", "Notice",
//					MB_OK | MB_ICONINFORMATION);
//			}
//			else if (ret == -1) {
//				MessageBox(hwnd, "Dialog failed!", "Error",
//					MB_OK | MB_ICONINFORMATION);
//			}
//		}
//		break;
//		// Other menu commands...
//		}
//		break;
//	case WM_LBUTTONDOWN:
//	{
//		char szFileName[MAX_PATH];
//		HINSTANCE hInstance = GetModuleHandle(NULL);
//
//		GetModuleFileName(hInstance, szFileName, MAX_PATH);
//		MessageBox(hwnd, szFileName, "This program is:", MB_OK | MB_ICONINFORMATION);
//	}
//	break;
//	case WM_CLOSE:
//		DestroyWindow(hwnd);
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	default:
//		return DefWindowProc(hwnd, msg, wParam, lParam);
//	}
//	return 0;
//}
//


LRESULT CALLBACK MainWindowProcessor(HWND eventHandler, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:
		DestroyWindow(eventHandler);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(eventHandler, msg, wParam, lParam);
	}

	return 0;
}

LRESULT CALLBACK PlayerWindowProcessor(HWND eventHandler, UINT msg, WPARAM wParam, LPARAM lparam)
{
	switch (msg)
	{
	case WM_PAINT:
		PAINTSTRUCT pc;
		HDC hdc;

		hdc = BeginPaint(eventHandler, &pc);

		if (hdc == NULL)
		{
			MessageBox(eventHandler, "Error with BeginPaint", "Caption", MB_ICONEXCLAMATION | MB_OK);
		}
		TextOut(hdc, 10, 10, "Unit: ", 6);
		TextOut(hdc, 10, 40, "Size: ", 6);
		TextOut(hdc, 10, 60, "WS: ", 4);
		TextOut(hdc, 10, 80, "BS: ", 4);
		TextOut(hdc, 10, 100, "Strength: ", 10);
		TextOut(hdc, 10, 120, "Toughness: ", 11);
		TextOut(hdc, 10, 140, "Attacks: ", 9);
		TextOut(hdc, 10, 160, "Wounds: ", 8);
		TextOut(hdc, 10, 180, "Initiative: ", 12);
		TextOut(hdc, 10, 200, "Leadership: ", 12);
		EndPaint(eventHandler, &pc);
		break;
	default:
		return DefWindowProc(eventHandler, msg, wParam, lparam);
	}

	return 0;
}

WNDCLASSEX RegisterWindowsClass(WNDPROC eventHandler, const char* name, HINSTANCE hInstance)
{
	WNDCLASSEX genericWindow = WindowComponents::MakeWindowDefinition(MainWindowProcessor, "genericWindow", hInstance);

	if (!RegisterClassEx(&genericWindow))
	{
		MessageBox(NULL, "Failed to register a window", "Register class error", MB_ICONEXCLAMATION | MB_OK);
	}

	return genericWindow;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	UnitClasses::UnitCollection unitsAvalibleForBattle("..\\WarhammerBattleGenerator\\bin\\Debug\\units.xml");
	WNDCLASSEX genericWindow = RegisterWindowsClass(MainWindowProcessor, "genericWindow", hInstance);

	HWND mainWindow = WindowComponents::GenerateWindow("genericWindow", "Warhammer Battle", NULL, hInstance, 900, 500);

	if (mainWindow == NULL)
	{
		MessageBox(NULL, "Window Creation Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	WNDCLASSEX playerWindowDefinition = WindowComponents::MakeWindowDefinition(PlayerWindowProcessor, "playerWindow", hInstance);

	if (!RegisterClassEx(&playerWindowDefinition))
	{
		MessageBox(NULL, "Could not make a player window", "Error in caption", MB_ICONEXCLAMATION | MB_OK);
	}

	HWND playerOneWindow = WindowComponents::GeneratePlayerWindow(mainWindow, hInstance, 50, 50);

	if (playerOneWindow == NULL)
	{
		MessageBox(NULL, "Window Creation Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	HWND playerOneUnitTypeComboBox = WindowComponents::GenerateComboBox(playerOneWindow, hInstance, 40, 5, 120, 1000);




	HWND playerOneSizeComboBox = WindowComponents::GenerataScrollableComboBox(playerOneWindow, hInstance, 40, 35, 50, 200);


	HWND playerTwoWindow = WindowComponents::GeneratePlayerWindow(mainWindow, hInstance, 600, 50);


	SendMessage(playerOneUnitTypeComboBox, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)"Blood Letter");
	SendMessage(playerOneUnitTypeComboBox, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)"Deamonette");
	SendMessage(playerOneUnitTypeComboBox, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)"Plauge bearer");
	SendMessage(playerOneUnitTypeComboBox, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)"Pink Horror");

	SendMessage(playerOneUnitTypeComboBox, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);

	for (int size = 1; size <= 30; size++)
	{
		char buffer[10];
		sprintf(buffer, "%d", size);
		SendMessage(playerOneSizeComboBox, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)buffer);
	}


	SendMessage(playerOneSizeComboBox, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);

	if (playerTwoWindow == NULL)
	{
		MessageBox(NULL, "Window Creation Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	HWND playerTwoUnitTypeComboBox = WindowComponents::GenerateComboBox(playerTwoWindow, hInstance, 40, 5, 120, 400);


	SendMessage(playerTwoUnitTypeComboBox, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)"Blood Letter");
	SendMessage(playerTwoUnitTypeComboBox, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)"Deamonette");
	SendMessage(playerTwoUnitTypeComboBox, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)"Plauge bearer");
	SendMessage(playerTwoUnitTypeComboBox, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)"Pink Horror");

	SendMessage(playerTwoUnitTypeComboBox, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);

	HWND playerTwoSizeComboBox = WindowComponents::GenerataScrollableComboBox(playerTwoWindow, hInstance, 40, 35, 50, 200);

	for (int size = 1; size <= 30; size++)
	{
		char buffer[10];
		sprintf(buffer, "%d", size);
		SendMessage(playerTwoSizeComboBox, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)buffer);
	}

	SendMessage(playerTwoSizeComboBox, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);

	ShowWindow(mainWindow, nCmdShow);
	UpdateWindow(mainWindow);

	MSG message;

	while (GetMessage(&message, NULL, 0, 0) > 0)
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
	return message.wParam;
}