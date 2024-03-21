#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int cx = 1;

int main() {

	Mat goruntu = imread("dik.png");

	//binary goruntu
	cvtColor(goruntu, goruntu, COLOR_BGR2GRAY);

	//canny kenarlari tespit edip gradient yaptigindan dolayi threshold yerine tercih edildi
	Canny(goruntu, goruntu, 200, 250);

	//line tespit
	vector<Vec4i> cikti;
	HoughLinesP(goruntu, cikti, 1, CV_PI / 180, 20, 120, 200);

	//line tespit edildi
	cvtColor(goruntu, goruntu, COLOR_GRAY2BGR);

	//tespit edilen yerelere line cek
	for (int i = 0; i < cikti.size(); i++) {

		line(goruntu, Point(cikti[i][0], cikti[i][1]), Point(cikti[i][2], cikti[i][3]), Scalar(0, 255, 0), 2);
		cout << "\033[2;36mtespit edilen cizgi sayisi :\033[0m" << cx << endl;
		cx++;
		imshow("anlik", goruntu);
		waitKey(500);
		destroyWindow("anlik");
		
	}

	imshow("son hali", goruntu);
	waitKey();
	return 0x0;
}