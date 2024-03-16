#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int olustur = 0, b = 255, g = 255, r = 255;

void mavi(int, void*) {
	b++;
}
void yesil(int, void*) {
	g++;
}
void kirmizi(int, void*) {
	r++;
}

void pencereAc() {


	Mat goruntu = imread("eva.jpg");
	Mat oynandi = goruntu.clone();
	Vec3b pikselYogunluk;

	namedWindow("eva pencere", WINDOW_AUTOSIZE);

	createTrackbar("mavi", "eva pencere", &b, 255, mavi);
	createTrackbar("yesil", "eva pencere", &g, 255, yesil);
	createTrackbar("kirmizi", "eva pencere", &r, 255, kirmizi);

	for (int i = 0; i < oynandi.rows; i++) {
		for (int j = 0; j < oynandi.cols; j++) {

			oynandi.at<Vec3b>(i, j)[0] = oynandi.at<Vec3b>(i, j)[0] + b;
			oynandi.at<Vec3b>(i, j)[1] = oynandi.at<Vec3b>(i, j)[1] + g;
			oynandi.at<Vec3b>(i, j)[2] = oynandi.at<Vec3b>(i, j)[2] + r;
		}
	}

	imshow("eva pencere", oynandi);
}

void pencereYenile(int , void*) {

	if (olustur == 1) {
		//pencere ac
		pencereAc();
	}
	else {
		//pencere kapat
		destroyWindow("eva pencere");
	}

}


int main() {

	namedWindow("pencere_yenile", WINDOW_AUTOSIZE);
	createTrackbar("yenile", "pencere_yenile", &olustur, 1, pencereYenile);

	waitKey();
	return 0x0;

}