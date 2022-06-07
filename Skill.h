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

class Scratching : public Skill {
public:
	Scratching() {
		name = "������";
		damage = 40;
		accuracyRate = 100;
	}
};

class FlameBaptism : public Skill {
public:
	FlameBaptism() {
		name = "�Ҳɼ���";
		damage = 40;
		accuracyRate = 100;
	}
};

class GrowPunch : public Skill {
public:
	GrowPunch() {
		name = "�׷ο���ġ";
		damage = 40;
		accuracyRate = 100;
	}
};

class FlameCar : public Skill {
public:
	FlameCar() {
		name = "ȭ���ڵ���";
		damage = 60;
		accuracyRate = 100;
	}
};

class Bumping: public Skill {
public:
	Bumping() {
		name = "�����ġ��";
		damage = 40;
		accuracyRate = 100;
	}
};

class LeafBlade : public Skill {
public:
	LeafBlade() {
		name = "�ٳ�������";
		damage = 40;
		accuracyRate = 95;
	}
};

class Gnaw : public Skill {
public:
	Gnaw() {
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

class Scuffle : public Skill {
public:
	Scuffle() {
		name = "��ġ��";
		damage = 40;
		accuracyRate = 100;
	}
};

class WaterCannon : public Skill {
public:
	WaterCannon() {
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