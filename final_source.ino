// 
// 01_LED_Blink
// 1個（0番目）のLEDが1秒おきに白色に点滅（Blink）する
// 
#include <Adafruit_NeoPixel.h>  //ライブラリAdafruit NeoPixelをインクルード

// テープLEDに接続するピンの番号（DIGITAL OUTピンであれば、どのピンを選択してもOK）
#define LED_PIN    6

// How many NeoPixels are attached to the Arduino?
//  （使用するテープについている光らせたい）RGB LEDの個数
#define LED_COUNT 64

// Adafruit_NeoPixel型の　「strip（(布・板などの)細長いきれ，一片 ）」という名前の変数を宣言している
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
// 最初のパラメータはテープ中のLEDの個数（今回のワークショップでは4個使用している）
// （切り取り線でカットしたり、自分ではんだづけして延長したりして増減できる）
// 2番目のパラメータは　LEDデータ通信に使用するピン番号　6
// 3番目のパラメータは NeoPixelの製品タイプを指定（Pixel type flags, add together as needed:）
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

// right button
const int RIGHT = 1;
bool right = false;
const int LEFT = 4;
bool left = false;
int what_face = 0;

int leftnum = 0;
int rightnum = 0;
bool lefton = false;
bool righton = false;
bool leftpressed = false;
bool rightpressed = false;
bool buttonpressed = false;
int randint = random(0, 2);


void still(){
  strip.setPixelColor(0 ,strip.Color(255, 239, 1));
  strip.setPixelColor(1 ,strip.Color(255, 239, 1));
  strip.setPixelColor(2 ,strip.Color(255, 239, 1));
  strip.setPixelColor(3 ,strip.Color(255, 239, 1));
  strip.setPixelColor(4 ,strip.Color(255, 239, 1));
  strip.setPixelColor(5 ,strip.Color(255, 239, 1));
  strip.setPixelColor(6 ,strip.Color(255, 239, 1));
  strip.setPixelColor(7 ,strip.Color(255, 239, 1));
  
  strip.setPixelColor(8 ,strip.Color(255, 239, 1));
  strip.setPixelColor(9 ,strip.Color(255, 239, 1));
  strip.setPixelColor(10 ,strip.Color(0, 0, 0));
  strip.setPixelColor(11 ,strip.Color(0, 0, 0));
  strip.setPixelColor(12 ,strip.Color(0, 0, 0));
  strip.setPixelColor(13 ,strip.Color(0, 0, 0));
  strip.setPixelColor(14 ,strip.Color(255, 239, 1));
  strip.setPixelColor(15 ,strip.Color(255, 239, 1));
  
  strip.setPixelColor(16 ,strip.Color(255, 239, 1));
  strip.setPixelColor(17 ,strip.Color(0, 0, 0));
  strip.setPixelColor(18 ,strip.Color(255, 239, 1));
  strip.setPixelColor(19 ,strip.Color(255, 239, 1));
  strip.setPixelColor(20 ,strip.Color(255, 239, 1));
  strip.setPixelColor(21 ,strip.Color(255, 239, 1));
  strip.setPixelColor(22 ,strip.Color(0, 0, 0));
  strip.setPixelColor(23 ,strip.Color(255, 239, 1));
  
  strip.setPixelColor(24 ,strip.Color(255, 239, 1));
  strip.setPixelColor(25 ,strip.Color(255, 239, 1));
  strip.setPixelColor(26 ,strip.Color(255, 239, 1));
  strip.setPixelColor(27 ,strip.Color(255, 239, 1));
  strip.setPixelColor(28 ,strip.Color(255, 239, 1));
  strip.setPixelColor(29 ,strip.Color(255, 239, 1));
  strip.setPixelColor(30 ,strip.Color(255, 239, 1));
  strip.setPixelColor(31 ,strip.Color(255, 239, 1));
  
  strip.setPixelColor(32 ,strip.Color(255, 239, 1));
  strip.setPixelColor(33 ,strip.Color(0, 0, 0));
  strip.setPixelColor(34 ,strip.Color(0, 0, 0));
  strip.setPixelColor(35 ,strip.Color(255, 239, 1));
  strip.setPixelColor(36 ,strip.Color(255, 239, 1));
  strip.setPixelColor(37 ,strip.Color(0, 0, 0));
  strip.setPixelColor(38 ,strip.Color(0, 0, 0));
  strip.setPixelColor(39 ,strip.Color(255, 239, 1));
  
  strip.setPixelColor(40 ,strip.Color(255, 239, 1));
  strip.setPixelColor(41 ,strip.Color(0, 0, 0));
  strip.setPixelColor(42 ,strip.Color(255, 255, 255));
  strip.setPixelColor(43 ,strip.Color(255, 239, 1));
  strip.setPixelColor(44 ,strip.Color(255, 239, 1));
  strip.setPixelColor(45 ,strip.Color(0, 0, 0));
  strip.setPixelColor(46 ,strip.Color(255, 255, 255));
  strip.setPixelColor(47 ,strip.Color(255, 239, 1));
  
  strip.setPixelColor(48 ,strip.Color(255, 239, 1));
  strip.setPixelColor(49 ,strip.Color(255, 239, 1));
  strip.setPixelColor(50 ,strip.Color(255, 239, 1));
  strip.setPixelColor(51 ,strip.Color(255, 239, 1));
  strip.setPixelColor(52 ,strip.Color(255, 239, 1));
  strip.setPixelColor(53 ,strip.Color(255, 239, 1));
  strip.setPixelColor(54 ,strip.Color(255, 239, 1));
  strip.setPixelColor(55 ,strip.Color(255, 239, 1));

  strip.setPixelColor(56 ,strip.Color(255, 239, 0));
  strip.setPixelColor(57 ,strip.Color(0, 0, 0));
  strip.setPixelColor(58 ,strip.Color(0, 0, 0));
  strip.setPixelColor(59 ,strip.Color(255, 239, 0));
  strip.setPixelColor(60 ,strip.Color(255, 239, 0));
  strip.setPixelColor(61 ,strip.Color(0, 0, 0));
  strip.setPixelColor(62 ,strip.Color(0, 0, 0));
  strip.setPixelColor(63 ,strip.Color(255, 239, 0));
  }


