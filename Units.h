#pragma once
#include <iostream>
#include <vector>
#include <stdlib.h>
//�̲���� ������� ��������� � �����ί ������ײ ���� �� ����� �������� �������ֲ� ��� ������� Բ����, �����²��� �̲�� ��������� � PLAYER
class Units {
	public:
	int m_x = 0;
	int m_y = 0;
	int m_color = 0;
	bool m_alive = true;
	char m_uni = 'O';
	Units();
	Units(int x, int y, bool color);

	void SetDead();

	virtual ~Units() = default;

	private:

};
