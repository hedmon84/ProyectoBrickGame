#include "stdafx.h"
#include "brick.h"



brick::brick() {

}


void brick:: newline() {
	
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	


}

void brick::Timer() {

	while (true) {
		if (msec == 1000)
		{
			++sec;
			msec = 0;
		}

		cout << "        " << msec;
		msec++;
		system("cls");

		std::this_thread::sleep_for(std::chrono::microseconds(1000000));



	}


	

	




}

void brick::clearscreen() {
	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);


}

void brick::mapa() {
	
	for (int i = 0; i < 20; i++) {
		for (int j = 0;j < 20; ++j) {

			map[i][0] = '|';
			map[i][18] = '|';
			map[i][j] = ' ';

		
		}
	}
}

void brick::carro() {

	mapa();
	srand(time(0));
	map[y][x] = car;
	for (;;) {
		clearscreen();
		//forma del carro
		map[y][x] = 'X';
		map[y][x + 1] = '|';
		map[y][x - 1] = '|';
		map[y + 1][x - 1] = 'o';
		map[y + 1][x + 1] = 'o';
		map[y - 1][x - 1] = 'o';
		map[y - 1][x + 1] = 'o';

		//Generar obstaculos
		map[a][b] = ' ';
		map[a][b] = ' ';
		map[a][b + 1] = ' ';
		map[a][b - 1] = ' ';
		map[a + 1][b - 1] = ' ';
		map[a + 1][b + 1] = ' ';
		map[a - 1][b - 1] = ' ';
		map[a - 1][b + 1] = ' ';
		++a;
		map[a][b] = obstacle;
		map[a][b + 1] = obstacle;
		map[a][b - 1] = obstacle;
		map[a + 1][b - 1] = obstacle;
		map[a + 1][b + 1] = obstacle;
		map[a - 1][b - 1] = obstacle;
		map[a - 1][b + 1] = obstacle;
		if (a > 20) {
			a = 0;
			b = rand() % 15 + 2;
		}

		//Corro el mapa
		for (int i = 0; i < 20; ++i) {
				

			for (int j = 0; j < 20; ++j) {
				
				cout << map[i][j];
				if (j >= 19) {
					cout << endl;
				}
			}
		}
	
		
		
		if (startup) {
			_getch();
			startup = false;

		}

		velocidad = timer +20;

		cout << "    Time: " << timer + (cashpickedup * 10);
		cout << "    vida: "<<   health;
		cout << "     Nivel:  "  << nivel;
		cout << "    velocidad :  "<< velocidad;
		cout << "Puntos :  " <<score;


		//reloj

		


			
		
		//moves the car to the left

		bool carrro;
		if (GetAsyncKeyState(VK_UP)) {

			carrro = true;
			speed -= 10;

		}
		else carrro = false;



	

			



		if (GetAsyncKeyState(VK_LEFT)) {
			if (map[y][x - 3] == obstacle) {
				goto lost;
			}
			else if (map[y][x - 3] != '|') {
				map[y][x] = ' ';
				map[y][x + 1] = ' ';
				map[y][x - 1] = ' ';
				map[y - 1][x - 1] = ' ';
				map[y + 1][x - 1] = ' ';
				map[y + 1][x + 1] = ' ';
				map[y - 1][x + 1] = ' ';
				x -= 3;
				map[y][x] = 'X';
				map[y][x + 1] = '|';
				map[y][x - 1] = '|';
				map[y + 1][x - 1] = 'o';
				map[y + 1][x + 1] = 'o';
				map[y - 1][x - 1] = 'o';
				map[y - 1][x + 1] = 'o';
			}
		}
		//moves the car to the right
		if (GetAsyncKeyState(VK_RIGHT)) {
			if (map[y][x + 3] == obstacle) {
				goto lost;
			}
			else if (map[y][x + 3] != '|') {
				map[y][x] = ' ';
				map[y][x + 1] = ' ';
				map[y][x - 1] = ' ';
				map[y + 1][x - 1] = ' ';
				map[y + 1][x + 1] = ' ';
				map[y - 1][x - 1] = ' ';
				map[y - 1][x + 1] = ' ';
				x += 3;
				map[y][x] = 'X';
				map[y][x + 1] = '|';
				map[y][x - 1] = '|';
				map[y + 1][x - 1] = 'o';
				map[y + 1][x + 1] = 'o';
				map[y - 1][x - 1] = 'o';
				map[y - 1][x + 1] = 'o';
			}
		}

		
		//checks if the car crashed

		 if (map[y - 2][x] == obstacle || map[y - 2][x - 1] == obstacle || map[y - 2][x + 1] == obstacle) {
		lost:
			cin.get();
			health = health - 1;

			vidas += 1;

			cout << "\n\nYou crashed!\n" << endl;
			y = 17, x = 9;
			system("pause");
			system("cls");

			
			for (int i = 16; i < 19; i++) {
				for (int j = 2; j < 18; ++j) {

					map[i][j] = ' ';

				} 
			}
			if (health == 0) {

				
				cout << "\n\nYou Lost!\n" << endl;
				health == 0;
				break;
			}

						
		 }

		

		 if (carrro == true) {
			 speed = 10;
		 }
		 else speed = 60;
		
		
		//speeds up the obstacles each time the player gets another 100 points
		++timer;
		if (timer == 20 || timer == 40 || timer == 60 || timer == 80 || timer == 100 || timer == 120 || timer == 140 || timer == 160 || timer == 170 || timer == 180) {
			speed -= 10;

		}
		Sleep(speed);

		manageScore();
		level();
		
		
		
	

			
	
	}
}

void brick::manageScore() {

	if (timer == 20) {
		score += 20;
	}
	if (timer == 60) {
		score += 40;
	}

	if (timer == 80) {
		score += 60;
	}

	if (timer == 100) {
		score += 80;
	}

	if (timer == 120) {
		score += 100;
	}

	if (timer == 140) {
		score += 130;
	}

	if (timer == 160) {
		score += 20;
	}

	if (timer == 180) {
		score += 170;
	}

	if (timer == 200) {
		score += 220;
	}

	if (timer == 210) {
		score += 280;
	}

	



}

void brick::level() {


	if (timer == 150) {
		nivel += 1;
	}
	if (timer == 250) {
		nivel += 1;
		
	}

	if (timer == 350) {
		nivel += 1;
	}

	if (timer == 400) {
		nivel += 1;
	}

	if (timer == 500) {
		nivel += 1;
	}

	if (timer == 550) {
		nivel += 1;
	}

	if (timer == 600) {
		nivel += 1;
	}

	if (timer == 700) {
		nivel += 170;
	}

	if (timer == 800) {
		nivel += 1;
	}

	if (timer == 900) {
		nivel += 1;
	}
	
	if (nivel < 1000) {
		nivel == 0;
	}



}

void brick::board() {

	cout << "Estadisticas de juego \n";
	cout << "Puntos conseguidos : " << score << endl;
	cout << "Velocidad alcanzada: " << velocidad << endl;
	cout << "muertas: " << vidas << endl;
	cout << endl ;

}
