#pragma once
#ifndef PROYECTOBRICKGAME_BRICK_H
#endif // !1
#define PROYECTOBRICKGAME_BRICK_H
#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include<time.h>
#include <ctime>
#include <conio.h>
#include <chrono>
#include <thread>
using namespace std;

class brick {
	
public:
	brick();

	void board();
	void newline();
	void mapa();
	void carro();
	void manageScore();
	void  level();
	void clearscreen();
	void usleep(__int64 usec);

	void Timer();
	


protected:
	int tmp = 3;

	char map[25][25];
	int y = 17, x = 9;
	int a = 0, b = rand() % 15 + 2;
	int timer = 0;
	int speed = 100;
	bool startup = true; 
	int cashpickedup = 0;
	char obstacle = 219;
	char car = 'X';
	int msec = 0;
	int sec = 0;
	int min = 0;
	int hr = 0;
	int nivel = 0 ;
	int velocidad = 0;
	int score = 0;
	int health = 3;


	



	





};