void smile(){
  strip.setPixelColor(0 ,strip.Color(255, 239, 1));
  strip.setPixelColor(1 ,strip.Color(255, 255, 255));
  strip.setPixelColor(2 ,strip.Color(255, 255, 255));
  strip.setPixelColor(3 ,strip.Color(255, 255, 255));
  strip.setPixelColor(4 ,strip.Color(255, 255, 255));
  strip.setPixelColor(5 ,strip.Color(255, 255, 255));
  strip.setPixelColor(6 ,strip.Color(255, 255, 255));
  strip.setPixelColor(7 ,strip.Color(255, 239, 0));
  
  strip.setPixelColor(8 ,strip.Color(255, 255, 255));
  strip.setPixelColor(9 ,strip.Color(150, 100, 70));
  strip.setPixelColor(10 ,strip.Color(255, 100, 100));
  strip.setPixelColor(11 ,strip.Color(255, 100, 100));
  strip.setPixelColor(12 ,strip.Color(255, 100, 100));
  strip.setPixelColor(13 ,strip.Color(255, 100, 100));
  strip.setPixelColor(14 ,strip.Color(150, 130, 130));
  strip.setPixelColor(15 ,strip.Color(255, 255, 255));
  
  strip.setPixelColor(16 ,strip.Color(150, 130, 130));
  strip.setPixelColor(17 ,strip.Color(255, 100, 100));
  strip.setPixelColor(18 ,strip.Color(255, 100, 100));
  strip.setPixelColor(19 ,strip.Color(255, 100, 100));
  strip.setPixelColor(20 ,strip.Color(255, 100, 100));
  strip.setPixelColor(21 ,strip.Color(255, 100, 100));
  strip.setPixelColor(22 ,strip.Color(255, 100, 100));
  strip.setPixelColor(23 ,strip.Color(150, 130, 130));
  
  strip.setPixelColor(24 ,strip.Color(255, 255, 255));
  strip.setPixelColor(25 ,strip.Color(255, 255, 255));
  strip.setPixelColor(26 ,strip.Color(255, 255, 255));
  strip.setPixelColor(27 ,strip.Color(255, 255, 255));
  strip.setPixelColor(28 ,strip.Color(255, 255, 255));
  strip.setPixelColor(29 ,strip.Color(255, 255, 255));
  strip.setPixelColor(30 ,strip.Color(255, 255, 255));
  strip.setPixelColor(31 ,strip.Color(255, 255, 255));
  
  strip.setPixelColor(32 ,strip.Color(255, 239, 1));
  strip.setPixelColor(33 ,strip.Color(255, 239, 1));
  strip.setPixelColor(34 ,strip.Color(255, 239, 1));
  strip.setPixelColor(35 ,strip.Color(255, 239, 1));
  strip.setPixelColor(36 ,strip.Color(255, 239, 1));
  strip.setPixelColor(37 ,strip.Color(255, 239, 1));
  strip.setPixelColor(38 ,strip.Color(255, 239, 1));
  strip.setPixelColor(39 ,strip.Color(255, 239, 1));
  
  strip.setPixelColor(40 ,strip.Color(0, 0, 0));
  strip.setPixelColor(41 ,strip.Color(255, 239, 1));
  strip.setPixelColor(42 ,strip.Color(0, 0, 0));
  strip.setPixelColor(43 ,strip.Color(255, 239, 0));
  strip.setPixelColor(44 ,strip.Color(255, 239, 0));
  strip.setPixelColor(45 ,strip.Color(0, 0, 0));
  strip.setPixelColor(46 ,strip.Color(255, 239, 1));
  strip.setPixelColor(47 ,strip.Color(0, 0, 0));
  
  strip.setPixelColor(48 ,strip.Color(255, 239, 0));
  strip.setPixelColor(49 ,strip.Color(0, 0, 0));
  strip.setPixelColor(50 ,strip.Color(0, 0, 0));
  strip.setPixelColor(51 ,strip.Color(255, 239, 0));
  strip.setPixelColor(52 ,strip.Color(255, 239, 0));
  strip.setPixelColor(53 ,strip.Color(0, 0, 0));
  strip.setPixelColor(54 ,strip.Color(0, 0, 0));
  strip.setPixelColor(55 ,strip.Color(255, 239, 0));

  strip.setPixelColor(56 ,strip.Color(255, 239, 0));
  strip.setPixelColor(57 ,strip.Color(255, 239, 0));
  strip.setPixelColor(58 ,strip.Color(255, 239, 0));
  strip.setPixelColor(59 ,strip.Color(255, 239, 0));
  strip.setPixelColor(60 ,strip.Color(255, 239, 0));
  strip.setPixelColor(61 ,strip.Color(255, 239, 0));
  strip.setPixelColor(62 ,strip.Color(255, 239, 0));
  strip.setPixelColor(63 ,strip.Color(255, 239, 0));
}

