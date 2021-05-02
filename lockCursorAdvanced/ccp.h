#pragma once
#include "includes.h"
typedef struct cursorPos {
public:
	int x;
	int y;
};

//RETGP allows 2 return values!
template <typename ab, typename bb>
struct retGP {
public:
	ab a;
	bb b;
};

cursorPos* cpH(POINT* pointx) {
	cursorPos cp;
	cp.x = pointx->x;
	cp.y = pointx->y;
	return &cp;
}

POINT* cpH(cursorPos* cp) {
	POINT p;
	p.x = cp->x;
	p.y = cp->y;
}

retGP<BOOL, cursorPos*> getCurrentCursorPos() {
	POINT currentcursorpos;
	retGP<BOOL, cursorPos*> rg;
	rg.a = GetCursorPos(&currentcursorpos);
	rg.b = cpH(&currentcursorpos);
	return rg;
}
