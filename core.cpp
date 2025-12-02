#include "core.h"

#include <Windows.h>

bool has_to_init = true;
LPCSTR font_path = "SawarabiMincho-Regular.ttf";
int title_illust;

void errorBox(const std::string str)
{
	const HWND hwnd = GetMainWindowHandle();
	MessageBox(hwnd, str.c_str(), "予期せぬエラーが発生しました．", MB_OK | MB_ICONERROR);
}

int gameInit()
{
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) {
	}
	else {
		errorBox("フォント読み込み時に予期せぬエラーが発生しました．");
		return -1;
	}
	
	if (ChangeFont("Sawarabi Mincho", DX_CHARSET_DEFAULT) == -1)
	{
		errorBox("フォント読み込み時に予期せぬエラーが発生しました．");
		return -1;
	}

	title_illust = LoadGraph("gazo_gamedx/title_illust.png");
	if (title_illust == -1)
	{
		errorBox("画像の読み込み時に予期せぬエラーが発生しました．");
		return -1;
	}

	return 0;
}
