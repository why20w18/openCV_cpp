/*#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {

	Mat goruntu = imread("tux.png");

	//olceklendir
	resize(goruntu, goruntu, Size(500, 500));

	//randu(goruntu, goruntu, Scalar(0, 0, 0), Scalar(255, 255, 255));

	namedWindow("tux_foto", WINDOW_AUTOSIZE);
	imshow("tux_foto", goruntu);

	waitKey();

	return 0x0;
}
*/
//-------------------------------------------------------------------------------------
/*#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {

	Mat goruntu = imread("tux.png");

	//resize 800kb 
	resize(goruntu, goruntu, Size(500, 500));
	
	//uzanti degistirme 40 kb
	imwrite("tux.jpeg",goruntu);

	//vektor ile kalite degistirme 8kb oldu
	vector<int> kalite;
	kalite.push_back(IMWRITE_JPEG_QUALITY);
	kalite.push_back(1);
	imwrite("tux.jpg", goruntu,kalite);

	//pencere acma
	namedWindow("tux_foto", WINDOW_AUTOSIZE);
	imshow("tux_foto", goruntu);

	waitKey();
	return 0x0;
}
*/
//-----------------------------------------------------------
/*#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {

	Mat goruntu = imread("tux.png");

	//resize
	resize(goruntu, goruntu, Size(500, 500));

	//goruntu formati
	imwrite("tux.bmp", goruntu);

	//gorun kalitesi

	vector<int> quality;
	quality.push_back(IMWRITE_JPEG_QUALITY);
	quality.push_back(1);

	imwrite("tux.jpg", goruntu, quality);

	//pencere
	namedWindow("tux_fot", WINDOW_AUTOSIZE);
	imshow("tux_fot", goruntu);


	waitKey();
	return 0x0;
}
*/
//---------------------------------------------------------------
/*
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {

	Mat goruntu = imread("tux.png");

	//resize
	resize(goruntu, goruntu, Size(500, 500));
	imshow("bgr hali", goruntu);


	//cvtColor hsv renk yogunlugu
	cvtColor(goruntu, goruntu, COLOR_BGR2HSV);
	imshow("hsv hali", goruntu);

	waitKey();
	return 0x0;
}
*/
//---------------------------------------------------------------
/*
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {

	VideoCapture videoInput("bladeRunner2049.mp4");

	if (videoInput.isOpened()){
		int i = 0;
		while (1) {
			Mat kare;
			videoInput.read(kare);
			imshow("blade runner 2049 edit", kare);
			i++;
			cout << "kare sayisi: " << i << endl;
			if (waitKey(100) == 'y') break;
		}
	}

	return 0x0;
}
*/
//------------------------------------------------------------------------------
/*
#include <opencv2/opencv.hpp>
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace cv;
using namespace this_thread;
using namespace chrono;

int main() {

	VideoCapture kamera(0);
	stringstream fpsDegeri;
	double fps;

	if (!kamera.isOpened()) {
		cout << "kamera bulunamadi !" << endl;
		return -1;
	}

	while (true) {
		Mat kare;
		bool isFrameRead = kamera.read(kare);
		if (!isFrameRead) {
			cout << "kameradan gelen goruntu okunmuyor !" << endl;
			return -2;
		}
		fps = kamera.get(CAP_PROP_FPS);
		fpsDegeri.str(" ");
		fpsDegeri.clear();
		fpsDegeri << "fps" << fps;
		putText(kare, fpsDegeri.str(), Point(50, 50), 1, 2, Scalar(0, 255, 0), 2);
		imshow("kamera", kare);
		if (waitKey(100) == 'y') break;
	}
	return 0x0;
}
*/
//-------------------------------------------------------------------------------------
/*
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {

	VideoCapture kamera(0);
	stringstream fpsSS;
	double fps;

	if (!kamera.isOpened()) {
		cout << "kamera bulunamadi !" << endl;
		return -1;
	}

	while (true) {

		Mat kare;

		bool isRead = kamera.read(kare);
		
		if (!isRead) {
			cout << "kare okunamiyor !" << endl;
			return -2;
		}
		fps = kamera.get(CAP_PROP_FPS);
		fpsSS.str(" ");
		fpsSS.clear();
		fpsSS << "fps : " << fps;
		putText(kare, fpsSS.str(), Point(10, 45), 1, 2, Scalar(0, 255, 0), 2);

		imshow("kamera penceresi", kare);

		if (waitKey(100) == 'y') break;

	}

	return 0x0;
}
*/
//----------------------------------------------------------------------
/*
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {

	VideoCapture kamera(0);
	double fps;
	stringstream fpsval;

	if (!kamera.isOpened()) {
		cout << "kamera bulunamadi !" << endl;
		return -1;
	}

	while (1) {

		Mat frame;

		bool okuma = kamera.read(frame);

		if (!okuma) {
			cout << "frame okumasi yapilamiyor !" << endl;
			return -2;
		}

		fps = kamera.get(CAP_PROP_FPS);
		fpsval.str(" ");
		fpsval.clear();
		fpsval << "fps : " << fps;
		putText(frame, fpsval.str(), Point(10, 45), 1, 2, Scalar(0, 255, 0), 2);

		imshow("kamera penceresi", frame);

		if (waitKey(100) == 'q') {
			cout << "cikis yapildi" << endl;
			break;
		}

	}
	return 0x0;
}
*/
/*
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {

	VideoCapture video("bladeRunner2049.mp4");
	int kareSayisi = 0;
	

	if (!video.isOpened()) {
		cout << "video konumda degil !" << endl;
		return -1;
	}

	while (1) {
		Mat frame;
		string mesaj = "kare sayisi: " + to_string(kareSayisi);

		video.read(frame);
		
		putText(frame, mesaj, Point(25, 50), 1, 2, Scalar(0, 255, 0), 3);
		kareSayisi++;
		
		imshow("video penceresi", frame);

		if (waitKey(100) == 'q') {
			cout << "cikis yapildi !" << endl;
			return -2;
		}
	}
	return 0x0;
}
*/
//webcamde isaretlenmis 100x200 noktasindaki pikselin yogunlugunu konsola veren program
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {

	VideoCapture kamera(0);
	stringstream fpsVal;
	double fps,pikselYogunlugu;

	//renk uzayini sec
	int sec;
	bool renkUzayi;

	cout << "0-COLOR_BGR2GRAY" << endl << "1-VARSAYILAN 3 BIT" << endl << "secim >>";
	cin >> sec;
	
	renkUzayi = (sec > 0) ? false : true;

	if (!kamera.isOpened()) {
		cout << "kamera bulunamadi !" << endl;
		return -1;
	}

	while (1) {

		Mat kare;
		
		//kare matrisine atama ve okuma kontrolu
		bool okuma = kamera.read(kare);

		if (!okuma) {
			cout << "kameradan kare okunamiyor !" << endl;
			return -2;
		}

		//fps degerini kameradan cek
		fps = kamera.get(CAP_PROP_FPS);
		fpsVal.str(" ");
		fpsVal.clear();
		fpsVal << "fps : " << fps;
		putText(kare, fpsVal.str(), Point(25, 45), 1, 2, Scalar(0, 255, 0), 2);

		//4 X isareti ile pikselin etrafini cevir 100,200 = noktasinda piksel yogunlugu okunacak
		//(kare, "hedef piksel", Point(75, 190), FONT_HERSHEY_COMPLEX , 0.8, Scalar(0, 0, 255), 3);
		
		putText(kare, "x", Point(100, 210), 1, 0.5, Scalar(0, 0, 255), 2);
		putText(kare, "x", Point(100, 190), 1, 0.5, Scalar(0, 0, 255), 2);
		putText(kare, "x", Point(90, 200), 1, 0.5, Scalar(0, 0, 255), 2);
		putText(kare, "x", Point(110, 200), 1, 0.5, Scalar(0, 0, 255), 2);

		//renk uzayini griye cevir yada normal tut
		if(renkUzayi) cvtColor(kare, kare, COLOR_BGR2GRAY);
		
		//hedef 100,200 noktasinin piksel yogunluk degeri
		if (renkUzayi) { //GRI RENK ISE
			pikselYogunlugu = kare.at<uchar>(100, 200);
			cout << "GRI RENKLERDE = TEK KANALDA = 100x200 adresindeki piksel yogunlugu: " << pikselYogunlugu << endl;
		}
		else { //Blue-Green-Red RENKLERDEYSE
			Vec3b renkYogunlugu3Kanal = kare.at<Vec3b>(100, 200);
			int b = renkYogunlugu3Kanal[0];
			int g = renkYogunlugu3Kanal[1];
			int r = renkYogunlugu3Kanal[2];

			cout << "BGR RENKLERDE = 3 KANALDA = 100x200 adresindeki piksel yogunlugu: " 
				<< to_string(r) + " " 
				<< to_string(g) + " " 
				<< to_string(b) + " " << endl;
		}

		//okunan kareyi pencereye basma
		imshow("kamera penceresi", kare);

		//cikmak icin
		if (waitKey(100) == 'q') {
			cout << "kamera penceresi kapatildi !" << endl;
			break;
		}

	}
	return 0x0;
}
