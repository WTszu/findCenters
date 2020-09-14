#ifndef _DETECTOR
#define _DETECTOR

#include <opencv2/opencv.hpp>
#include <iostream>

class Detector
{
public:
	void set_img(cv::Mat& src);
	std::vector<cv::Point> detect();
	void print();

private:
	cv::Mat _img;
	std::vector<cv::Point> _points;
};

#endif _DETECTOR