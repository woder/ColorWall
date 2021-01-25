#define FASTLED_INTERRUPT_RETRY_COUNT 0

#include <FastLED.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "Panel.h"
#include "Settings.h"
//#include "effects/Solid.h"
//#include "effects/Wash.h"
//#include "effects/Smooth.h"
//#include "effects/Colory.h"
//#include "effects/Bpm.h"

FASTLED_USING_NAMESPACE

#if defined(FASTLED_VERSION) && (FASTLED_VERSION < 3001000)
#warning "Requires FastLED 3.1 or later; check github for latest code."
#endif

#define FRAMES_PER_SECOND  200

CRGB leds[NUM_LEDS];
Panel *panels[NUM_PANELS];

const char *ssid =  "Banana";     // replace with your wifi ssid and wpa2 key
const char *pass =  "fruit4336";
ESP8266WebServer server ( 80 ); //the port to run the HTTP server
IPAddress ip(192, 168, 3, 6);  //the IP address of the device
IPAddress gateway(192, 168, 1, 1); //the gateway
IPAddress subnet(255, 255, 0, 0); //the subnet

Settings settings;
Effect *currentEffect = new Solid(panels, leds);

unsigned long previousMillis = 0;
bool powered = true;

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

void setup() {
  delay(3000); // 3 second delay for recovery

  Serial.begin(115200);
  while(!Serial) {
	  //wait
  }

  //uncomment for WiFi
  WiFi.mode(WIFI_STA);
  WiFi.config(ip, gateway, subnet);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("Device Started");
  Serial.println("-------------------------------------");
  Serial.println("Running DHT!");
  Serial.println("-------------------------------------");

  WiFi.setSleepMode(WIFI_NONE_SLEEP);

  int ledNum = NUM_PANELS * NUM_LEDS_PER_PANEL;
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, ledNum).setCorrection(TypicalLEDStrip);

  Vector<PanelSettings> panelSettings = settings.getPanels();

  int start = 0;
  for(int i = 0; i < NUM_PANELS; i++) {
	  panels[i] = new Panel(DATA_PIN, start, start+NUM_LEDS_PER_PANEL, leds);
	  panels[i]->setHue(panelSettings.at(i).hue);
	  panelSettings.at(i).panelId = i;
	  start += NUM_LEDS_PER_PANEL;
  }

  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5,  4700);

  //load the settings
  settings.loadSettings();
  setEffect(settings.getCurrentEffect());


  server.on("/effect", HTTPMethod::HTTP_POST, handleSetEffect);
  server.on("/effect", HTTPMethod::HTTP_GET, handleGetEffect);
  server.on("/panels", HTTPMethod::HTTP_POST, handleSetPanels);
  server.on("/panels", HTTPMethod::HTTP_GET, handleGetPanels);
  server.on("/power", HTTPMethod::HTTP_POST, handleSetPower);
  server.on("/power", HTTPMethod::HTTP_GET, handleGetPower);
  server.onNotFound(handleNotFound);

  server.begin();
}

void loop() {

	server.handleClient();

	unsigned long currentMillis = millis();

	if(powered) {
		if(currentMillis - previousMillis >= DRAW_DELAY) {
			previousMillis = currentMillis;

			currentEffect->run();

			// send the 'leds' array out to the actual LED strip
			FastLED.show();
			// insert a delay to keep the framerate modest
			//FastLED.delay(1000/FRAMES_PER_SECOND);
		}
	} else {
		memset8( leds, 0, NUM_LEDS * sizeof(CRGB));
		FastLED.show();
	}


	yield();
}

void setEffect(uint8_t effectNum) {
	//since we are setting the effect, we must delete the object
	delete currentEffect;
	switch(static_cast<Effects>(effectNum)) {
		case Effects::Smooth:
			currentEffect = new Smooth(panels, leds, settings.getEffects().at(static_cast<int>(Effects::Smooth)));
			break;
		case Effects::Bpm:
			currentEffect = new Bpm(panels, leds, settings.getEffects().at(static_cast<int>(Effects::Bpm)));
			break;
		case Effects::Solid:
			currentEffect = new Solid(panels, leds);
			break;
		case Effects::Colory:
			currentEffect = new Colory(panels, leds, settings.getEffects().at(static_cast<int>(Effects::Colory)));
			break;
		case Effects::Wash:
			currentEffect = new Wash(panels, leds, settings.getEffects().at(static_cast<int>(Effects::Wash)));
			break;
	}

}

