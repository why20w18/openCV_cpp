#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int cx = 0;

int main() {

	Mat goruntu = imread("para.jpg");
	resize(goruntu, goruntu, Size(500, 500));
	imshow("ORIJINAL GORUNTU",goruntu);

	//binary cevirme
	cvtColor(goruntu, goruntu, COLOR_BGR2GRAY);

	threshold(goruntu, goruntu, 210, 255, THRESH_BINARY_INV);
	//imshow("BINARY CIKTISI", goruntu);

	//konturlama
	vector<vector<Point>> kontur;
	vector<Vec4i> hie;

	findContours(goruntu, kontur, hie, RETR_EXTERNAL, CHAIN_APPROX_NONE);

	//cevreleme
	RotatedRect dikdortgen;

	for (int i = 0; i < kontur.size(); i++) {

		drawContours(goruntu, kontur, i, Scalar(0, 0, 255), 2);
		dikdortgen = minAreaRect(kontur[i]);
		putText(goruntu, format("%d", i + 1), dikdortgen.center, 2, 2, Scalar(0, 255, 0), 3);
		cout << "sayilan nesne : " << i + 1 << endl;
		cx = i + 1;
	}
	cout << "\033[1;34mTOPLAM NESNE SAYISI : \033[0m" << cx << endl;

	cvtColor(goruntu, goruntu, COLOR_GRAY2BGR);

	imshow("NESNE SAYMASI", goruntu);
	waitKey();
	return 0x0;
}