#pragma once

#include "DxLib.h"

#include "core.h"

#define GAUGEWIDTH 200

class Loading
{
private:
	int loading_file_;
public:
	void drawLoadingScreen(int file_num);
	int loadGraphic(int file_num);
};