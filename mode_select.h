#pragma once

#include "DxLib.h"

#include "core.h"

#define NUM_MODE_SELECT_BUTTON 10

class ModeSelect
{
private:
	int m_title_illust;
	int m_cursor = 3;

public:
	int init();

	void update(Scene& scene);

	void draw();
};
