#include <idDHT11.h>
#include <LiquidCrystal.h>

float temp;
int idDHT11pin = 2;
int idDHT11intNumber = 0;

LiquidCrystal lcd(12,11,6,5,4,3);
idDHT11 DHT11(idDHT11pin,idDHT11intNumber,dht11_wrapper);

void dht11_wrapper();

void setup() 
{  
  lcd.begin(16,2);    
  delay(5000);
  lcd.clear();    
}

void dht11_wrapper() 
{
  DHT11.isrCallback();
}

void displayStatus()
{
  lcd.setCursor(0,0);  
  lcd.print("Humidity:");
  lcd.setCursor(9,0);
  lcd.print(DHT11.getHumidity(), 2);
  lcd.setCursor(12,0);
  lcd.print("%");
  lcd.setCursor(0,1);
  lcd.print("Temp.:");
  lcd.setCursor(6,1);
  lcd.print(DHT11.getCelsius(), 2);
  lcd.setCursor(10,1);
  lcd.print("*C");  
}

void loop()
{ 
  lcd.setCursor(0,0);
  DHT11.acquire();
  while (DHT11.acquiring());
  displayStatus();  
  delay(1000);
}
