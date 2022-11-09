#pragma once
#include <iostream>
#include <vector>
#include <stdlib.h>
//гл╡мхрх опхмжхо бхбедеммъ г опнярн╞ оепедюв╡ ╡мтх мю а╡кэь пнбхмемс ╡мтнплюж╡ч юкъ йнкэнпс т╡цспх, лнфкхб╡ярэ гл╡мх йннпдхмюр с PLAYER
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
