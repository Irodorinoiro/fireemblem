#include "attack.h"
void Attack::init()
{
	if (has_to_init)
	{
		has_to_init = false;

		moving_timer_ = 0;
		moving_timer_debug_ = 0;
		paramater_byleth_ = BYLETH_POS_X;
		paramater_edelgard_ = EDELGARD_POS_X;
		// 画像読み取り
		background_atk_ = LoadGraph("picture_atk_illust/background_attack.png");
		byleth0_ = LoadGraph("picture_atk_illust/byleth0.png");
		byleth1_ = LoadGraph("picture_atk_illust/byleth1.png");
		byleth2_ = LoadGraph("picture_atk_illust/byleth2.png");
		byleth3_ = LoadGraph("picture_atk_illust/byleth3.png");
		byleth4_ = LoadGraph("picture_atk_illust/byleth4.png");
		byleth5_ = LoadGraph("picture_atk_illust/byleth5.png");
		byleth6_ = LoadGraph("picture_atk_illust/byleth6.png");
		byleth7_ = LoadGraph("picture_atk_illust/byleth7.png");
		edelgard0_ = LoadGraph("picture_atk_illust/edelgard0.png");
		edelgard1_ = LoadGraph("picture_atk_illust/edelgard1.png");
		edelgard2_ = LoadGraph("picture_atk_illust/edelgard2.png");
		edelgard3_ = LoadGraph("picture_atk_illust/edelgard3.png");
		edelgard4_ = LoadGraph("picture_atk_illust/edelgard4.png");
		edelgard5_ = LoadGraph("picture_atk_illust/edelgard5.png");
		edelgard6_ = LoadGraph("picture_atk_illust/edelgard6.png");
		edelgard7_ = LoadGraph("picture_atk_illust/edelgard7.png");

		if (background_atk_ == -1)
		{
			errorBox("[title.cpp][戦闘背景読み取り]");
			MessageBox(NULL, "画像読み込み失敗", "Error", MB_OK);
		}
		if (byleth0_ == -1 || byleth1_ == -1 || byleth2_ == -1 || byleth3_ == -1 || byleth4_ == -1 || byleth5_ == -1 || byleth6_ == -1 || byleth7_ == -1)
		{
			printf("[title.cpp][byleth piicture読み取り]");
			MessageBox(NULL, "画像読み込み失敗", "Error", MB_OK);
		}
		else
		{
			printf("[title.cpp][byleth piicture読み取り成功]");
		}
	}
}

void Attack::draw()
{
	DrawGraph(0, 0, background_atk_, FALSE);
	DrawGraph(330, 300, byleth0_, TRUE);
	//DrawGraph(BYLETH_POS_X, EDELGARD_POS_Y, byleth0_, TRUE);
	//DrawGraph(EDELGARD_POS_X, EDELGARD_POS_Y, edelgard0_, TRUE);
	DrawFormatString(100, 0, GetColor(WHITE), "moving_timer = %d", moving_timer_);
}

