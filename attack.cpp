#include "attack.h"
void Attack::init()
{
	if (has_to_init)
	{
		has_to_init = false;

		moving_timer_ = 0;
		paramater_ = 750;
		// ‰æ‘œ“Ç‚İæ‚è
		background_atk_ = LoadGraph("picture_atk_illust/background_attack.png");
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
	DrawGraph(330, 300, byleth0_, TRUE);
	DrawFormatString(100, 0, GetColor(WHITE), "moving_timer = %d", moving_timer_);
}

void Attack::atkMotionByleth(int B0, int B1, int B2, int B3, int B4, int B5, int B6, int B7) 
{
	//DrawGraph(800, 300, byleth0_, TRUE);
	if (moving_timer_ <= BEFORE_ATTACK_FRAME)
	{
		DrawGraph(CHARACTER_POS_X, CHARACTER_POS_Y, byleth0_, TRUE);
		
	}
	else if (moving_timer_ <= BEFORE_ATTACK_FRAME + 1)
	{
		DrawGraph(CHARACTER_POS_X, CHARACTER_POS_Y, byleth1_, TRUE);
	}
	else if (moving_timer_ <= BEFORE_ATTACK_FRAME + 2)
	{
		DrawGraph(paramater_, PARABOLA(paramater_), byleth2_, TRUE);
		paramater_ -= 10;
	}
	//ƒWƒƒƒ“ƒvŠJn
	else if (moving_timer_ <= BEFORE_ATTACK_FRAME + 4)
	{
		DrawGraph(paramater_, PARABOLA(paramater_), byleth4_, TRUE);
		paramater_ -= 10;
	}
	else if (moving_timer_ == BEFORE_ATTACK_FRAME + 5)
	{
		paramater_ = 620;
		DrawGraph(paramater_, PARABOLA(paramater_), byleth4_, TRUE);
		paramater_ -= 10;
	}
	else if (moving_timer_ <= BEFORE_ATTACK_FRAME + 9)
	{
		DrawGraph(paramater_, PARABOLA(paramater_), byleth4_, TRUE);
		paramater_ -= 8;
	}
	else if (moving_timer_ == BEFORE_ATTACK_FRAME + 10)
	{
		DrawGraph(paramater_, PARABOLA(paramater_), byleth3_, TRUE);
		paramater_ -= 8;
		WaitTimer(1000 / FPS_30);
	}
	else if (moving_timer_ == BEFORE_ATTACK_FRAME + 11)
	{
		paramater_ = 435;
		DrawGraph(paramater_, PARABOLA(paramater_), byleth5_, TRUE);
		WaitTimer(1000 / FPS_30);
	}
	else if (moving_timer_ <= BEFORE_ATTACK_FRAME + 12)
	{
		DrawGraph(paramater_, PARABOLA(paramater_), byleth6_, TRUE);
		paramater_ -= 2;
		WaitTimer(1000 / FPS_30);
	}
	else if (moving_timer_ <= BEFORE_ATTACK_FRAME + 100)
	{
		DrawGraph(paramater_, PARABOLA(paramater_), byleth7_, TRUE);
		WaitTimer(1000 / FPS_30);
	}
	DrawFormatString(300, 0, GetColor(WHITE), "À•W; %f", paramater_);
	DrawFormatString(300, 50, GetColor(WHITE), "À•W; %f", PARABOLA(paramater_));
	++moving_timer_;
	//WaitTimer(1000);
}
