#include "DxLib.h"

#include "core.h"
#include "key.h"
#include "game_manager.h"
#include "opening.h"
#include "title.h"
#include "mode_select.h"
#include "attack.h"

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Opening opening;
	Title title;
	ModeSelect mode_select;
	Attack attack;
	GameManager game;

	SetOutApplicationLogValidFlag(FALSE);
	SetWaitVSyncFlag(TRUE);
	
	if (DxLib_Init() == -1)
	{
		errorBox("初期化時に予期せぬエラーが発生しました．");
		return -1;
	}

	if (ChangeWindowMode(TRUE) == -1)
	{
		errorBox("ウィンドウモード遷移時に予期せぬエラーが発生しました．");
		return -1;
	}
	SetGraphMode(WIDTH_X, WIDTH_Y, 32);
	SetWindowSize(WIDTH_X, WIDTH_Y);
	SetDrawScreen(DX_SCREEN_BACK);
	SetMainWindowText(TITLE_TEXT);

	Scene game_state = Scene::TITLE;

	if (gameInit() == -1)
	{
		errorBox("初期化時に予期せぬエラーが発生しました．");
		//return -1;
	}

	while (ProcessMessage() == 0)
	{
		checkKeyState();
		FPS(FPS_30);

		if (ClearDrawScreen() == -1)
		{
			return -1;
		}

		switch (game_state)
		{
		case Scene::OPENING:
			opening.init();
			opening.update(game_state);
			opening.draw();
			break;

			// タイトル画面（初期画面）
		case Scene::TITLE:
			title.init();
			title.update(game_state);
			title.draw();
			break;

		case Scene::MODE_SELECT:
			mode_select.init();
			mode_select.update(game_state);
			mode_select.draw();
			break;

		case Scene::EXTRA:
			//game_state = game.Extra();
			break;

		case Scene::SCENE1:
			break;

		case Scene::MAP:
			break;

		case Scene::ATTACK:
			attack.init();
			attack.draw();
			//attack.atkMotionByleth(attack.byleth0_, attack.byleth1_, attack.byleth2_, attack.byleth3_, attack.byleth4_, attack.byleth5_, attack.byleth6_, attack.byleth7_);
			attack.atkMotionEdelgard(attack.edelgard0, attack.edelgard1, attack.edelgard2, attack.edelgard3, attack.edelgard4, attack.edelgard5, attack.edelgard6, attack.edelgard7);
			break;
		case Scene::GAME_END:
			DxLib_End();
			return 0;
		}

		DrawFormatString(0, 0, GetColor(WHITE), "%d", (int)GetFPS());

		if (ScreenFlip() == -1)
		{
			errorBox("裏画面の表画面への反映時に予期せぬエラーが発生しました．");
			return -1;
		}
	}

	DxLib_End();
	return 0;
}