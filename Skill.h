#pragma once
#include <string>

using namespace std;

class Skill {
public:
	string name;
	int damage;
	int accuracyRate;
	//int pp; // 추후 개발 예정
};

class Scratch : public Skill {
public:
	Scratch() {
		name = "할퀴기";
		damage = 40;
		accuracyRate = 100;
	}
};

class Ember : public Skill {
public:
	Ember() {
		name = "불꽃세례";
		damage = 40;
		accuracyRate = 100;
	}
};

class PowerUpPunch : public Skill {
public:
	PowerUpPunch() {
		name = "그로우펀치";
		damage = 40;
		accuracyRate = 100;
	}
};

class FlameWheel : public Skill {
public:
	FlameWheel() {
		name = "화염자동차";
		damage = 60;
		accuracyRate = 100;
	}
};

class Tackle: public Skill {
public:
	Tackle() {
		name = "몸통박치기";
		damage = 40;
		accuracyRate = 100;
	}
};

class RazorLeaf : public Skill {
public:
	RazorLeaf() {
		name = "잎날가르기";
		damage = 40;
		accuracyRate = 95;
	}
};

class Bite : public Skill {
public:
	Bite() {
		name = "물기";
		damage = 60;
		accuracyRate = 100;
	}
};

class Megadrain : public Skill {
public:
	Megadrain() {
		name = "메가드레인";
		damage = 40;
		accuracyRate = 100;
	}
};

class Pound : public Skill {
public:
	Pound() {
		name = "막치기";
		damage = 40;
		accuracyRate = 100;
	}
};

class WaterGun : public Skill {
public:
	WaterGun() {
		name = "물대포";
		damage = 40;
		accuracyRate = 100;
	}
};

class Peck : public Skill {
public:
	Peck() {
		name = "쪼기";
		damage = 35;
		accuracyRate = 100;
	}
};

class BubbleBeam : public Skill {
public:
	BubbleBeam() {
		name = "거품광선";
		damage = 65;
		accuracyRate = 100;
	}
};