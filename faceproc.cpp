#include "faceproc.h"
#include <clarity.h>
#include <pose.h>

void FaceEvaluate(Mat img, Rect r, Points2f landmark, struct FaceAttribute *attrs)
{
    const cv::Rect rect = cv::Rect(r.x, r.y, r.width, r.height);
    std::vector<cv::Point2f> pts;

    for (size_t i = 0; i < landmark.length; i++)
    {
        pts.push_back(cv::Point2f(landmark.points[i].x, landmark.points[i].y));
    }
    attrs->clarity = evaluate_clarity(*img, rect);
    attrs->lightness = evaluate_lightness(*img, rect);
    //std::cout << "r: " << rect.x << "," << rect.y << "," << rect.width << "," << rect.height << std::endl;
    //std::cout << "clarity:" << attrs->clarity << std::endl;
    evaluate_pose(*img, pts, attrs->roll, attrs->yaw, attrs->pitch);
}
