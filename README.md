
# Arpha - Mrx04programmer
<center>
<img src="https://raw.githubusercontent.com/mrx04programmer/Arpha/master/ico.png" width="250" align="right"><br>
</center>
Pack de herramientas para pruebas de penetración en sistemas por medio de Arduino UNO.


## Modulos
**Arpha**
Basado en extraer información organizada y silenciosamente , haciendose pasar por el teclado del dispositivo.
En la linea 28 del Archivo *Arpha.ino* se configura la linea de comando a correr:
<br><br><br>![COMMAND](https://raw.githubusercontent.com/mrx04programmer/Arpha/master/img/command.png)
Y en el campo donde se encuentra **'ATTACKER_IP_SERVER'** es donde se debe cambiar por la ip del servidor a enviar la petición y posteriormente su puerto especifico.

**MouseController**
La idea de MouseController es poder crear un Mouse virtual por medio del arduino conectado, en el método **loop** del archivo, se encuentra su configuración al gusto propio. Por defecto esta en *0*
![LOOP](https://raw.githubusercontent.com/mrx04programmer/Arpha/master/img/loop.png)<br>
<br>En la función de Mouse.move, se establecen las coordenadas a mover el ratón o mouse. Para ello se necesita saber que el primer dato es el valor de la coordenada **x**, es decir horizontal, luego separado de una coma(,) se asgina el valor de **y**, es decir vertical y separado de una coma(,) se asigna el valor al mover la rueda del ratón o mouse.

**Wifi**
El modulo de Wifi es especializado en el arte del pentesting llamado Steal Wifi Info, el cual se trata de obtener la información importante de los Access Point que han sido conectados en el objetivo.

## Arduino Interpretación
<img align="left" src="https://raw.githubusercontent.com/mrx04programmer/Arpha/master/img/arduino.png" width="350">
<div>

1. Al oprimir el botón , envíara el código a compilarlo 
2. Recibirá las ordenes y las leerá
3. Enviará nuevamente las peticiones pero al dispositivo como salida.
</div>

<br><a href="#"><img src="https://img.shields.io/badge/Versión%20De%20Software-1.0-b?style=plastic&color=white&logoColor=black"></a>
<a href="#"><img src="https://img.shields.io/badge/Lenguaje%20Utilizado-Arduino-b?style=plastic&logo=arduino&color=informational&logoColor=white"></a>



