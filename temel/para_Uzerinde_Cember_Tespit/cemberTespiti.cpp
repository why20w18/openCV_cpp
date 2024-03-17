#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {

	Mat goruntu = imread("lira.jpg");
	imshow("madeni lira", goruntu);

	//griye ceviriyorum
	cvtColor(goruntu, goruntu, COLOR_BGR2GRAY);

	//filtreleme gerekli tum cemberleri tam olarak algilayamadi
	morphologyEx(goruntu, goruntu, MORPH_GRADIENT, getStructuringElement(MORPH_RECT, Size(3, 3)), Point(-1, -1), 2);

	//binary cevir
	Canny(goruntu, goruntu, 200, 250);

	//circle tespit
	vector<Vec3f> cikti; //3 float kanal var
	HoughCircles(goruntu, cikti, HOUGH_GRADIENT,1,100);

	/*
	* dp degeri varsayilan 1
	* min dist = 2 cember arasi minimum mesafe
	*/


	cvtColor(goruntu, goruntu, COLOR_GRAY2BGR);
	for (int i = 0; i < cikti.size(); i++) {
		Point cemberMerkezi(cvRound(cikti[i][0]), cvRound(cikti[i][1]));
		float yaricap = cvRound(cikti[i][2]);

		circle(goruntu, cemberMerkezi, yaricap, Scalar(0, 255, 0), 3);

	}

	imshow("tespit sonrasi cikti", goruntu);

	waitKey();
	return 0x0;
}