void Attack::atkMotionByleth(int char0, int char1, int char2, int char3, int char4, int char5, int char6, int char7) 
{
//攻撃モーション
	if (moving_timer_ <= BEFORE_ATTACK_FRAME)
	{
		DrawGraph(BYLETH_POS_X, BYLETH_POS_Y, char0, TRUE);
	}
	else if (moving_timer_ <= BEFORE_ATTACK_FRAME + 1)
	{
		DrawGraph(BYLETH_POS_X, BYLETH_POS_Y, char1, TRUE);
	}
	//ジャンプ開始
	else if (moving_timer_ <= BEFORE_ATTACK_FRAME + 2)
	{
		DrawGraph(paramater_byleth_, PARABOLA_BYLETH(paramater_byleth_), char2, TRUE);
		paramater_byleth_ -= 10;
	}
	else if (moving_timer_ <= BEFORE_ATTACK_FRAME + 4)
	{
		DrawGraph(paramater_byleth_, PARABOLA_BYLETH(paramater_byleth_), char4, TRUE);
		paramater_byleth_ -= 10;
	}
	else if (moving_timer_ == BEFORE_ATTACK_FRAME + 5)
	{
		paramater_byleth_ = 620;
		DrawGraph(paramater_byleth_, PARABOLA_BYLETH(paramater_byleth_), char4, TRUE);
		paramater_byleth_ -= 10;
	}
	else if (moving_timer_ <= BEFORE_ATTACK_FRAME + 9)
	{
		DrawGraph(paramater_byleth_, PARABOLA_BYLETH(paramater_byleth_), char4, TRUE);
		paramater_byleth_ -= 8;
	}
	else if (moving_timer_ == BEFORE_ATTACK_FRAME + 10)
	{
		paramater_byleth_ = 495;
		DrawGraph(paramater_byleth_, PARABOLA_BYLETH(paramater_byleth_), char3, TRUE);
		//paramater_ -= 8;
		WaitTimer(1000 / FPS_30);
	}
	else if (moving_timer_ == BEFORE_ATTACK_FRAME + 11)
	{
		paramater_byleth_ = 440;
		DrawGraph(paramater_byleth_, PARABOLA_BYLETH(paramater_byleth_), char5, TRUE);
		WaitTimer(1000 / FPS_30);
	}
	else if (moving_timer_ <= BEFORE_ATTACK_FRAME + 12)
	{
		paramater_byleth_ -= 5;
		DrawGraph(paramater_byleth_, PARABOLA_BYLETH(paramater_byleth_), char6, TRUE);
		WaitTimer(1000 / FPS_30);
	}
	else if (moving_timer_ < AFTER_ATTACK_FRAME)
	{
		DrawGraph(paramater_byleth_, PARABOLA_BYLETH(paramater_byleth_), char7, TRUE);
	}
// 撤退モーション
	else if (moving_timer_ == AFTER_ATTACK_FRAME)
	{
		DrawGraph(paramater_byleth_, PARABOLA_BYLETH(paramater_byleth_), char0, TRUE);
		WaitTimer(800);
	}
	//ジャンプ開始
	else if (moving_timer_ <= AFTER_ATTACK_FRAME + 4)
	{
		DrawGraph(paramater_byleth_, PARABOLA_BYLETH(paramater_byleth_), char1, TRUE);
		paramater_byleth_ += 10;
	}
	else if (moving_timer_ == AFTER_ATTACK_FRAME + 5)
	{
		paramater_byleth_ = 600;
		DrawGraph(paramater_byleth_, PARABOLA_BYLETH(paramater_byleth_), char2, TRUE);
		paramater_byleth_ += 10;
	}
	else if (moving_timer_ <= AFTER_ATTACK_FRAME + 9)
	{
		DrawGraph(paramater_byleth_, PARABOLA_BYLETH(paramater_byleth_), char2, TRUE);
		paramater_byleth_ += 8;
	}
	else if (moving_timer_ == AFTER_ATTACK_FRAME + 10)
	{
		DrawGraph(paramater_byleth_, PARABOLA_BYLETH(paramater_byleth_), char2, TRUE);
		paramater_byleth_ += 8;
		WaitTimer(1000 / FPS_30);
	}
	else if (moving_timer_ == AFTER_ATTACK_FRAME + 11)
	{
		DrawGraph(paramater_byleth_, PARABOLA_BYLETH(paramater_byleth_), char2, TRUE);
		WaitTimer(1000 / FPS_30);
	}
	else if (moving_timer_ <= AFTER_ATTACK_FRAME + 12)
	{
		paramater_byleth_ += 8;
		DrawGraph(paramater_byleth_, PARABOLA_BYLETH(paramater_byleth_), char2, TRUE);
	}
	else if (moving_timer_ <= AFTER_ATTACK_FRAME + 13)
	{
		DrawGraph(BYLETH_POS_X - 3, BYLETH_POS_Y - 3, char1, TRUE);
		}
	else if (moving_timer_ < AFTER_ATTACK_FRAME + 100)
	{
		DrawGraph(BYLETH_POS_X, BYLETH_POS_Y, char0, TRUE);
	}
	DrawFormatString(300, 0, GetColor(WHITE), "[DEBUG] 座標; %f", paramater_byleth_);
	DrawFormatString(300, 50, GetColor(WHITE), "[DEBUG] 座標; %f", PARABOLA_BYLETH(paramater_byleth_));
	++moving_timer_;
	//WaitTimer(1000);
}

