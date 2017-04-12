#include <Windows.h>

namespace WindowComponents
{
	WNDCLASSEX MakeWindowDefinition(WNDPROC eventHandler, const char* className, HINSTANCE parent);
	HWND  GenerateWindow(const char* windowClass, const char* windowTitle, HWND parentWindow, HINSTANCE parentInstance, int width, int heigth);
	HWND GeneratePlayerWindow(HWND parentWindow, HINSTANCE parentInstance, int xPosition, int yPosition);
	HWND GenerateComboBox(HWND parentWindow, HINSTANCE parentInstance, int xPosition, int yPosition, int width, int heigth);
	HWND GenerataScrollableComboBox(HWND parentWindow, HINSTANCE parentInstance, int xPosition, int yPosition, int width, int height);
}