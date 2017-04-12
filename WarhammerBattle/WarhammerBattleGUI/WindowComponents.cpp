#include "WindowComponents.h"

namespace WindowComponents
{
	WNDCLASSEX MakeWindowDefinition(WNDPROC eventHandler, const char* className, HINSTANCE parent)
	{
		WNDCLASSEX genericWindow;

		genericWindow.cbSize = sizeof(WNDCLASSEX);
		genericWindow.style = 0;
		genericWindow.lpfnWndProc = eventHandler;
		genericWindow.cbClsExtra = 0;
		genericWindow.cbWndExtra = 0;
		genericWindow.hInstance = parent;
		genericWindow.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		genericWindow.hCursor = LoadCursor(NULL, IDC_ARROW);
		genericWindow.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		genericWindow.lpszMenuName = NULL;
		genericWindow.lpszClassName = className;
		genericWindow.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

		return genericWindow;
	}

	HWND  GenerateWindow(const char* windowClass, const char* windowTitle, HWND parentWindow, HINSTANCE parentInstance, int width, int heigth)
	{
		HWND window;
		window = CreateWindowEx(
			WS_EX_CLIENTEDGE,
			"genericWindow",
			"Warhammer Battle",
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT, width, heigth,
			parentWindow, NULL, parentInstance, NULL);

		return window;
	}

	HWND GeneratePlayerWindow(HWND parentWindow, HINSTANCE parentInstance, int xPosition, int yPosition)
	{
		HWND window;
		window = CreateWindowEx(
			WS_EX_CLIENTEDGE,
			"playerWindow",
			"Player One",
			WS_CHILD | WS_VISIBLE | WS_CAPTION,
			xPosition, yPosition, 250, 300,
			parentWindow, NULL, parentInstance, NULL);

		return window;
	}

	HWND GenerateComboBox(HWND parentWindow, HINSTANCE parentInstance, int xPosition, int yPosition, int width, int heigth)
	{
		HWND comboBox;
		comboBox = CreateWindowEx(WS_EX_CLIENTEDGE, "ComboBox", NULL,
			WS_BORDER | WS_VISIBLE |
			WS_CHILD | CBS_DROPDOWNLIST,
			xPosition, yPosition, width, heigth, parentWindow, NULL, parentInstance, NULL);

		return comboBox;
	}

	HWND GenerataScrollableComboBox(HWND parentWindow, HINSTANCE parentInstance, int xPosition, int yPosition, int width, int height)
	{
		HWND comboBox;
		comboBox = CreateWindowEx(WS_EX_CLIENTEDGE, "ComboBox", NULL,
			WS_BORDER | WS_VISIBLE |
			WS_CHILD | CBS_DROPDOWNLIST | WS_VSCROLL,
			xPosition, yPosition, width, height, parentWindow, NULL, parentInstance, NULL);

		return comboBox;
	}
}