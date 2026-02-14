#include "attack.h"
void Attack::init()
{
	if (has_to_init)
	{
		has_to_init = false;

		moving_timer_ = 0;
		// ‰æ‘œ“Ç‚İæ‚è
		background_atk_ = LoadGraph("background_attack.png");
		byleth0_ = LoadGraph("picture_atk_illust/byleth0.png");
		byleth1_ = LoadGraph("picture_atk_illust/byleth1.png");
		byleth2_ = LoadGraph("picture_atk_illust/byleth2.png");
		byleth3_ = LoadGraph("picture_atk_illust/byleth3.png");
		byleth4_ = LoadGraph("picture_atk_illust/byleth4.png");
		byleth5_ = LoadGraph("picture_atk_illust/byleth5.png");
		byleth6_ = LoadGraph("picture_atk_illust/byleth6.png");
		byleth7_ = LoadGraph("picture_atk_illust/byleth7.png");
		if (background_atk_ == -1)
		{
			errorBox("[title.cpp][í“¬”wŒi“Ç‚İæ‚è]");
			MessageBox(NULL, "‰æ‘œ“Ç‚İ‚İ¸”s", "Error", MB_OK);
		}
		if (byleth0_ == -1 || byleth1_ == -1 || byleth2_ == -1 || byleth3_ == -1 || byleth4_ == -1 || byleth5_ == -1 || byleth6_ == -1 || byleth7_ == -1)
		{
			printf("[title.cpp][byleth piicture“Ç‚İæ‚è]");
			MessageBox(NULL, "‰æ‘œ“Ç‚İ‚İ¸”s", "Error", MB_OK);
		}
		else
		{
			printf("[title.cpp][byleth piicture“Ç‚İæ‚è¬Œ÷]");
		}
	}
}

void Attack::draw()
{
	DrawGraph(0, 0, background_atk_, FALSE);
	DrawGraph(300, 300, byleth0_, TRUE);
	DrawFormatString(100, 0, GetColor(WHITE), "moving_timer = %d", moving_timer_);
}

void Attack::atkMotionByleth(int B0, int B1, int B2, int B3, int B4, int B5, int B6, int B7) 
{
	//DrawGraph(800, 300, byleth0_, TRUE);
	if (moving_timer_ <= 120)
	{
		DrawGraph(800, 300, byleth0_, TRUE);
	}
	else
	{
		DrawGraph(800, 300, byleth5_, TRUE);
	}
	++moving_timer_;
}