void tired() {
  strip.setPixelColor(0 ,strip.Color(50, 175, 255));
  strip.setPixelColor(1 ,strip.Color(255, 239, 0));
  strip.setPixelColor(2 ,strip.Color(0, 0, 0));
  strip.setPixelColor(3 ,strip.Color(242, 39, 223));
  strip.setPixelColor(4 ,strip.Color(242, 39, 223));
  strip.setPixelColor(5 ,strip.Color(0, 0, 0));
  strip.setPixelColor(6 ,strip.Color(255, 239, 0));
  strip.setPixelColor(7 ,strip.Color(255, 239, 0));
  
  strip.setPixelColor(8 ,strip.Color(50, 175, 255));
  strip.setPixelColor(9 ,strip.Color(255, 239, 0));
  strip.setPixelColor(10 ,strip.Color(0, 0, 0));
  strip.setPixelColor(11 ,strip.Color(0, 0, 0));
  strip.setPixelColor(12 ,strip.Color(0, 0, 0));
  strip.setPixelColor(13 ,strip.Color(0, 0, 0));
  strip.setPixelColor(14 ,strip.Color(255, 239, 0));
  strip.setPixelColor(15 ,strip.Color(255, 239, 0));
  
  strip.setPixelColor(16 ,strip.Color(255, 100, 100));
  strip.setPixelColor(17 ,strip.Color(255, 100, 100));
  strip.setPixelColor(18 ,strip.Color(255, 239, 0));
  strip.setPixelColor(19 ,strip.Color(0, 0, 0));
  strip.setPixelColor(20 ,strip.Color(0, 0, 0));
  strip.setPixelColor(21 ,strip.Color(255, 239, 0));
  strip.setPixelColor(22 ,strip.Color(255, 100, 100));
  strip.setPixelColor(23 ,strip.Color(255, 100, 100));
  
  strip.setPixelColor(24 ,strip.Color(50, 175, 255));
  strip.setPixelColor(25 ,strip.Color(0, 0, 0));
  strip.setPixelColor(26 ,strip.Color(255, 239, 0));
  strip.setPixelColor(27 ,strip.Color(255, 239, 0));
  strip.setPixelColor(28 ,strip.Color(255, 239, 0));
  strip.setPixelColor(29 ,strip.Color(255, 239, 0));
  strip.setPixelColor(30 ,strip.Color(0, 0, 0));
  strip.setPixelColor(31 ,strip.Color(50, 175, 255));
  
  strip.setPixelColor(32 ,strip.Color(255, 239, 0));
  strip.setPixelColor(33 ,strip.Color(255, 239, 0));
  strip.setPixelColor(34 ,strip.Color(0, 0, 0));
  strip.setPixelColor(35 ,strip.Color(255, 239, 0));
  strip.setPixelColor(36 ,strip.Color(255, 239, 0));
  strip.setPixelColor(37 ,strip.Color(0, 0, 0));
  strip.setPixelColor(38 ,strip.Color(255, 239, 0));
  strip.setPixelColor(39 ,strip.Color(255, 239, 0));
  
  strip.setPixelColor(40 ,strip.Color(255, 239, 0));
  strip.setPixelColor(41 ,strip.Color(0, 0, 0));
  strip.setPixelColor(42 ,strip.Color(255, 239, 0));
  strip.setPixelColor(43 ,strip.Color(255, 239, 0));
  strip.setPixelColor(44 ,strip.Color(255, 239, 0));
  strip.setPixelColor(45 ,strip.Color(255, 239, 0));
  strip.setPixelColor(46 ,strip.Color(0, 0, 0));
  strip.setPixelColor(47 ,strip.Color(255, 239, 0));
  
  strip.setPixelColor(48 ,strip.Color(255, 239, 0));
  strip.setPixelColor(49 ,strip.Color(255, 239, 0));
  strip.setPixelColor(50 ,strip.Color(255, 239, 0));
  strip.setPixelColor(51 ,strip.Color(255, 239, 0));
  strip.setPixelColor(52 ,strip.Color(255, 239, 0));
  strip.setPixelColor(53 ,strip.Color(255, 239, 0));
  strip.setPixelColor(54 ,strip.Color(255, 239, 0));
  strip.setPixelColor(55 ,strip.Color(255, 239, 0));

  strip.setPixelColor(56 ,strip.Color(255, 239, 0));
  strip.setPixelColor(57 ,strip.Color(255, 239, 0));
  strip.setPixelColor(58 ,strip.Color(255, 239, 0));
  strip.setPixelColor(59 ,strip.Color(255, 239, 0));
  strip.setPixelColor(60 ,strip.Color(255, 239, 0));
  strip.setPixelColor(61 ,strip.Color(255, 239, 0));
  strip.setPixelColor(62 ,strip.Color(255, 239, 0));
  strip.setPixelColor(63 ,strip.Color(255, 239, 0));
  
}

