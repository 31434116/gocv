package gocv

/*
#include <stdlib.h>
#include "munkres.h"
*/
import "C"

type Munkres struct {
	p C.Munkres
}

func NewMunkres() Munkres {
	return Munkres{p: C.Munkres_New()}
}

func (m *Munkres) Solve(src Mat, dst *Mat) {
	C.Munkres_Solve(m.p, src.p, dst.p)
}

func (m *Munkres) Close() {
	C.Munkres_Close(m.p)
}
