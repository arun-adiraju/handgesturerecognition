//opencv
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>
//C
#include <stdio.h>
//C++
#include <iostream>
#include <sstream>

using namespace cv;
using namespace std;

void help();
void processVideo();
void condefects(vector<Vec4i> convexityDefectsSet, vector<Point> mycontour, Mat &original);
void showimgcontours(Mat &threshedimg, Mat &original, char* imageType);
int main1();
