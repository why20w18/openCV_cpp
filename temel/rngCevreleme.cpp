#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int iterasyon = 0;

int main() {

	Mat goruntu(500, 500, CV_8UC3, Scalar::all(0));

	RNG& sayi = theRNG();

	cout << "\033[1;31mcikis icin q tusuna basili tutun\033[0m" << endl;

	while (true) {

		int val = sayi.uniform(1, 255);
		
		vector<Point> noktalar;

		//rastgele nokta olustur vektorde depola
		for (int i = 0; i < val; i++) {
			Point nokta;
			nokta.x = sayi.uniform(goruntu.cols / 5 , goruntu.cols * 3 /4);
			nokta.y = sayi.uniform(goruntu.rows / 5 , goruntu.rows * 3 / 4 );

			noktalar.push_back(nokta);
		}

		//dikdortgen cizdir etrafina
		Point2f dikdortgenKose[4];
		RotatedRect dikdorgen = minAreaRect(noktalar);
		dikdorgen.points(dikdortgenKose);

		//ucgen cizdir etrafina
		vector<Point2f> ucKose;
		minEnclosingTriangle(noktalar, ucKose);

		//circle ciz etrafina
		Point2f merkezNokta;
		float yaricap = 0;
		minEnclosingCircle(noktalar, merkezNokta, yaricap);

		//circle ile kucuk noktalar olustur vektorde depoladigin noktalara gore
		int noktaYaricap = 12;
		for (int j = 0; j < val; j++) {

			circle(goruntu, noktalar[j], noktaYaricap , Scalar(255, 255, 255), 1);

		}
		
		//dikdorgen cizmek icin line ciz
		for (int r = 0; r < 4; r++) {

			line(goruntu, dikdortgenKose[r], dikdortgenKose[(r + 1) % 4], Scalar(255, 0, 0));

		}

		//ucgen cizmek icin line olustur
		for (int t = 0; t < 3; t++) {

			line(goruntu, ucKose[t], ucKose[(t + 1) % 3], Scalar(0, 0, 255));

		}

		//circle ciz noktalarin etrafina
		circle(goruntu, merkezNokta, cvRound(yaricap), Scalar(0, 255, 0), 1);

		iterasyon++;
		cout << "suan olusturulan nokta sayisi : " << val << endl << "\033[1;36miterasyon sayisi : \033[0m" << iterasyon << endl;
		imshow("rng noktalari", goruntu);
		waitKey(0);
		goruntu = Scalar::all(0);

		if (waitKey(100) == 'q') break;

	}


	return 0x0;
}