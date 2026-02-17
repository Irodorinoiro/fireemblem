#include "loading.h"

void Loading::drawLoadingScreen(int file_num)
{
	DrawString(0, 0, "Now Loading ...", GetColor(WHITE));

	// ゲージの全体をピンクで描画
	DrawBox(0, 32, GAUGEWIDTH, 56, GetColor(128, 128, 128), TRUE);

	// 現時点で読み込み終わっている分を白色で描画
	DrawBox(0, 32, loading_file_ * GAUGEWIDTH / file_num, 56, GetColor(PINK), TRUE);
}

int Loading::loadGraphic(int file_num)
{
	for (loading_file_ = 0; loading_file_ < file_num; ++loading_file_)
	{
		//GrHandle[loading_file_] = LoadGraph("Test1.bmp");

		// ２０個読み込み終わる毎に読み込み中画面を一回更新する
		if (loading_file_ % 20 == 0)
		{
			// 画面の初期化
			ClearDrawScreen();

			// 読み込み中画面を描画
			drawLoadingScreen(file_num);

			// 裏画面の内容を表画面に反映
			ScreenFlip();

			// メッセージ処理
			if (ProcessMessage() != 0) break;
		}

	}
	return 0;
}