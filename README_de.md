[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver BMP280

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/bmp280/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE) 

Der BMP280 ist ein absoluter Luftdrucksensor, der insbesondere für mobile Anwendungen geeignet ist. Seine geringen Abmessungen und sein geringer Stromverbrauch ermöglichen den Einsatz in batteriebetriebenen Geräten wie Mobiltelefonen, GPS-Modulen oder Uhren. Der BMP280 basiert auf der bewährten piezoresistiven Drucksensortechnologie von Bosch und zeichnet sich durch hohe Genauigkeit und Linearität sowie Langzeitstabilität und hohe EMV-Robustheit aus. Zahlreiche Möglichkeiten zur Gerätebedienung garantieren höchste Flexibilität. Das Gerät ist hinsichtlich Stromverbrauch, Auflösung und Filterleistung optimiert.

LibDriver BMP280 ist ein voll funktionsfähiger Treiber für BMP280, der von LibDriver eingeführt wurde. Er ermöglicht die kontinuierliche Messung von Druck und Temperatur, die einmalige Messung von Druck und Temperatur sowie andere Funktionen. LibDriver ist MISRA-kompatibel.

### Inhaltsverzeichnis

  - [Anweisung](#Anweisung)
  - [Installieren](#Installieren)
  - [Nutzung](#Nutzung)
    - [example basic](#example-basic)
    - [example shot](#example-shot)
  - [Dokument](#Dokument)
  - [Beitrag](#Beitrag)
  - [Lizenz](#Lizenz)
  - [Kontaktieren Sie uns](#Kontaktieren-Sie-uns)

### Anweisung

/src enthält LibDriver BMP280-Quelldateien.

/interface enthält die plattformunabhängige Vorlage LibDriver BMP280 IIC, SPI.

/test enthält den Testcode des LibDriver BMP280-Treibers und dieser Code kann die erforderliche Funktion des Chips einfach testen.

/example enthält LibDriver BMP280-Beispielcode.

/doc enthält das LibDriver BMP280-Offlinedokument.

/Datenblatt enthält BMP280-Datenblatt.

/project enthält den allgemeinen Beispielcode für Linux- und MCU-Entwicklungsboards. Alle Projekte verwenden das Shell-Skript, um den Treiber zu debuggen, und die detaillierten Anweisungen finden Sie in der README.md jedes Projekts.

/misra enthält die Ergebnisse des LibDriver MISRA Code Scans.

### Installieren

Verweisen Sie auf eine plattformunabhängige IIC, SPI-Schnittstellenvorlage und stellen Sie Ihren Plattform-IIC, SPI-Treiber fertig.

Fügen Sie /src, /interface und /example zu Ihrem Projekt hinzu.

### Nutzung

#### example basic

```C
#include "driver_bmp280_basic.h"

uint8_t res;
uint32_t i;
float temperature_c;
float pressure_pa;

/* basic init */
res = bmp280_basic_init(BMP280_INTERFACE_IIC, BMP280_ADDRESS_ADO_LOW);
if (res != 0)
{
    return 1;
}

...
    
/* loop */
for (i = 0; i < 3; i++)
{
    /* delay 1000ms */
    bmp280_interface_delay_ms(1000);

    /* read data */
    res = bmp280_basic_read((float *)&temperature_c, (float *)&pressure_pa);
    if (res != 0)
    {
        (void)bmp280_basic_deinit();

        return 1;
    }

    /* output */
    bmp280_interface_debug_print("bmp280: %d/%d.\n", i + 1, 3);
    bmp280_interface_debug_print("bmp280: temperature is %0.2fC.\n", temperature_c);
    bmp280_interface_debug_print("bmp280: pressure is %0.2fPa.\n", pressure_pa);
    
    ...
}

...
    
/* deinit */
(void)bmp280_basic_deinit();

return 0;
```
#### example shot

```C
#include "driver_bmp280_shot.h"

uint8_t res;
uint32_t i;
float temperature_c;
float pressure_pa;

/* shot init */
res = bmp280_shot_init(BMP280_INTERFACE_IIC, BMP280_ADDRESS_ADO_LOW);
if (res != 0)
{
    return 1;
}

...
    
/* loop */
for (i = 0; i < 3; i++)
{
    /* delay 1000ms */
    bmp280_interface_delay_ms(1000);

    /* read data */
    res = bmp280_shot_read((float *)&temperature_c, (float *)&pressure_pa);
    if (res != 0)
    {
        (void)bmp280_shot_deinit();

        return 1;
    }

    /* output */
    bmp280_interface_debug_print("bmp280: %d/%d.\n", i + 1, 3);
    bmp280_interface_debug_print("bmp280: temperature is %0.2fC.\n", temperature_c);
    bmp280_interface_debug_print("bmp280: pressure is %0.2fPa.\n", pressure_pa);
    
    ...
}

...
    
/* deinit */
(void)bmp280_shot_deinit();

return 0;
```

### Dokument

Online-Dokumente: [https://www.libdriver.com/docs/bmp280/index.html](https://www.libdriver.com/docs/bmp280/index.html).

Offline-Dokumente: /doc/html/index.html.

### Beitrag

Bitte beachten Sie CONTRIBUTING.md.

### Lizenz

Urheberrechte © (c) 2015 - Gegenwart LibDriver Alle Rechte vorbehalten



Die MIT-Lizenz (MIT)



Hiermit wird jeder Person kostenlos die Erlaubnis erteilt, eine Kopie zu erhalten

dieser Software und zugehörigen Dokumentationsdateien (die „Software“) zu behandeln

in der Software ohne Einschränkung, einschließlich, aber nicht beschränkt auf die Rechte

zu verwenden, zu kopieren, zu modifizieren, zusammenzuführen, zu veröffentlichen, zu verteilen, unterzulizenzieren und/oder zu verkaufen

Kopien der Software und Personen, denen die Software gehört, zu gestatten

dazu eingerichtet werden, unter folgenden Bedingungen:



Der obige Urheberrechtshinweis und dieser Genehmigungshinweis müssen in allen enthalten sein

Kopien oder wesentliche Teile der Software.



DIE SOFTWARE WIRD "WIE BESEHEN" BEREITGESTELLT, OHNE JEGLICHE GEWÄHRLEISTUNG, AUSDRÜCKLICH ODER

STILLSCHWEIGEND, EINSCHLIESSLICH, ABER NICHT BESCHRÄNKT AUF DIE GEWÄHRLEISTUNG DER MARKTGÄNGIGKEIT,

EIGNUNG FÜR EINEN BESTIMMTEN ZWECK UND NICHTVERLETZUNG VON RECHTEN DRITTER. IN KEINEM FALL DARF DAS

AUTOREN ODER URHEBERRECHTSINHABER HAFTEN FÜR JEGLICHE ANSPRÜCHE, SCHÄDEN ODER ANDERE

HAFTUNG, OB AUS VERTRAG, DELIKT ODER ANDERWEITIG, ENTSTEHEND AUS,

AUS ODER IM ZUSAMMENHANG MIT DER SOFTWARE ODER DER VERWENDUNG ODER ANDEREN HANDLUNGEN MIT DER

SOFTWARE.

### Kontaktieren Sie uns

Bitte senden Sie eine E-Mail an lishifenging@outlook.com.