void face(int x){


if (x == 0){
    smile();
  }else if (x ==1){
    still();
  }else{
    tired();
  }

  
  }



void right_arrow(){
  strip.setPixelColor(0 ,strip.Color(0, 0, 0));
  strip.setPixelColor(1 ,strip.Color(0, 0, 0));
  strip.setPixelColor(2 ,strip.Color(0, 0, 0));
  strip.setPixelColor(3 ,strip.Color(0, 0, 0));
  strip.setPixelColor(4 ,strip.Color(50, 175, 255));
  strip.setPixelColor(5 ,strip.Color(0, 0, 0));
  strip.setPixelColor(6 ,strip.Color(0, 0, 0));
  strip.setPixelColor(7 ,strip.Color(0, 0, 0));
  
  strip.setPixelColor(8 ,strip.Color(0, 0, 0));
  strip.setPixelColor(9 ,strip.Color(0, 0, 0));
  strip.setPixelColor(10 ,strip.Color(50, 175, 255));
  strip.setPixelColor(11 ,strip.Color(50, 175, 255));
  strip.setPixelColor(12 ,strip.Color(0, 0, 0));
  strip.setPixelColor(13 ,strip.Color(0, 0, 0));
  strip.setPixelColor(14 ,strip.Color(0, 0, 0));
  strip.setPixelColor(15 ,strip.Color(0, 0, 0));
  
  strip.setPixelColor(16 ,strip.Color(0, 0, 0));
  strip.setPixelColor(17 ,strip.Color(0, 0, 0));
  strip.setPixelColor(18 ,strip.Color(0, 0, 0));
  strip.setPixelColor(19 ,strip.Color(0, 0, 0));
  strip.setPixelColor(20 ,strip.Color(50, 175, 255));
  strip.setPixelColor(21 ,strip.Color(50, 175, 255));
  strip.setPixelColor(22 ,strip.Color(50, 175, 255));
  strip.setPixelColor(23 ,strip.Color(0, 0, 0));
  
  strip.setPixelColor(24 ,strip.Color(50, 175, 255));
  strip.setPixelColor(25 ,strip.Color(50, 175, 255));
  strip.setPixelColor(26 ,strip.Color(50, 175, 255));
  strip.setPixelColor(27 ,strip.Color(50, 175, 255));
  strip.setPixelColor(28 ,strip.Color(50, 175, 255));
  strip.setPixelColor(29 ,strip.Color(50, 175, 255));
  strip.setPixelColor(30 ,strip.Color(50, 175, 255));
  strip.setPixelColor(31 ,strip.Color(50, 175, 255));
  
  strip.setPixelColor(32 ,strip.Color(50, 175, 255));
  strip.setPixelColor(33 ,strip.Color(50, 175, 255));
  strip.setPixelColor(34 ,strip.Color(50, 175, 255));
  strip.setPixelColor(35 ,strip.Color(50, 175, 255));
  strip.setPixelColor(36 ,strip.Color(50, 175, 255));
  strip.setPixelColor(37 ,strip.Color(50, 175, 255));
  strip.setPixelColor(38 ,strip.Color(50, 175, 255));
  strip.setPixelColor(39 ,strip.Color(50, 175, 255));
  
  strip.setPixelColor(40 ,strip.Color(0, 0, 0));
  strip.setPixelColor(41 ,strip.Color(50, 175, 255));
  strip.setPixelColor(42 ,strip.Color(50, 175, 255));
  strip.setPixelColor(43 ,strip.Color(50, 175, 255));
  strip.setPixelColor(44 ,strip.Color(0, 0, 0));
  strip.setPixelColor(45 ,strip.Color(0, 0, 0));
  strip.setPixelColor(46 ,strip.Color(0, 0, 0));
  strip.setPixelColor(47 ,strip.Color(0, 0, 0));
  
  strip.setPixelColor(48 ,strip.Color(0, 0, 0));
  strip.setPixelColor(49 ,strip.Color(0, 0, 0));
  strip.setPixelColor(50 ,strip.Color(0, 0, 0));
  strip.setPixelColor(51 ,strip.Color(0, 0, 0));
  strip.setPixelColor(52 ,strip.Color(50, 175, 255));
  strip.setPixelColor(53 ,strip.Color(50, 175, 255));
  strip.setPixelColor(54 ,strip.Color(0, 0, 0));
  strip.setPixelColor(55 ,strip.Color(0, 0, 0));

  strip.setPixelColor(56 ,strip.Color(0, 0, 0));
  strip.setPixelColor(57 ,strip.Color(0, 0, 0));
  strip.setPixelColor(58 ,strip.Color(0, 0, 0));
  strip.setPixelColor(59 ,strip.Color(50, 175, 255));
  strip.setPixelColor(60 ,strip.Color(0, 0, 0));
  strip.setPixelColor(61 ,strip.Color(0, 0, 0));
  strip.setPixelColor(62 ,strip.Color(0, 0, 0));
  strip.setPixelColor(63 ,strip.Color(0, 0, 0));
  
  }

  void left_arrow(){
  strip.setPixelColor(0 ,strip.Color(0, 0, 0));
  strip.setPixelColor(1 ,strip.Color(0, 0, 0));
  strip.setPixelColor(2 ,strip.Color(0, 0, 0));
  strip.setPixelColor(3 ,strip.Color(50, 175, 255));
  strip.setPixelColor(4 ,strip.Color(0, 0, 0));
  strip.setPixelColor(5 ,strip.Color(0, 0, 0));
  strip.setPixelColor(6 ,strip.Color(0, 0, 0));
  strip.setPixelColor(7 ,strip.Color(0, 0, 0));
  
  strip.setPixelColor(8 ,strip.Color(0, 0, 0));
  strip.setPixelColor(9 ,strip.Color(0, 0, 0));
  strip.setPixelColor(10 ,strip.Color(0, 0, 0));
  strip.setPixelColor(11 ,strip.Color(0, 0, 0));
  strip.setPixelColor(12 ,strip.Color(50, 175, 255));
  strip.setPixelColor(13 ,strip.Color(50, 175, 255));
  strip.setPixelColor(14 ,strip.Color(0, 0, 0));
  strip.setPixelColor(15 ,strip.Color(0, 0, 0));
  
  strip.setPixelColor(16 ,strip.Color(0, 0, 0));
  strip.setPixelColor(17 ,strip.Color(50, 175, 255));
  strip.setPixelColor(18 ,strip.Color(50, 175, 255));
  strip.setPixelColor(19 ,strip.Color(50, 175, 255));
  strip.setPixelColor(20 ,strip.Color(0, 0, 0));
  strip.setPixelColor(21 ,strip.Color(0, 0, 0));
  strip.setPixelColor(22 ,strip.Color(0, 0, 0));
  strip.setPixelColor(23 ,strip.Color(0, 0, 0));
  
  strip.setPixelColor(24 ,strip.Color(50, 175, 255));
  strip.setPixelColor(25 ,strip.Color(50, 175, 255));
  strip.setPixelColor(26 ,strip.Color(50, 175, 255));
  strip.setPixelColor(27 ,strip.Color(50, 175, 255));
  strip.setPixelColor(28 ,strip.Color(50, 175, 255));
  strip.setPixelColor(29 ,strip.Color(50, 175, 255));
  strip.setPixelColor(30 ,strip.Color(50, 175, 255));
  strip.setPixelColor(31 ,strip.Color(50, 175, 255));
  
  strip.setPixelColor(32 ,strip.Color(50, 175, 255));
  strip.setPixelColor(33 ,strip.Color(50, 175, 255));
  strip.setPixelColor(34 ,strip.Color(50, 175, 255));
  strip.setPixelColor(35 ,strip.Color(50, 175, 255));
  strip.setPixelColor(36 ,strip.Color(50, 175, 255));
  strip.setPixelColor(37 ,strip.Color(50, 175, 255));
  strip.setPixelColor(38 ,strip.Color(50, 175, 255));
  strip.setPixelColor(39 ,strip.Color(50, 175, 255));
  
  strip.setPixelColor(40 ,strip.Color(0, 0, 0));
  strip.setPixelColor(41 ,strip.Color(0, 0, 0));
  strip.setPixelColor(42 ,strip.Color(0, 0, 0));
  strip.setPixelColor(43 ,strip.Color(0, 0, 0));
  strip.setPixelColor(44 ,strip.Color(50, 175, 255));
  strip.setPixelColor(45 ,strip.Color(50, 175, 255));
  strip.setPixelColor(46 ,strip.Color(50, 175, 255));
  strip.setPixelColor(47 ,strip.Color(0, 0, 0));
  
  strip.setPixelColor(48 ,strip.Color(0, 0, 0));
  strip.setPixelColor(49 ,strip.Color(0, 0, 0));
  strip.setPixelColor(50 ,strip.Color(50, 175, 255));
  strip.setPixelColor(51 ,strip.Color(50, 175, 255));
  strip.setPixelColor(52 ,strip.Color(0, 0, 0));
  strip.setPixelColor(53 ,strip.Color(0, 0, 0));
  strip.setPixelColor(54 ,strip.Color(0, 0, 0));
  strip.setPixelColor(55 ,strip.Color(0, 0, 0));

  strip.setPixelColor(56 ,strip.Color(0, 0, 0));
  strip.setPixelColor(57 ,strip.Color(0, 0, 0));
  strip.setPixelColor(58 ,strip.Color(0, 0, 0));
  strip.setPixelColor(59 ,strip.Color(0, 0, 0));
  strip.setPixelColor(60 ,strip.Color(50, 175, 255));
  strip.setPixelColor(61 ,strip.Color(0, 0, 0));
  strip.setPixelColor(62 ,strip.Color(0, 0, 0));
  strip.setPixelColor(63 ,strip.Color(0, 0, 0));
  
  }

  
