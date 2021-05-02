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

template <typename otherpar=POINT>
cursorPos* cpH(otherpar* pointx) {
	cursorPos cp;
	cp.x = pointx->x;
	cp.y = pointx->y;
	return &cp;
}

template <typename otherpar = POINT>
otherpar* cpH(cursorPos* cp) {
	POINT p;
	p.x = cp->x;
	p.y = cp->y;
}

retGP<BOOL, cursorPos*> getCurrentCursorPos() {
	POINT currentcursorpos;
	retGP<BOOL, cursorPos*> rg;
	rg.a = GetCursorPos(&currentcursorpos);
	rg.b = cpH<POINT>(&currentcursorpos);
	return rg;
}
