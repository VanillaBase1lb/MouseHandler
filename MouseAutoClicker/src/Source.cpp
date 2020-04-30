#include <iostream>
#include <Windows.h>


void MouseClicker(POINT& mousePos, int timeDelay, int clickCount)
{
	for (int i = 0; i < clickCount; i++)
	{
		mouse_event(MOUSEEVENTF_LEFTDOWN, mousePos.x, mousePos.y, NULL, NULL);
		mouse_event(MOUSEEVENTF_LEFTUP, mousePos.x, mousePos.y, NULL, NULL);
		Sleep(timeDelay);
	}
}

int main(int argc, char* argv[])
{
	while (true)
	{
		std::cout << "How many clicks do you want? :\n";
		int clickCount;
		std::cin >> clickCount;

		std::cout << "Time interval between 2 clicks(in miliseconds) :\n";
		int timeDelay;
		std::cin >> timeDelay;

		std::cout << "Keep your mouse on target and hit enter to execute\n";

		POINT mousePos;
		GetCursorPos(&mousePos);

		std::cin.get();
		std::cin.get();


		MouseClicker(mousePos, timeDelay, clickCount);

		std::cout << "Do this again? (y/n)\n";
		char repeat;
		std::cin >> repeat;

		switch (repeat)
		{
		case 'y':
			system("cls");
			break;
		case 'Y':
			system("cls");
			break;
		default:
			return 0;
		}
	}

	return 0;
}