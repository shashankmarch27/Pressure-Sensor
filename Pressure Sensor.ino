// Included required library for oled display and bmp280
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_BMP280.h>
#include <Wire.h>

// Defined oled dimensions
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

// Software reset the oled
#define OLED_RESET -1

//Defined address for the sensor and display
#define SENSOR_ADDRESS 0X76
#define DISPLAY_ADDRESS 0X3C

// Created a object named display
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
// Created a object named bmp;
Adafruit_BMP280 bmp;

// Declared Variable to store temperature, pressure, altitude readings
float temperature;
float pressure;
float altitude; 

// setup function
void setup() {
  // Initialized the sensor
  bmp.begin(SENSOR_ADDRESS);
  
  // Initialized the display              
  display.begin(SSD1306_SWITCHCAPVCC, DISPLAY_ADDRESS);

  // Clear the display
  display.clearDisplay();
  display.display();

  // Display the Startup Screen
  display.setTextColor(WHITE);
  display.setCursor(32,12);
  display.setTextSize(2);          
  display.println("BMP280"); 
  display.display();
  
  delay(2000);
}

// Super loop
void loop() {
  // Clear the display
  display.clearDisplay();
  // get sensor readings
  temperature = bmp.readTemperature(); 
  pressure = bmp.readPressure()/100;   
  altitude = bmp.readAltitude(1019.66);

  // Load the temperature reading
  display.setCursor(0,0);
  display.setTextSize(2); 
  display.print("Temp");
  display.setCursor(0,18);
  display.print(temperature,1);
  display.setCursor(50,17);
  display.setTextSize(1);
  display.print("C");

  // Load the Pressure reading
  display.setTextSize(1);
  display.setCursor(65,0);
  display.print("Pressure");
  display.setCursor(65,10);
  display.print(pressure);
  display.setCursor(110,10);
  display.print("hPa");

  // Load the altitide reading
  display.setCursor(65,25);
  display.print("Alt");
  display.setCursor(90,25);
  display.print(altitude,0);
  display.setCursor(110,25);
  display.print("m");

  // Display the loaded readings
  display.display();
  delay(2000);  
}