//the not found endpoint
void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += ( server.method() == HTTP_GET ) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";

  for ( uint8_t i = 0; i < server.args(); i++ ) {
    message += " " + server.argName ( i ) + ": " + server.arg ( i ) + "\n";
  }

  server.send ( 404, "text/plain", message );
}


void handleSetPower() {
	if(server.hasArg("plain") == false) {
		server.send(200, "text/plain", "Body not received");
		return;
	}

	String payload = server.arg("plain");
	const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
	DynamicJsonDocument root(capacity);

	auto error = deserializeJson(root, payload);
	if(error) {
        Serial.print(F("deserializeJson() failed with code "));
        Serial.println(error.c_str());
        return;
	}

	powered = root["power"];

	server.send(200, "text/plain", "OK");
}

void handleGetPower() {
	StaticJsonDocument<200> root;
	root["power"] = powered;

	String output;
	serializeJson(root, output);

	server.send(200, "application/json", output);
}

void handleSetPanels() {
	if(server.hasArg("plain") == false) {
		server.send(200, "text/plain", "Body not received");
		return;
	}

	String payload = server.arg("plain");
	const size_t capacity = JSON_OBJECT_SIZE(3*NUM_PANELS) + JSON_ARRAY_SIZE(NUM_PANELS) + 60;
	DynamicJsonDocument root(capacity);

	auto error = deserializeJson(root, payload);
	if(error) {
        Serial.print(F("deserializeJson() failed with code "));
        Serial.println(error.c_str());
        return;
	}

	JsonArray arr = root.as<JsonArray>();
	for(JsonVariant value : arr) {
		int id = value["id"];
		uint8_t hue = value["hue"];
		JsonVariant b = value["brightness"];

		if(id > ARRAY_SIZE(panels)) {
			server.send(400, "text/plain", "ID above maximum panel number!");
			return;
		}

		PanelSettings p = settings.getPanels().at(id);
		if(!b.isNull()) {
			uint8_t brightness = b.as<uint8_t>();
			p.brightness = brightness;
			panels[id]->setBrightness(brightness);
		}

		p.hue = hue;
		panels[id]->setHue(hue);
	}

	//save the changes
	settings.saveSettings();

	server.send(200, "text/plain", "OK");
}

void handleGetPanels() {
	const size_t capacity = JSON_OBJECT_SIZE(3*NUM_PANELS) + JSON_ARRAY_SIZE(NUM_PANELS) + 60;
	StaticJsonDocument<capacity> root;
	JsonArray arr = root.to<JsonArray>();
	for(int i = 0; i < NUM_PANELS; i++) {
		JsonObject panel = arr.createNestedObject();
		panel["id"] = i;
		panel["hue"] = panels[i]->getHue();
	}

	String output;
	serializeJson(arr, output);

	server.send(200, "application/json", output);
}

void handleSetEffect() {
	if(server.hasArg("plain") == false) {
		server.send(200, "text/plain", "Body not received");
		return;
	}

	String payload = server.arg("plain");
	const size_t capacity = JSON_OBJECT_SIZE(5) + 60;
	DynamicJsonDocument root(capacity);

	auto error = deserializeJson(root, payload);
	if(error) {
        Serial.print(F("deserializeJson() failed with code "));
        Serial.println(error.c_str());
        String msg = "Invalid Json! ex: ";
		server.send(400, "text/plain", msg + error.c_str());
        return;
	}



	uint8_t id = root["effect"];
	//values come from the outside so verify they are correct
	if(id < 0 || id >= static_cast<uint8_t>(Effects::Last)) {
		//this value is not a valid effect
		server.send(400, "text/plain", "Incorrect effect ID!");
		return;
	}

	//tell the settings manager about our change
	settings.setCurrentEffect(id);
	EffectManager::updateSettings(id, root, settings.getEffects().at(id));
	settings.saveSettings();
	//actually set the effect
	setEffect(settings.getCurrentEffect());

	server.send(200, "text/plain", "OK");
}

void handleGetEffect() {
	const size_t capacity = JSON_OBJECT_SIZE(1) + 60;
	DynamicJsonDocument root(capacity);
	root["effect"] = settings.getCurrentEffect();
	currentEffect->getSettings(root);

	String output;
	serializeJson(root, output);

	server.send(200, "application/json", output);
}