void off() {

  strip.setPixelColor(0 ,strip.Color(0, 0, 0));
  strip.setPixelColor(1 ,strip.Color(0, 0, 0));
  strip.setPixelColor(2 ,strip.Color(0, 0, 0));
  strip.setPixelColor(3 ,strip.Color(0, 0, 0));
  strip.setPixelColor(4 ,strip.Color(0, 0, 0));
  strip.setPixelColor(5 ,strip.Color(0, 0, 0));
  strip.setPixelColor(6 ,strip.Color(0, 0, 0));
  strip.setPixelColor(7 ,strip.Color(0, 0, 0));
  
  strip.setPixelColor(8 ,strip.Color(0, 0, 0));
  strip.setPixelColor(9 ,strip.Color(0, 0, 0));
  strip.setPixelColor(10 ,strip.Color(0, 0, 0));
  strip.setPixelColor(11 ,strip.Color(0, 0, 0));
  strip.setPixelColor(12 ,strip.Color(0, 0, 0));
  strip.setPixelColor(13 ,strip.Color(0, 0, 0));
  strip.setPixelColor(14 ,strip.Color(0, 0, 0));
  strip.setPixelColor(15 ,strip.Color(0, 0, 0));
  
  strip.setPixelColor(16 ,strip.Color(0, 0, 0));
  strip.setPixelColor(17 ,strip.Color(0, 0, 0));
  strip.setPixelColor(18 ,strip.Color(0, 0, 0));
  strip.setPixelColor(19 ,strip.Color(0, 0, 0));
  strip.setPixelColor(20 ,strip.Color(0, 0, 0));
  strip.setPixelColor(21 ,strip.Color(0, 0, 0));
  strip.setPixelColor(22 ,strip.Color(0, 0, 0));
  strip.setPixelColor(23 ,strip.Color(0, 0, 0));
  
  strip.setPixelColor(24 ,strip.Color(0, 0, 0));
  strip.setPixelColor(25 ,strip.Color(0, 0, 0));
  strip.setPixelColor(26 ,strip.Color(0, 0, 0));
  strip.setPixelColor(27 ,strip.Color(0, 0, 0));
  strip.setPixelColor(28 ,strip.Color(0, 0, 0));
  strip.setPixelColor(29 ,strip.Color(0, 0, 0));
  strip.setPixelColor(30 ,strip.Color(0, 0, 0));
  strip.setPixelColor(31 ,strip.Color(0, 0, 0));
  
  strip.setPixelColor(32 ,strip.Color(0, 0, 0));
  strip.setPixelColor(33 ,strip.Color(0, 0, 0));
  strip.setPixelColor(34 ,strip.Color(0, 0, 0));
  strip.setPixelColor(35 ,strip.Color(0, 0, 0));
  strip.setPixelColor(36 ,strip.Color(0, 0, 0));
  strip.setPixelColor(37 ,strip.Color(0, 0, 0));
  strip.setPixelColor(38 ,strip.Color(0, 0, 0));
  strip.setPixelColor(39 ,strip.Color(0, 0, 0));
  
  strip.setPixelColor(40 ,strip.Color(0, 0, 0));
  strip.setPixelColor(41 ,strip.Color(0, 0, 0));
  strip.setPixelColor(42 ,strip.Color(0, 0, 0));
  strip.setPixelColor(43 ,strip.Color(0, 0, 0));
  strip.setPixelColor(44 ,strip.Color(0, 0, 0));
  strip.setPixelColor(45 ,strip.Color(0, 0, 0));
  strip.setPixelColor(46 ,strip.Color(0, 0, 0));
  strip.setPixelColor(47 ,strip.Color(0, 0, 0));
  
  strip.setPixelColor(48 ,strip.Color(0, 0, 0));
  strip.setPixelColor(49 ,strip.Color(0, 0, 0));
  strip.setPixelColor(50 ,strip.Color(0, 0, 0));
  strip.setPixelColor(51 ,strip.Color(0, 0, 0));
  strip.setPixelColor(52 ,strip.Color(0, 0, 0));
  strip.setPixelColor(53 ,strip.Color(0, 0, 0));
  strip.setPixelColor(54 ,strip.Color(0, 0, 0));
  strip.setPixelColor(55 ,strip.Color(0, 0, 0));

  strip.setPixelColor(56 ,strip.Color(0, 0, 0));
  strip.setPixelColor(57 ,strip.Color(0, 0, 0));
  strip.setPixelColor(58 ,strip.Color(0, 0, 0));
  strip.setPixelColor(59 ,strip.Color(0, 0, 0));
  strip.setPixelColor(60 ,strip.Color(0, 0, 0));
  strip.setPixelColor(61 ,strip.Color(0, 0, 0));
  strip.setPixelColor(62 ,strip.Color(0, 0, 0));
  strip.setPixelColor(63 ,strip.Color(0, 0, 0));
}



