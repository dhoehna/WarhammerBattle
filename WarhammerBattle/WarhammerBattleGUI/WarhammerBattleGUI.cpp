#include <windows.h>
#include "WarhammerBattleGUI.h"
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
		TextOut(hdc, 10, 10, "Unit", 4);
		TextOut(hdc, 10, 40, "Size", 4);
		/*
		TextOut(hdc, 10, 55,  "        WS: ", 12);
		TextOut(hdc, 10, 75,  "        BS: ", 12);
		TextOut(hdc, 10, 95,  "  Strength: ", 12);
		TextOut(hdc, 10, 115,  " Toughness: ", 12);
		TextOut(hdc, 10, 125, "   Attacks: ", 12);
		TextOut(hdc, 10, 145, "    Wounds: ", 12);
		TextOut(hdc, 10, 165, "Initiative: ", 12);
		TextOut(hdc, 10, 185, "Leadership: ", 12);
		*/
		EndPaint(eventHandler, &pc);
		break;
	default:
		return DefWindowProc(eventHandler, msg, wParam, lparam);
	}

	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX genericWindow;

	genericWindow.cbSize = sizeof(WNDCLASSEX);
	genericWindow.style = 0;
	genericWindow.lpfnWndProc = MainWindowProcessor;
	genericWindow.cbClsExtra = 0;
	genericWindow.cbWndExtra = 0;
	genericWindow.hInstance = hInstance;
	genericWindow.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	genericWindow.hCursor = LoadCursor(NULL, IDC_ARROW);
	genericWindow.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	genericWindow.lpszMenuName = NULL;
	genericWindow.lpszClassName = "genericWindow";
	genericWindow.hIconSm = LoadIcon(NULL, IDI_APPLICATION);


	if (!RegisterClassEx(&genericWindow))
	{
		MessageBox(NULL, "Could not make a generic window", "Error in caption", MB_ICONEXCLAMATION | MB_OK);
	}

	HWND mainWindow;
	mainWindow = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		"genericWindow",
		"Warhammer Battle",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 900, 500,
		NULL, NULL, hInstance, NULL);

	if (mainWindow == NULL)
	{
		MessageBox(NULL, "Window Creation Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	WNDCLASSEX playerWindow;
	playerWindow.cbSize = sizeof(WNDCLASSEX);
	playerWindow.style = 0;
	playerWindow.lpfnWndProc = PlayerWindowProcessor;
	playerWindow.cbClsExtra = 0;
	playerWindow.cbWndExtra = 0;
	playerWindow.hInstance = hInstance;
	playerWindow.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	playerWindow.hCursor = LoadCursor(NULL, IDC_ARROW);
	playerWindow.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	playerWindow.lpszMenuName = NULL;
	playerWindow.lpszClassName = "playerWindow";
	playerWindow.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&playerWindow))
	{
		MessageBox(NULL, "Could not make a player window", "Error in caption", MB_ICONEXCLAMATION | MB_OK);
	}

	HWND playerOneWindow;
	playerOneWindow = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		"playerWindow",
		"Player One",
		WS_CHILD | WS_VISIBLE | WS_CAPTION,
		50, 50, 250, 300,
		mainWindow, NULL, hInstance, NULL);

	if (playerOneWindow == NULL)
	{
		MessageBox(NULL, "Window Creation Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	HWND playerOneUnitTypeComboBox;
	playerOneUnitTypeComboBox = CreateWindowEx(WS_EX_CLIENTEDGE, "ComboBox", NULL,
		WS_BORDER | WS_VISIBLE |
		WS_CHILD | CBS_DROPDOWNLIST,
		// No size yet--resize after setting image list.
		40,      // Vertical position of Combobox
		5,      // Horizontal position of Combobox
		120,      // Sets the width of Combobox
		1000,    // Sets the height of Combobox
		playerOneWindow,
		NULL,
		hInstance,
		NULL);

	
	SendMessage(playerOneUnitTypeComboBox, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)"Blood Letter");
	SendMessage(playerOneUnitTypeComboBox, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)"Deamonette");
	SendMessage(playerOneUnitTypeComboBox, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)"Plauge bearer");
	SendMessage(playerOneUnitTypeComboBox, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)"Pink Horror");
	
	SendMessage(playerOneUnitTypeComboBox, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);

	HWND playerOneSizeComboBox;
	playerOneSizeComboBox = CreateWindowEx(WS_EX_CLIENTEDGE, "ComboBox", NULL,
		WS_BORDER | WS_VISIBLE |
		WS_CHILD | CBS_DROPDOWNLIST | WS_VSCROLL,
		// No size yet--resize after setting image list.
		40,      // Vertical position of Combobox
		35,      // Horizontal position of Combobox
		50,      // Sets the width of Combobox
		200,    // Sets the height of Combobox
		playerOneWindow,
		NULL,
		hInstance,
		NULL);

	for (int size = 1; size <= 30; size++)
	{
		char buffer[10];
		sprintf(buffer, "%d", size);
		SendMessage(playerOneSizeComboBox, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)buffer);
	}

	SendMessage(playerOneSizeComboBox, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);

	HWND playerTwoWindow;
	playerTwoWindow = CreateWindowEx(WS_EX_CLIENTEDGE,
		"playerWindow",
		"Player Two",
		WS_CHILD | WS_VISIBLE | WS_CAPTION,
		600, 50, 250, 300,
		mainWindow, NULL, hInstance, NULL);

	if (playerTwoWindow == NULL)
	{
		MessageBox(NULL, "Window Creation Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	HWND playerTwoUnitTypeComboBox;
	playerTwoUnitTypeComboBox = CreateWindowEx(WS_EX_CLIENTEDGE, "ComboBox", NULL,
		WS_BORDER | WS_VISIBLE |
		WS_CHILD | CBS_DROPDOWNLIST |WS_VSCROLL,
		// No size yet--resize after setting image list.
		40,      // Vertical position of Combobox
		5,      // Horizontal position of Combobox
		120,      // Sets the width of Combobox
		400,    // Sets the height of Combobox
		playerTwoWindow,
		NULL,
		hInstance,
		NULL);

	


	SendMessage(playerTwoUnitTypeComboBox, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)"Blood Letter");
	SendMessage(playerTwoUnitTypeComboBox, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)"Deamonette");
	SendMessage(playerTwoUnitTypeComboBox, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)"Plauge bearer");
	SendMessage(playerTwoUnitTypeComboBox, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)"Pink Horror");

	SendMessage(playerTwoUnitTypeComboBox, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);

	HWND playerTwoSizeComboBox;
	playerTwoSizeComboBox = CreateWindowEx(WS_EX_CLIENTEDGE, "ComboBox", NULL,
		WS_BORDER | WS_VISIBLE |
		WS_CHILD | CBS_DROPDOWNLIST | WS_VSCROLL,
		// No size yet--resize after setting image list.
		40,      // Vertical position of Combobox
		35,      // Horizontal position of Combobox
		50,      // Sets the width of Combobox
		200,    // Sets the height of Combobox
		playerTwoWindow,
		NULL,
		hInstance,
		NULL);

	for (int size = 1; size <= 30; size++)
	{
		char buffer[10];
		sprintf(buffer, "%d", size);
		SendMessage(playerTwoSizeComboBox, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)buffer);
	}

	SendMessage(playerTwoSizeComboBox, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
	/*
	HWND playerOneContainer;
	playerOneContainer = CreateWindowEx(WS_EX_CLIENTEDGE, "Window", "Player One", WS_VISIBLE | WS_CHILD, 10, 10, 100, 100, mainWindow, NULL, hInstance, NULL);
	*/
	/*
	HWND coolComboBox;
	coolComboBox = CreateWindowEx(WS_EX_CLIENTEDGE, "ComboBox", NULL,
		WS_BORDER | WS_VISIBLE |
		WS_CHILD | CBS_DROPDOWNLIST,
		// No size yet--resize after setting image list.
		10,      // Vertical position of Combobox
		10,      // Horizontal position of Combobox
		50,      // Sets the width of Combobox
		100,    // Sets the height of Combobox
		mainWindow,
		NULL,
		hInstance,
		NULL);

	*/
	/*
	HWND coolButton;
	coolButton = CreateWindowEx(WS_EX_CLIENTEDGE,
		"BUTTON",
		"Okay",
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 100, 100, 100, 100, mainWindow, NULL, (HINSTANCE)GetWindowLong(mainWindow, GWL_HINSTANCE), NULL);
		*/
		/*
		HWND coolButton;
		coolButton = CreateWindow(
			"BUTTON",  // Predefined class; Unicode assumed
			"OK",      // Button text
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles
			10,         // x position
			10,         // y position
			100,        // Button width
			100,        // Button height
			mainWindow,     // Parent window
			NULL,       // No menu.
			(HINSTANCE)GetWindowLong(mainWindow, GWL_HINSTANCE),
			NULL);      // Pointer not needed
		*/
	ShowWindow(mainWindow, nCmdShow);
	UpdateWindow(mainWindow);

	MSG message;

	while (GetMessage(&message, NULL, 0, 0) > 0)
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
	return message.wParam;
	/*WNDCLASSEX wc;
	HWND hwnd;
	MSG Msg;

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	wc.lpszClassName = g_szClassName;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Window Registration Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		g_szClassName,
		"The title of my window",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 240, 120,
		NULL, NULL, hInstance, NULL);

	if (hwnd == NULL)
	{
		MessageBox(NULL, "Window Creation Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&Msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;*/
}