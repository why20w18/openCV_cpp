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
				<< to_string(b) + " " 
				<< to_string(g) + " " 
				<< to_string(r) + " " << endl;
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