// 初期設定（一度だけsetup内を実行）
void setup() {
  // テープLEDを開始
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)

  pinMode( RIGHT, INPUT_PULLUP );
  pinMode(LEFT, INPUT_PULLUP);
  Serial.begin(9600);

  // テープLEDの点灯を更新　
  // 色設定をしていないが（開始直後なので）最初は全てオフになる
  strip.show();            // Turn OFF all pixels ASAP
  // テープLEDのブライトネス（明るさ）を設定　
  // LED全体の明るさを設定できる 適宜数値を変えてみてください
  //（255の最高にすると結構明るすぎなのと、LED個数が大きくなると電流大なのでここで小さくしておくことが多い）
  strip.setBrightness(5); // Set BRIGHTNESS to about 1/5 (max = 255)
}

// 高速で繰り返し実行する
void loop() {

  // 0番のLEDを、色を設定する
  // 関数：strip.setPixelColor(LEDの番号, 色の設定）  1ピクセル（1個のRGB LED）の色を設定する
  // 色は、strip.Color(Red, Green, Blue)で設定　各色255段階で表す　
  // 255, 255, 255 : White
  // 255, 239, 0 : Yellow
  // 0, 0, 0 : Black
  // 242, 39, 223 : Pink
  // 255, 213, 250: cheek
  // 200, 133, 0 : brown

  ///what_face = random(0, 2);

/*
 if (digitalRead(LEFT) == LOW){
      left = !left;
      delay (300);
    }
  if (left == false){
      left_arrow();
      strip.show();
  }else{
    off();
    strip.show();
  }

*/


  if (digitalRead(RIGHT) == LOW){
      right = !right;
      delay (300);
    }

  if (right == false){
      right_arrow();
    strip.show();
    
  }else{
  off();
  strip.show();
  }


  // テープLEDの点灯を更新 :  ↑の色設定後、strip.show()を実行することでLEDの色が設定値に変わる


}
