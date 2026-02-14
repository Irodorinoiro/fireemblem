#include "attack.h"
void Attack::init()
{
	if (has_to_init)
	{
		has_to_init = false;

		moving_timer_ = 0;
		test = 750;
		// âÊëúì«Ç›éÊÇË
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
			errorBox("[title.cpp][êÌì¨îwåiì«Ç›éÊÇË]");
			MessageBox(NULL, "âÊëúì«Ç›çûÇ›é∏îs", "Error", MB_OK);
		}
		if (byleth0_ == -1 || byleth1_ == -1 || byleth2_ == -1 || byleth3_ == -1 || byleth4_ == -1 || byleth5_ == -1 || byleth6_ == -1 || byleth7_ == -1)
		{
			printf("[title.cpp][byleth piictureì«Ç›éÊÇË]");
			MessageBox(NULL, "âÊëúì«Ç›çûÇ›é∏îs", "Error", MB_OK);
		}
		else
		{
			printf("[title.cpp][byleth piictureì«Ç›éÊÇËê¨å˜]");
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
		//DrawBox(test, PARABOLA(test), test + 10, PARABOLA(test) + 10, GetColor(WHITE), TRUE);
		
	}
	else if (moving_timer_ <= BEFORE_ATTACK_FRAME + MOTHION_FRAME)
	{
		DrawGraph(CHARACTER_POS_X, CHARACTER_POS_Y, byleth1_, TRUE);
	}
	else if (moving_timer_ <= BEFORE_ATTACK_FRAME + MOTHION_FRAME*2)
	{
		DrawGraph(test, PARABOLA(test), byleth2_, TRUE);
		test -= 10;
	}
	//ÉWÉÉÉìÉväJén
	else if (moving_timer_ <= BEFORE_ATTACK_FRAME + MOTHION_FRAME * 4)
	{
		DrawGraph(test, PARABOLA(test), byleth4_, TRUE);
		test -= 10;
	}
	else if (moving_timer_ <= BEFORE_ATTACK_FRAME + MOTHION_FRAME * 6)
	{
		test = 650;
		DrawGraph(test, PARABOLA(test), byleth4_, TRUE);
		test -= 3;
	}
	else if (moving_timer_ <= BEFORE_ATTACK_FRAME + MOTHION_FRAME * 7)
	{
		DrawGraph(test, PARABOLA(test), byleth3_, TRUE);
		test -= 2;
	}
	else if (moving_timer_ <= BEFORE_ATTACK_FRAME + MOTHION_FRAME * 8)
	{
		DrawGraph(test, PARABOLA(test), byleth5_, TRUE);
		test -= 2;
	}
	else if (moving_timer_ <= BEFORE_ATTACK_FRAME + MOTHION_FRAME * 9)
	{
		DrawGraph(test, PARABOLA(test), byleth6_, TRUE);
		test -= 1;
	}
	else if (moving_timer_ <= BEFORE_ATTACK_FRAME + MOTHION_FRAME * 100)
	{
		DrawGraph(test, PARABOLA(test), byleth7_, TRUE);
	}
#if 0
	else if (moving_timer_ <= BEFORE_ATTACK_FRAME + MOTHION_FRAME * 12)
	{
		DrawGraph(test, PARABOLA(test), byleth5_, TRUE);
	}
	else if (moving_timer_ <= BEFORE_ATTACK_FRAME + MOTHION_FRAME * 13)
	{
		DrawGraph(test, PARABOLA(test), byleth6_, TRUE);
	}
	else if (moving_timer_ <= BEFORE_ATTACK_FRAME + MOTHION_FRAME * 100)
	{
		DrawGraph(test, PARABOLA(test), byleth7_, TRUE);
	}
	else
	{
		DrawGraph(test, PARABOLA(test), byleth7_, TRUE);
	}
#endif

#if 0
	if (moving_timer_ > BEFORE_ATTACK_FRWME)
	{
		//DrawGraph(test, PARABOLA(test), byleth0_, TRUE);
		DrawBox(test, PARABOLA(test), test + 10, PARABOLA(test) + 10, GetColor(WHITE), TRUE);
		test -= 3;
	}
#endif
	DrawFormatString(300, 0, GetColor(WHITE), "ç¿ïW; %f", test);
	DrawFormatString(300, 50, GetColor(WHITE), "ç¿ïW; %f", PARABOLA(test));
	++moving_timer_;
}
