#pragma once

#include "core.h"

class Attack
{
public:
	void init();
	void draw();
	void atkMotionByleth(int char0, int char1, int char2, int char3, int char4, int char5, int char6, int char7);
	void atkMotionEdelgard(int char0, int char1, int char2, int char3, int char4, int char5, int char6, int char7);

	// background picture
	int background_atk;

	// attack motion picture
	int byleth0;
	int byleth1;
	int byleth2;
	int byleth3;
	int byleth4;
	int byleth5;
	int byleth6;
	int byleth7;
	int edelgard0;
	int edelgard1;
	int edelgard2;
	int edelgard3;
	int edelgard4;
	int edelgard5;
	int edelgard6;
	int edelgard7;
	//void update(Scene& scene);
private:
	unsigned int moving_timer_;
	unsigned int moving_timer_debug_;
	float paramater_byleth_;
	float paramater_edelgard_;
};

