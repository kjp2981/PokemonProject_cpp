#pragma once
#include <string>

using namespace std;

class Skill {
public:
	string name;
	int damage;
	int accuracyRate;
	//int pp; // ���� ���� ����
};

class Scratch : public Skill {
public:
	Scratch() {
		name = "������";
		damage = 40;
		accuracyRate = 100;
	}
};

class Ember : public Skill {
public:
	Ember() {
		name = "�Ҳɼ���";
		damage = 40;
		accuracyRate = 100;
	}
};

class PowerUpPunch : public Skill {
public:
	PowerUpPunch() {
		name = "�׷ο���ġ";
		damage = 40;
		accuracyRate = 100;
	}
};

class FlameWheel : public Skill {
public:
	FlameWheel() {
		name = "ȭ���ڵ���";
		damage = 60;
		accuracyRate = 100;
	}
};

class Tackle: public Skill {
public:
	Tackle() {
		name = "�����ġ��";
		damage = 40;
		accuracyRate = 100;
	}
};

class RazorLeaf : public Skill {
public:
	RazorLeaf() {
		name = "�ٳ�������";
		damage = 40;
		accuracyRate = 95;
	}
};

class Bite : public Skill {
public:
	Bite() {
		name = "����";
		damage = 60;
		accuracyRate = 100;
	}
};

class Megadrain : public Skill {
public:
	Megadrain() {
		name = "�ް��巹��";
		damage = 40;
		accuracyRate = 100;
	}
};

class Pound : public Skill {
public:
	Pound() {
		name = "��ġ��";
		damage = 40;
		accuracyRate = 100;
	}
};

class WaterGun : public Skill {
public:
	WaterGun() {
		name = "������";
		damage = 40;
		accuracyRate = 100;
	}
};

class Peck : public Skill {
public:
	Peck() {
		name = "�ɱ�";
		damage = 35;
		accuracyRate = 100;
	}
};

class BubbleBeam : public Skill {
public:
	BubbleBeam() {
		name = "��ǰ����";
		damage = 65;
		accuracyRate = 100;
	}
};