#include <Windows.h>
#include <iostream>
#include <conio.h>

void Retracer(POINT* mousePos, int delay, int noOfSaves)
{
	std::cout << "DO NOT MOVE/CLICK THE MOUSE NOW!\n\n" << std::endl;

	for (int i = 0; i < noOfSaves; i++)
	{
		Sleep(delay);

		SetCursorPos(mousePos[i].x, mousePos[i].y);

		mouse_event(MOUSEEVENTF_LEFTDOWN, mousePos[i].x, mousePos[i].y, NULL, NULL);
		mouse_event(MOUSEEVENTF_LEFTUP, mousePos[i].x, mousePos[i].y, NULL, NULL);

		std::cout << i + 1 << "th save clicked!\n";
	}
}

int Saver(POINT* mousePos)
{
	std::cout << "Hover the mouse to the desired location and \n press 'k' to start saving mouse positions.\n";
	std::cout << "\nPress 'k' to start saving mouse locations and 'q' to STOP!!!" << std::endl;

	bool quit = true;
	int noOfSaves = 0;

	while (quit)
	{
		if (_kbhit())
		{
			char kbKey = _getch();
			if (kbKey == 'k')
			{
				GetCursorPos(&mousePos[noOfSaves]);
				std::cout << noOfSaves + 1 << " positions saved...\n";
				noOfSaves++;
			}
			if (kbKey == 'q')
				quit = false;
		}
	}

	return noOfSaves;
}

int Delay()
{
	std::cout << "Enter delay between 2 clicks in miliseconds... ";
	int delay;
	std::cin >> delay;

	return delay;
}

int main(int argc, char* argv[])
{
	
	
	char repeat;

	while (true)
	{
		POINT mousePos[100];

		Retracer(mousePos, Delay(), Saver(mousePos));

		std::cout << "\n\nDo this again? (y/n)\n";
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