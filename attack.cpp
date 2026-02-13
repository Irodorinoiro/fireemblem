#include "attack.h"
void Attack::init()
{
	if (has_to_init)
	{
		has_to_init = false;

		// ‰æ‘œ“Ç‚İæ‚è
		background_atk = LoadGraph("background_attack.png");
		byleth0 = LoadGraph("picture_atk_illust/byleth0.png");
		if (background_atk == -1)
		{
			errorBox("[title.cpp][í“¬”wŒi“Ç‚İæ‚è]");
		}
	}
}

void Attack::draw()
{
	DrawGraph(0, 0, background_atk, FALSE);
	DrawGraph(800, 300, byleth0, TRUE);
}