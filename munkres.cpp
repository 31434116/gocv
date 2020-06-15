#include "munkres.h"

Munkres Munkres_New()
{
    return new cv::Munkres();
}

void Munkres_Solve(Munkres m, Mat src, Mat dst)
{
    m->solve(*src, *dst);
}

void Munkres_Close(Munkres m)
{
    delete m;
}