#include "Units.h"

Units::Units(){}

Units::Units(int x, int y, bool color) {
	if(color == 1){
		m_color = 139;
		m_uni = 'O';
	} else {
		m_color = 128;
		m_uni = 'X';
	}
	m_x = x;
	m_y = y;
	m_alive = true;
	
}

void Units::SetDead() {
	m_alive = false;
}
