#pragma once

#include "DxLib.h"
#include "core.h"

/// <summary>
/// ボタンを制御するクラス
/// </summary>
class Button
{
private:
	char* m_text;
	int m_font_size;
	int diff_x = -50;
	int diff_y = -5;

	bool is_to_right = true;

	unsigned int m_arrow_img;
public:
	/// <summary>
	/// 矢印の画像を読み込む
	/// </summary>
	/// <param name="">ファイルパス</param>
	void LoadArrowImage(const char* file_path);

	/// <summary>
	/// 矢印の描画
	/// </summary>
	void DrawArrow();

	void FontDraw(int size, int x, int y, const char* sentence);
};