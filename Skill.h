#pragma once
#include <string>
#include"TypeEnum.h"

//enum SkillType {
//	Fire = 1, // ��
//	Grass, // Ǯ
//	Water, // ��
//	Electric, // ����
//	Dragon, // �巡��
//	Flying, // ����
//	Ghost, // ��Ʈ
//	Bug, // ����
//	Normal, // �븻
//	Fighting, // ����
//	Dark, // ��
//	Rock // ����
//};

class Skill {
public:
	std::string name;
	int damage;
	int accuracyRate;
	int type;
	//int pp; // ���� ���� ����
};

class Scratch : public Skill {
public:
	Scratch() {
		name = "������";
		damage = 40;
		accuracyRate = 100;
		type = Normal;
	}
};

class Ember : public Skill {
public:
	Ember() {
		name = "�Ҳɼ���";
		damage = 40;
		accuracyRate = 100;
		type = Fire;
	}
};

class PowerUpPunch : public Skill {
public:
	PowerUpPunch() {
		name = "�׷ο���ġ";
		damage = 40;
		accuracyRate = 100;
		type = Fighting;
	}
};

class FlameWheel : public Skill {
public:
	FlameWheel() {
		name = "ȭ���ڵ���";
		damage = 60;
		accuracyRate = 100;
		type = Fire;
	}
};

class Tackle: public Skill {
public:
	Tackle() {
		name = "�����ġ��";
		damage = 40;
		accuracyRate = 100;
		type = Normal;
	}
};

class RazorLeaf : public Skill {
public:
	RazorLeaf() {
		name = "�ٳ�������";
		damage = 40;
		accuracyRate = 95;
		type = Grass;
	}
};

class Bite : public Skill {
public:
	Bite() {
		name = "����";
		damage = 60;
		accuracyRate = 100;
		type = Dark;
	}
};

class Megadrain : public Skill {
public:
	Megadrain() {
		name = "�ް��巹��";
		damage = 40;
		accuracyRate = 100;
		type = Grass;
	}
};

class Pound : public Skill {
public:
	Pound() {
		name = "��ġ��";
		damage = 40;
		accuracyRate = 100;
		type = Normal;
	}
};

class WaterGun : public Skill {
public:
	WaterGun() {
		name = "������";
		damage = 40;
		accuracyRate = 100;
		type = Water;
	}
};

class Peck : public Skill {
public:
	Peck() {
		name = "�ɱ�";
		damage = 35;
		accuracyRate = 100;
		type = Flying;
	}
};

class BubbleBeam : public Skill {
public:
	BubbleBeam() {
		name = "��ǰ����";
		damage = 65;
		accuracyRate = 100;
		type = Water;
	}
};

class QuickAttack : public Skill {
public:
	QuickAttack() : Skill() {
		name = "������ȭ";
		damage = 40;
		accuracyRate = 100;
		type = Normal;
	}
};

class Spark : public Skill {
public:
	Spark() : Skill() {
		name = "����ũ";
		damage = 65;
		accuracyRate = 100;
		type = Electric;
	}
};

class Thunderbolt : public Skill {
public:
	Thunderbolt() : Skill() {
		name = "10����Ʈ";
		damage = 95;
		accuracyRate = 100;
		type = Electric;
	}
};

class Thunder : public Skill {
public:
	Thunder() : Skill() {
		name = "����";
		damage = 120;
		accuracyRate = 70;
		type = Electric;
	}
};

class DragonBreath : public Skill {
public:
	DragonBreath() : Skill() {
		name = "���Ǽ���";
		damage = 60;
		accuracyRate = 100;
		type = Dragon;
	}
};

class DragonClaw : public Skill {
public:
	DragonClaw() : Skill() {
		name = "�巡��ũ��";
		damage = 80;
		accuracyRate = 100;
		type = Dragon;
	}
};

class WingAttack : public Skill {
public:
	WingAttack() : Skill() {
		name = "����ġ��";
		damage = 60;
		accuracyRate = 100;
		type = Flying;
	}
};

class AerialAce : public Skill {
public:
	AerialAce() : Skill() {
		name = "�����ȯ";
		damage = 60;
		accuracyRate = 100;
		type = Flying;
	}
};

class AuraSphere : public Skill {
public:
	AuraSphere() : Skill() {
		name = "�ĵ�ź";
		damage = 90;
		accuracyRate = 100;
		type = Fighting;
	}
};

class AncientPower : public Skill {
public:
	AncientPower() : Skill() {
		name = "��������";
		damage = 60;
		accuracyRate = 100;
		type = Rock;
	}
};

class ShadowForce : public Skill {
public:
	ShadowForce() : Skill() {
		name = "�������̺�";
		damage = 120;
		accuracyRate = 100;
		type = Ghost;
	}
};