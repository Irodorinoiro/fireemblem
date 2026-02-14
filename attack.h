#pragma once

#include "core.h"

class Attack
{
public:
	void init();
	void draw();
	void atkMotionByleth(int B0, int B1, int B2, int B3, int B4, int B5, int B6, int B7);

	// background picture
	int background_atk_;

	// attack motion picture
	int byleth0_;
	int byleth1_;
	int byleth2_;
	int byleth3_;
	int byleth4_;
	int byleth5_;
	int byleth6_;
	int byleth7_;
	int edelgard0_;
	int edelgard1_;
	int edelgard2_;
	int edelgard3_;
	int edelgard4_;
	int edelgard5_;
	int edelgard6_;
	int edelgard7_;
	int hubert0_;
	int hubert1_;
	int hubert2_;
	int hubert3_;
	int hubert4_;
	int hubert5_;
	int hubert6_;
	int hubert7_;
	//void update(Scene& scene);
private:
	unsigned int moving_timer_;
	float paramater_;
};

