#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

bool osTespit = false;

#ifdef _WIN32
    osTespit = true;
#endif

using namespace std;
using namespace cv;

int main(){

    string konumGirme;

    if(osTespit){
        cout << "\033[1;31mKullanilan Isletim Sistemi : Windows\033[0m" << endl;
        konumGirme = "\033[1;32mornek gorsel konumu : C:\\Users\\KULLANICI_ADI\\gorseller\\ocr.jpg\033[0m";
    }
    
    else if(!osTespit) {
        cout << "\033[1;31mKullanilan Isletim Sistemi : Linux\033[0m" << endl;
        konumGirme = "\033[1;32mornek gorsel konumu : /home/KULLANICI_ADI/gorseller/ocr.jpg\033[0m";
    }
    String path;
    cout << konumGirme << endl << "GORSEL KONUMU >>>";
    cin >>path;

    Mat goruntu = imread(path);
    
    if(goruntu.empty()){
    cerr << "\n\n---goruntu yuklenemedi goruntu konumunu tekrar kontrol edin---\n\n" << endl; 
    return -1;
    }
    
    imshow("GORSEL",goruntu);
    waitKey(0);
    
    cvtColor(goruntu,goruntu,COLOR_BGR2GRAY);
    
    tesseract::TessBaseAPI base;

    //sudo apt install tesseract-ocr-tur
    base.Init(NULL,"tur",tesseract::OEM_LSTM_ONLY);
    base.SetPageSegMode(tesseract::PSM_AUTO);

    //data,sutun,satir,kanal_sayisi = 1 gray , 
    base.SetImage(goruntu.data , goruntu.cols , goruntu.rows , 1 , goruntu.cols * 1);

    cout << endl << "\033[1;36mGORUNTUDEN CIKARTILAN METIN :\033[0m\n" << base.GetUTF8Text() << endl;

    cout << "\033[1;31mevet/hayir\033[0m\n\033[1;36mcikartilan metini txt olarak kaydetmek ister misiniz >>\033[0m";
    string secim;
    cin >> secim; 

    if(secim == "evet"){

        cout << "\033[1;32mtxt dosyasini kaydetmek istediginz konumu dosya adi ve uzantisiyla beraber girin >>\033[0m";
        cin >> path;

        ofstream dosya(path);
        dosya << base.GetUTF8Text() << endl;
        dosya.close();
        cout << "dosya kaydedildi ..." << endl;
        return 0x0;
    }
    else if(secim == "hayir"){
        cout << "cikis yapiliyor ..." << endl;
        return 0x1;
    }

}