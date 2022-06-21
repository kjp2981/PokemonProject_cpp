#pragma once
#include <string>
#include"TypeEnum.h"

//enum SkillType {
//	Fire = 1, // 불
//	Grass, // 풀
//	Water, // 물
//	Electric, // 번개
//	Dragon, // 드래곤
//	Flying, // 비행
//	Ghost, // 고스트
//	Bug, // 벌레
//	Normal, // 노말
//	Fighting, // 격투
//	Dark, // 악
//	Rock // 바위
//};

class Skill {
public:
	std::string name;
	int damage;
	int accuracyRate;
	int type;
	//int pp; // 추후 개발 예정
};

class Scratch : public Skill {
public:
	Scratch() {
		name = "할퀴기";
		damage = 40;
		accuracyRate = 100;
		type = Normal;
	}
};

class Ember : public Skill {
public:
	Ember() {
		name = "불꽃세례";
		damage = 40;
		accuracyRate = 100;
		type = Fire;
	}
};

class PowerUpPunch : public Skill {
public:
	PowerUpPunch() {
		name = "그로우펀치";
		damage = 40;
		accuracyRate = 100;
		type = Fighting;
	}
};

class FlameWheel : public Skill {
public:
	FlameWheel() {
		name = "화염자동차";
		damage = 60;
		accuracyRate = 100;
		type = Fire;
	}
};

class Tackle: public Skill {
public:
	Tackle() {
		name = "몸통박치기";
		damage = 40;
		accuracyRate = 100;
		type = Normal;
	}
};

class RazorLeaf : public Skill {
public:
	RazorLeaf() {
		name = "잎날가르기";
		damage = 40;
		accuracyRate = 95;
		type = Grass;
	}
};

class Bite : public Skill {
public:
	Bite() {
		name = "물기";
		damage = 60;
		accuracyRate = 100;
		type = Dark;
	}
};

class Megadrain : public Skill {
public:
	Megadrain() {
		name = "메가드레인";
		damage = 40;
		accuracyRate = 100;
		type = Grass;
	}
};

class Pound : public Skill {
public:
	Pound() {
		name = "막치기";
		damage = 40;
		accuracyRate = 100;
		type = Normal;
	}
};

class WaterGun : public Skill {
public:
	WaterGun() {
		name = "물대포";
		damage = 40;
		accuracyRate = 100;
		type = Water;
	}
};

class Peck : public Skill {
public:
	Peck() {
		name = "쪼기";
		damage = 35;
		accuracyRate = 100;
		type = Flying;
	}
};

class BubbleBeam : public Skill {
public:
	BubbleBeam() {
		name = "거품광선";
		damage = 65;
		accuracyRate = 100;
		type = Water;
	}
};

class QuickAttack : public Skill {
public:
	QuickAttack() : Skill() {
		name = "전광석화";
		damage = 40;
		accuracyRate = 100;
		type = Normal;
	}
};

class Spark : public Skill {
public:
	Spark() : Skill() {
		name = "스파크";
		damage = 65;
		accuracyRate = 100;
		type = Electric;
	}
};

class Thunderbolt : public Skill {
public:
	Thunderbolt() : Skill() {
		name = "10만볼트";
		damage = 95;
		accuracyRate = 100;
		type = Electric;
	}
};

class Thunder : public Skill {
public:
	Thunder() : Skill() {
		name = "번개";
		damage = 120;
		accuracyRate = 70;
		type = Electric;
	}
};

class DragonBreath : public Skill {
public:
	DragonBreath() : Skill() {
		name = "용의숨결";
		damage = 60;
		accuracyRate = 100;
		type = Dragon;
	}
};

class DragonClaw : public Skill {
public:
	DragonClaw() : Skill() {
		name = "드래곤크루";
		damage = 80;
		accuracyRate = 100;
		type = Dragon;
	}
};

class WingAttack : public Skill {
public:
	WingAttack() : Skill() {
		name = "날개치기";
		damage = 60;
		accuracyRate = 100;
		type = Flying;
	}
};

class AerialAce : public Skill {
public:
	AerialAce() : Skill() {
		name = "제비반환";
		damage = 60;
		accuracyRate = 100;
		type = Flying;
	}
};

class AuraSphere : public Skill {
public:
	AuraSphere() : Skill() {
		name = "파동탄";
		damage = 90;
		accuracyRate = 100;
		type = Fighting;
	}
};

class AncientPower : public Skill {
public:
	AncientPower() : Skill() {
		name = "원시의힘";
		damage = 60;
		accuracyRate = 100;
		type = Rock;
	}
};

class ShadowForce : public Skill {
public:
	ShadowForce() : Skill() {
		name = "섀도다이브";
		damage = 120;
		accuracyRate = 100;
		type = Ghost;
	}
};