#include <pgmspace.h>
 
#define SECRET
#define THINGNAME "ESP32_DHT11"                           //change this
 
const char WIFI_SSID[] = "Airtel_sara_4856";               //change this
const char WIFI_PASSWORD[] = "air29791";                  //change this
const char AWS_IOT_ENDPOINT[] = "aooqgia1fx31q-ats.iot.us-east-1.amazonaws.com";       //change this

// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";
 
// Device Certificate                                               //change this
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVAN/188wldRSdz8+ievVHFQn1m/SPMA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yNDA5MjQxMzU4
MjdaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQC/6PDwEQNIrx4zN8v+
646u+uNMBxzXMX2lrHvISj7qXh2IdPiX9sNjdzcLG+8GZUsTQpKKlAOhnE31rEZB
4rt0LHHuLirVGqh6CHHrCqBM8mtt2jPVXiK90LEKHoeAsU4fr459PUIx036sH/yO
ILzVZT/Vvq3dry44g78ma1RlKXj7cxJsay+a5TFMfwgmYPtjO/Lykl8dsDkBo68U
gLOQMu8J+3GQotyMWh50y9a8sX1PRRtia8SlDIVJFmXild1mOylFWFKAX7q0jZs5
578r4mzFHwbKj8AmopP1X31s4RAGOuVIjef8lq7wzBhScFU0buxG1m3OljpG1tf9
m1HBAgMBAAGjYDBeMB8GA1UdIwQYMBaAFPDqm/W07MQI0xosCTC5cwl4BDquMB0G
A1UdDgQWBBSKojhyIsDsEaqm2HtLYrZgNwuPYDAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAS1CXmylbTNhctvDev7dT33R4
Umn/BfkLpmr94/+S1qB68LBLem2hA9L0IKaTKvKeB+ZUGn+/287ggvvhv1ZomJHv
1rvtjTh79yyXadKd0F7ic9uvSzAl7WqdnFAVl2uusKwVpQqiTXUnaUzKN5ihVkk/
zsMenvyuyE6thdhFaxRxyf6RWAogaOcsGhDa0QYEY/mVVqUM5rZuh4yukWLIS29W
uPYYuq7uHD67xQg4zUh84mXV0Yow6SS3R3gUr8WnB4h3Mp/9oUP2vzEh4fAxoCvf
zuOw8U19wU8bvULeny5UFBvs3BQedz5AuQNWhdqDyXUFIACe8GB7N3RQ7dqc4A==
-----END CERTIFICATE-----
 
 
)KEY";
 
// Device Private Key                                               //change this
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEowIBAAKCAQEAv+jw8BEDSK8eMzfL/uuOrvrjTAcc1zF9pax7yEo+6l4diHT4
l/bDY3c3CxvvBmVLE0KSipQDoZxN9axGQeK7dCxx7i4q1Rqoeghx6wqgTPJrbdoz
1V4ivdCxCh6HgLFOH6+OfT1CMdN+rB/8jiC81WU/1b6t3a8uOIO/JmtUZSl4+3MS
bGsvmuUxTH8IJmD7Yzvy8pJfHbA5AaOvFICzkDLvCftxkKLcjFoedMvWvLF9T0Ub
YmvEpQyFSRZl4pXdZjspRVhSgF+6tI2bOee/K+JsxR8Gyo/AJqKT9V99bOEQBjrl
SI3n/Jau8MwYUnBVNG7sRtZtzpY6RtbX/ZtRwQIDAQABAoIBAAgXPwkv/m5zC5fn
M0+FCNfxteF/r0SXTo/MjM9t6echnqchH1Xwzl4EKarrO5GOdbLTLLBw+xI2L8c6
wx+F+pc0RH1hLucbH509e+gH46g61DKmb2cAeAB+qugdT2MqlnuZgC1hhsfo/b8t
/gzT7oIkqaNOTbA58X3qeAWbosw896uyag8YgQfY7LZHmL4p+Yj2drexlFiUL0xa
LKj6ngmt56IoHorwowYRccxuH8nUPhwcvBYr1zcIy/d/6HUE1tqDdiyrpp+yLzAp
7GrD6qB20JFg6dNbO/uEjRFkC7bSHMQG/bY5I8VOuK1kAmIlrAMmhzRfrtl9NjCK
SDitWh0CgYEA5l3WpXzBAsi2cbYYWGBckUv3Z1zX4BxFfl7k8B/rYaLVYoeNSYC2
6LvMftEkJRBlmTOTY7+D8y1zvjJHAVF9EYtNhAjSNMEPRqRsOi8qKJL4t18IranV
hqG+QCOdP0LaFJfNYpbYi9yI3I1BwmqsBCwvIL/vJHiHC9d+Pa8GwCMCgYEA1UOj
HoErmXhn9MBYI1V4WeHmWMvnJrFQzDClQ+XrHXVK5YsR5uv0qkaMtZwQjo/ZYLGH
Q40L0w3JPCzHzJ9uO+66ERJ5xB6sAVOSROeAZqkWFhxKfin8t9P30qqmEQ34Mi0h
SAZoLjh4AOPkySasTf26tmlD03c5LtQb2DPvkssCgYAMMZlkBxd8Wz11BWuCeg9M
TZYZ7YsrvLNc/g7mOvpNn73lykELS/nildY8PDvKjnSiSF2b4Q5N9/Dxd13Uzwhs
vk/rFkByNGnnllp4NfjoTudFZY1jC+NWjgcxA/GV4KcEggiIGG378T95VSzO6rCS
Q/h2plI1Pv/++3geMb6MuwKBgQCfxsjS9duAY6Ee0Ww3LLW6QXCeXkWTy4zJLjjj
IcKAk3vFdee3plfrqmeJOJ9+727g7qB0j5uoR8/YcYRPXbLs2/IzEDCCKqibZc1U
Kk0cnNmbPx7gXvyjjP9Cqe85H8ovbXhdyc8LserWX+bsfTjiRZI5T6wtJkmFOAyU
cnSu+QKBgFlzPrZtuwqVRgNEUgwI3CT7SbSLmcI/MHraQYCf4gnEmiDRAJIqR/C5
/n0fOcWVOdreGjYVGngrNYJ0oLAnb2YJooW0QLK8WbPuZiiKdpDb5iQDrA+C43Kx
YICQbAPD7zj/tr+4cirypzK6tHMFFLWf5eMACybT9GraJqKkPFur
-----END RSA PRIVATE KEY-----
 
 
)KEY";