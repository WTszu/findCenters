#include "Detector.hpp"

int main() {
	cv::Mat src = cv::imread("test.png", cv::IMREAD_COLOR);
	if (src.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	Detector d;
	d.set_img(src);
	d.detect();
	d.print();

	cv::waitKey(0);
	return 0;
}
