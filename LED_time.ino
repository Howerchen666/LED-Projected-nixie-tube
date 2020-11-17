#include <DS3231.h>
#include <Wire.h>
DS3231 Clock;
bool Century=false;
bool h12;
bool PM;
byte ADay, AHour, AMinute, ASecond, ABits;
bool ADy, A12h, Apm;
byte year, month, date, DoW, hour, minute, second;
/*******************************************************************************************************************************/
#include <Adafruit_NeoPixel.h>
#define PIN      5// On Trinket or Gemma, suggest changing this to 1
#define NUMPIXELS 60 // Popular NeoPixel ring size
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels
/*******************************************************************************************************************************/
const int H_button=6;
const int M_button=7;
/*******************************************************************************************************************************/
void setup() {
                      Serial.begin(115200);
                      pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
    
/*******************************************************************************************************************************/
                        Wire.begin();
/*******************************************************************************************************************************/                    
                          // Clock.setSecond(50);//配置秒 
                          //Clock.setMinute(16);//配置分钟 
                         // Clock.setHour(14);  //配置小时（24小时制） 
                         // Clock.setDoW(6);    //配置星期
                         // Clock.setDate(29);  //配置日
                          //Clock.setMonth(2);  //配置月
                          //Clock.setYear(20);  //配置年 (仅最后两位)

                         //Serial.println(DHT_LIB_VERSION);//输出版本信息
                       //Serial.println();
                         //Serial.println("Type,\tstatus,\tHumidity (%),\tTemperature (C)");//                        
                    }
void loop() {
 /*******************************************************************************************************************************/                            
                     //pixels.clear(); // Set all pixel colors to 'off'
                     int second,minute,hour,date,month,year,temperature; 
                      second=Clock.getSecond();
                      minute=Clock.getMinute();
                      hour=Clock.getHour(h12, PM);
                      date=Clock.getDate();//date=Clock.getDate();   
                      month=Clock.getMonth(Century);
                      year=Clock.getYear(); 
                      temperature=Clock.getTemperature();
                        if(digitalRead(H_button)==0){
                          delay(100);
                          if(digitalRead(H_button)==0){
                              hour=Clock.getHour(h12,PM);
                              hour++;
                              if(hour==24){
                                  hour=0;
                              }
                               Clock.setHour(hour);
                          }
                      }
                     else{
                         hour=Clock.getHour(h12,PM);
                      }
                    
                    /******************************************************************************
                     * 设置分钟部分
                     ******************************************************************************/  
                        if(digitalRead(M_button)==0){
                          delay(100);
                          if(digitalRead(M_button)==0){
                               minute=Clock.getMinute();
                               minute++;
                              if(minute==60){
                                  minute=0;
                              }
                               Clock.setMinute(minute);
                          }
                      }
                      else{
                        minute=Clock.getMinute();
                      } 
                        pixels.setPixelColor(hour/10, pixels.Color(0, 0, 255));
                         pixels.setPixelColor(hour%10+10, pixels.Color(0, 0, 255));
                         pixels.setPixelColor(minute/10+20, pixels.Color(0, 255, 0));
                         pixels.setPixelColor(minute%10+30, pixels.Color(0, 255, 0));
                         pixels.setPixelColor(second/10+40, pixels.Color(255, 0, 0));
                         pixels.setPixelColor(second%10+50, pixels.Color(255, 0, 0));
                         pixels.show();   // Send the updated pixel colors to the hardware.
                         pixels.clear();
 /*******************************************************************************************************************************/     
  /*******************************************************************************************************************************/             
}
