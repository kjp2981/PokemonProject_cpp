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

class Scratching : public Skill {
public:
	Scratching() {
		name = "할퀴기";
		damage = 40;
		accuracyRate = 100;
	}
};

class FlameBaptism : public Skill {
public:
	FlameBaptism() {
		name = "불꽃세례";
		damage = 40;
		accuracyRate = 100;
	}
};

class GrowPunch : public Skill {
public:
	GrowPunch() {
		name = "그로우펀치";
		damage = 40;
		accuracyRate = 100;
	}
};

class FlameCar : public Skill {
public:
	FlameCar() {
		name = "화염자동차";
		damage = 60;
		accuracyRate = 100;
	}
};

class Bumping: public Skill {
public:
	Bumping() {
		name = "몸통박치기";
		damage = 40;
		accuracyRate = 100;
	}
};

class LeafBlade : public Skill {
public:
	LeafBlade() {
		name = "잎날가르기";
		damage = 40;
		accuracyRate = 95;
	}
};

class Gnaw : public Skill {
public:
	Gnaw() {
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

class Scuffle : public Skill {
public:
	Scuffle() {
		name = "막치기";
		damage = 40;
		accuracyRate = 100;
	}
};

class WaterCannon : public Skill {
public:
	WaterCannon() {
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