#include "Detector.hpp"

void Detector::set_img(cv::Mat& src) {
	cvtColor(src, src, CV_RGB2GRAY);
	GaussianBlur(src, src, cv::Size(3, 3), 0, 0);
	//blur(graySrc, graySrc, Size(3, 3));
	//medianBlur(graySrc, graySrc, 5);
	cv::Canny(src, src, 130, 255);
	//cv::threshold(src, src, 130, 255, THRESH_BINARY);
	src.copyTo(Detector::_img);
}

std::vector<cv::Point> Detector::detect() {
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierachy;
	findContours(Detector::_img, contours, hierachy, CV_RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE, cv::Point(0, 0));

	std::vector<cv::Moments> contourMomments(contours.size());
	for (int i = 0; i < contours.size(); i++) {
		contourMomments[i] = moments(contours[i], false);
		Detector::_points.push_back(cv::Point(contourMomments[i].m10 / contourMomments[i].m00, contourMomments[i].m01 / contourMomments[i].m00));
	}
	return Detector::_points;
}

void Detector::print() {
	for (int i = 0; i < Detector::_points.size(); i++) {
		printf("( %d , %d )\n", Detector::_points[i].x, Detector::_points[i].y);
	}
}