void Attack::atkMotionEdelgard(int char0, int char1, int char2, int char3, int char4, int char5, int char6, int char7)
{
#if 0
	DrawBox(paramater_edelgard_, PARABOLA_EDELGARD(paramater_edelgard_), paramater_edelgard_ + 10, PARABOLA_EDELGARD(paramater_edelgard_) + 10, GetColor(WHITE), TRUE);
	--paramater_edelgard_;
#endif

	//攻撃モーション
	if (moving_timer_debug_ <= BEFORE_ATTACK_FRAME)
	{
		DrawGraph(EDELGARD_POS_X, EDELGARD_POS_Y, char0, TRUE);

	}
	else if (moving_timer_debug_ <= BEFORE_ATTACK_FRAME + 1)
	{
		DrawGraph(EDELGARD_POS_X, EDELGARD_POS_Y, char1, TRUE);
	}
	//ジャンプ開始
	else if (moving_timer_debug_ <= BEFORE_ATTACK_FRAME + 2)
	{
		DrawGraph(paramater_edelgard_, PARABOLA_EDELGARD(paramater_edelgard_), char2, TRUE);
		paramater_edelgard_ -= 10;
	}
	else if (moving_timer_debug_ <= BEFORE_ATTACK_FRAME + 4)
	{
		DrawGraph(paramater_edelgard_, PARABOLA_EDELGARD(paramater_edelgard_), char4, TRUE);
		paramater_edelgard_ -= 10;
	}
	else if (moving_timer_debug_ == BEFORE_ATTACK_FRAME + 5)
	{
		paramater_edelgard_ = 540;
		DrawGraph(paramater_edelgard_, PARABOLA_EDELGARD(paramater_edelgard_), char4, TRUE);
		paramater_edelgard_ -= 10;
	}
	else if (moving_timer_debug_ <= BEFORE_ATTACK_FRAME + 9)
	{
		DrawGraph(paramater_edelgard_, PARABOLA_EDELGARD(paramater_edelgard_), char4, TRUE);
		paramater_edelgard_ -= 8;
	}
	else if (moving_timer_debug_ == BEFORE_ATTACK_FRAME + 10)
	{
		paramater_edelgard_ = 370;
		DrawGraph(paramater_edelgard_, PARABOLA_EDELGARD(paramater_edelgard_), char3, TRUE);
		//paramater_ -= 8;
		WaitTimer(1000 / FPS_30);
	}
	else if (moving_timer_debug_ == BEFORE_ATTACK_FRAME + 11)
	{
		paramater_edelgard_ = 350;
		DrawGraph(paramater_edelgard_, PARABOLA_EDELGARD(paramater_edelgard_), char5, TRUE);
		WaitTimer(1000 / FPS_30);
	}
	else if (moving_timer_debug_ <= BEFORE_ATTACK_FRAME + 12)
	{
		paramater_edelgard_ -= 5;
		DrawGraph(paramater_edelgard_, PARABOLA_EDELGARD(paramater_edelgard_), char6, TRUE);
		WaitTimer(1000 / FPS_30);
	}
	else if (moving_timer_debug_ < AFTER_ATTACK_FRAME)
	{
		DrawGraph(paramater_edelgard_, PARABOLA_EDELGARD(paramater_edelgard_), char7, TRUE);
	}
	// 撤退モーション
	else if (moving_timer_debug_ == AFTER_ATTACK_FRAME)
	{
		DrawGraph(paramater_edelgard_, PARABOLA_EDELGARD(paramater_edelgard_), char0, TRUE);
		WaitTimer(800);
	}
	//ジャンプ開始
	else if (moving_timer_debug_ <= AFTER_ATTACK_FRAME + 4)
	{
		DrawGraph(paramater_edelgard_, PARABOLA_EDELGARD(paramater_edelgard_), char1, TRUE);
		paramater_edelgard_ += 10;
	}
	else if (moving_timer_debug_ == AFTER_ATTACK_FRAME + 5)
	{
		paramater_edelgard_ = 530;
		DrawGraph(paramater_edelgard_, PARABOLA_EDELGARD(paramater_edelgard_), char4, TRUE);
		paramater_edelgard_ += 10;
	}
	else if (moving_timer_debug_ <= AFTER_ATTACK_FRAME + 9)
	{
		DrawGraph(paramater_edelgard_, PARABOLA_EDELGARD(paramater_edelgard_), char4, TRUE);
		paramater_edelgard_ += 8;
	}
	else if (moving_timer_debug_ == AFTER_ATTACK_FRAME + 10)
	{
		DrawGraph(paramater_edelgard_, PARABOLA_EDELGARD(paramater_edelgard_), char4, TRUE);
		paramater_edelgard_ += 8;
		WaitTimer(1000 / FPS_30);
	}
	else if (moving_timer_debug_ == AFTER_ATTACK_FRAME + 11)
	{
		paramater_edelgard_ = 600;
		DrawGraph(paramater_edelgard_, PARABOLA_EDELGARD(paramater_edelgard_), char4, TRUE);
		WaitTimer(1000 / FPS_30);
	}
	else if (moving_timer_debug_ <= AFTER_ATTACK_FRAME + 12)
	{
		paramater_edelgard_ += 8;
		DrawGraph(paramater_edelgard_, PARABOLA_EDELGARD(paramater_edelgard_), char4, TRUE);
	}
	else if (moving_timer_debug_ <= AFTER_ATTACK_FRAME + 13)
	{
		DrawGraph(EDELGARD_POS_X - 3, EDELGARD_POS_Y - 3, char1, TRUE);
	}
	else if (moving_timer_debug_ < AFTER_ATTACK_FRAME + 100)
	{
		DrawGraph(EDELGARD_POS_X, EDELGARD_POS_Y, char0, TRUE);
	}
	DrawFormatString(300, 0, GetColor(WHITE), "[DEBUG] 座標; %f", paramater_edelgard_);
	DrawFormatString(300, 50, GetColor(WHITE), "[DEBUG] 座標; %f", PARABOLA_EDELGARD(paramater_edelgard_));
	++moving_timer_debug_;
	//WaitTimer(1000);
}