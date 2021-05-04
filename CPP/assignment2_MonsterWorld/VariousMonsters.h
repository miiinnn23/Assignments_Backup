#ifndef __VARIOUS_MONSTERS_H__
#define __VARIOUS_MONSTERS_H__

#include "Monster.h"

/*
 * 모든 몬스터는 이동 경로 사이에 존재하는 아이템은 획들 할 수 없다.
 * 오직 자신이 그 턴에 최종적으로 도착한 위치의 아이템만 획득 할 수 있다.
 */

// 몬스터의 기본 이동 동작을 따른다. (9가지 경우의 수 이동)
class Zombie : public Monster
{
public:
	Zombie(string n = "Zombie", string i = "Z", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Zombie()
	{
		cout << " Zombie";
	}
};

// 가로 또는 세로로만 이동 한다 (4가지 경우의 수 이동)
class Vampire : public Monster
{
public:
	Vampire(string n = "Vampire", string i = "V", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Vampire() { cout << " Vampire"; }

	void move(vector<vector<int> > &map, int maxx, int maxy)
	{
		q = p;

		if(dist < 20) {
			int caseNum = rand() % 4 + 1;
			if(caseNum == 1)    p = p + Point(0, -1);       // ↑
			else if(caseNum == 2)   p = p + Point(1, 0);    // →
			else if(caseNum == 3)   p = p + Point(0, 1);    // ↓
			else	p = p + Point(-1, 0);  				    // ←
			
			clip(maxx, maxy);
		}
		eat(map);
	}
};

// 순간이동을 할 수 있다. 매 이동턴 마다 화면 내의 랜덤한 한 지점으로 이동 한다. (제자리 포함)
class KGhost : public Monster
{
public:
	KGhost(string n = "KGhost", string i = "G", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~KGhost() { cout << " KGhost"; }

	void move(vector<vector<int> > &map, int maxx, int maxy)
	{
		q = p;

		if(dist < 20) {
			int xPos = rand() % maxx;
			int yPos = rand() % maxy;
			p = Point(xPos , yPos);
		}
		eat(map);
	}
};

// 가로 또는 세로 방향으로만 이동 할 수 있다.
// 한 칸 또는 두 칸을 이동 할 수 있다. (제자리에 머무를 수는 없다.)
class Jiangshi : public Monster
{
	bool bHori;

public:
	// bHori는 horizontal 이동 여부이다.
	// 이 값이 true 이면 가로방향으로만, false 이면 세로방향으로만 이동 할 수 있다.
	Jiangshi(string n = "Jiangshi", string i = "J", int x = 0, int y = 0, bool bH = true)
		: Monster(n, i, x, y), bHori(bH) {}
	~Jiangshi() { cout << " Jiangshi"; }

	void move(vector<vector<int> > &map, int maxx, int maxy)
	{
		q = p;
		
		if(dist < 20) {
			int caseNum = rand() % 4 + 1;
			if(bHori == false) { // false
				if(caseNum == 1)    p = p + Point(0, -1);       // ↑
				else if(caseNum == 2)   p = p + Point(0, -2);   // ↑↑
				else if(caseNum == 3)   p = p + Point(0, 1);    // ↓
				else	p = p + Point(0, 2);  				    // ↓↓
			}
			else{ // true
				if(caseNum == 1)    p = p + Point(1, 0);        // →
				else if(caseNum == 2)   p = p + Point(2, 0);    // →→
				else if(caseNum == 3)   p = p + Point(-1, 0); 	// ←
				else	p = p + Point(-2, 0);  				    // ←←
			}
			clip(maxx, maxy);
		}
		eat(map);
	}
};

#endif