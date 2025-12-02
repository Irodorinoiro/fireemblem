#include "button.h"

void  Button::LoadArrowImage(const char* file_path)
{
	m_arrow_img = LoadGraph(file_path);
}

void Button::DrawArrow()
{
	if (/*m_cursor % m_num_button == m_order*/true)
	{
		if (is_to_right)
		{
			++diff_x;
			if (diff_x == -45)
			{
				is_to_right = false;
			}
		}
		else
		{
			--diff_x;
			if (diff_x == -55)
			{
				is_to_right = true;
			}
		}
		// DrawGraph(m_x + diff_x, m_y + diff_y, m_arrow_img, TRUE);
	}
}

void Button::FontDraw(int size, int x, int y, const char* sentence)
{
	SetFontSize(size);
	unsigned int a = GetColor(BLUE);
	DrawFormatString(x, y, a, "%s", sentence);
}
